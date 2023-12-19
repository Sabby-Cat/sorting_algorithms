#include "sort.h"
/**
 * swap_ele - Swap two integers in array
 * @a: first int
 * @b: second int
 */
void swap_ele(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort array of ints in ascending order using shell sort 
 * @array: array of ints
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ele(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
