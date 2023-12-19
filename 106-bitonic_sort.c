#include "sort.h"
void swap_ele(int *a, int *b);
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
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
 * bit_merge - Sort bitonic sequence inside array of ints
 * @array: array of ints
 * @size: size of the array
 * @start: starting index of sequence in array
 * @seq: size of the sequence
 * @flow: direction to sort in
 */
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ele(array + i, array + i + jump);
		}
		bit_merge(array, size, start, jump, flow);
		bit_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bit_seq - Convert array of ints into bitonic sequence
 * @array: array of ints
 * @size: size of  array
 * @start: starting index of block of building bitonic sequence
 * @seq: size of block of building bitonic sequence
 * @flow: direction to sort bitonic sequence block in
 */
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t par = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
		bit_seq(array, size, start, par, UP);
		bit_seq(array, size, start + par, par, DOWN);
		bit_merge(array, size, start, seq, flow);
		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort(ascending) array of ints using bitonic sort
 * @array: array of ints
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_seq(array, size, 0, size, UP);
}
