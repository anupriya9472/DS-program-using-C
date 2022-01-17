#include<conio.h>
#include<stdio.h>
#include<process.h>
#define MAX 10
int ar[MAX];
int top=-1;
void push(int);
int pop();
void display();
void pick();

void main()
{
    char ch;
    int data;
start:
    printf("\noperation of stack using array:-\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY ALL\n4.PICK\n5.EXIT\nPRESS ANY KEY______");
    ch=getche();
    switch(ch)
    {
    case '1':
        printf("\nenter data to push in stack:-");
        scanf("%d",&data);
        push(data);
        break;
    case '2':
        data=pop();
        if(data!=0)
            printf("\ndata poped from stack is %d",data);
        else
            printf("\nStack underflow");
        break;
    case '3':
        display();
        break;
    case '4':
        pick();
        break;
    case '5':
        exit(0);
        break;
    default:
        printf("\ntry again invalid key____");
    }
    goto start;
}
void push(int x)
{
    if(top==MAX-1)
    {
        printf("\nStack overflow data not inserted");
    }
    else
    {
        top++;
        ar[top]=x;
    }
}
int pop()
{
    int data=0;
    if(top!=-1)
    {
        data=ar[top];
        top--;
    }
    return data;
}
void display()
{
    if(top<0)
    {
        printf("\nStack is empty");
    }
    else
    {
        for(int i=top; i>=0; i--)
        {
            printf("\n%d data is %d",(i+1),ar[i]);
        }
    }
}
void pick()
{
    if(top!=-1)
    {
        printf("\nData on top position is %d",ar[top]);
    }
    else
    {
        printf("\nStack is not available");
    }
}
