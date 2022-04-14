#include <stdio.h>





void Radixsort(int a[], int n)
{
    int bucket[10][5], buck[10];
    int div,num,large,i,j,pass,k,l;
    div = 1;
    num = 0;
    large = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > large)
            large = a[i];
    }
    while (large > 0)
    {
        num = num + 1;
        large = large / 10;
    }
    for (pass = 0; pass < num; pass++)
    {
        for (k = 0; k < 10; k++)
            buck[k] = 0;
        for (i = 0; i < n; i++)
        {
            l = (a[i] / div) % 10;
            bucket[l][buck[l]++] = a[i];
        }
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < buck[k]; j++)
                a[i++] = bucket[k][j];
        }
        div = div * 10;
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
    Radixsort(a, n);
    printf("\n_______________after sorting______________\n");
    display(a, n);
    return 0;
}
