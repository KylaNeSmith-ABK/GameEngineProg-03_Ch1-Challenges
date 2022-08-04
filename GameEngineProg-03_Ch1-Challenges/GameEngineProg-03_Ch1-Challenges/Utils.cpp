#include "Utils.h"

void Utils::BubbleSort(int arr[], int arraySize)
{
	for (int index_1 = 0; index_1 < arraySize - 1; index_1++)
	{
		for (int index_2 = 0; index_2 < arraySize - 2; index_2++)
		{
			// if next value is less than current value
			if (arr[index_2] > arr[index_2 + 1])
			{
				// perform swapping of values
				int temp = arr[index_2];

				arr[index_2] = arr[index_2 + 1];

				arr[index_2 + 1] = temp;
			}
		}
	}
}

void Utils::FillArray(int arr[], int arraySize, int maxRandValue)
{
	for (int index = 0; index < arraySize - 1; index++)
	{
		arr[index] = rand() % maxRandValue + 1;
	}
}

void Utils::PrintArray(int arr[], int arraySize)
{
	for (int index = 0; index < arraySize - 1; index++)
	{
		printf("%i ", arr[index]);
	}
}

uint32_t Utils::GetNanos()
{
	return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}
