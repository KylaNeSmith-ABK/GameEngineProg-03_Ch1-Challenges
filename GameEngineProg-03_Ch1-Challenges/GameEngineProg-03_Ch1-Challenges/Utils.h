#pragma once
#include <chrono>
#include <iostream>

class Utils
{
public:
	static void BubbleSort(int arr[], int arraySize);

	// fills Int array with random values
	static void FillArray(int arr[], int arraySize = 10, int maxRandValue = 100);

	static void PrintArray(int arr[], int arraySize);

	static uint32_t GetNanos();
};