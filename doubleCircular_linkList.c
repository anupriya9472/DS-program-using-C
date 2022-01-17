#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
struct stu
{
    char nm[20],fnm[20];
    struct stu *pre,*next;
}*s=NULL,*t,*p;

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
    //clrscr();
    printf("\noperation of double circular linked list\n");
    printf("1.create list\n2.display list\n3.insert new node\n4.add new node");
    printf("\n5.delete all\n6.remove a node\n7.Exit \nPress Any Key...");
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
        printf("\nEnter name of the student:-");
//gets(temp.nm);
        scanf("%s",&temp.nm);
        printf("Enter father\'s name:-");
        scanf("%s",&temp.fnm);
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
        printf("\nenter position which u want to delete data:-");
        scanf("%d",&pos);
        remove_data(pos);
        break;
    case '7':
        printf("Thanku For Useing Circular Linked List Operation Press Any Key To Exit");
        getche();
        exit(0);
    default:
        printf("Invalid Choice Try again press any key to Continuee...");
    }
    getch();
    goto st;
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
        s->pre=s;
        s->next=s;
        ton++;
        t=s;
start:
        printf("do you want to add more data press y for yes:-");
        ch=getche();
        if(ch=='y'||ch=='Y')
        {
            p=(struct stu *)malloc(sizeof(struct stu));
            printf("\nenter name:-");
            gets(p->nm);
            printf("enter father\'s name:-");
            gets(p->fnm);//data is initilized into new node now link it
            p->pre=t;// initilize previous pointer of new node
            p->next=s;//initilize next pointer of new node
            t->next=p;//link with previous node
            s->pre=p;
            t=t->next;//move current node to new node it can be same as t=p
            ton++;
            goto start;
        }
        else
        {
            printf("\nthanks for creating list:\n");
        }
    }
    else
    {
        printf("\nlist already exist try again PRESS ANY KEY TO CONTINUEE...:");
        getch();
    }
}
void display()
{
    char ch;
    if(s!=NULL)
    {
        t=s;
start:
       // clrscr();
        printf("\nDetail of student :-\nName=%s\nFather\'s name=%s\n",t->nm,t->fnm);
start2:
        printf("\nPRESS\NP to Previous\nN to  next \nD to display all \nE to End display \npress your choice");
        ch=getche();
        switch(ch)
        {
        case 'p':
        case 'P':
            if(t==s)
            {
                printf("You are on First Data Now You are moving To last data press any key to continue..");
                t=t->pre;
                goto start;
            }
            else
            {
                t=t->pre;
                goto start;
            }
            break;
        case 'n':
        case 'N':
            if(t->next==s)
            {
                printf("You are on last data,now you are moving to first data. press any key to continue..");
                getch();
                t=t->next;
                goto start;
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
            //clrscr();
            do
            {
                printf("\nDetail of student:-\n");
                printf("Name=%s\nFather\'s name=%s\n=========================\n",t->nm,t->fnm);
                t=t->next;
            }
            while(t!=s);
            break;
        case 'e':
        case 'E':
            printf("\nthanku for useing display operation press any key to cont...");
            getch();
            break;
        default:
            printf("\ninvalid key try again...");
            goto start2;
        }
    }
    else
    {
        printf("\nThere no any data in list press any key to continue....");
    }
}
void delete_all()
{
//logicaly delet all data not physicaly
    free(s);
    ton=0;
    s=NULL;
    t=NULL;
    p=NULL;//set all veriable to null because no data is rest into the memory

    printf("Their is no data to delete Press any key to continue..");
    getch();
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
        p->pre=s->pre;
        p->next=s;
        s->pre->next=p;
        s->pre=p;
        ton++;
        printf("\ndata added successfully");
    }
    else
    {
        printf("list not exist try again ,press any key to continue...");
        getch();
    }
}
void remove_data(int pos)
{
//remove node from given position
    int i;
    if(s==NULL||pos>ton||pos<1)//means list is empty or position is less or greter then existing position
    {
        printf("list is empty or position is invalid try again press any key to continue...");
        getch();
    }
    else
    {
        if(pos==1)
        {
            p=s;//store node which you want to delete in p
            s=p->next;
            s->pre=p->pre;
            p->pre->next=s;
            free(p);
            printf("1st node delete successfully");
            if(ton==1)
            {
                s=NULL;
                t=NULL;
                p=NULL;
            }
            ton--;
        }
        else
        {
            t=s;
            for(i=2; i<=pos; i++) //target the node which u want to delete
            {
                t=t->next;
            }
            p=t;
            p->next->pre=p->pre;
            p->pre->next=p->next;
            free(p);
            ton--;
            printf("data on position %d is delete successfully. press any key to continue..",pos);
            getch();
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
            temp->next=s;
            temp->pre=s->pre;
            s->pre->next=temp;
            s->pre=temp;
            s=temp;
            ton++;
            return (1);
        }
        else
        {
            t=s;//temp holds the memory where you want to insert node
            for (i=2; i<pos; i++)
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
