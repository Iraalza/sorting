#include <iostream>
using namespace std;

int main()
{
	while (true) {
		setlocale(LC_ALL, "Rus");
		int i;
		int n;
		cout << "Количество элементов в массиве > "; cin >> n;
		int* mas = new int[n];
		for (i = 0; i < n; i++)
		{
			cout << i + 1 << " элемент > "; cin >> mas[i];
		}
		cout << " Выберите метод сортировки массива " << endl;
		cout << " 1 - методом экстремумов " << endl;
		cout << " 2 - методом пузырька " << endl;
		cout << " 3 - методом вставки " << endl;
		int b;
		cin >> b;
		if (b == 1) {
			int i;
			int k = 0;
			for (i = 0; i < n - 1; i++) {
				int min = i;
				for (int j = i + 1; j < n; j++) {
					if (mas[j] < mas[min]) {
						min = j;
						k++;
					}
				}
				int c = mas[i];
				mas[i] = mas[min];
				mas[min] = c;
			}
			cout << endl << "Результирующий массив: ";
			for (i = 0; i < n; i++) {
				cout << mas[i] << ' ';
			}
			cout << endl << "Количество сравнений: " << k << endl;
		}
		if (b == 2) {
			int i;
			int k = 0;
			int temp;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (mas[j] > mas[j + 1]) {
						temp = mas[j];
						mas[j] = mas[j + 1];
						mas[j + 1] = temp;
						k++;
					}
				}
			}
			cout << endl << "Результирующий массив: ";
			for (i = 0; i < n; i++) {

				cout << mas[i] << ' ';
			}
			cout << endl << "Количество перестановок: " << k << endl;
		}
		if (b == 3) {
			int i, j, key = 0, temp = 0;
			for (i = 0; i < n - 1; i++)
			{
				key = i + 1;
				temp = mas[key];
				for (j = i + 1; j > 0; j--)
				{
					if (temp < mas[j - 1])
					{
						mas[j] = mas[j - 1];
						key = j - 1;
					}
				}
				mas[key] = temp;
			}
			cout << endl << "Результирующий массив: ";
			for (i = 0; i < n; i++) {

				cout << mas[i] << ' ';
			}
			cout << endl;
		}
		delete[] mas;
	}
}