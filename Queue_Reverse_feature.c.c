#include <stdio.h>
#define MAX 20
int queue[MAX], front = -1, rear = -1;
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (front == (rear + 1) % MAX)
        return 1;
    else
        return 0;
}
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue is Full !!!!!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("%d is inserted\n", item);
    }
}
void dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is Empty !!!!\n");
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("%d is deleted \n", item);
    }
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf(" queue is Empty\n");
    }
    else
    {
        printf("\n Elements are : ");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
    }
}
void reverse(){
    int i,j,rev_queue[MAX];
    printf("Reverse\n");
    i = rear;
    j = 0;
    while (i >= front)
    {
        rev_queue[j++] = queue[i--];
    }
    for ( i = 0; i <= j; i++)
    {
       queue[i] = rev_queue[i];
    }
    
}
int main()
{
    int ch, t = 1, item;
    while (t == 1)
    {
        printf("______________MENU_____________\n");
        printf("1) Enter the data\n2) Delete \n3) dispaly Data \n4) Reverse Queue\n5) EXIT \n");
        printf("Enter your choice.......\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter you data : ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
            break;
        case 5:
            t = 2;
            break;
        default:
            break;
        }
    }
    return 0;
}