#include <chrono>
#include <stdlib.h>
#include <iostream>

//#include "Graph.h"

uint32_t GetNanos();

void BubbleSort(int arr[], int arraySize);

void FillArray(int arr[], int arraySize = 10, int maxRandValue = 100);
void PrintArray(int arr[], int arraySize);

int main()
{
	const int ARRAY_SIZE = 10;
	uint32_t start = 0, end = 0;

	int arr[ARRAY_SIZE] = { 0 };
	FillArray(arr, ARRAY_SIZE);

	PrintArray(arr, ARRAY_SIZE);
	start = GetNanos();
	BubbleSort(arr, ARRAY_SIZE);
	end = GetNanos();
	printf("\n");
	printf("BubbleSort took: %i nanoseconds", (end - start));
	printf("\n");
	PrintArray(arr, ARRAY_SIZE);

	/*Node* nodeTest = new Node("Start");
	std::cout << nodeTest;*/
}

uint32_t GetNanos()
{
	return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

void BubbleSort(int arr[], int arraySize)
{
	for (int index_1 = 0; index_1 < arraySize - 1; index_1++)
	{
		for (int index_2 = 0; index_2 < arraySize - 2; index_2++)
		{
			if (arr[index_2] > arr[index_2 + 1])
			{
				int temp = arr[index_2];

				arr[index_2] = arr[index_2 + 1];

				arr[index_2 + 1] = temp;
			}
		}
	}
}

void FillArray(int arr[], int arraySize, int maxRandValue)
{
	for (int index = 0; index < arraySize - 1; index++)
	{
		arr[index] = rand() % maxRandValue + 1;
	}
}

void PrintArray(int arr[], int arraySize)
{
	for (int index = 0; index < arraySize - 1; index++)
	{
		printf("%i ", arr[index]);
	}
}
