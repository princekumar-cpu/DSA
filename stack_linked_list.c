#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct stack
{
    char name[MAX];
    int roll_number,marks;
    struct stack *prev;
};

struct stack *top = NULL;
int count = 0;

void push(char name[MAX],int roll_num,int marks)
{
    struct stack *temp = (struct stack*)malloc(sizeof(struct stack));

    if (temp == NULL)
    {
        printf("Memory is not available\n");
    }
    else if (top == NULL)
    {
        strcpy(temp->name, name);
        temp->roll_number = roll_num;
        temp->marks = marks;
        top = temp;
        top->prev = NULL;
        printf("%s is pushed\n", name);
    }
    else
    {
        temp->prev = top;
        strcpy(temp->name, name);
        temp->roll_number = roll_num;
        temp->marks = marks;
        top = temp;
        printf("%s is pushed\n", name);
    }
}
void pop()
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    if (top == NULL)
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        temp = top;
        top = top->prev;
        printf("%s is poped \n", temp->name);
        free(temp);
    }
}
void display()
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    int count= 0;
    if (top == NULL)
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        temp = top;
        printf("________________Record details________________\n\n");
        while (temp  != NULL)
        {
            printf("Record of student %d\n",++count);
            printf("Name\t\t:\t%s\n",temp->name);
            printf("Roll number :\t%d\n",temp->roll_number);
            printf("Marks \t\t:\t%d\n\n",temp->marks);
            temp = temp->prev;
        }
        free(temp);
    }
}

int main()
{
    int ch, t = 0,roll_num,marks;
    char temp[MAX];
    while (t == 0)
    {
        printf("_______________Menu________________\n\n1) Push record\n2) Pop record \n3) Display record\n4) EXIT\n\nEnter your choice.....");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Record of student %d",++count);
            printf("\nEnter the name\t\t:\t");
            scanf("%s",&temp);
            printf("\nEnter the Roll number\t:\t");
            scanf("%d",&roll_num);
            printf("\nEnter the Marks\t\t:\t");
            scanf("%d",&marks);
            push(temp,roll_num,marks);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            t = 1;
            break;
        default:
            printf("Invalid choice!!!!\n");
            break;
        }
    }
    return 0;
}