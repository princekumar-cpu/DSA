#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct node
{
    char name[MAX];
    int roll_number,marks;
    struct node *next;
};

struct node *start = NULL;
int count = 0;

void insert_at_beging(char name[MAX],int roll_num,int marks)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory is not available\n");
    }
    else{
        strcpy(temp->name, name);
        temp->roll_number = roll_num;
        temp->marks = marks;
        temp->next = NULL;

        if (start == NULL){
            start = temp;
            printf("%s is inserted\n", name);
        }
        else{
            temp->next = start;
            start = temp;
            printf("%s is inserted\n", name);
        }
    }
}
void insert_at_end(char name[MAX],int roll_num,int marks){
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    if (temp1 == NULL && temp2 == NULL)
    {
        printf("Memory is not available\n");
    }
    else{
        strcpy(temp1->name, name);
        temp1->roll_number = roll_num;
        temp1->marks = marks;
        temp1->next = NULL;

        if (start == NULL){
            start = temp1;
            printf("%s is inserted\n", name);
        }
        else{
            temp2 = start;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp1;
            printf("%s is inserted\n", name);
        }
    }
}

void insert_at_given_pos(char name[MAX],int roll_num,int marks){
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    struct node *temp3 = (struct node*)malloc(sizeof(struct node));
    int pos,num=0;
    if (temp1 == NULL && temp2 == NULL)
    {
        printf("Memory is not available\n");
    }
    else{
        strcpy(temp1->name, name);
        temp1->roll_number = roll_num;
        temp1->marks = marks;
        temp1->next = NULL;

        printf("Enter the position \n");
        scanf("%d",&pos);
        if (start == NULL){
            start = temp1;
            printf("%s is inserted\n", name);
        }
        else{
            temp3 = start;
            while (temp3->next != NULL && pos > num)
            {
                num += 1;
                temp2 = temp3;
                temp3 = temp3->next;
            }
            temp1->next = temp3;
            temp2->next = temp1;
            printf("%s is inserted\n", name);
        }
    }
}
void delete_from_beging(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(start == NULL){
        printf("List is empty\n");
    }
    else{
        temp = start;
        start = start->next;
        printf("%s is deleted\n", temp->name);
        free(temp);
    }
}
void delete_from_end(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    if(start == NULL){
        printf("List is empty\n");
    }
    else{
        temp = start;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        printf("%s is deleted\n",temp->name);
        free(temp);
        
    }
}
void delete_from_given_pos(){
    struct node *temp1 ;
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    struct node *temp3 = (struct node*)malloc(sizeof(struct node));
    int pos,num=0;
    if (temp1 == NULL && temp2 == NULL)
    {
        printf("Memory is not available\n");
    }
    else{
        printf("Enter the position \n");
        scanf("%d",&pos);
        if (start == NULL){
            printf("List is empty\n");
        }
        else{

            temp3 = start;
            while ((pos -1) > num ||
             temp3 == NULL)
            {
                num += 1;
                temp2 = temp3;
                temp3 = temp3->next;
            }
            if(temp3 == NULL){
                printf("Record in the list is less than the given position \n");
            }
            else{
                temp1 = temp3;
                temp2->next = temp3->next;
                temp1->next = NULL;
                printf("%s is deleted\n", temp1->name);
                free(temp1);
            }
        }
    }
}
void display()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int count= 0;
    if (start == NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        temp = start;
        printf("________________Record details________________\n\n");
        while (temp  != NULL)
        {
            printf("Record of student %d\n",++count);
            printf("Name\t\t:\t%s\n",temp->name);
            printf("Roll number :\t\t%d\n",temp->roll_number);
            printf("Marks \t\t:\t%d\n\n",temp->marks);
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
        printf("_______________Menu________________\n\n1) Insert record at beging\n2) Insert record at end\n3) Insert record at given position\n");
        printf("4) Delete record from beging \n5) Delete record from end \n6) Delete record from given pos \n7) Display record\n8) EXIT\n\nEnter your choice.....  ");
        scanf("%d",&ch);
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
            insert_at_beging(temp,roll_num,marks);
            break;
        case 2:
            printf("Record of student %d",++count);
            printf("\nEnter the name\t\t:\t");
            scanf("%s",&temp);
            printf("\nEnter the Roll number\t:\t");
            scanf("%d",&roll_num);
            printf("\nEnter the Marks\t\t:\t");
            scanf("%d",&marks);
            insert_at_end(temp,roll_num,marks);
            break;
        case 3:
            printf("Record of student %d",++count);
            printf("\nEnter the name\t\t:\t");
            scanf("%s",&temp);
            printf("\nEnter the Roll number\t:\t");
            scanf("%d",&roll_num);
            printf("\nEnter the Marks\t\t:\t");
            scanf("%d",&marks);
            insert_at_given_pos(temp,roll_num,marks);
            break;
        case 4:
            delete_from_beging();
            break;
        case 5:
            delete_from_end();
            break;
        case 6:
            delete_from_given_pos();
            break;
        case 7:
            display();
            break;
        case 8:
            t = 1;
            break;
        default:
            printf("Invalid choice!!!!\n");
            break;
        }
    }
    return 0;
}