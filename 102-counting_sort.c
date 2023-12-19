#include "sort.h"
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
 * counting_sort - Sort(ascending) array of ints using counting sort
 * @array: array of ints
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sto, max, i;

	if (array == NULL || size < 2)
		return;
	sto = malloc(sizeof(int) * size);
	if (sto == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sto);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sto[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sto[i];
	free(sto);
	free(count);
}
