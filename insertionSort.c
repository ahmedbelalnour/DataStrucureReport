/*insertion sort example
*/
#include <stdio.h>
#include <malloc.h>
//function declaration
void InsertionSort(int *arr, int arrSize);

int main(){
	//variable declaration
	int *arr, i, arrSize;
	printf("Enter Array Size: ");
	scanf("%d",&arrSize);
	arr=(int *)malloc(arrSize*sizeof(int));
	if(arr)
	{
		printf("Enter the %d elements of the array:\n",arrSize);
		//input
		for(i = 0; i < arrSize; i++)
		{
			scanf("%d", &arr[i]);
		}
		//sort
		InsertionSort(arr, arrSize);	//passing arr address and no. of elements
		printf("Elements After sorting: ");
		//output
		for(i = 0; i < arrSize; i++)
		{
			printf("%d  ", arr[i]);
		}
	}
	return 0;
}

//function definition
void InsertionSort(int *arr, int arrSize)
{
	int i, j, temp;
	for(i = 1; i <= arrSize-1; i++)
	{
		temp = arr[i];
		j = i-1;
		while(temp < arr[j] && j >= 0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}