/*************************************************************************
    > File Name: qsort.c
    > Author: gl
    > Mail: lzs123@911gll.cn
    > Created Time: Tue 11 Sep 2018 07:05:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	int sno;
	float sight;
	float weight; 
	char name[16];
}stu;

int cmp_int(const void *a, const void *b);
int cmp_stu(const void *a, const void *b);
void Qsort(void *a, int n, int size, int (*cmp)(const void *, const void *));
void quick_sort(int n, int *a);
int main()
{
	stu s[5] = {
				1009, 5.2, 79.5, "李一", 	
				1003, 4.4, 72.9, "李二", 
				1002, 4.7, 38.1, "李三", 
				1004, 3.5, 77.2, "李四", 
				1007, 5.6, 57.3, "李五" 
				};

	Qsort(s, 5, sizeof(stu), cmp_stu);

	int i = 0;

	for(i = 0; i < 5; i++)
	  printf("%d %.2f, %.2f, %s\n", s[i].sno, s[i].sight, s[i].weight, s[i].name);

	int a[5] = {1, 34, 445 ,676 ,5};

	Qsort(a, 5, sizeof(a[1]), cmp_int);

	for(i = 0; i < 5; i++)
	  printf("%d ", a[i]);

	printf("\n");

	return 0;
}

//递归实现普通快排
void quick_sort(int n, int *a)
{
	int i = 0, j = n - 1;
	int temp = a[0];

	if(n < 2) return;

	while(i != j)
	{
		while(i != j && a[j] <= temp) j--;
		a[i] = a[j];

		while(i != j && a[i] >= temp) i++;
		a[j] = a[i];
	}
	a[i] = temp;
	
	quick_sort(i, a);
	quick_sort(n - i - 1, a + i + 1);
}

//回调实现快排
void Qsort(void *a, int n, int size, int(*cmp)(const void *, const void *))
{
	void *temp = (void *)malloc(size);
	int i = 0, j = n - 1;
	memcpy(temp, a + 0 * size, size);

	if(n < 2) return;

	while(i != j)
	{
		while(i != j && cmp(a + j * size, temp) >= 0) j--;
			memcpy(a + i * size, a + j * size, size);

		while(i != j && cmp(a + i * size, temp) <= 0) i++;
			memcpy(a + j * size, a + i * size, size);
	}

	memcpy(a + i * size, temp, size);

	Qsort(a, i, size, cmp);
	Qsort(a + (i + 1) * size, n - i - 1, size, cmp);
	
	free(tmp);
}

int cmp_stu(const void *a, const void *b)
{
	stu s1 = *((stu *)a);
	stu s2 = *((stu *)b);

	if((s1.sno) > (s2.sno)) return 1;
	if((s1.sno) < (s2.sno)) return -1;
	if((s1.sno) == (s2.sno)) return 0;
}

int cmp_int(const void *a, const void *b)
{
	return (*(int *)a) - (*(int *)b);
}
