#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
struct node
{
    int data;
    struct node *next;
}*f=NULL,*r=NULL,*p=NULL,*t=NULL;

void Add_Q(int);
void De_Q();
void display();
void pick();

void main()
{
    int data;
    char ch;
st:
    printf("\nOperation of Queue using link list:\n1.Add Queue\n2.Delete Queue\n");
    printf("3.Display all data\n4.Pick\n5.Exit\nPress any key---");
    ch=getche();
    switch (ch)
    {
    case '1':
        printf("\nEnter data to add in Queue:-");
        scanf("%d",&data);
        Add_Q(data);
        break;
    case '2':
        De_Q();
        break;
    case '3':
        display();
        break;
    case '4':
        pick();
        break;
    case '5':
        exit(0);
    default:
        printf("\ninvalid key try again");
    }
    goto st;
}
void Add_Q(int data)
{
    if(r==NULL)
    {
        r=(struct node *)malloc(sizeof(struct node));
        r->data=data;
        r->next=NULL;
    }
    else
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=data;
        t->next=NULL;
        r->next=t;
        r=t;
    }
    if(f==NULL)
    {
        f=r;
    }
}
void De_Q()
{
    if(f!=NULL)
    {
        t=f;
        printf("\n%d data deleted",f->data);
        f=f->next;
        free(t);
    }
    else
    {
        printf("\nQueue is underflow");
    }
}
void display()
{
    if(f!=NULL)
    {
        t=f;
        printf("\nData in Queue:--");
        while(t!=NULL)
        {
            printf("%d,",t->data);
            t=t->next;
        }
    }
    else
    {
        printf("\nData not available");
    }
}
void pick()
{
    if(r!=NULL)
    {
        printf("\nData on top position is %d",r->data);
    }
    else
    {
        printf("\nQueue in not available");
    }
}
