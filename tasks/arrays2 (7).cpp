#include <iostream>
#include <time.h>
using namespace std;

/* 1. ¬ двумерном массиве размерности M x N помен€ть местами чЄтные строки с нечЄтными.
Ќадеюсь, что имелось ввиду помен€ть горизонтальные строки местами */

//int main()
//{
//	const int size = 6;
//	int arr[size][size];
//	int num = 1;
//	int temp_num;
//
//	for (int i = 0; i < size; i++)
//	{
//		temp_num = num + size;
//
//		for (int j = 0; j < size; j++)
//		{
//			arr[i][j] = temp_num;
//			cout << arr[i][j] << "\t";
//			temp_num++;
//		}
//
//		cout << endl;
//
//		i++;
//		if (i == size)
//			break;
//
//		for (int j = 0; j < size; j++)
//		{
//			arr[i][j] = num;
//			cout << arr[i][j] << "\t";
//			num++;
//		}
//
//		num += size;
//
//		cout << endl;
//	}
//
//	return 0;
//}



/* 2. ƒан двумерный массив размерностью M x N, заполненный случайными числами из диапазона от - 100 до 100. 
	  ќпределить сумму элементов массива, расположенных между минимальным и максимальным элементами. */

//int main()
//{
//	srand(time(0));
//	const int size = 5;
//	int arr[size][size];
//	int min_loc[2]; //i | j
//	int max_loc[2]; //i | j
//	int min = 100;
//	int max = -100;
//	int index = 0;
//	int min_index;
//	int max_index;
//	int sum = 0;
//	bool StartCount = false;
//	bool End = false;
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			arr[i][j] = 100 - rand() % 201;
//			cout << arr[i][j] << "  ";
//
//			if (arr[i][j] < min)
//			{
//				min = arr[i][j];
//				min_index = index;
//				min_loc[0] = i;
//				min_loc[1] = j;
//			}
//
//			if (arr[i][j] > max)
//			{
//				max = arr[i][j];
//				max_index = index;
//				max_loc[0] = i;
//				max_loc[1] = j;
//			}
//
//			index++;
//		}
//
//		cout << endl;
//	}
//
//	if (min_index < max_index)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (i == min_loc[0] && j == min_loc[1])
//					StartCount = true;
//
//				if (StartCount == true)
//				{
//					sum += arr[i][j];
//				}
//
//				if (i == max_loc[0] && j == max_loc[1])
//				{
//					End = true;
//					break;
//				}
//			}
//
//			if (End == true)
//				break;
//		}
//	}
//
//	if (min_index > max_index)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (i == max_loc[0] && j == max_loc[1])
//					StartCount = true;
//
//				if (StartCount == true)
//				{
//					sum += arr[i][j];
//				}
//
//				if (i == min_loc[0] && j == min_loc[1])
//				{
//					End = true;
//					break;
//				}
//			}
//
//			if (End == true)
//				break;
//		}
//	}
//
//	cout << "\nMin: " << min << ", index: " << min_index;
//	cout << "\nMax: " << max << ", index: " << max_index;
//	cout << "\nSum: " << sum;
//
//	cout << endl;
//	return 0;
//}



/* 3. «аполнить квадратную матрицу размером M x N по спирали. „исло 1 ставитс€ в центр матрицы, а затем массив заполн€етс€ по спирали против часовой стрелки значени€ми по возрастанию. */

//int main()
//{
//	const int size = 5;
//	int arr[size][size];
//	int num = 25;
//	int i = 0;
//	int j = 0;
//	int i_beg = 0;
//	int i_end = 0;
//	int j_beg = 0;
//	int j_end = 0;
//
//	while (num > 0)
//	{
//		arr[i][j] = num;
//
//		if (i == i_beg && j < size - j_end - 1)						//≈сли у нас верхн€€ сторона пр€моугольника и она не достигла правой стороны, то двигаемс€ вправо
//			j++;
//
//		else if (j == size - j_end - 1 && i < size - i_end - 1)		//≈сли мы на правой стороне пр€моугольника и не достигли нижней стороны, то двигаемс€ вниз
//			i++;
//
//		else if (i == size - i_end - 1 && j > j_beg)				//≈сли мы на нижней стороне пр€моугольника и не достигли левой стороны, то двигаемс€ влево
//			j--;
//
//		else														//»наче двигаемс€ вверх
//			i--;
//
//		if ((i == i_beg + 1) && (j == j_beg))
//		{
//			i_beg++;
//			i_end++;
//			j_beg++;
//			j_end++;
//		}
//
//		num--;
//	}
//
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			cout << arr[i][j];
//
//			if (arr[i][j] < 10)
//				cout << "  ";
//			else
//				cout << " ";
//		}
//
//		cout << endl;
//	}
//
//	cout << endl;
//	return 0;
//}



/* 4. “о же самое, только число 1 ставитс€ в угловой (например, верхний левый) элемент, и спираль закручиваетс€ к центру матрицы. */

//int main()
//{
//	const int size = 6;
//	int arr[size][size];
//	int num = 1;
//	int i = 0;
//	int j = 0;
//	int i_beg = 0;
//	int i_end = 0;
//	int j_beg = 0;
//	int j_end = 0;
//
//	while (num <= size * size)
//	{
//		arr[i][j] = num;
//
//		if (i == i_beg && j < size - j_end - 1)						//≈сли у нас верхн€€ сторона пр€моугольника и она не достигла правой стороны, то двигаемс€ вправо
//			j++;
//
//		else if (j == size - j_end - 1 && i < size - i_end - 1)		//≈сли мы на правой стороне пр€моугольника и не достигли нижней стороны, то двигаемс€ вниз
//			i++;
//
//		else if (i == size - i_end - 1 && j > j_beg)				//≈сли мы на нижней стороне пр€моугольника и не достигли левой стороны, то двигаемс€ влево
//			j--;
//
//		else														//»наче двигаемс€ вверх
//			i--;
//
//		if ((i == i_beg + 1) && (j == j_beg))
//		{
//			i_beg++;
//			i_end++;
//			j_beg++;
//			j_end++;
//		}
//
//		num++;
//	}
//
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			cout << arr[i][j];
//
//			if (arr[i][j] < 10)
//				cout << "  ";
//			else
//				cout << " ";
//		}
//
//		cout << endl;
//	}
//
//	cout << endl;
//	return 0;
//}



/* 5. «аполнить массив M x N следующим образом:
	 1  2  3  4  5  6
	 12 11 10 9  8  7
*/

//int main()
//{
//	const int sizei = 5;
//	const int sizej = 6;
//	int arr[sizei][sizej];
//	int num = 1;
//	bool sw = true;
//
//	for (int i = 0; i < sizei; i++)
//	{
//		if (sw == true)
//		{
//			for (int j = 0; j < sizej; j++)
//			{
//				arr[i][j] = num;
//				cout << arr[i][j] << "\t";
//				num++;
//			}
//
//			sw = false;
//			cout << endl;
//			continue;
//		}
//
//		if (sw == false)
//		{
//			num += sizej;
//			int temp = num - 1;
//
//			for (int j = 0; j < sizej; j++)
//			{
//				arr[i][j] = temp;
//				cout << arr[i][j] << "\t";
//				temp--;
//			}
//
//			sw = true;
//			cout << endl;
//			continue;
//		}
//	}
//
//	return 0;
//}