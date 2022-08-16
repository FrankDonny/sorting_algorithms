#include "sort.h"

/**
 * max_num - function to find th bmaxmum number
 * @array: the array to find the number
 * @size: size of the array
 * Return: the max number
 */
int max_num(int *array, size_t size)
{
	int max = 0;
	int i;

	for (i = 0; i < (int)size - 1; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - an algorithm that uses count sort to sort data
 * @array: the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = max_num(array, size);
	int *count = malloc(sizeof(int) * max);
	int *new_array = malloc(sizeof(int) * size);

	if (size < 2)
		return;
	if (count == NULL)
	{
		free(count);
		return;
	}
	if (new_array == NULL)
	{
		free(new_array);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
		new_array[count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];

	print_array(count, max + 1);
	free(count);
	free(new_array);
}
