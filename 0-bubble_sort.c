#include "sort.h"
/**
 * bubble_sort - sort a list with bubble sort
 * @array: array to sort
 * @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool check = false;
    int tmp;

	if (!array || size < 2)
		return;
	while (check == false)
	{
		check = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
                array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				check = false;
			}
		}
		len--;
	}
}
