#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void merge(int *A, int *B, int left, int mid, int right);
void sort(int *array, int low, int high);
void merge_sort(int *array, size_t size);
int *malloc_array(int size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void heapify(int *array, int sub_array_size, size_t size, int i);
void split(int *A, int *B, int left, int right);
void print_subarray(int *arr, int start, int end);
void radix_sort(int *array, size_t size);
int get_digit(int digit, int num);
int digit_bubble_sort(int *array, size_t size, int digit);

#endif
