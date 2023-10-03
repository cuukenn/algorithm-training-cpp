#include "popsort.h"
#include "arrayutil.h"

void PopSort::sort(int *array, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (*(array + i) >= *(array + j))
            {
                continue;
            }
            swap(array, i, j);
        }
    }
}