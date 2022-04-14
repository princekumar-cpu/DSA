#include<stdio.h>

int binary_search(int a[20],int n,int key,int lb,int ub){
    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub)/2;
        if (a[mid] == key)
        {
            printf("%d is present at %d position in the list \n",key,mid+1);
            return 0;
        }
        else if(a[mid] < key ){
            lb = mid + 1;
        }
        else{
            ub = mid - 1;
        }
    }
    printf("Sorry %d is not in the list \n",key);
}

int main(){
    int n,key,a[20];
    printf("How many number you want to enter :     \n");
    scanf("%d", &n);
    printf("Enter the number \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the element your want to search : ");
    scanf("%d",&key);
    binary_search(a,n,key,0,n-1);
    return 0;
}

