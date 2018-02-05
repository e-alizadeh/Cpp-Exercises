// Fibonacci Sequence Implementation
// 1) Recursive method: Time Complexity of O(2^n)   (where n is number of elements in an array)
// 2) Iterative method: Time Complexity of O(n)   

#include "stdafx.h"
#include <iostream>
using namespace std;


int recursiveFibonacci(const int);
int iterativeFibonacci(const int);


int main()
{
	
	cout << "Enter a value n for Fib(n): ";
	int n;
	cin >> n;

	cout << "--------------------------------------------\n";
	cout << "Fibonacci Sequence using Recursive method:\n";
	cout << "Fib(" << n << ") = " << recursiveFibonacci(n) << endl;

	cout << "--------------------------------------------\n";
	cout << "Fibonacci Sequence using Iterative method:\n";
	cout << "Fib(" << n << ") = " << iterativeFibonacci(n) << endl;

    return 0;
}

int recursiveFibonacci(const int n) {
	if (n <= 1)
		return n;
	else // no need for else
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}


int iterativeFibonacci(const int n) {
	if (n <= 1)
		return n;
	
	int F1 = 0;
	int F2 = 1;
	int F;

	for (int i = 2; i <= n; i++)
	{
		F = F1 + F2;
		F1 = F2;
		F2 = F;
	}

	return F;
}