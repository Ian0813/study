

	#include<stdio.h>
	

	void QuickSort(int *array, int start, int end);


	int main()
	{
		int i, j, array[100], num;

		printf("Enter Number of Elments in Array\n");
		scanf("%d", &num);

		printf("Enter elements of Array\n");
		for(i = 0; i < num; i++)
			scanf("%d", &array[i]);
		QuickSort(array, 0, num - 1);
		printf("Array after Sorting\n");
		for(i = 0; i < num; i++)
			printf("%d ", array[i]);
		printf("\n");	
	}

	void QuickSort(int *array, int start, int end)
	{
		int index = start, pivot = array[end], temp, i; // taking the last number in array as pivot
		if(start < end)
		{
			for(i = start; i < end; i++)
			{
				if(array[i] <= pivot)
				{
					temp = array[i];
					array[i] = array[index];
					array[index] = temp;
					index++;
				}
			}
			temp = array[index];
			array[index] = array[end];
			array[end] = temp;
			QuickSort(array, start, index-1);
			QuickSort(array, index+1, end);
		}
	}
