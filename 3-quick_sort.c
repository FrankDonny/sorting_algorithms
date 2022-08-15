#include "sort.h"

/*
 * swap - this function swaps the elements
 * @a: first element
 * @b: second element
 */
void swap(int *array, int *a, int *b, int size)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    print_array(array, size);
}

/*
 * partition_array - this function partitions the array into
 * sub-arrays
 * @array: the array to be partitioned
 * @low_idx: the lower-bound index/end
 * @high_idx: the upper-bound index/start
 * Return: the end
 */
int partition_array(int *array, int low_idx, int high_idx)
{
    int pivot = array[low_idx];
    int start = low_idx;
    int end = high_idx;

    while (start < end)
    {
        while (array[start] <= pivot)
            start++;

        while (array[end] > pivot)
            end--;

        if (start < end)
        {
            swap(array, &array[start], &array[end], high_idx + 1);
        }
    }
    swap(array, &array[low_idx], &array[end], high_idx + 1);
    return end;
}

/*
 * sorting - this function sorts the array
 * @lowIdx: the lower-bound index/end
 * @highIdx: the upper-bound index/start
 */
void sorting(int *array, int lowIdx, int highIdx)
{
    int loc;

    if (lowIdx < highIdx)
    {
        loc = partition_array(array, lowIdx, highIdx);
        sorting(array, lowIdx, loc - 1);
        sorting(array, loc + 1, highIdx);
    }
}

/*
 * quick_sort - this function calls the sorting function
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
    sorting(array, 0, (int)size - 1);
}
