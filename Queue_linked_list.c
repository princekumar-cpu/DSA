#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct queue
{
    char name[MAX];
    int roll_number,marks;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;
int count = 0;

void enqueue(char name[MAX],int roll_num,int marks){
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    if(temp == NULL){
        printf("Memory creation error");
    }
    else{
        strcpy(temp->name,name);
        temp->roll_number = roll_num;
        temp->marks = marks;
        temp->next = NULL;

        if(front == NULL){
            front = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }

}

void dequeue(){
    struct queue *temp = (struct queue*)malloc(sizeof(struct queue));
    if(front == NULL){
        printf("Queue is empty");
    }
    else{
        temp = front;
        if(rear == temp){
            front = NULL;
            rear = NULL;
            printf("%s is dequeued\n",temp->name);
            free(temp);
        }
        else{
            front = front->next;
            printf("%s is dequeued\n",temp->name);
            free(temp);
        }

    }
}

void display()
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    int count= 0;
    if (front == NULL)
    {
        printf("Queue is Empty\n\n");
    }
    else
    {
        temp = front;
        printf("________________Record details________________\n\n");
        while (temp  != NULL)
        {
            printf("Record of student %d\n",++count);
            printf("Name\t\t:\t%s\n",temp->name);
            printf("Roll number\t:\t%d\n",temp->roll_number);
            printf("Marks\t\t:\t%d\n\n",temp->marks);
            temp = temp->next;
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
        printf("_______________Menu________________\n\n1) Enqueue record\n2) Dequeue record \n3) Display record\n4) EXIT\n\nEnter your choice.....");
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
            enqueue(temp,roll_num,marks);
            break;
        case 2:
            dequeue();
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