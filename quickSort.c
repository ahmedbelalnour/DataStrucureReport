// QuickSort.c
#include <stdio.h>
#include <malloc.h>

void QuickSort( int *arr, int beg, int end);
int Partition( int *arr, int beg, int end);


void main() 
{
	//variable declaration
	int *arr, i, arrSize;
	printf("Enter Array Size: ");
	scanf("%d",&arrSize);
	arr=(int *)malloc(arrSize*sizeof(int));
	//input
	if(arr)
	{
		printf("Enter the %d elements of the array:\n",arrSize);
		for(i = 0; i < arrSize; i++)
			scanf("%d", &arr[i]);
		//sort
		QuickSort(arr,0 ,arrSize-1);	//passing arr address and no. of elements
		printf("Elements After sorting: ");
		//output
		for(i = 0; i < arrSize; i++)
			printf("%d  ", arr[i]);
	}
}



void QuickSort( int *arr, int beg, int end)
{
   int pivot;

   if( beg < end ) 
   {
   	// divide and conquer
       pivot = Partition( arr, beg, end);
       QuickSort( arr, beg, pivot-1);
       QuickSort( arr, pivot+1, end);
   }
	
}



int Partition( int *arr, int beg, int end) 
{
   int pivot, i, j, temp;
   pivot = arr[beg];
   i = beg; j = end+1;
		
   while( 1)
   {
		do
		{
			++i;
		}while( arr[i] <= pivot && i <= end );
		
		do
		{
			--j;
		}while( arr[j] > pivot );
		
		if( i >= j )
		{
			break;
		}
		temp = arr[i]; 
		arr[i] = arr[j]; 
		arr[j] = temp;
   }
   temp = arr[beg]; 
   arr[beg] = arr[j]; 
   arr[j] = temp;
   return j;
}