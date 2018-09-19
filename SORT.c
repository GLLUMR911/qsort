/*************************************************************************
	> File Name: SORT.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Sep 2018 08:22:53 AM CST
 ************************************************************************/

#include <string.h>
#include <stdlib.h>

void bubble_sort(int n, int *a)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void select_sort(int n, int *a)
{
    int i, j, temp, min;
    
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }

        if(i != min)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

void insert_sort(int n, int *a)
{
    int i, j, temp;

    for(i = 1; i < n; i++)
    {
        temp = a[i];
        for(j = i; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        
        a[j] = temp;
    }
}

void quick_sort(int n, int *a)
{
    int i = 0, j = n - 1, k = a[0];

    if(n < 2)  return;

    while(i != j)
    {
        while(i != j && a[j] >= k) j--;
        a[i] = a[j];

        while(i != j && a[i] <=k) i++;
        a[j] = a[i];
    }

    a[i] = k;

    quick_sort(i, a);
    quick_sort(n - i - 1, a + i + 1);

}

void Qsort(void *a, int n, int size, int(*cmp)(const void *, const void*))
{
	int i = 0, j = n - 1;
	void *k = (void *)malloc(size);
	
	memcpy(k, a + 0 * size, size);
	
	if(n < 2) return;

	while(i != j)
	{
		while(i != j && cmp(a + j * size, k) >= 0) j--;
		memcpy(a + i * size, a + j * size, size);
		
		while(i != j && cmp(a + i * size, k) <= 0) i++;
		memcpy(a + j * size, a + i * size, size);
	}

	memcpy(a + i * size, k, size);

	Qsort(a, i, size, cmp);
	Qsort(a + (i + 1)* size, n - i - 1, size, cmp);
	
	free(k);
}



