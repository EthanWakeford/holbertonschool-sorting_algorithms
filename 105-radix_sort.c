#include "sort.h"

/**
 * radix_sort - sorts with radix sort
 *
 * @array: array to sort
 * @size: size of array to sort
*/

void radix_sort(int *array, size_t size)
{
	int digit = 10, sorting = 1;

	if (size == 1)
		return;

	while (1)
	{
		sorting = digit_bubble_sort(array, size, digit);
		if (!sorting)
			break;
		print_array(array, size);
		digit *= 10;
	}
}

/**
 * get_digit - returns specified digit of number
 *
 * @digit: digit to grab(in powers of 10) times 10, eg digit == 10 ->
 * grab digit at ones place
 * @num: number to get digit from
 * Return: the number at the digit
*/

int get_digit(int digit, int num)
{
	int sub_digit = digit / 10;

/* return -1 if num does not contain targeted digit*/
	if (num / (digit / 10) == 0)
		return (-1);
	num = num % digit;
	if (sub_digit > 1)
		num = num / sub_digit;
	return (num);
}

/**
 * digit_bubble_sort - uses bubble sort to sort array based on specified digit
 *
 * @array: array to sort
 * @size: size of array
 * @digit: digit to sort based on
 *
 * Return: 1 on successful sort, 0 if no more sorting needs to occur
*/

int digit_bubble_sort(int *array, size_t size, int digit)
{
	int i, tmp, length = (int)size, status = 0, unsorted = 1;

	for (i = 0; i < length; i++)
	{
		/*searches for if any number large enough for current digit check*/
		if (get_digit(digit, array[i]) >= 0)
		{
			status = 1;
			break;
		}
	}
	if (!status)
		return (status);

	while (unsorted)
	{
		unsorted = 0;
		for (i = 0; i + 1 < length; i++)
		{
			if (get_digit(digit, array[i]) > get_digit(digit, array[i + 1]))
			{
				unsorted = 1;
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}
		length--;
	}
	return (status);
}
