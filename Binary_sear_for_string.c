#include<stdio.h>
#include<string.h>
int binary_search(char ch[10][20],int n,char key[20],int lb,int ub){
    int mid;
    int count = 0;
    while (lb <= ub)
    {
        mid = (lb + ub)/2;
        if (strcmp(ch[mid],key) ==0)
        {
            printf("%s is present at %d position in the list \n",key,mid+1);
            printf("Number of iteration %d \n",count);
            return 0;
        }
        else if(strcmp(ch[mid], key) > 0 ){
            ub = mid - 1;
        }
        else{
            lb = mid + 1;
        }
        count = count + 1;
    }
    printf("Number of iteration %d and ",count);
    printf("%s is not in the list \n",key);
}

int main(){
    int n;
    char ch[10][20],key[20];
    printf("How many string you want to enter :     ");
    scanf("%d", &n);
    printf("\nEnter the strings \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s",ch[i]);
    }
    printf("\nEnter the element your want to search : ");
    scanf("%s",key);
    binary_search(ch,n,key,0,n-1);
    return 0;
}
