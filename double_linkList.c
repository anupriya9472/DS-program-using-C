#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
struct stu
{
    char nm[20],fnm[20];
    struct stu *pre,*next;
}*s,*t,*p;

int ton=0;
void create();
void display();
void delete_all();
void add_data();
void remove_data(int);
int insert_node(struct stu *,int);

void main()
{
    struct stu temp;
    int pos;
    char ch;
st:
    printf("\noperation of double link list\n");
    printf("1.create list\n2.display list\n3.insert new node\n4.add new node");
    printf("\n5.delete all\n6.remove a node \n7.exit\npress____:-");
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
// struct stu temp;
        printf("\nenter name of the student:-");
        gets(temp.nm);
        printf("enter father\'s name:-");
        gets(temp.fnm);
        gets(temp.fnm);
st1:
        printf("\nenter position where u want to insert this:-");
        scanf("%d",&pos);
        if(insert_node(&temp,pos)!=1)
        {
            printf("invalid position try again");
            goto st1;
        }
        else
        {
            printf("data inserted successfully");
        }
        break;
    case '4':
        add_data();
        break;
    case '5':
        delete_all();
        break;
    case '6':
        printf("\nenter position where u want to delete data:-");
        scanf("%d",&pos);
        remove_data(pos);
        break;
    case '7':
        exit(0);
    default:
        printf("\ntry again");
    }
    printf("\ndo u want to do any operation then press y:-");
    ch=getche();
    if(ch=='y'||ch=='Y')
        goto st;
    else
        printf("\nthank u");
}
void create()
{
    char ch;
    if(s==NULL)
    {
        s=(struct stu *)malloc(sizeof(struct stu));
        printf("\nenter name:-");
        gets(s->nm);
        printf("enter father\'s name:-");
        gets(s->fnm);
        s->pre=NULL;
        s->next=NULL;
        ton++;
start:
        printf("do you want to add more data press y for yes:-");
        ch=getche();
        if(ch=='y'||ch=='Y')
        {
            p=(struct stu *)malloc(sizeof(struct stu));
            printf("\nenter name:-");
            gets(p->nm);
            printf("enter father\'s name:-");
            gets(p->fnm);
            p->pre=NULL;
            p->next=NULL;
            ton++;
            t=s;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=p;
            p->pre=t;
            goto start;
        }
        else
        {
            printf("\nthanks for creating list:\n");
        }
    }
    else
    {
        printf("\nlist already exist try again:");
    }
}
void display()
{
    char ch;
    if(s!=NULL)
    {
        t=s;
start:
        printf("\nName=%s\nFather\'s name=%s\n",t->nm,t->fnm);
start2:
        printf("\npress p for print previous data\npress n to print next data\npress d to display all data\npress e to exit\npress......");
        ch=getche();
        switch(ch)
        {
        case 'p':
        case 'P':
            if(t->pre==NULL)
            {
                printf("there is no privous data");
                goto start2;
            }
            else
            {
                t=t->pre;
                goto start;
            }
            break;
        case 'n':
        case 'N':
            if(t->next==NULL)
            {
                printf("there is no next data");
                goto start2;
            }
            else
            {
                t=t->next;
                goto start;
            }
            break;
        case 'd':
        case 'D':
            t=s;
            while(t!=NULL)
            {
                printf("\nData...\n");
                printf("Name=%s\nFather\'s name=%s",t->nm,t->fnm);
                t=t->next;
            }
            break;
        case 'e':
        case 'E':
            exit(0);
        default:
            printf("invalid key try again");
            goto start2;
        }
    }
    else
    {
        printf("\nno any data in list");
    }
}
void delete_all()
{
    while(s!=NULL)
    {
        t=s->next;
        free(s);
        s=t;
    }
}
void add_data()
{
    if(s!=NULL)
    {
        p=(struct stu *)malloc(sizeof(struct stu));
        printf("\nenter name:-");
        gets(p->nm);
        printf("enter father\'s name:-");
        gets(p->fnm);
        p->pre=NULL;
        p->next=NULL;
        ton++;
        t=s;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=p;
        p->pre=t;
        printf("\ndata added successfully");
    }
    else
    {
        printf("list not exist try again");
    }
}
void remove_data(int pos)
{
    int i;
    if(s==NULL||pos>ton||pos<1)
    {
        printf("list is empty or position is invalid");
    }
    else
    {
        if(pos==1)
        {
            p=s;
            s=p->next;
            s->pre=NULL;
            free(p);
            ton--;
            printf("1st node delete successfully");
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
            p=t->next;
            p->pre=t;
            ton--;
            printf("data on position %d is delete successfully",pos);
        }
    }
}
int insert_node(struct stu *temp,int pos)
{
    int i;
    if(s==NULL||pos>ton||pos<1)
    {
        return (0);
    }
    else
    {
        if(pos==1)
        {
            t=s;
            s=temp;
            s->next=t;
            s->pre=NULL;
            ton++;
            return (1);
        }
        else
        {
            t=s;
            for(i=2; i<pos; i++)
            {
                t=t->next;
            }
            temp->next=t->next;
            temp->pre=t;
            t->next=temp;
            t=temp->next;
            t->pre=temp;
            ton++;
            return (1);
        }
    }
}
