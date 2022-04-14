#include <stdio.h>

void insertionsort(int a[],int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void display(int a[10], int n)
{
    printf("Elements are ....... \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
int main()
{
    int a[10], n;
    printf("How many number you want to enter :     \n");
    scanf("%d", &n);
    printf("Enter the number \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n_______________Before sorting______________\n");
    display(a, n);
    insertionsort(a, n);
    printf("\n_______________after sorting______________\n");
    display(a, n);
    return 0;
}