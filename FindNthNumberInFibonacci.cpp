﻿#include <iostream>
#include <chrono>
#include <unordered_map>

long FindNthNumberinFibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return FindNthNumberinFibonacci(n - 1) + FindNthNumberinFibonacci(n - 2);
}
std::unordered_map<int, long> numberFibonacciMap;
long FindNthNumberinFibonacciMemoized(int n)
{
	if (numberFibonacciMap.end() != numberFibonacciMap.find(n))
		return numberFibonacciMap[n];
	if (n == 1 || n == 2)
		return 1;
	else
	{
		long fiboNumber = FindNthNumberinFibonacciMemoized(n - 1) + FindNthNumberinFibonacciMemoized(n - 2);
		numberFibonacciMap[n] = fiboNumber;
		return fiboNumber;
	}		
}

long FindNthNumberinFibonacciWithoutRecursion(int n)
{
	long *fibonacci = new long[n];
	fibonacci[0] = 1;
	fibonacci[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	return fibonacci[n - 1];
}

int main()
{
	auto start = std::chrono::steady_clock::now();
	long num = FindNthNumberinFibonacci(40);		//3415985489 ns
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
	
	start = std::chrono::steady_clock::now();
	num = FindNthNumberinFibonacciMemoized(40);		//685220 ns
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	start = std::chrono::steady_clock::now();
	num = FindNthNumberinFibonacciWithoutRecursion(40);	//2188 ns	
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	return 0;
}
