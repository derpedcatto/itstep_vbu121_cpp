#include <iostream>
using namespace std;

/* 1. 
Написать функцию, которая в качестве аргументов принимает указатель на
целочисленный одномерный динамический массив, а также его количество
элементов, и ВОЗВРАЩАЕТ (в параметрах-указателях) 4 значения: минимальный
и максимальный элемент, сумму и произведение всех чисел.
*/

//void func(int* arr, int* size, int* min, int* max, int* sum, int* multipl)
//{
//	for (int i = 0; i < *size; i++)
//	{
//		if (arr[i] > *max)
//		{
//			*max = arr[i];
//		}
//
//		if (arr[i] < *min)
//		{
//			*min = arr[i];
//		}
//
//		*sum += arr[i];
//		*multipl *= arr[i];
//	}
//}

//int main()
//{
//	srand(time(NULL));
//	int min = 20;
//	int max = 0;
//	int sum = 0;
//	int multipl = 1;
//
//	int size;
//	cout << "Enter size: ";
//	cin >> size;
//
//	int* arr = new int[size];
//
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = 1 + rand() % 20;
//		cout << arr[i] << " ";
//	}
//
//	cout << endl << endl;
//	func(arr, &size, &min, &max, &sum, &multipl);
//
//	printf("min: %d\nmax: %d\nsum: %d\nmultipl: %d",
//			min, max, sum, multipl);
//
//	cout << endl;
//	return 0;
//}



/* 2. 
Написать библиотеку myarray.h с рядом функций для работы с динамическими массивами:
a) Выделения динамической памяти под массив
b) Инициализации динамического массива случайными числами
c) Показа динамического массива на экран консоли
d) Очистки памяти от динамического массива
е) Добавления элемента в начало массива
f) Добавления элемента в конец массива
д) Вставки элемента по указанному индексу
h) Удаления элемента из начала массива
i) Удаления элемента из конца массива
Ј) Удаления элемента по указанному индексу
*/

//#include "myarray.h"

//int main()
//{
//	srand(time(NULL));
//
//	int size = 0;
//	int* arr = (int*)malloc(0);
//
//	char choice;
//
//	while (true)
//	{
//		cout << "Your current array size: " << size << endl;
//		cout << "a) Allocate memory to array\nb) Fill array with random numbers\nc) Show array\nd) Clear array memory\n";
//		cout << "e) Add first index array element\nf) Add last index array element\ng) Add any index array element\n";
//		cout << "h) Delete first index array element\ni) Delete last  array element\nj) Delete any index array element\nk) Exit";
//		cout << "\n\n--> ";
//		cin >> choice;
//
//		cout << endl << endl;
//
//		switch (choice)
//		{
//			case char(97):
//			{
//				allocate_memory(arr, size);
//				break;
//			}
//
//			case char(98):
//			{
//				if (size == 0)
//					cout << "Error: size is 0";
//				else
//					fill_array(arr, size);
//				break;
//			}
//
//			case char(99):
//			{
//				show_array(arr, size);
//				break;
//			}
//
//			case char(100):
//			{
//				clear_array(arr, size);
//				break;
//			}
//
//			case char(101):
//			{
//				add_first(arr, size);
//				break;
//			}
//
//			case char(102):
//			{
//				add_last(arr, size);
//				break;
//			}
//
//			case char(103):
//			{
//				add_any(arr, size);
//				break;
//			}
//
//			case char(104):
//			{
//				if (size == 0)
//					cout << "Error: size is 0";
//				else
//					delete_first(arr, size);
//				break;
//			}
//
//			case char(105):
//			{
//				if (size == 0)
//					cout << "Error: size is 0";
//				else
//					delete_last(arr, size);
//				break;
//			}
//
//			case char(106):
//			{
//				if (size == 0)
//					cout << "Error: size is 0";				
//				else
//					delete_any(arr, size);
//				break;
//			}
//
//			case char(107):
//			{
//				return 0;
//			}
//		}
//		cout << "\nDone!\n\n\n";
//	}
//}



/* 3.
Даны два массива: А[М] и B[N] (М и N вводятся с клавиатуры). Необходимо
создать третий массив минимально возможного размера, в котором нужно
собрать общие элементы двух массивов (без повторений).
*/

