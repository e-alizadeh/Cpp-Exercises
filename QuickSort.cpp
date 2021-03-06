// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// below two libraries are loaded to generate a different value every time the program is run.
#include <cstdlib>      /* rand() */
#include <time.h>       /* time() */

using namespace std;

void swap(int *a, int *b); // a <-> b

void printArray(int nArray[], int nSizeArray);  // print all elements of an array

int partition(int nArray[], int nIdxStart, int nIdxEnd); // nArray[nIdxEnd] = Pivot
int randomizedPartition(int nArray[], int nIdxStart, int nIdxEnd); // nArray[nIdxEnd] = Pivot
void QuickSort(int nArray[], int nIdxStart, int nIdxEnd);


/* --------------------------------------------------------- */
int main()
{

	int nArray[] = { 7, 2, 1, 6, 8, 5, 3, 4 };
	int nSizeArray = sizeof(nArray) / sizeof(nArray[0]);
	
	int nIdxStart = 0;
	int nIdxEnd = nSizeArray - 1;

	cout << "Unsorted Array: \n";
	printArray(nArray, nSizeArray);



	int nIdxPartition = randomizedPartition(nArray, nIdxStart, nIdxEnd);

	cout << "\nRandomized Partitioned Array!!!: \n";
	printArray(nArray, nSizeArray);



	QuickSort(nArray, nIdxStart, nIdxEnd);

	cout << "\nSorted Array: \n";
	printArray(nArray, nSizeArray);

    return 0;
}
/* --------------------------------------------------------- */



void swap(int *a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void printArray(int nArray[], int nSizeArray)
{
	for (int i = 0; i < nSizeArray; i++)
	{
		std::cout << nArray[i] << " ";
	}
	std::cout << std::endl;
}



// Partitioning nArray into two sections where (elements <= nPivot) go to left and (elements > nPivot) go to right
int partition(int nArray[], int nIdxStart, int nIdxEnd) 
{
	int nPivot = nArray[nIdxEnd];
	int nIdxPartition = nIdxStart;
	
	for (int i = nIdxStart; i <= nIdxEnd - 1; i++) 
	{
		if (nArray[i] <= nPivot) // all elements 
		{
			swap(&nArray[i], &nArray[nIdxPartition]);
			nIdxPartition++; 
		}
	}
	swap(&nArray[nIdxPartition] , &nArray[nIdxEnd]);
	return nIdxPartition;
}



void QuickSort(int nArray[], int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nIdxPartition = partition(nArray, nStart, nEnd);
		QuickSort(nArray, nStart, nIdxPartition - 1);
		QuickSort(nArray, nIdxPartition + 1, nEnd);
	}
}


// Partitioning nArray into two sections where (elements <= nPivot) go to left and (elements > nPivot) go to right
int randomizedPartition(int nArray[], int nIdxStart, int nIdxEnd)
{
	/* initialize random seed: */
	srand(time(NULL));  // In order to generate a different value every time the program is run
	int nIdxPivot = rand() % nIdxEnd + nIdxStart; // random selection of nIdxPivot such that: nIdxStart < nIdxPivot < nIdxEnd

	cout << "Randomly selected pivot " << nArray[nIdxPivot] << endl;
	swap(&nArray[nIdxPivot], &nArray[nIdxEnd]);
	int nIdxPartition = partition(nArray, nIdxStart, nIdxEnd);

	return nIdxPartition;
}