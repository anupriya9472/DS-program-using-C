#include<conio.h>
#include<stdio.h>
#define Max 5
void Add_Queue(int *,int *,int *,int ,int,char );
int De_Queue(int *,int *,int *);
void Display_all (int *,int *,int *);
void Pick(int *,int *,int *);
int main()
{
	int Queue[Max],right=-1,left=-1;
	char ch,e;
	int data;
	st:
	printf("\n Operation of Output Restricted D Queue\n");
	printf("1.Add queue\n2.Delelte queue\n3.Display all\n4.Pick \n5.Exit\nPress any option____:-");
	ch=getche();
	switch (ch)
	{
		case '1':
		printf("\nenter no to add in queue:-");
		scanf("%d",&data);
		printf("Enter which end you want to add data if right then press r and if left then press l:-  ");
		scanf("%c",&e);
		e=getche();
		Add_Queue(Queue,&right,&left,Max,data,e);
		break;
		case '2':
		data=De_Queue(Queue,&right,&left);
		if (data!=0)
		{
			printf("\n%d data deleted",data);
		}
		break;
		case '3':
		Display_all(Queue,&right,&left);
		break;
		case '4':
		Pick(Queue,&right,&left);
		break;
		case '5':
		exit(0);
		default:
		printf("\nInvalid key try again");
	}
	goto st;
}
void Add_Queue(int *q,int *r,int *l,int m,int data, char e)
{
	if (e=='l')
	{
		if (*l==-1||*l>0)
		{
			if (*l==-1)
			{
				*l+=1;
				*r+=1;
				q[*l]=data;
			}
			else
			{
				*l-=1;
				q[*l]=data;
			}
		}
		else
		{
			printf("\nQueue is full from left end try again");
		}
	}
	else if (e=='r')
	{
		if (*l==-1||*r<m-1)
		{
			if (*l==-1)
			{
				*l+=1;
				*r+=1;
				q[*r]=data;
			}
			else
			{
				*r+=1;
				q[*r]=data;
			}
		}
		else
		{
			printf("\nQueue is full from right end try again");
		}
	}
	if (*l==-1)
	{
	*l=0;}
}
int De_Queue(int *q,int *r,int *f)
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
void Display_all (int *q,int *r,int *f)
{
	int i;
	if (*r!=-1)
	{
		printf("\nData in Queue is :-");
	for (i=*f;i<=*r;i++)
	{
		printf(" %d,",*(q+i));
	}
	}
	else
	{
		printf("\nQueue is not available");
	}
}
void Pick(int *q,int *r,int *l)
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
