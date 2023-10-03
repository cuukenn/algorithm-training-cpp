#include "selectsort.h"
#include "arrayutil.h"

void SelectSort::sort(int *array, int len)
{
    int n = len;
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(array + j) < *(array + k))
            {
                k = j;
            }
        }
        swap(array, i, k);
    }
}