#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define Max 5
void Add_Queue(int *,int *,int *,int,int );
int De_Queue(int *,int *,int *);
void Display_all (int *,int *,int *);
void Pick(int *,int *,int *);
int main()
{
    int Queue[Max],rear=-1,front=-1;
    char ch;
    int data;
st:
    printf("\n Operation of Queue using array\n");
    printf("1.Add queue\n2.Delelte queue\n3.Display all\n4.Pick \n5.Exit\nPress any option____:-");
    ch=getche();
    switch (ch)
    {
    case '1':
        printf("\nenter no to add in queue:-");
        scanf("%d",&data);
        Add_Queue(Queue,&front,&rear,Max,data);
        break;
    case '2':
        data=De_Queue(Queue,&front,&rear);
        if (data!=0)
        {
            printf("\n%d data deleted",data);
        }
        break;
    case '3':
        Display_all(Queue,&front,&rear);
        break;
    case '4':
        Pick(Queue,&front,&rear);
        break;
    case '5':
        exit(0);
    default:
        printf("\nInvalid key try again");
    }
    goto st;
    return 0;
}
void Add_Queue(int *p,int *f,int *r,int m,int data)
{
    if (*r>=m-1)
    {
        printf("\nQueue is overflow");
    }
    else
    {
        *r+=1;
        p[*r]=data;
    }
    if (*f==-1)
    {
        *f=0;
    }
}
int De_Queue(int *q,int *f,int *r)
{
    int data=0;
    if (*f==-1||*r<*f)
    {
        printf("\nQueue is underflow");

    }
    else
    {
        data=q[*f];
        *f=*f+1;
    }
    if (*f>*r)
    {
        *f=-1;
        *r=-1;
    }
    return data;
}
void Display_all (int *q,int *f,int *r)
{
    int i;
    if (*r!=-1)
    {
        for (i=*f; i<=*r; i++)
        {
            printf("\n%d data is :- %d",i+1,*(q+i));
        }
    }
    else
    {
        printf("\nQueue is not available");
    }
}
void Pick(int *q,int *f,int *r)
{
    if (*r!=-1)
    {
        printf("\nData on top position is %d",q[*r]);
    }
    else
    {
        printf("\nQueue is not available");
    }
}
