// Bubble Sort Algorithm
// Time Complexity: O(n^2)   (where n is number of elements in an array)


#include <iostream>
using namespace std;

int *BubbleSort(int nArray[], size_t nNumElements); // Function Prototype 

void BubbleSort_efficient(int nArray[], size_t nNumElements); // Function Prototype 

int main()
{
	int nArray[] = { 1, 4, 2, 6, 8, 3, 2 };

	size_t nNumElements = sizeof(nArray) / sizeof(nArray[0]);

	cout << "Bubble Sort: BEFORE\n";
	cout << "----------------------- \n";
	for (unsigned int i = 0; i < nNumElements; i++)
	{
		cout << nArray[i] << "  ";
	}
	cout << endl;



	int *pnArray_sorted = BubbleSort(nArray, nNumElements);

	cout << "----------------------- \n";
	cout << "Bubble Sort: AFTER\n";
	cout << "----------------------- \n";
	for (unsigned int i = 0; i < nNumElements; i++)
	{
		cout << *pnArray_sorted << "  ";
		pnArray_sorted++;	
	}
	cout << endl;


	BubbleSort_efficient(nArray, nNumElements);

	cout << "----------------------------------------- \n";
	cout << "Bubble Sort (Efficient version): AFTER\n";
	cout << "----------------------------------------- \n";
	for (unsigned int i = 0; i < nNumElements; i++)
	{
		cout << nArray[i] << "  ";
	}
	cout << endl;


    return 0;
}




int *BubbleSort(int nArray[], const size_t nNumElements)
{
	for (int i = 0; i < nNumElements; i++)
	{
		for (int j = 0; j < nNumElements - 1; j++)
		{
			if (nArray[j] > nArray[j+1])  // A[j] > A[j+1]
			{
				int temp = nArray[j]; // temp = A[j]
				nArray[j] = nArray[j+1]; // A[j] = A[j+1]
				nArray[j+1] = temp;  // A[j+1] = temp
			}
		}
	}
	return nArray;
}


// For a practice, the function return type is void !!!
void BubbleSort_efficient(int nArray[], const size_t nNumElements)
{
	for (int i = 0; i < nNumElements; i++)
	{
		bool flag = 0; // new line
		for (int j = 0; j < nNumElements - i - 1; j++)  // modified line
		{
			if (nArray[j] > nArray[j + 1])  // A[j] > A[j+1]
			{
				int temp = nArray[j]; // temp = A[j]
				nArray[j] = nArray[j + 1]; // A[j] = A[j+1]
				nArray[j + 1] = temp;  // A[j+1] = temp

				bool flag = 1; // new line
			}
		}
		if(flag == 0) // if there is No swapping
		{
			break;
		}
	}
}
