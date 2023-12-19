#include "sort.h"
void swap_ele(int *a, int *b);
int hoare_part(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
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
 * hoare_part - Order subset of array according to hoare partition scheme
 * @array: array of ints
 * @size: size of array
 * @left: starting index of subset to order
 * @right: ending index of subset to order
 * Return: final partition index
 */
int hoare_part(int *array, size_t size, int left, int right)
{
	int pivot, up, down;

	pivot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_ele(array + up, array + down);
			print_array(array, size);
		}
	}
	return (up);
}

/**
 * hoare_sort - Implement quicksort algorithm through recursion
 * @array: array of ints
 * @size: size of array
 * @left: starting index of array partition to order
 * @right: ending index of array partition to order
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int mid;

	if (right - left > 0)
	{
		mid = hoare_part(array, size, left, right);
		hoare_sort(array, size, left, mid - 1);
		hoare_sort(array, size, mid, right);
	}
}

/**
 * quick_sort_hoare - Sort(ascending) an array of ints using quicksort
 * @array: array of ints
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
