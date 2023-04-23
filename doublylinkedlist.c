******************************************************
DATA STRUCTURES
*************************************************************************
DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *create_list(struct node *start);
void display (struct node *start);
struct node *addtoempty(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);

main()
{
    int choice ,data ,item;
    struct node *start=NULL;
    while(1)
    {
        printf(" 1. create list  \n");
        printf(" 2. display  \n");
        printf(" 3. add to empty list\n");
        printf(" 4. add at beginning \n");
        printf(" 5. add at end \n");
        printf(" 6. add after \n");
        printf(" 7. add before \n");
        printf(" 8. deletion \n");
        printf(" 9. reverse \n");
        printf(" 10.quit \n");
        printf(" enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            start=create_list(start);
            display(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Enter the element to be inserted:");
            scanf("%d",&data);
            start=addtoempty(start,data);
            display(start);
            break;
        case 4:
            printf("Enter the element to be inserted:");
            scanf("%d",&data);
            start=addatbeg(start,data);
            display(start);
            break;
        case 5:
            printf("Enter the element to be inserted:");
            scanf("%d",&data);
            start=addatend(start,data);
            display(start);
            break;
        case 6:
            printf("Enter the elements to be inserted:");
            scanf("%d",&data);
            printf("Enter the element after which to insert:");
            scanf("%d",&item);
            start=addafter(start,data,item);
            display(start);
            break;
        case 7:
            printf("Enter the elemet to be inserted:");
            scanf("%d",&data);
            printf("Enter the elements before which to insert:");
            scanf("%d",&item);
            start=addbefore(start,data,item);
            display(start);
            break;
        case 8:
            printf("Enter the element to be deleted: ");
            scanf("%d",&data);
            start=del(start,data);
            display(start);
            break;
        case 9:
            start=reverse(start);
            display(start);
            break;
        case 10:
            exit(1);
        default:
        printf("Wrong choice\n");
        }
    }
}
void display (struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("the list is empty \n");
        return;
    }
    p=start;
    printf("list is  :\n");
    while(p!=NULL)
    {
        printf(" %d",p->info);
        p=p->next;
    }
        printf("\n");
}
struct node *addtoempty(struct node *start,int data)
{

    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev =NULL;
    tmp->next=NULL;
    start=tmp;
    return start;
};
struct node  *addatbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;
    return start;
}
struct node *addatend( struct node*start,int data)
{
    struct node *tmp,*p;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    while(p->next!=NULL)
        p=p->next;
    p->next=tmp;
    tmp->next=NULL;
    tmp->prev=p;
    return start;
}
struct node *addafter(struct node *start,int data,int item)
{
    struct node *tmp,*p;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp->prev=p;
            tmp->next=p->next;
            if(p->next==NULL)
                p->next->prev=tmp;
            p->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf(" %d not present in the list \n", item);
    return start;
}
struct node *addbefore( struct node* start , int data ,int item)
{
    struct node *tmp,*q;
    if(start==NULL)
    {
        printf(" list is empty \n ");
        return start;
    }
    if(start->info==item)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->prev=NULL;
        tmp->next=start;
        start->prev=tmp;
        return start;
    }
    q=start;
    while(q!=NULL)
    {
        if(q->info=item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->prev= q->prev;
            tmp->next=q;
            q->prev->next=tmp;
            q->prev=tmp;
            return start;
        }
        q=q->next;
    }
    printf(" %d element not fount \n",item);
    return start;
}
struct node *create_list(struct node *start)
{
    int i,n,data;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;
    printf("enter the elements to be inserted  :- ");
    scanf("%d",&data);
    start=addtoempty(start,data);
    for(i=2;i<=n;i++)
    {
        printf("enter the elements to be inserted :- ");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;
}
struct node *del(struct node *start,int data)
{
    struct node *tmp;
    if(start==NULL)
    {
        printf("list is empty \n ");
        return start;
    }
    if(start->next==NULL)
        if(start->info==data)
        {
            tmp=start;
            start=NULL;
            free(tmp);
            return start;
        }
        else
        {
            printf(" element %d not found \n",data);
            return start;
        }
    if(start->info==data)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        free(tmp);
        return start;
    }
    tmp=start->next;
    while(tmp->next!=NULL)
    {
        if(tmp->info==data)
            {
                tmp->prev->next=tmp->next;
                tmp->next->prev=tmp->prev;
                free(tmp);
                return start;
            }
            tmp=tmp->next;
    }
    if(tmp->info==data)
    {
        tmp->prev->next=NULL;
        free(tmp);
        return start;
    }
    printf("element %d not found \n",data);
    return start;
}



struct node *reverse(struct node *start)
{
    struct node *p1 ,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    printf("list reversed \n");
    return start;
}
