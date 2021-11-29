#pragma once

void allocate_memory(int*& arr, int& size)
{
	int tmp_size;
	do
	{
		cout << "Enter value to allocate: ";
		cin >> tmp_size;

	} while (tmp_size < 1);

	size += tmp_size;

	arr = (int*)realloc(arr, size * sizeof(int));

	//replace garbage with 0
	for (int i = size - tmp_size; i < size; i++)
	{
		arr[i] = 0;
	}
}

void fill_array(int* arr, int &size)
{
	int min;
	int max;

	cout << "Enter min range value: ";
	cin >> min;
	do
	{
		cout << "Enter max range value: ";
		cin >> max;

	} while (max < min);

	for (int i = 0; i < size; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}

void show_array(int* arr, int &size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void clear_array(int*& arr, int &size)
{
	free(arr);
	size = 0;
	arr = (int*)malloc(size);
}

void add_first(int*& arr, int& size)
{
	int tmp_val;
	cout << "Enter value: ";
	cin >> tmp_val;

	size++;
	arr = (int*)realloc(arr, size * sizeof(int));

	for (int i = size - 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[0] = tmp_val;
}

void add_last(int*& arr, int& size)
{
	int tmp_val;
	cout << "Enter value: ";
	cin >> tmp_val;

	size++;
	arr = (int*)realloc(arr, size * sizeof(int));

	arr[size - 1] = tmp_val;
}

void add_any(int*& arr, int& size)
{
	int tmp_val;
	cout << "Enter value: ";
	cin >> tmp_val;

	int tmp_index;
	do
	{
		cout << "Enter index: ";
		cin >> tmp_index;
	} while (tmp_index < 0 || tmp_index > size);

	size++;
	arr = (int*)realloc(arr, size * sizeof(int));

	for (int i = size - 1; i >= tmp_index; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[tmp_index] = tmp_val;
}

void delete_first(int*& arr, int& size)
{
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
	arr = (int*)realloc(arr, size * sizeof(int));
}

void delete_last(int*& arr, int& size)
{
	size--;
	arr = (int*)realloc(arr, size * sizeof(int));
}

void delete_any(int*& arr, int& size)
{
	int tmp_index;
	do
	{
		cout << "Enter index: ";
		cin >> tmp_index;

	} while (tmp_index < 0 || tmp_index > size - 1);

	for (int i = tmp_index; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
	arr = (int*)realloc(arr, size * sizeof(int));
}



/*old new | delete option*/
/*
void allocate_memory(int*& arr, int& size)
{
	int tmp_size;
	cout << "Enter value to allocate: ";
	cin >> tmp_size;

	size += tmp_size;
	int* tmp_arr = new int[size];

	for (int i = 0; i < size - tmp_size; i++)
	{
		tmp_arr[i] = arr[i];
	}

	//replace garbage with 0
	for (int i = size - tmp_size; i < size; i++)
	{
		tmp_arr[i] = 0;
	}

	delete[] arr;
	arr = tmp_arr;

	cout << "\nMemory allocated";
}

void clear_array(int*& arr, int& size)
{
	delete[] arr;
	size = 0;
	arr = new int[size];

	cout << "\nArray is freed from memory";
}
*/