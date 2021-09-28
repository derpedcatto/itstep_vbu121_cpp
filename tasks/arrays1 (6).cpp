#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;

/* 1. Создать символьный массив из 100 случайных элементов. Определить, сколько в нём цифр, букв и знаков пунктуации. */

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	srand(time(NULL));
//	char arr[100];
//	int count_num = 0;
//	int count_letter = 0;
//	int count_char = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		arr[i] = 32 + rand() % 94;
//		cout << arr[i] << " ";
//
//		if (arr[i] > 48 && arr[i] < 58)
//			count_num++;
//
//		if ((arr[i] > 65 && arr[i] < 90) || (arr[i] > 97 && arr[i] < 122))
//			count_letter++;
//
//		if (arr[i] == 33 || arr[i] == 34 || arr[i] == 40 || arr[i] == 41 || 
//			arr[i] == 44 || arr[i] == 45 || arr[i] == 46 || arr[i] == 58 || 
//			arr[i] == 59 || arr[i] == 63 || arr[i] == 96)
//			count_char++;
//	}
//
//	cout << "\n\nКол-во чисел: " << count_num;
//	cout << "\nКол-во букв: " << count_letter;
//	cout << "\nКол-во знаков пунктуации: " << count_char;
//
//	cout << endl;
//	return 0;
//}



/* 2. Создать массив из 10 целых случайных чисел. Изменить порядок следования элементов массива на противоположный (1 - й элемент меняется с 10 - м, 2 - й элемент с 9 - м и тд). */

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	srand(time(NULL));
//	int arr[10];
//	int inv_arr[10];
//	int c = 0;
//
//	cout << "Массив:\t\t     ";
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = rand() % 21;
//		cout << arr[i] << " ";
//	}
//
//	cout << "\nПеревёрнутый массив: ";
//
//	for (int j = 9; j >= 0; j--)
//	{
//		inv_arr[c] = arr[j];
//		cout << inv_arr[c] << " ";
//		c++;
//	}
//
//	cout << endl;
//	return 0;
//}



/* 3. Написать программу, копирующую один массив в другой следующим образом: сначала копируются последовательно все элементы, большие 0, затем последовательно все элементы, равные 0, а затем последовательно все элементы, меньшие 0. */

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	srand(time(NULL));
//	int A[15];
//	int B[15];
//	int c = 0;
//
//	cout << "Массив А: ";
//	for (int i = 0; i < 15; i++)
//	{
//		A[i] = rand() % 21 - 10;
//		cout << A[i] << " ";
//	}
//
//	//Положительные
//	for (int i = 0; i < 15; i++)
//		if (A[i] > 0)
//		{
//			B[c] = A[i];
//			c++;
//		}
//
//	//Нули
//	for (int i = 0; i < 15; i++)
//		if (A[i] == 0)
//		{
//			B[c] = A[i];
//			c++;
//		}
//
//	//Негативные
//	for (int i = 0; i < 15; i++)
//		if (A[i] < 0)
//		{
//			B[c] = A[i];
//			c++;
//		}
//
//	cout << "\nМассив B: ";
//	for (int i = 0; i < 15; i++)
//		cout << B[i] << " ";
//
//	cout << endl;
//	return 0;
//}



/* 4. Даны 2 массива размерности M и N соответственно. Необходимо переписать в третий массив общие элементы первых двух массивов, без повторений. */

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	srand(time(NULL));
//	int A[15];
//	int B[15];
//	int C[15];
//	int index = 0;
//	bool isRepeated = false;
//
//	cout << "Массив А: ";
//	for (int i = 0; i < 15; i++)
//	{
//		A[i] = rand() % 6;
//		cout << A[i] << " ";
//	}
//
//	cout << "\nМассив B: ";
//	for (int i = 0; i < 15; i++)
//	{
//		B[i] = rand() % 6;
//		cout << B[i] << " ";
//	}
//
//	for (int i = 0; i < 15; i++)
//	{
//		for (int j = 0; j < 15; j++)
//		{
//			if (A[i] == B[j])
//			{
//				for (int c = 0; c <= 15; c++)
//				{
//					if (A[i] == C[c])
//					{
//						isRepeated = true;
//						break;
//					}
//
//					else
//						isRepeated = false;
//				}
//
//				if (isRepeated == false)
//				{
//					C[index] = A[i];
//					index++;
//				}
//			}
//		}
//	}
//
//	cout << "\nОбщие элементы массивов: ";
//	for (int i = 0; i < index; i++)
//		cout << C[i] << " ";
//
//	cout << endl;
//	return 0;
//}



/* 4. Создать массив из 20 случайных чисел в диапазоне от - 10 до 20. Определить максимальное количество подряд идущих положительных элементов, не прерываемых ни нулями, ни отрицательными числами. Вывести найденный фрагмент. */

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	srand(time(NULL));
//	const int size = 20;
//	int arr[size];
//	int count = 0;
//	int true_count = 0;
//	int max = 0;
//	int min;
//	int true_max;
//	int true_min;
//
//	cout << "Массив: ";
//
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 31 - 10;
//		cout << arr[i] << " ";
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] < 1)
//			count = 0;
//
//		if (arr[i] > 0 && arr[i + 1] < 1)
//			max = i;
//
//		if (arr[i] > 0)
//			count++;
//
//		if (count == 1)
//			min = i;
//
//		if (count > true_count)
//		{
//			true_min = min;
//			true_max = max;
//			true_count = count;
//		}
//	}
//
//	cout << "\n\nСамый большой фрагмент из положительных элементов: ";
//
//	for (int i = true_min; i <= true_max; i++)
//		cout << arr[i] << " ";
//
//	cout << "\nНачальный индекс: " << true_min << "\nПоследний индекс: " << true_max;
//
//	cout << endl;
//	return 0;
//}