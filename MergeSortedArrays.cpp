#include <iostream>

int main()
{
	int arr1[] = { 1,2,8,10 };
	int arr2[] = { 1,2,4,5,6,7,9 };
	int arr1Size = std::size(arr1);
	int arr2Size = std::size(arr2);
	int totalLen = arr1Size + arr2Size;
	int* mergedArr = new int[totalLen];
	int k = 0, j = 0;

	for (int i = 0; i < totalLen; ++i)
	{
		if (arr1[k] <= arr2[j] && k < arr1Size)
		{
			mergedArr[i] = arr1[k];
			k++;
		}
		else if (j < arr2Size)
		{
			mergedArr[i] = arr2[j];
			j++;
		}
	}
	if (k < arr1Size)
	{
		while (k != arr1Size)
		{
			mergedArr[arr2Size + k] = arr1[k];
			++k;
		}
	}

	for (int i = 0; i < totalLen; ++i)
		std::cout << mergedArr[i] << "	";
	
	return 0;
}