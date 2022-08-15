#include "sort.h"

/*
 * shell_sort - this function uses the Knuth sequence algorithm scheme to sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t i, j, num, gap = 1;

    while (gap <= (size - 1) / 3)
        gap = 3 * gap + 1;

    while (gap >= 1)
    {
        for (i = gap; i < size; i++)
        {
            num = array[i];
            for (j = i - gap; (int)j >= 0 && (int)num < array[j]; j = j - gap)
                array[j + gap] = array[j];
            array[j + gap] = (int)num;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}