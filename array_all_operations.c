#include<conio.h>
#include<stdio.h>
#define Max 10
void Create (int *,int *,int);//1
void Display  (int *,int *,int);//2
void Add_data (int *,int *,int,int);//3
void Search_data (int *,int *,int,int);//4
void Search_pos (int *,int *,int,int);//5
void Insert_data (int *,int *,int,int,int);//6
void Delete_data (int *,int *,int,int);//7
void Delete_all (int *);//8
void main ()
{
    int list [Max];
    int cp=-1, data, pos;
    char ch;
start:
    printf("\nOPERATION OF ARRAY:-\n");
    printf("1.CREATE\n 2.DISpLay\n 3.ADD_DATA\n 4.SEARCH_DATA DATA WISE\n 5.DISPLAY DATA POSITION WISE\n 6.INSERT NEW DATA\n 7.DELETE FROM POSITION\n 8.DELETE ALL DATA\n 9. exit\n");
    ch=getch();
    switch(ch)
    {
    case '1':
        Create(list, &cp, Max);
        break;
    case '2':
        Display(list, &cp, Max);
        break;
    case '3':
        printf("Enter data to add in the existing list:-");
        scanf("%d", & data);
        Add_data(list, &cp, Max,data);
        break;
    case '4':
        printf("Enter data to search in list :-");
        scanf("%d", & data);
        Search_data(list,& cp,Max,data);
        break;
    case '5':
        printf("Enter position which data you want to see and :-");
        scanf("%d", & pos);
        Search_pos(list, &cp,Max, pos);
        break;
    case '6':
        printf("Enter position where you want to insert data and :- " );
        scanf("%d", & pos);
        printf("Enter data to insert:-");
        scanf("%d", & data);
        Insert_data(list,&cp,Max,pos,data);
        break;
    case '7':
        printf("Enter position which you want to delete:-");
        scanf("%d", & pos);
        Delete_data(list,&cp,Max,pos);
        break;
    case '8':
        Delete_all(&cp);
        break;
    case '9':
        exit (0);
    default:
        printf("plz enter a valid option:-");
    }
    //getch ();
    goto start;
}
void Create (int *p,int *cp,int m)//1
{
    int i,t,n;
    if (*cp>-1)
    {
        printf  (" list already exist try again \n");
        //exit;
    }
    else
    {
        printf("how many data you want to add :- ");
        scanf("%d",&n);
        if (n>-1&&n <=m)
        {
            for (i=0; i <n; i++)
            {
                printf("enter data:- ");
                scanf("%d",&t);
                p [i]=t;
            }
            *cp=n-1;
            printf("\nlist created successfully..");
        }
        else
        {
            printf("not a valid number try again\n ");
        }
    }
}
void Display(int *p,int *cp,int m)//2
{
    if (*cp >-1)
    {
        for (int i=0; i <=*cp; i++)
        {
            printf("%d\n",p [i]);
        }
    }
    else
    {
        printf("no data in list\n");
    }
}
void Add_data (int *p,int *cp,int m,int data)//3
{
    *cp+=1;
    if (*cp>=m)
    {
        printf("list is full\n");
    }
    else
    {
        p [*cp]=data;
    }
}
void Search_data (int *p,int *cp,int m,int sd)//4
{
    if (*cp>-1)
    {
        int f=0,i;
        for (i=0; i <*cp; i++)
        {
            if (p [i]==sd)
            {
                printf("data founded on %d position \n",i+1);
                f=1;
            }
        }
        if (f==0)
        {
            printf("data not founded\n");
        }
    }
}
void Search_pos (int *p,int *cp,int m,int pos)//5
{
    if (pos <=*cp&&*cp >-1)
    {
        printf("on pos data is %d\n",p [pos-1]);
    }
    else
    {
        printf(" data not founded\n");
    }
}
void Insert_data (int *p,int *cp,int m,int pos,int data)//6
{
    *cp+=1;
    if (*cp <0||pos>=*cp||pos==(m-1))
    {
        printf("insert not allowed on this position try again\n");
        *cp-=1;
    }
    else
    {
        for (int i=*cp; i>=pos; i--)
        {
            p [i+1]=p [i];
        }
        p [pos]=data;
        //*cp+=1;
    }
}
void Delete_data (int *p,int *cp,int m,int pos)//7
{
    if (*cp>-1&&pos <=*cp)
    {
        for  (int i=pos-1; i <=*cp; i++)
        {
            p [i]=p [i+1];
        }
        *cp-=1;
    }
    else
    {
        printf("data operation not performed successfully try again\n ");
    }
}
void Delete_all (int *cp)//8
{
    *cp=-1;
    printf ("\ndelete operation perform successfully :\n");
}
