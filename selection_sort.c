#include <stdio.h>

void Selectionsort(int a[], int n)
{
    int i, pos, j, large;
    for (i = n - 1; i > 0; i--)
    {
        large = a[0];
        pos = 0;
        for (j = 1; j <= i; j++)
        {
            if (a[j] > large)
            {
                large = a[j];
                pos = j;
            }
        }
        a[pos] = a[i];
        a[i] = large;
    }
}

void display(int a[10],int n){
    printf("Elements are ....... \n");
    for(int i = 0; i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int a[10],n;
    printf("How many number you want to enter :     \n");
    scanf("%d",&n);
    printf("Enter the number \n");
    for(int i = 0; i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n_______________Before sorting______________\n");
    display(a,n);
    Selectionsort(a,n);
    printf("\n_______________after sorting______________\n");
    display(a,n);
    return 0;
}
