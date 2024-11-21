#include <iostream>
#include <fstream>
#include <random>
#include "DynamicArrSequence.h"
#include "Sorter.h"
#include "test.h"
using namespace std;
void test_Merge_Sort_numbers() {
	try {
		srand(time(NULL));
		int size = 1e5;
		int diaposon = 200;
		Sorter<double> sorter;
		sorter.init(Sorter<double>::sorts::MergeSort);
		DynamicArrSequence<double> arr(size);
		for (int i = 0; i < size; ++i) {
			arr.push_back(rand() % diaposon);
		}
		sorter.sort(arr);
		for (int i = 1; i < size; ++i) {
			if (arr[i - 1] > arr[i]) {
				cout << "test_Merge_Sort_numbers - error sort";
				break;
			}
		}
	}
	catch (std::exception& e) {
		cout << "test_Merge_Sort_numbers - error "<< endl;
		cout << e.what() << endl;
		return;
	}
	cout << "test_Merge_Sort_numbers - complete" << endl;
}


void test_Quick_Sort_numbers() {
	try {
		srand(time(NULL));
		int size = 1e5;
		int diaposon = 200;
		Sorter<double> sorter;
		DynamicArrSequence<double> arr(size);
		for (int i = 0; i < size; ++i) {
			arr.push_back(rand() % diaposon);
		}
		sorter.sort(arr);
		for (int i = 1; i < size; ++i) {
			if (arr[i - 1] > arr[i]) {
				cout << "test_Quick_Sort_numbers - error sort";
				break;
			}
		}
	}
	catch (std::exception& e) {
		cout << "test_Quick_Sort_numbers - error " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "test_Quick_Sort_numbers - complete" << endl;
}

class people {
	int age;
	const char* name;
public:
	people() : age(0) , name("Oleg") {}
	people(int a) : age(a), name("Oleg") {}
	bool operator<(people& p) {
		return age < p.age;
	}
	bool operator>(people& p) {
		return age > p.age;
	}
};
void test_Merge_sort_people () {
	try {
		srand(time(NULL));
		int size = 1e5;
		int diaposon = 200;
		Sorter<people> sorter;
		sorter.init(Sorter<people>::sorts::MergeSort);
		DynamicArrSequence<people> arr(size);
		for (int i = 0; i < size; ++i) {
			arr.push_back(rand() % diaposon);
		}
		sorter.sort(arr);
		for (int i = 1; i < size; ++i) {
			if (arr[i - 1] > arr[i]) {
				cout << "test_Merge_sort_people - error sort";
				break;
			}
		}
	}
	catch (std::exception& e) {
		cout << "test_Merge_sort_people - error " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "test_Merge_sort_people - complete" << endl;
}

void test_Quick_sort_people() {
	try {
		srand(time(NULL));
		int size = 1e5;
		int diaposon = 200;
		Sorter<people> sorter;
		DynamicArrSequence<people> arr(size);
		for (int i = 0; i < size; ++i) {
			arr.push_back(rand() % diaposon);
		}
		sorter.sort(arr);
		for (int i = 1; i < size; ++i) {
			if (arr[i - 1] > arr[i]) {
				cout << "test_Quick_sort_people - error sort";
				break;
			}
		}
	}
	catch (std::exception& e) {
		cout << "test_Quick_sort_people - error " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "test_Quick_sort_people - complete" << endl;
}
template <typename T>
void print(DynamicArrSequence<T>& arr) {
	std::cout << "[ ";
	for (int i = 0; i < arr.get_colElm(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]";
}

void test_Merge_sort_file() {
	try {

		std::ifstream inputFile("inputM.txt");
		DynamicArrSequence<double> arr;
		double number;
		while (inputFile >> number) {
			arr.push_back(number);
		}
		inputFile.close();

		

		Sorter<double> sorter;
		sorter.init(Sorter<double>::sorts::MergeSort);
		sorter.sort(arr);

		std::ofstream outputFile("outputM.txt");
		for (int i = 0; i < arr.get_colElm(); i++) {
			outputFile << arr[i] << " ";
		}
		outputFile.close();
		

		std::ifstream inputFile2("outputM.txt");
		DynamicArrSequence<double> arr2;
		double number2;
		while (inputFile2 >> number2) {
			arr2.push_back(number2);
		}

		for (int i = 1; i < arr2.get_colElm(); ++i) {
			if (arr2[i - 1] > arr2[i]) {
				cout << "\nerror sort";
				break;
			}
		}
		inputFile2.close();
	}
	catch (std::exception& e) {
		cout << "test_Merge_sort_file - error " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "test_Merge_sort_file - complete" << endl;
}

void test_Quick_sort_file() {
	try {

		std::ifstream inputFile("inputQ.txt");
		DynamicArrSequence<double> arr;
		double number;
		while (inputFile >> number) {
			arr.push_back(number);
		}
		inputFile.close();

		Sorter<double> sorter;
		sorter.sort(arr);

		std::ofstream outputFile("outputQ.txt");
		for (int i = 0; i < arr.get_colElm(); i++) {
			outputFile << arr[i] << " ";
		}
		outputFile.close();


		std::ifstream inputFile2("outputQ.txt");
		DynamicArrSequence<double> arr2;
		double number2;
		while (inputFile2 >> number2) {
			arr2.push_back(number2);
		}

		for (int i = 1; i < arr2.get_colElm(); ++i) {
			if (arr2[i - 1] > arr2[i]) {
				cout << "\nerror sort";
				break;
			}
		}
		inputFile2.close();
	}
	catch (std::exception& e) {
		cout << "test_Quick_sort_file - error " << endl;
		cout << e.what() << endl;
		return;
	}
	cout << "test_Quick_sort_file - complete" << endl;
}