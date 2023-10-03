#include <stdio.h>
#include <string>
#include "arrayutil.h"
#include <time.h>
#include <math.h>
#include "qsort.h"
#include "popsort.h"
#include "insertsort.h"
#include "selectsort.h"
using namespace std;
struct isort_item
{
    void *sort;
    string name;
};

static void srun(ISort *sort)
{
    int size = 10;
    int *num = get_ramdon_array(size);
    printf("raw array   : ");
    print(num, size);
    clock_t startTimestamp = clock();
    sort->sort(num, size);
    clock_t endTimestamp = clock();
    printf("sorted array in(%dms): ", endTimestamp - startTimestamp);
    print(num, size);
}
static void mrun()
{
    const int ISORT_SIZE = 4;
    isort_item *isorts = new isort_item[ISORT_SIZE]{
        {new PopSort, "Pop Sort"},
        {new SelectSort, "Select Sort"},
        {new InsertSort, "Inster Sort"},
        {new QSort(), "Quick Sort"},
    };
    int **copied_arrays = new int *[ISORT_SIZE];
    const int ARRAY_SIZE = pow(10, 5);
    printf("preparing data...\n");
    int *array = get_ramdon_array(ARRAY_SIZE);
    for (int i = 0; i < ISORT_SIZE; i++)
    {
        *(copied_arrays + i) = new int[ARRAY_SIZE];
        memcpy(*(copied_arrays + i), array, ARRAY_SIZE * sizeof(int));
    }
    printf("starting sort...\n");
    for (int i = 0; i < ISORT_SIZE; i++)
    {
        isort_item *item = isorts + i;
        if (item != NULL)
        {
            ISort *sort = (ISort *)(item->sort);
            int *copied_array = *(copied_arrays + i);
            clock_t startTimestamp = clock();
            sort->sort(copied_array, ARRAY_SIZE);
            clock_t endTimestamp = clock();
            printf("sorted array in (%s, %dms): \n", item->name.c_str(), endTimestamp - startTimestamp);
        }
    }
    printf("end sort\n");
}

int main(int argc, char *argv[])
{
    // mrun();
    srun(new QSort);
    return 0;
}