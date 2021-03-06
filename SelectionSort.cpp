// Selection Sort Algorithm
// Time Complexity: O(n^2)   (where n is number of elements in an array)

#include <iostream>
using namespace std;

int *SelectionSort(int nArray[], int nNumElements); // function prototype

int main()
{
	int nArray[] = { 1, 4, 2, 6, 8, 3, 2};

	size_t nNumElements = sizeof(nArray)/sizeof(nArray[0]); // Number of elements in the array

	cout << "Selection Sort: BEFORE\n";
	cout << "----------------------- \n";
	for (unsigned int i = 0; i < nNumElements; i++)
	{
		cout << nArray[i] << "  ";
	}
	cout << endl;

	
	int *pnArray_sorted = SelectionSort(nArray, nNumElements);


	cout << "----------------------- \n";
	cout << "Selection Sort: AFTER\n";
	cout << "----------------------- \n";
	for (unsigned int i = 0; i < nNumElements; i++)
	{
		cout << *pnArray_sorted << "  ";
		pnArray_sorted++;	//
	}
	cout << endl;

    return 0;
}


int *SelectionSort(int nArray[], int nNumElements)
{
	for (int i = 0; i < nNumElements - 1; i++)  // n - 2 passes
	{
		int idxMin = i; // elements from i till n-1 are new candidates

		for (int j = i + 1; j < nNumElements; j++) // n - 1 passes
		{
			if (nArray[j] < nArray[idxMin])
			{
				idxMin = j;		// update the index of the minimum element
			}
		}

		int temp = nArray[i];
		nArray[i] = nArray[idxMin];
		nArray[idxMin] = temp;
	}

	return nArray;
}


// below implementation requires no return value 
/*
void SelectionSort(int nArray[], int nNumElements)
{
	//.....

}
*/