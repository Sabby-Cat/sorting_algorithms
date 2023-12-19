#include "sort.h"
void merge_subarr(int *part, int *buff, size_t front, size_t mid,
		size_t back);
void merge_rec(int *part, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
/**
 * merge_subarr - Sort subarray of ints
 * @part: subarray of array of ints
 * @buff: buffer to store sorted subarray
 * @front: front index of array
 * @mid: middle index of array
 * @back: back index of array
 */
void merge_subarr(int *part, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(part + front, mid - front);
	printf("[right]: ");
	print_array(part + mid, back - mid);
	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (part[i] < part[j]) ? part[i++] : part[j++];
	for (; i < mid; i++)
		buff[k++] = part[i];
	for (; j < back; j++)
		buff[k++] = part[j];
	for (i = front, k = 0; i < back; i++)
		part[i] = buff[k++];
	printf("[Done]: ");
	print_array(part + front, back - front);
}

/**
 * merge_rec - Implement merge sort through recursion
 * @part: subarray of array of ints
 * @buff: buffer to store sorted result
 * @front: front index of subarray
 * @back: back index of subarray
 */
void merge_rec(int *part, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_rec(part, buff, front, mid);
		merge_rec(part, buff, mid, back);
		merge_subarr(part, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort(ascending) array of ints using the merge sort
 * @array: array of ints
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	merge_rec(array, buff, 0, size);
	free(buff);
}
