#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[]) //argc counts args, *argv is an array of pointers aka a STRING input by the user. ./main is 1 string, ./main 1024 is 2 strings (main and 1024).
{
	if(argc != 2)
	{
		printf("Error; enter 2 arguments only! ./main and your desired array size!\n");
		return 1;//return 1/fail.
	}
	int size = atoi(argv[1]); //ASC to integer. converts string into integer value, using string index 1 (technically string 2).
		if(size <= 0)
		{
			printf("Error; enter positive, nonzero integer values only!\n");
			return 1;
		}
	Array *arr = (Array *)malloc(sizeof(Array)); //initial malloc for typedef struct "Array"
	arr->size=size; //field SIZE set to SIZE
	arr->data = (double *)malloc(size * sizeof(double)); //field DATA allocated enough memory for each index/value of SIZE (determined by user at runtime)
	//Casting with type Array using (Array *). Same as a void cast (Void *).
	for(int i = 0; i < arr->size; i++)
	{
		arr->data[i] = (i * 0.0) + (i + 1); //fills every index with a new value. could use any operand here. I'm setting each index equal to 0 and adding 1 per value. 
	}
	
	printf("Primary Array:\n");
	output_array(arr); //array is created. output_array prints it to screen. 
	//shift_array(arr); //calling shift_array on Array. "DEPRECATED. Changed order of function calls because original order was taking adjacent average of SHIFTED array."
	//output_array(arr); //running output again to verify shift.

	Array *avg = avg_adj(arr);//pointer type Array fed to avg_adj function. Avg adj will return it. 
	shift_array(arr);
	printf("Shifted Array:\n");
	output_array(arr);
	printf("Average Adjacent Array:\n");
	output_array(avg); //output array called again to display brand new, half-sized Array. 
	
	free(arr->data); //call frees inside ---> outside so program knows what to free, when. 
	free(arr); //then the pointer to struct Array itself
	free(avg->data); //then the data field within new avg array
	free(avg); //then the new avg array itself

	return 0;
}



