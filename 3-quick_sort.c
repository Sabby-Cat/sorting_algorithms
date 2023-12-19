#include "sort.h"
void swap_ele(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_part - Orders ubset of int array according to lomuto partition scheme
 * (last element as pivot).
 * @array: array to sort
 * @size: size the array
 * @left: starting to order
 * @right: ending index to order
 * Return: final partition index
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ele(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		swap_ele(array + up, pivot);
		print_array(array, size);
	}
	return (up);
}

/**
 * lomuto_sort - sort using quicksort
 * @array: array to be sorted
 * @size: size of array
 * @left: starting index to order
 * @right: ending index to order
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort array using quicksort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
