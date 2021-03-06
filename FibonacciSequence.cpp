// Fibonacci Sequence Implementation
// 1)  Recursive method : Time Complexity of O(2^n)   &   Space Complexity of O(n) (function call stack size)
// 2.a) Dynamic Programming (iterative): Time Complexity of O(n)    &   Space Complexity of O(n) 
// 2.b) Dynamic Programming (Space Optimized): Time Complexity of O(n)    &   Space Complexity of O(1)   
// 3)  Recursion with Memoization_: Time Complexity proportional to the max depth of recursion tree


#include "stdafx.h"
#include <iostream>
#include <vector>	// using "static std::vector<int> table" in Memoization

using namespace std;


int recursiveFib(const int);
int iterativeFib(const int);	// This actually uses Dynamic Programming
int iterativeFib_SpaceOptimized(const int);	// This actually uses Dynamic Programming
int recursiveFib_Memo(const int);
//int Fib_DynamicProgramming_vector(const int);

int main()
{
	
	cout << "Enter a value n for Fib(n): ";
	int n;
	cin >> n;

	cout << "-----------------------------------------------------------------------------------\n";
	cout << "Fibonacci Sequence using Recursive method:\n";
	cout << "Fib(" << n << ") = " << recursiveFib(n) << endl << endl;

	cout << "-----------------------------------------------------------------------------------\n";
	cout << "Fibonacci Sequence using Dynamic Programming (Iterative method):\n";
	cout << "Fib(" << n << ") = " << iterativeFib_SpaceOptimized(n) << endl << endl;


	cout << "-----------------------------------------------------------------------------------\n";
	cout << "Fibonacci Sequence using Dynamic Programming (Space Optimized) (Iterative method):\n";
	cout << "Fib(" << n << ") = " << iterativeFib_SpaceOptimized(n) << endl << endl;


	cout << "-----------------------------------------------------------------------------------\n";
	cout << "Fibonacci Sequence using Recursion with Memoization:\n";
	cout << "Fib(" << n << ") = " << recursiveFib_Memo(n) << endl << endl;

	//cout << "-----------------------------------------------------\n";
	//cout << "Fibonacci Sequence using Dynamic Programming:\n";
	//cout << "Fib(" << n << ") = " << Fib_DynamicProgramming_vector(n) << endl;

    return 0;
}



int recursiveFib(const int n) {
	if (n <= 1)
		return n;
	else // no need for else
		return recursiveFib(n - 1) + recursiveFib(n - 2);
}



int iterativeFib(const int n) { // using vector data type
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



int iterativeFib_SpaceOptimized(const int n) {
	if (n <= 1)
		return n;
	
	int Fib;
	int F1 = 0;
	int F2 = 1;


	for (int i = 2; i <= n; i++)
	{
		Fib = F1 + F2;
		F1 = F2;
		F2 = Fib;
	}

	return Fib;
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


