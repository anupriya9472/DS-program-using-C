#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
#define M 5
struct element
{
    int data,pr;
};
void Add_Q(struct element *,int *,int *);
void De_Q(struct element *,int *,int *);
void Display(struct element *,int *,int *);
void Pick(struct element *,int *);
void main()
{
    struct element Q[M];
    int F=-1,R=-1;
    char ch;
st:
    printf("\nOperation of Priority Queue using Array:\n");
    printf("1.Add Queue\n2.De Queue\n3.Display all data\n4.Pick\n5.Exit\nPress any key---");
    ch=getche();
    switch (ch)
    {
    case '1':
        Add_Q(Q,&R,&F);
        break;
    case '2':
        De_Q(Q,&R,&F);
        break;
    case '3':
        Display(Q,&R,&F);
        break;
    case '4':
        Pick(Q,&R);
        break;
    case '5':
        exit(0);
    default:
        printf("\ninvalid key try again");
    }
    goto st;
}
void Add_Q(struct element *Q,int *R,int *F)
{
    struct element temp;
    int i;
    if(*R>=M-1)
    {
        printf("\nQueue is overflow");
    }
    else
    {
        printf("\nEnter data to add in queue:-");
        scanf("%d",&temp.data);
        printf("Enter there priority:-");
        scanf("%d",&temp.pr);
        *R+=1;
        if(*R==0)
        {
            Q[*R]=temp;
        }
        else
        {
            i=*R-1;
            while (i>=*F)
            {
                if (Q[i].pr>temp.pr)
                {
                    Q[i+1]=Q[i];
                }
                else
                {
                    break;
                }
                i--;
            }
            Q[i+1]=temp;
        }
        printf("Data added sucessfully\n");
        if(*F==-1)
        {
            *F=0;
        }
    }
}
void De_Q(struct element *Q,int *R,int *F)
{
    if(*F==-1||*R<*F)
    {
        printf("\nQueue is underflow");
    }
    else
    {
        printf("\n%d data and there priority %d is deleted",Q[*F].data,Q[*F].pr);
        *F+=1;
        if(*F>*R)
        {
            *F=-1;
            *R=-1;
        }
    }
}
void Display(struct element *Q,int *R,int *F)
{
    int i;
    if(*R!=-1)
    {
        printf("\nData in Queue is__:");
        for(i=*F; i<=*R; i++)
        {
            printf("\nData is %d and its priority is %d ",Q[i].data,Q[i].pr);
        }
    }
    else
    {
        printf("\nData not available");
    }
}
void Pick(struct element *Q,int *R)
{
    if(*R!=-1)
    {
        printf("\nData on top position is %d and there priority is %d",Q[*R].data,Q[*R].pr);
    }
    else
    {
        printf("\nData not available");
    }
}
