#include "sort.h"
int get_max(int *array, int size);
void radix_count(int *array, size_t size, int dig, int *buff);
void radix_sort(int *array, size_t size);
/**
 * get_max - Get maximum value in array of ints
 * @array: array of ints
 * @size: size of array
 * Return: maximum int in array
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_count - Sort(ascend) significant digits of array using counting sort
 * @array: array of ints
 * @size: size of array
 * @dig: significant digit to sort on
 * @buff: buffer to store sorted array
 */
void radix_count(int *array, size_t size, int dig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / dig) % 10] += 1;
	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / dig) % 10] - 1] = array[i];
		count[(array[i] / dig) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort(ascending) array of ints using the radix sort
 * @array: array of ints
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, dig, *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	max = get_max(array, size);
	for (dig = 1; max / dig > 0; dig *= 10)
	{
		radix_count(array, size, dig, buff);
		print_array(array, size);
	}
	free(buff);
}
