#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void output_array(Array *arr)
{
	printf("Array size: %d\n", arr->size);
	for(int i = 0; i < arr->size; i++)
	{
		printf("[%.3f]", arr->data[i]);
	}
	printf("\n");
	//catches trailing line. arr->size points to the size field in our custom struct for loop count. 
}
void shift_array(Array *arr)
{
	double fIndex = arr->data[0];//copies FIRST index value for final swap.
	for(int i = 0; i < arr->size-1; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	arr->data[arr->size - 1] = fIndex;//arr->points to data, [arr->size - 1] determines WHERE in data to look.
	//have to use arr->size - 1 because otherwise [i + 1] goes out of bounds of array. This is why we need fIndex to save first index value and copy it to the last index the loop can't iterate on. 
}
Array *avg_adj(Array *arr)
{
	Array *newArray = (Array *)malloc(sizeof(Array));
	newArray->size = arr->size/2;//integer division truncates and drops the last index anyway. 
	newArray->data = (double *)malloc(newArray->size * sizeof(double));

	for(int i = 0; i < newArray->size; i++)
	{
		newArray->data[i] = (arr->data[2 * i] + arr->data[2 * i + 1])/2.0;//ensures double/floating point division. pointer arrithmetic like on whiteboard. 
	}
	return newArray;
}

