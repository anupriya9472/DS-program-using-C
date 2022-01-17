#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
}*top=NULL,*t,*p;

void push(int);
void pop();
void pick();
void display();


void main()
{
    char ch;
    int data;
start:
    printf("\nOperation of Stack using linked list:\n");
    printf("1.Push\n2.Pop\n3.pick\n4.display\n0.Exit\npress any key...");
    ch=getche();
    switch(ch)
    {
    case'1':
            printf("\nenter the data:-");
        scanf("%d",&data);
        push(data);
        break;
    case'2':
            pop();
        break;
    case'3':
            pick();
        break;
    case'4':
            display();
        break;
    case'0':
            exit(0);
    default:
        printf("\ninvailed key...try again");
    }
    goto start;
}

void push(int data)
{
    if(top==NULL)
    {
        top=(struct node*) malloc(sizeof(struct node));
        top->data=data;
        top->prev=NULL;
    }
    else
    {
        p=(struct node*) malloc(sizeof (struct node));
        p->data=data;
        p->prev=top;
        top=p;
    }
}
void pop()
{
    if(top!=NULL)
    {
        printf("\npoping thse data is %d",top->data);
        p=top;
        top=top->prev;
        free(p);
    }
    else
    {
        printf("\nstrack is under flow");
    }
}

void pick()
{
    if(top!=NULL)
    {
        printf("\npick the data is %d",top->data);
    }
    else
    {
        printf("\nstack is empty");
    }
}

void display()
{
    t=top;
    printf("\n");
    if(t!=NULL)
    {
        while(t!=NULL)
        {
            printf("%d, ",t->data);
            t=t->prev;
        }
    }
    else
    {
        printf("stack is empty");
    }
}
