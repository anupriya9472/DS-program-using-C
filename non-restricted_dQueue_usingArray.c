#include<conio.h>
#include<stdio.h>
#define Max 5
void Add_Q(int *,int *,int *,int,char );
void De_Q(int *,int *,int *,char );
void Display_all (int *,int *,int *);
void Pick(int *,int *);
void main()
{
    int Q[Max],right=-1,left=-1;
    char ch;
    int data;
st:
    printf("\n Operation of Non Restricted D Queue Using Array\n");
    printf("1.Add data from left end\n2.Add data from Right end\n3.Delete data from Left end\n4.Delete data from Right end \n5.Display all\n6.Pick \n7.Exit\nChoose any option____:-");
    ch=getche();
    switch (ch)
    {
    case '1':
        printf("\nEnter no to add in queue:-");
        scanf("%d",&data);
        Add_Q(Q,&right,&left,data,'l');
        break;
    case '2':
        printf("\nEnter no to add in queue:-");
        scanf("%d",&data);
        Add_Q(Q,&right,&left,data,'r');
        break;
    case '3':
        De_Q(Q,&right,&left,'l');
        break;
    case '4':
        De_Q(Q,&right,&left,'r');
        break;
    case '5':
        Display_all(Q,&right,&left);
        break;
    case '6':
        Pick(Q,&right);
        break;
    case '7':
        exit(0);
    default:
        printf("\nInvalid key try again");
    }
    goto st;
}
void Add_Q(int *q,int *r,int *l,int data, char e)
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
                printf("\nData added successfully");
            }
            else
            {
                *l-=1;
                q[*l]=data;
                printf("\nData added successfully");
            }
        }
        else
        {
            printf("\nQueue is full from left end try again");
        }
    }
    else if (e=='r')
    {
        if (*l==-1||*r<Max-1)
        {
            if (*l==-1)
            {
                *l+=1;
                *r+=1;
                q[*r]=data;
                printf("\nData added successfully");
            }
            else
            {
                *r+=1;
                q[*r]=data;
                printf("\nData added successfully");
            }
        }
        else
        {
            printf("\nQueue is full from right end try again");
        }
    }
    if (*l==-1)
    {
        *l=0;
    }
}
void De_Q(int *q,int *r,int *l,char e)
{
    int data=0;
    if (e=='l')
    {
        if (*l!=-1||*r>*l)
        {
            data=q[*l];
            *l+=1;
            printf("\n%d data is deleted ",data);
        }
        else
        {
            printf("\nNo any data left end try again");
        }
    }
    else if (e=='r')
    {
        if (*r!=-1||*r<Max)
        {
            data=q[*r];
            *r-=1;
            printf("\n%d data is deleted ",data);
        }
        else
        {
            printf("\nNo any data Right end try again");
        }
    }
    if (*l>*r)
    {
        *l=-1;
        *r=-1;
    }
}
void Display_all (int *q,int *r,int *l)
{
    int i;
    if (*r!=-1)
    {
        printf("\nData in Queue is :-");
        for (i=*l; i<=*r; i++)
        {
            printf(" %d,",*(q+i));
        }
    }
    else
    {
        printf("\nQueue is not available");
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
        printf("\nQueue is not available");
    }
}