//int main()
//{
//	srand(time(NULL));
//	int* 1 = new int;
//	int* 2 = new int;
//
//	cout << "Enter arr1 : ";
//	cin >> *1;
//
//	cout << "Enter arr2 : ";
//	cin >> *2;
//
//	int* arr1 = new int[*1];
//	int* arr2 = new int[*2];
//
//	cout << "\n\narr1: ";
//	for (int i = 0; i < *1; i++)
//	{
//		arr1[i] = 1 + rand() % 10;
//		cout << arr1[i] << " ";
//	}
//	cout << "\narr2: ";
//	for (int i = 0; i < *2; i++)
//	{
//		arr2[i] = 1 + rand() % 10;
//		cout << arr2[i] << " ";
//	}
//
//	//-------------------------------------------------//
//
//	int* _temp = new int;
//
//	if (*1 <= *2)
//		*_temp = *1;
//	else
//		*_temp = *2;
//
//	int* arr_temp = new int[*_temp];
//
//	int* index = new int(0);
//	bool isFirst = true;
//	bool isRepeated = false;
//
//	//-------------------------------------------------//
//
//	for (int i = 0; i < *1; i++)
//	{
//		for (int j = 0; j < *2; j++)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				if (isFirst)
//				{
//					arr_temp[*index] = arr1[i];
//					isFirst = false;
//					break;
//				}
//
//				for (int c = 0; c < *_temp; c++)
//				{
//					if (arr1[i] == arr_temp[c])
//					{
//						isRepeated = true;
//						break;
//					}
//				}
//
//				if (!isRepeated)
//				{
//					*index = *index + 1;
//					arr_temp[*index] = arr1[i];
//				}
//			}
//
//			isRepeated = false;
//		}
//	}
//
//
//	//-------------------------------------------------//
//
//	int* 3 = new int(*index);
//	int* arr3 = new int[*3];
//
//	for (int i = 0; i <= *3; i++)
//	{
//		arr3[i] = arr_temp[i];
//	}
//
//	delete index;
//	delete _temp;
//	delete[] arr_temp;
// 
//  index = nullptr;
//  _temp = nullptr;
//  arr_temp = nullptr;
//
//	//-------------------------------------------------//
//
//	cout << "\narr3: ";
//	for (int i = 0; i <= *3; i++)
//	{
//		cout << arr3[i] << " ";
//	}
//
//
//	cout << endl;
//	return 0;
//}



/*4. 
Написать функцию, вставляющую/удаляющую строку/столбец двумерного
динамического массива по указанному номеру.
*/

