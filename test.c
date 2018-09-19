/*************************************************************************
	> File Name: 9_6.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Sep 2018 08:22:53 AM CST
 ************************************************************************/

#include <stdio.h>
#include "SORT.h"

int cmp(const void *a, const void *b)
{
	return (*(int *)a) - (*(int *)b);
}


int main()
{
    int a[10] = {2, 34, 54, 5455, 312, 4, 66, 44, 33, 22};

    int i, s;
    scanf("%d", &s);

    switch(s)
    {
        case 1:bubble_sort(10, a);
            break;

        case 2:select_sort(10, a);
            break;

        case 3:insert_sort(10, a);
            break;

        case 4:quick_sort(10, a);
			break;
		case 5:Qsort(a, 10, sizeof(a[1]), cmp);
			break;
    }

    for(i = 0; i < 10; i++)
    printf("%d ", a[i]);

    return 0;
}
