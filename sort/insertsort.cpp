#include "insertsort.h"
#include "arrayutil.h"

void InsertSort::sort(int *array, int len)
{
    for (int i = 1; i < len; i++)
    {
        int ni = *(array + i);
        for (int j = i - 1; j >= 0; j--)
        {
            if (ni >= *(array + j))
            {
                break;
            }
            swap(array, i, j);
        }
    }
}