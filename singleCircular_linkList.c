#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*t,*p,*s;

void create_list() ;
void display_list() ;
void del_node(int);
void insert_node(int);
void search_data(int);
void search_pos(int);
void add_data(int);
void remove_list();
int total_node();

void main()
{
    char ch;
    int pos,data;
start:
    printf("\nOperations of Single Circular Link List: \n");
    printf("1.create list\n2.display all\n3.delete node\n4.insert new data\n5.sarch data\n6.search data pos\n7.add_new data\n8.remove list\n9.exit\nPress any key : ");
    ch=getche();
    switch(ch)
    {
    case '1':
        create_list();
        break;
    case '2':
        display_list();
        break;
    case '3':
        printf("\nenter position which you want to delete:-");
        scanf("%d",&pos);
        del_node(pos);
        break;
    case '4':
        printf("\nenter position where you want insert new data:-");
        scanf("%d",&pos);
        insert_node(pos);
        break;
    case '5':
        printf("\nenter data which you want to search:-");
        scanf("%d",&data);
        search_data(data);
        break;
    case '6':
        printf("\nenter position which you want to display:-");
        scanf("%d",&pos);
        search_pos(pos);
        break;
    case '7':
        printf("\nenter data to add in list:-");
        scanf("%d",&data);
        add_data(data);
        break;
    case '8':
        remove_list();
        break;
    case '9':
        printf("\nThank You!\n");
        exit(0);
    default:
        printf("\ninvalid key please try again");
    }
    goto start;
}
void create_list()
{
    int data;
    char ch;
    if(s==NULL)
    {
        s=(struct node *) malloc(sizeof (struct node));
        printf("\nEnter the data:-");
        scanf("%d",&data);
        s->data=data;
        s->next=s;
start:
        printf("Do you want to add more if yes press y key");
        ch=getche ();
        if (ch=='y'||ch=='Y')
        {
            p=(struct node *) malloc(sizeof (struct node ));
            printf("\nEnter the data:-");
            scanf("%d",&data);
            p->data=data;
            p->next=s;
            t=s;
            while (t->next!=s)
            {
                t=t->next ;
            }
            t->next=p;
            goto start;
        }
        else
        {
            printf("\nThank u ");
        }
    }
    else
    {
        printf("\nList already exist please try again");
    }
}
void display_list()
{
    if(s!=NULL)
    {
        p=s;
        printf("\n");
        do
        {
            printf("%d, ",p->data);
            p=p->next;
        }while(p!=s);
    }
    else
    {
        printf("\nData not found");
    }
}
int total_node()
{
    int tn=0;
    t=s;
    if(s!=NULL)
    {
        do
        {
            tn++;
            t=t->next;
        }
        while(t!=s);
    }
    return tn;
}
void add_data(int data)
{
    if(s!=NULL)
    {
        p=(struct node *) malloc(sizeof (struct node));
        p->data=data;
        p->next=s;
        t=s;
        while(t->next!=s)
        {
            t=t->next;
        }
        t->next=p;
        printf("\ndata added successfully");
    }
    else
    {
        printf("\nList not exist\n");
    }
}
void search_data(int data)
{
    int pos=0,flag=0;
    t=s;
    if(s!=NULL)
    {
        do
        {
            pos++;
            if(t->data==data)
            {
                printf("\n %d is found on position %d\n",data,pos);
                flag=1;
            }
            t=t->next;
        }
        while(t!=s);
    }
    if(flag==0)
    {
        printf("\ndata not found\n");
    }
}
void search_pos(int pos)
{
    int i;
    int tn=total_node();
    if(tn==0||pos>tn||pos<1)
    {
        printf("\nlist is empty or position invalid please try again\n");
    }
    else
    {
        t=s;
        for(i=2; i<=pos; i++)
        {
            t=t->next;
        }
        printf("\ndata on position %d is %d \n",pos,t->data);
    }
}
void del_node(int pos)
{
    int tn=total_node();
    int i;
    if(s==NULL||pos>tn||pos<1)
    {
        printf("\nlist is empty or position is invalid try again..\n");
    }
    else
    {
        if(pos==1)
        {
            p=s;
            s=p->next;
            t=s;
            while(t->next!=p)
            {
                t=t->next;
            }
            t->next=s;
            free(p);
            printf("\nfirst node deleted successfully");
        }
        else
        {
            t=s;
            for(i=2; i<pos; i++)
            {
                t=t->next;
            }
            p=t->next;
            t->next=p->next;
            free(p);
            printf("\n%d position data deleted successfully",pos);
        }
    }
}
void insert_node(int pos)
{
    int i,data;
    int tn=total_node();
    if(s==NULL||pos>tn||pos<1)
    {
        printf("\nlist is empty or position is invalid try again");
    }
    else
    {
        p=(struct node*) malloc(sizeof (struct node));
        printf("\nenter the data to insert in list:-");
        scanf("%d",&data);
        p->data=data;
        p->next=NULL;
        if(pos==1)
        {
            t=s;
            p->next=s;
            s=p;
            printf("first node inserted successfully");
        }
        else
        {
            t=s;
            for(i=2; i<pos; i++)
            {
                t=t->next;
            }
            p->next=t->next;
            t->next=p;
        }
    }
}
void remove_list()
{
    s=NULL;
    free(p);
    free(t);
    printf("\nList is deleted successfully..\n");
}
