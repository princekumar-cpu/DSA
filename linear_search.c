#include<stdio.h>

int linear_search(int a[20],int n,int key){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (a[i]== key)
        {
            printf("%d is present at %d position in the list \n",key,i+1);
            return 0;
        }
    }
    printf("Sorry %d is not in the list \n",key);
}

int main()
{
    int a[20], n,key;
    printf("How many number you want to enter :     \n");
    scanf("%d", &n);
    printf("Enter the number \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the element your want to search : ");
    scanf("%d",&key);
    linear_search(a,n,key);
    return 0;
}