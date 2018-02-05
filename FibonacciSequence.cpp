// Fibonacci Sequence Implementation
// 1) _Recursive method_: Time Complexity of O(2^n)   (where n is number of elements in an array)
// 2) _Iterative method_: Time Complexity of O(n)   
// 3) _Recursion with Memoization_: Time Complexity proportional to the max depth of recursion tree
// 3) _Dynamic Programming_

#include "stdafx.h"
#include <iostream>
#include <vector>	// using "static std::vector<int> table" in Memoization

using namespace std;


int recursiveFib(const int);
int iterativeFib(const int);
int recursiveFib_Memo(const int);
int Fib_DynamicProgramming(const int);

int main()
{
	
	cout << "Enter a value n for Fib(n): ";
	int n;
	cin >> n;

	cout << "-----------------------------------------------------\n";
	cout << "Fibonacci Sequence using Recursive method:\n";
	cout << "Fib(" << n << ") = " << recursiveFib(n) << endl;

	cout << "-----------------------------------------------------\n";
	cout << "Fibonacci Sequence using Iterative method:\n";
	cout << "Fib(" << n << ") = " << iterativeFib(n) << endl;


	cout << "-----------------------------------------------------\n";
	cout << "Fibonacci Sequence using Recursion with Memoization:\n";
	cout << "Fib(" << n << ") = " << recursiveFib_Memo(n) << endl;

	cout << "-----------------------------------------------------\n";
	cout << "Fibonacci Sequence using Dynamic Programming:\n";
	cout << "Fib(" << n << ") = " << Fib_DynamicProgramming(n) << endl;

    return 0;
}

int recursiveFib(const int n) {
	if (n <= 1)
		return n;
	else // no need for else
		return recursiveFib(n - 1) + recursiveFib(n - 2);
}


int iterativeFib(const int n) {
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

int recursiveFib_Memo(const int n) {
	static vector<int> FibMemory; // our memory (cache) that is defined using vector data type
	
	if (n <= 1)
	{
		return n;
	}
	else if ( n >= FibMemory.size())
	{
		FibMemory.resize(n + 1);
	}

	if (FibMemory[n] == 0)	// // only calculates the Fibonacci if we don't have a value
	{
		FibMemory[n] = recursiveFib_Memo(n - 1) + recursiveFib_Memo(n - 2);
	}

	return FibMemory[n];
}


int Fib_DynamicProgramming(const int n) {
	if (n <= 1)
	{
		return n;
	}

	static vector<int> table(n+1); 
	table[0] = 0;
	table[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		table[i] = table[i - 1] + table[i - 2];
	}

	return table.back();
}