//void arr2d_func(int**& arr, int& rows, int& cols, int& choice)
//{
//	switch (choice)
//	{
//		/*new column*/
//		case 1:
//		{
//			int index;
//			do
//			{
//				cout << "Enter index: ";
//				cin >> index;
//
//			} while (index < 0 || index > cols);
//
//			cols++;
//
//
//			/*init tmp_arr*/
//			int** tmp_arr = new int* [rows];
//			for (int i = 0; i < rows; i++)
//			{
//				tmp_arr[i] = new int[cols];
//			}
//
//
//			/*copying arr to tmp_arr*/
//			for (int i = 0; i < rows; i++)
//			{
//				for (int j = 0; j < cols - 1; j++)
//				{
//					tmp_arr[i][j] = arr[i][j];
//				}
//			}
//
//
//			/*allocating space for new column*/
//			for (int i = 0; i < rows; i++)
//			{
//				for (int j = cols - 1; j > index; j--)
//				{
//					tmp_arr[i][j] = tmp_arr[i][j - 1];
//				}
//			}
//
//
//			/*filling index values with specified num*/
//			int num;
//			cout << "Enter num: ";
//			cin >> num;
//
//			for (int i = 0; i < rows; i++)
//			{
//				tmp_arr[i][index] = num;
//			}
//
//
//			/*reallocating arr to tmp_arr*/
//			for (int i = 0; i < rows; i++)
//			{
//				delete[] arr[i];
//			}
//			delete[] arr;
//
//			arr = tmp_arr;
//
//			break;
//		}
//
//		/*new row*/
//		case 2:
//		{
//			int index;
//			do
//			{
//				cout << "Enter index: ";
//				cin >> index;
//
//			} while (index < 0 || index > rows);
//
//			rows++;
//
//			/*init tmp_arr*/
//			int** tmp_arr = new int* [rows];
//			for (int i = 0; i < rows; i++)
//			{
//				tmp_arr[i] = new int[cols];
//			}
//
//
//			/*copying arr to tmp_arr*/
//			for (int i = 0; i < rows - 1; i++)
//			{
//				for (int j = 0; j < cols; j++)
//				{
//					tmp_arr[i][j] = arr[i][j];
//				}
//			}
//
//
//			/*allocating space for new row*/
//			for (int i = rows - 1; i > index; i--)
//			{
//				for (int j = 0; j < cols; j++)
//				{
//					tmp_arr[i][j] = tmp_arr[i - 1][j];
//				}
//			}
//
//			/*filling index values with specified num*/
//			int num;
//			cout << "Enter num: ";
//			cin >> num;
//
//			for (int j = 0; j < cols; j++)
//			{
//				tmp_arr[index][j] = num;
//			}
//
//
//			/*reallocating arr to tmp_arr*/
//			for (int i = 0; i < cols - 1; i++)
//			{
//				delete[] arr[i];
//			}
//			delete[] arr;
//
//			arr = tmp_arr;
//
//			break;
//		}
//
//		/*delete column*/
//		case 3: 
//		{
//			int index;
//			do
//			{
//				cout << "Enter index: ";
//				cin >> index;
//
//			} while (index < 0 || index > cols - 1);
//
//			cols--;
//
//
//			/*init tmp_arr*/
//			int** tmp_arr = new int* [rows];
//			for (int i = 0; i < rows; i++)
//			{
//				tmp_arr[i] = new int[cols];
//			}
//
//
//			/*copying arr to tmp_arr with index skip*/
//			int temp;
//			for (int i = 0; i < rows; i++)
//			{
//				temp = index;
//
//				for (int j = 0; j < cols; j++)
//				{
//					if (j == temp)
//					{
//						temp++;
//						tmp_arr[i][j] = arr[i][j + 1];
//					}
//
//					else
//						tmp_arr[i][j] = arr[i][j];
//				}
//			}
//
//
//			/*reallocating arr to tmp_arr*/
//			for (int i = 0; i < rows; i++)
//			{
//				delete[] arr[i];
//			}
//			delete[] arr;
//
//			arr = tmp_arr;
//
//			break;
//		}
//
//		/*delete row*/
//		case 4:
//		{
//			int index;
//			do
//			{
//				cout << "Enter index: ";
//				cin >> index;
//
//			} while (index < 0 || index > rows - 1);
//
//			rows--;
//
//
//			/*init tmp_arr*/
//			int** tmp_arr = new int* [rows];
//			for (int i = 0; i < rows; i++)
//			{
//				tmp_arr[i] = new int[cols];
//			}
//
//
//			/*copying arr to tmp_arr with index skip*/
//			bool sw = true;
//			for (int i = 0; i < rows; i++)
//			{
//				if (i == index)
//					sw = false;
//
//				if (sw)
//					for (int j = 0; j < cols; j++)
//					{
//						tmp_arr[i][j] = arr[i][j];
//					}
//
//				if (!sw)
//					for (int j = 0; j < cols; j++)
//					{
//						tmp_arr[i][j] = arr[i + 1][j];
//					}
//			}
//
//
//			/*reallocating arr to tmp_arr*/
//			for (int i = 0; i < rows; i++)
//			{
//				delete[] arr[i];
//			}
//			delete[] arr;
//
//			arr = tmp_arr;
//
//			break;
//		}
//	}
//}

//int main()
//{
//	int choice;
//	int rows = 5;
//	int cols = 5;
//
//	/*init array*/
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		arr[i] = new int[cols];
//	}
//
//	/*fill array*/
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			arr[i][j] = i + j;
//		}
//	}
//
//	while (true)
//	{
//		if (rows == 0 || cols == 0)
//		{
//			cout << "Array is empty!";
//			return 0;
//		}
//
//		do
//		{
//			cout << "\n\n";
//			cout << "1) Add column or row\n";
//			cout << "2) Delete column or row\n";
//			cout << "3) Show 2D array\n";
//			cout << "4) Exit\n";
//			cout << "--> ";
//			cin >> choice;
//			cout << "\n\n";
//
//		} while (choice < 0 || choice > 4);
//
//		switch (choice)
//		{
//			case 1:
//			{
//				do
//				{
//					cout << "1) Column\n";
//					cout << "2) Row\n";
//					cout << "--> ";
//					cin >> choice;
//					cout << "\n";
//
//				} while (choice != 1 && choice != 2);
//
//				arr2d_func(arr, rows, cols, choice);
//
//				break;
//			}
//
//			case 2:
//			{
//				do
//				{
//					cout << "3) Column\n";
//					cout << "4) Row\n";
//					cout << "--> ";
//					cin >> choice;
//					cout << "\n";
//
//				} while (choice != 3 && choice != 4);
//
//				arr2d_func(arr, rows, cols, choice);
//
//				break;
//			}
//
//			case 3:
//			{
//				for (int i = 0; i < rows; i++)
//				{
//					for (int j = 0; j < cols; j++)
//					{
//						cout << arr[i][j] << "\t";
//					}
//					cout << endl;
//				}
//				break;
//			}
//
//			case 4:
//			{
//				return 0;
//			}
//		}
//	}
//}