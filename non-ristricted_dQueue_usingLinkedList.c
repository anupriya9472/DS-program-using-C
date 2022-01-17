#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
struct node
{
    int data;
    struct node *next,*pre;
}*l=NULL,*r=NULL,*p=NULL,*t=NULL;
void Add_Q(int,char);
void De_Q(char);
void display();
void pick();
void main()
{
    int data;
    char ch;
st:
    printf("\nOperation of Non-restricted D-QUEUE using link list:\n1.Add data from Right end\n2.Add data from Left end\n3.Delete data from left end \n4.Delete data from right end\n");
    printf("5.Display all data\n6.Pick\n7.Exit\nPress any key---");
    ch=getche();
    switch (ch)
    {
    case '1':
        printf("\nEnter data to add in Queue:-");
        scanf("%d",&data);
        Add_Q(data,'r');
        break;
    case '2':
        printf("\nEnter data to add in Queue:-");
        scanf("%d",&data);
        Add_Q(data,'l');
        break;
    case '3':
        De_Q('l');
        break;
    case '4':
        De_Q('r');
        break;
    case '5':
        display();
        break;
    case '6':
        pick();
        break;
    case '7':
        exit(0);
    default:
        printf("\ninvalid key try again");
    }
    goto st;
}
void Add_Q(int data,char s)
{
    if (s=='r')
    {
        if(r==NULL)
        {
            r=(struct node *)malloc(sizeof(struct node));
            r->data=data;
            r->next=NULL;
            r->pre=NULL;
            printf("\nData added successfully");
        }
        else
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=data;
            t->next=NULL;
            t->pre=r;
            r->next=t;
            r=t;
            printf("\nData added successfully");
        }
        if(l==NULL)
        {
            l=r;
        }
    }
    else if (s=='l')
    {
        if (l!=NULL)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=data;
            t->pre=NULL;
            t->next=l;
            l->pre=t;
            l=t;
            printf("\nData added successfully");
        }
        else
        {
            l=(struct node *)malloc(sizeof(struct node));
            l->data=data;
            l->pre=NULL;
            l->next=NULL;
            printf("\nData added successfully");
        }
        if (r==NULL)
        {
            r=l;
        }
    }
}
void De_Q(char s)
{
    if (s=='l')
    {
        if(l!=NULL)
        {
            t=l;
            printf("\n%d data deleted",l->data);
            l=l->next;
            l->pre=NULL;
            free(t);
        }
        else
        {
            printf("\nQueue is underflow");
        }
    }
    else if (s=='r')
    {
        if (r!=NULL)
        {
            t=r;
            printf("\n%d data deleted",r->data);
            r=r->pre;
            r->next=NULL;
            free(t);
        }
        else
        {
            printf("\nQueue is underflow");
        }
    }
}
void display()
{
    if(l!=NULL)
    {
        t=l;
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
