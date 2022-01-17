#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
#define Max 3
void Add_Queue(int *,int *,int *,int ,int );
void De_Queue(int *,int *,int *,int );
void Display (int *,int *,int *);
void Pick(int *,int *);
int main()
{
	int Queue[Max],rear=-1,front=-1;
	char ch;
	int data;
	st:
	printf("\n Operation of Circular Queue\n");
	printf("1.Add data\n2.Remove data \n3.Pick data\n4.Display all data \n5.Exit\nPress any key____:-");
	ch=getche();
	switch (ch)
	{
		case '1':
		printf("\nenter no to add in queue:-");
		scanf("%d",&data);
		Add_Queue(Queue,&front,&rear,Max,data);
		break;
		case '2':
		De_Queue(Queue,&front,&rear,Max);
		break;
		case '3':
		Pick(Queue, &rear);
		break;
		case '4':
		Display (Queue,&front,&rear);
		break;
		case '5':
		exit(0);
		default:
		printf("\nInvalid key try again");
	}
	goto st;
	return 0;
}
void Add_Queue(int *q,int *f,int *r,int m,int data)
{
	if (*f==(*r+1)%m)
	{
		printf("\nQueue is overflow");
	}
	else
	{
		*r=(*r+1)%m;
		q[*r]=data;
		printf("\ndata added successfully");
	if (*f==-1)
	{
	*f=0;}
	}
}
void De_Queue(int *q,int *f,int *r,int m)
{
	if (*f==-1)
	{
		printf("\nQueue is underflow");
	}
	else
	{
		printf("\n%d data deleted",q[*f]);
		*f=(*f+1)%m;
	}
	if (*f==*r+1)
		{
			*f=-1;
			*r=-1;
		}
}
void Display (int *q,int *f,int *r)
{
	int t;
	if (*r!=-1)
	{
		t=*f;
		printf("\nData in Queue is___: ");
	    do
			{
			printf(" %d,",q[t]);
			t=(t+1)%Max;
			}while (t!=(*r+1)%Max);
	}
	else
	{
		printf("\nData not available");
	}
}
void Pick(int *q,int *r)
{
	if (*r!=-1)
	{
	printf("\nData on top position is %d",q[*r]);
	}
	else
	{
	printf("\ndata is not available");
	}
}
