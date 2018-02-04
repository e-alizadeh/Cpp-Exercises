// Binary Search Algorithm
/* 
This file performs the following operations using Binary Search:
- Finding an element in an integer array,
- Finding the first occurrence of an element in an integer array,
- Finding the last occurrence of an element in an integer array.
*/

#include <iostream>
using namespace std;

// Function prototypes
int BinarySearch(int*, int, int);
int BinarySearch_FirstOccurance(int*, int, int);
int BinarySearch_LastOccurance(int*, int, int);


int main()
{
	int A[] = { 2, 4, 10, 10, 10, 18, 20 };

	int size = sizeof(A)/sizeof(A[0]);
	int x = 10; // element to be searched.

	cout << x << " is available at index " << BinarySearch(A, size, x) << endl;
	cout << x << " is first occurred at index " << BinarySearch_FirstOccurance(A, size, x) << endl;
	cout << x << " is last occurred at index " << BinarySearch_LastOccurance(A, size, x) << endl;

    return 0;
}



int BinarySearch(int A[], int size, int x) {
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high) 
	{
		mid = (low + high) / 2;

		if (x == A[mid]) 
		{
			return mid;
		} 
		else if (x < A[mid])
		{
			high = mid - 1;
		}
		else // x > A[mid]
		{
			low = mid + 1;
		}
	}
	return -1;
}

int BinarySearch_FirstOccurance(int A[], int size, int x)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int result = -1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (x == A[mid])
		{
			result = mid;
			high = mid - 1;
		}
		else if (x < A[mid])
		{
			high = mid - 1;
		}
		else // x > A[mid]
		{
			low = mid + 1;
		}
	}
	return result;
}


int BinarySearch_LastOccurance(int A[], int size, int x)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int result = -1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (x == A[mid])
		{
			result = mid;
			low = mid + 1;
		}
		else if (x < A[mid])
		{
			high = mid - 1;
		}
		else // x > A[mid]
		{
			low = mid + 1;
		}
	}
	return result;
}
