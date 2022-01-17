#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<process.h>
struct node
{
    int num;
    struct node *next;
}*s,*t,*p;

void create();//
void display();//
void del_node(int);
void insert_data(int);//
void search_data(int);
void search_pos(int);
void add_data(int);
void delete_list();
int total_node();//

void main()
{
    int data,pos;
    char ch;
start:
    printf("\noperation of single link list:\n");
    printf("1.create list\n2.display all\n3.delete node\n4.insert data\n5.search data\n6.search position\n");
    printf("7.add data\n8.delete list\n9.exit");
    printf("\nchose any option:");
    ch=getche();
    switch(ch)
    {
    case '1':
        create();
        break;
    case '2':
        display();
        break;
    case '3':
        printf("\nenter position from which you want to delete node:-");
        scanf("%d",&pos);
        del_node(pos);
        break;
    case '4':
        printf("\nenter position where you want to insert data in list:-");
        scanf("%d",&pos);
        insert_data(pos);
        break;
    case'5':
            printf("\nenter data for search in list:-");
        scanf("%d",&data);
        search_data(data);
        break;
    case '6':
        printf("\nenter position from which you want to see data:-");
        scanf("%d",&pos);
        search_pos(pos);
        break;
    case '7':
        printf("\nenter data to add in list:-");
        scanf("%d",&data);
        add_data(data);
        break;
    case '8':
        delete_list();
        break;
    case '9':
        exit(0);
    default:
        printf("try again");
    }
    goto start;
}
void display()
{
    if(s!=NULL)
    {
        p=s;
        printf("\n");
        while(p!=NULL)
        {
            printf("%d,",p->num);
            p=p->next;
        }
    }
    else
    {
        printf("\nno any data in list");
    }
}
void create()
{
    int data;
    char ch;
    if(s!=NULL)
    {
        printf("\nlist already exist try again:");
    }
    else
    {
        s=(struct node *)malloc(sizeof(struct node));
        printf("\nenter no to add in list:-");
        scanf("%d",&data);
        s->num=data;
        s->next=NULL;
start:
        printf("do you want to add more data press y for yes:-");
        ch=getche();
        if(ch=='y'||ch=='Y')
        {
            t=(struct node *)malloc(sizeof(struct node));
            printf("\nenter no to add in list:-");
            scanf("%d",&data);
            t->num=data;
            t->next=NULL;
            p=s;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            goto start;
        }
        else
        {
            printf("\nthanks for creating list:\n");
        }
    }
}
int total_node()
{
    int tn=0;
    t=s;
    while(t!=NULL)
    {
        tn++;
        t=t->next;
    }
    return tn;
}
void insert_data(int pos)
{
    int data,tn=total_node();
    if(s==NULL||pos>tn||pos<1)
    {
        printf("\ninsert not allow this position because this position invalid");
    }
    else
    {
        p=(struct node *)malloc(sizeof(struct node));
        printf("\nenter data to insert in list:-");
        scanf("%d",&data);
        p->num=data;
        p->next=NULL;
        if(pos==1)
        {
            t=s;
            p->next=s;
            s=p;
            printf("\nFirst node inserted successfully");
        }
        else
        {
            t=s;
            for(int i=2; i<pos; i++)
            {
                t=t->next;
            }
            p->next=t->next;
            t->next=p;
            printf("\nData inserted successfully");
        }
    }
}
void search_data(int data)
{
    if(s!=NULL)
    {
        int f=0,pos=0;
        p=s;
        while(p!=NULL)
        {
            pos++;
            if(p->num==data)
            {
                printf("\n%d data is founded on address %d",data,pos);
                f=1;
            }
            p=p->next;
        }
        if(f==0)
            printf("\ndata not founded in this list");
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
void add_data(int data)
{
    if(s!=NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->num=data;
        t->next=NULL;
        p=s;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
        printf("\nData added successfully..\n");
    }
    else
    {
        printf("\nno any list available plz create list then try again..\n");
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
        printf("\ndata on position %d is %d \n",pos,t->num);
    }
}
void delete_list()
{
    s=NULL;
    free(p);
    free(t);
    printf("\nList is deleted successfully..\n");
}
