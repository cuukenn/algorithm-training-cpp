#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayutil.h"
void swap(int *array, int s1, int s2)
{
    int tmp = *(array + s1);
    *(array + s1) = *(array + s2);
    *(array + s2) = tmp;
}
void print(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}
int *get_ramdon_array(int size)
{
    int *num = new int[size]{0};
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        *(num + i) = rand();
    }
    return num;
}