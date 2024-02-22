#include <iostream>

class MyException : public std::invalid_argument {
	int First_Element, Progression_Size, Difference;
	int* Data;
public:
	MyException(const std::string& msg, int first, int size, int d, int* data) :std::invalid_argument(msg) {
		First_Element = first;
		Progression_Size = size;
		Difference = d;
		Data = data;
	}

	void Print(){
		std::cout << "Invalid Arithmetical Progression" << std::endl;
		std::cout << "First Element: " << First_Element << std::endl;
		std::cout << "Difference: " << Difference << std::endl;
		std::cout << "Data: " << std::endl;
		for (int i = 0; i < Progression_Size; i++) {
			std::cout << Data[i] << " ";
		}
		std::cout << std::endl;
	}



};

class Arithmetical_Progression {
public:
	int First_Element, Progression_Size, Difference;
	int* Data;

	Arithmetical_Progression(int first, int size, int d, int* data) {
		if (size <= 0) {
			throw std::invalid_argument("Invalid size of progression");
		}
		First_Element = first;
		Progression_Size = size;
		Difference = d;
		Data = new int[size];
		

		//progression check
		for (int i = 0; i < Progression_Size; i++) {
			Data[i] = first + i * d;
			if (data[i] != Data[i]) {
				delete[] Data;
				throw MyException("It's not an Arithmetical Progression!", first, size, d, data);
			}
		}
	}

	void Show(){
		std::cout << "Arithmetical Progression : " << std::endl;
		for (int i = 0; i < Progression_Size; i++) {
			std::cout << Data[i] << ' ';
		}
		std::cout << std::endl;
	}

	~Arithmetical_Progression() {
		delete[] Data;
	}
};


int main() {
	try {
		int Good_Massiv[3] = { 2,4,6 };
		Arithmetical_Progression Good_Progression(2, 3, 2,Good_Massiv);
		Good_Progression.Show();


		int Bad_Massiv[3] = { 2,4,666 };
		Arithmetical_Progression Bad_Progression(2, 3, 2, Bad_Massiv);
		Bad_Progression.Show();
	}
	catch (const MyException& exp){
		std::cout << "Exception: " << exp.what() << std::endl;
	}
	catch (const std::exception& exp) {
		std::cout << "Exception: " << exp.what() << std::endl;
	}

	return 0;
}