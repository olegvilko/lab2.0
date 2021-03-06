// Вильковского О. С., 1 курс, ПИз-18
// Лабораторная 2, вариант 15
// Определить, лежит ли максимальный элемент квадратной матрицы в той области, что лежит выше ее побочной диагонали

#include "pch.h"
#include <iostream>
#include <locale>
#define NUMBEROFCHECKS 3

using namespace std;

int lengthArray;

void setOptions() {
	setlocale(LC_ALL, "Russian");
	system("color F0");
}

int** inputMatrix() {
	cout << "Введите размерность матрицы: ";
	cin >> lengthArray;
	int **arr = new int *[lengthArray];
	for (int i = 0; i < lengthArray; i++) {
		arr[i] = new int[lengthArray];
	}
	for (int j = 0; j != lengthArray; j++) {
		for (int i = 0; i != lengthArray; i++) {
			cout << "Введите значение элемента a" << j + 1 << i + 1 << ": ";
			cin >> arr[i][j];
		}
	}
	return arr;
}

int findMax(int** arr) {
	int max = arr[0][0];
	for (int j = 0; j != lengthArray; j++) {
		for (int i = 0; i != lengthArray; i++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	cout << "Максимальный элемент: " << max << endl;
	return max;
}

bool checkMaxHigherSide(int** arr, int max) {
	bool flag = false;
	for (int j = 0; j < lengthArray; j++) {
		for (int i = lengthArray - j - 2; i >= 0; i--) {
			if (arr[i][j] == max) {
				flag = true;
				j = lengthArray;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	setOptions();
	for (int i = 0; i < NUMBEROFCHECKS; i++) {
		int **arr = inputMatrix();
		int max = findMax(arr);
		if (checkMaxHigherSide(arr, max)) {
			cout << "Максимальный элемент лежит выше побочной диагонали" << endl;
		}
		else {
			cout << "Максимальный элемент не лежит выше побочной диагонали" << endl;
		}
	}
	system("pause");
}

