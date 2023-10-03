#include "qsort.h"
#include "arrayutil.h"
#include <time.h>
#include <random>
static int partition(int *array, int left, int right)
{
    srand(time(0));
    int i = left, j = right, pti = i + rand() % (j - i);
    while (i < j)
    {
        while (i < j && *(array + j) >= *(array + pti))
            j--;
        while (i < j && *(array + i) <= *(array + pti))
            i++;
        swap(array, i, j);
    }
    swap(array, i, pti);
    return i;
}
void qsort(int *array, int left, int right)
{
    // 子数组长度为 1 时终止递归
    if (left >= right)
        return;
    // 哨兵划分
    int pivot = partition(array, left, right);
    // 递归左子数组、右子数组
    qsort(array, left, pivot - 1);
    qsort(array, pivot + 1, right);
}
void QSort::sort(int *array, int len)
{
    qsort(array, 0, len - 1);
}