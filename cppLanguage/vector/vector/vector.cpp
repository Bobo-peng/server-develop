// vector.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
void vector_test()
{
	std::vector<int> arr(10,1);
	std::cout << "arr(10,1):size=" << arr.size() << "; capacity=" << arr.capacity() << std::endl;
	arr.push_back(5);
	std::cout << "arr.push_back(11):size=" << arr.size() << "; capacity=" << arr.capacity() << std::endl;
	//arr.clear();
	//std::cout << "arr.clear():size=" << arr.size() << "; capacity=" << arr.capacity() << std::endl;
	arr.resize(16);
	std::cout << "arr.resize(0):size=" << arr.size() << "; capacity=" << arr.capacity() << std::endl;
	arr.reserve(50);
	std::cout << "arr.reserve(0):size=" << arr.size() << "; capacity=" << arr.capacity() << std::endl;
	//std::vector<int> arr1 = std::vector<int>(arr);
	//arr1.swap(arr);
	std::vector<int>(arr).swap(arr);
	//std::cout << "std::vector<int> arr1 = std::vector<int>(arr),arr1:size=" << arr1.size() << "; capacity=" << arr1.capacity() << std::endl;
	std::cout << "vector<int>(arr).swap(arr):size=" << arr.size() << "; capacity=" << arr.capacity() << std::endl;
}
void Test()
{
	vector_test();
}
int main()
{
	Test();
	getchar();
    return 0;
}

