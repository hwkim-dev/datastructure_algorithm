#include <iostream>

using namespace std;

#define NUM_INPUT 6


void insertionSort(int *A, int n)
{
	int key, j;
	for (int i = 1; i < n; ++i) 
	{
		key = A[i];
		//insert A[i] into the sorted subarray A[1 : i-1]
		j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];

			j = j - 1;
		}
		A[j + 1] = key;
	}
}

int main() 
{
	/*
	i : sequence of n numbers {a_1, a_2, a_3, ..., a_n}
	o : permutation (re-ordering) 
	{a_1 <= a_2 <= a_3 <= ... <= a_n}
	*/
	
	int input[NUM_INPUT] = {5, 2, 4, 6, 1, 3};
	insertionSort(input, NUM_INPUT);
	for (int i = 0; i < NUM_INPUT; i++)
	{
		cout << input[i] << ", ";
	}

	return 0;
}