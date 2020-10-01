#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};

struct node* Create_node()
{
struct node *n;
n=(struct node*)malloc(sizeof(struct node));
n->next=NULL;
return n;
}

void insert(struct node **start)
{
struct node *t,*p;
t=Create_node();
printf("Enter Data :");
scanf("%d",&t->data);
if(*start==NULL)
*start=t;
else
{
    p=(*start);
while(p->next!=NULL)
    {
    p=p->next;
}
p->next=t;
}
}
void delete(struct node **start)
{
    int n,m;
    printf("Enter Positon :");
    scanf("%d",&n);
    printf("Enter no. of nodes to be deleted :");
    scanf("%d",&m);
    struct node *p,*q,*r;
    if(*start==NULL)
        printf("\nList is Empty\n");
    else if((*start)->next==NULL&&n==1)
    {
        printf("\nNo nodes available after given position\n");
    }
    else
    {
        p=(*start);
        q=(*start);
        r=NULL;
        for(int i=1;i<m-1;i++)
        {
            if(p==NULL)
            {
                printf("Not Enough Nodes to delete\n");
                return;
            }
            p=p->next;
            r=p;
        }
        for(int j=1;j<m+n-1;j++)
        {
            if(q==NULL)
            {
                printf("\nNot Enough Nodes to Delete\n");
                return;
            }
            q=q->next;
        }
        p->next=q->next;
        free(r);
    }

}

void view(struct node **start)
{
    struct node *t;
    if(*start==NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        t=(*start);
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
    }
}

int main()
{
    struct node *start=NULL;
    int choice;
    printf("1.Insert Node");
    printf("\n2.Delete Nodes");
    printf("\n3.View List");
    printf("\n4.EXIT\n");
    while(1)
    {
        printf("\nEnter Your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert(&start);
            break;
        case 2:
            delete(&start);
            break;
        case 3:
            view(&start);
            break;
        case 4:
            exit(0);
        }
    }
}
