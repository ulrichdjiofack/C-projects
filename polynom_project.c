#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdlib.h>

struct poly_node

{
    int coef,exp;
    struct poly_node *link;
};

void create_poly(struct poly_node **,int,int);
void display_poly(struct poly_node *);
void add_poly(struct poly_node **,struct poly_node **,struct poly_node **);
void multiply_poly(struct poly_node **,struct poly_node **,struct poly_node **);
void degree_poly(struct poly_node *);
void eval_poly(struct poly_node *);

void main()

{
    struct poly_node *p=NULL,*q=NULL,*r=NULL;
    int i,n,c,e,choice;
    int C;
    printf("\t\t\tImplementing polynomials in c using link list\n");
    printf("\t\t\t**********************************************\n");

    while(choice!=6)
    {
       // printf("1. Create polynomials\n2. Display polynomials\n3 .Add polynomials\n4. Multiply polynomials\n5. Get degree of polynomial\n6. Exit\n");

        printf("\n\n===========================\n");
    printf("(1). Create new polynomial\n");
    printf("(2). Display polynomial\n");
    printf("(3). Add polynomial\n");
    printf("(4). Degree of the polynomial\n");
    printf("(5). Evaluate the polynomial at a particular point\n");
    printf("(6). Multiply polynomial\n");
    printf("(0). Exit\n");
    printf("=====================================================\n\n");

        printf("Enter your choice Please\n");
        //printf("\tchoose an option : \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("[] * Creating polynomials ...\n\n");
            printf("Enter first polynomial!\n");
            printf("Enter no of terms:");
            scanf("%d",&n);
            for(i=0; i<n; i++)

            {
                printf("Enter coefficient: ");

                scanf("%d",&c);

                printf("Enter exponent: ");

                scanf("%d",&e);

                create_poly(&p,c,e);

            }

            printf("\nEnter second polynomial!\n");

            printf("Enter no of terms:");

            scanf("%d",&n);

            for(i=0; i<n; i++)

            {
                printf("Enter coefficient: ");

                scanf("%d",&c);

                printf("Enter exponent: ");

                scanf("%d",&e);

                create_poly(&q,c,e);

            }
            printf("[] * Polynomials created sucessfully !!!\n");
            break;
        case 2:

            printf("[] * Displaying polynomials ...\n");
            printf("First polynomial: ");

            display_poly(p);

            printf("Second polynomial: ");

            display_poly(q);
            break;

        case 3:

            add_poly(&p,&q,&r);

            printf("Summing the two polynomials you previously created:\n");

            display_poly(r);
            break;
        case 6:
            r=NULL;

            multiply_poly(&p,&q,&r);

            printf("Product of the two polynomial:\n");

            display_poly(r);
            break;
        case 4:
            printf("[] Get degree of which polynomial ?\n");
            printf("enter [1] for polynomial P\tenter [2] for polynomial Q\n");
            scanf("%d",&C);
            if(C==1)
            {
            printf("[] * Polynomial is : ");
            display_poly(p);
                degree(p);

            }
            else
            {
            printf("[] * Polynomial is : ");
            display_poly(q);
                degree(q);
            }

            break;

        }
    }
}

void degree(struct poly_node *start)
{
    struct poly_node *temp;
    temp=start;
    int degree;
//INT_MIN is an interger type and its value is -32767 or less.
    if(temp==NULL)
    {
        printf("polynomial is empty !\n");
    }
    else
    {
    degree=temp->exp;
        while(temp!=NULL)
        {
            if(degree<temp->exp){
            degree=temp->exp;
            }
            temp=temp->link;
        }
        printf("Degree of polynomial is : %d\n",degree);
    }
}

void create_poly(struct poly_node **start,int c,int e)

{
    struct poly_node *temp,*temp1,*prev;

    if (*start==NULL)

    {

        temp=(struct poly_node*)malloc(sizeof(struct poly_node));

        if (temp==NULL)

            printf("Node is not created, Term cannot be inserted\n");

        else

        {
            temp->coef=c;

            temp->exp=e;

            temp->link=NULL;

            *start=temp;

        }
    }

    else

    {
        temp1=*start;

        while (temp1!=NULL && temp1->exp>e)

        {

            prev=temp1;

            temp1=temp1->link;

        }

        if(temp1==NULL)

        {

            temp=(struct poly_node *)malloc(sizeof(struct poly_node));

            if (temp==NULL)

                printf("Node is not created\n");

            else

            {
                temp->coef=c;

                temp->exp=e;

                temp->link=NULL;

                prev->link=temp;

            }

        }

        else

        {
            if(temp1->exp==e)

                temp1->coef=temp1->coef+c;

            else

            {
                if(temp1==*start)

                {
                    temp=(struct poly_node *)malloc (sizeof (struct poly_node));

                    if(temp==NULL)

                        printf("Node is not created\n");

                    else

                    {
                        temp->coef=c;

                        temp->exp=e;

                        temp->link=*start;

                        *start=temp;

                    }
                }

                else

                {
                    temp=(struct poly_node *)malloc(sizeof(struct poly_node));

                    if (temp==NULL)

                        printf("Node is not created\n");

                    else

                    {
                        temp->coef=c;

                        temp->exp=e;

                        temp->link=temp1;

                        prev->link=temp;

                    }
                }
            }

        }
    }
}

void display_poly(struct poly_node *start)

{
    struct poly_node *temp;

    temp=start;

    if (temp==NULL)

        printf("Empty polynomial\n");

    else

    {
        while(temp!=NULL)

        {
            printf("%d x^%d",temp->coef,temp->exp);

            temp=temp->link;

            if(temp!=NULL)

                printf(" + ");

            else

                printf("\n\n");

        }
    }
}

void add_poly(struct poly_node** p,struct poly_node **q,struct poly_node** start_r)

{
    int c,e;

    struct poly_node *pptr,*qptr;

    *start_r=NULL;

    pptr=*p;

    qptr=*q;

    while(pptr!=NULL && qptr!=NULL)

    {
        if (pptr->exp==qptr->exp)

        {

            c=pptr->coef+qptr->coef;

            e=pptr->exp;

            create_poly(start_r,c,e);

            pptr=pptr->link;

            qptr=qptr->link;

        }

        else

        {
            if (pptr->exp>qptr->exp)

            {
                c=pptr->coef;

                e=pptr->exp;

                create_poly(start_r,c,e);

                pptr=pptr->link;

            }

            else

            {
                c=qptr->coef;

                e=qptr->exp;

                create_poly(start_r,c,e);

                qptr=qptr->link;

            }
        }
    }

    while(pptr!=NULL)

    {

        c=pptr->coef;

        e=pptr->exp;

        create_poly(start_r,c,e);

        pptr=pptr->link;

    }

    while (qptr!=NULL)

    {

        c=qptr->coef;

        e=qptr->exp;

        create_poly(start_r,c,e);

        qptr=qptr->link;

    }
}


void multiply_poly(struct poly_node ** p,struct poly_node **q,struct poly_node** r)

{

    int c,e;

    struct poly_node *pptr,*qptr;

    *r=NULL;

    pptr=*p;

    qptr=*q;

    if (*p==NULL && *q==NULL)

        printf("\nMultiplication of polynomial is not possible!\n");

    else

    {
        while(pptr!=NULL)

        {

            qptr=*q;

            while(qptr!=NULL)

            {

                c=pptr->coef*qptr->coef;

                e=pptr->exp+qptr->exp;

                create_poly(r,c,e);

                qptr=qptr->link;

            }

            pptr=pptr->link;

        }
    }
}
