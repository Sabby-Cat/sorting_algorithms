#include "sort.h"
void swap_ele(int *a, int *b);
void make_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
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
 * make_heap - Turn binary tree into complete binary heap
 * @array: array of ints repr a binary tree
 * @size: size of array/tree
 * @base: index of base row of tree
 * @root: root node of binary tree
 */
void make_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t pre, nex, big;

	pre = 2 * root + 1;
	nex = 2 * root + 2;
	big = root;
	if (pre < base && array[pre] > array[big])
		big = pre;
	if (nex < base && array[nex] > array[big])
		big = nex;
	if (big != root)
	{
		swap_ele(array + root, array + big);
		print_array(array, size);
		make_heap(array, size, base, big);
	}
}

/**
 * heap_sort - Sort(Ascending) an array of ints using heap sort
 * @array: array of ints
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		make_heap(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap_ele(array, array + i);
		print_array(array, size);
		make_heap(array, size, i, 0); 
	}
}
