#ifndef ARRAY_H
#define ARRAY_H

struct _my_array
{
	int size;
	double *data;
};
typedef struct _my_array Array;

void output_array(Array *arr);
void shift_array(Array *arr);
Array *average_adjacent(Array *arr);
//function prototypes. ouput and shift are void because they return nothing.everything is done with pointers. average_adjacent builds an entirely new array struct with updated values.


#endif
