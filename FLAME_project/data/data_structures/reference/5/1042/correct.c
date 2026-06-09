#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct multinomial
{
    int coefficient;
    int index;
    struct multinomial *next;
};
int main()
{
	char c;
    int coe,ind,i,j,num1=0,num2=0,ind_mid,flag=0,flag_first=1,flag1=0;
    long long int ind_min=9999999999;
    struct multinomial *first_1=NULL,*first_2=NULL,*first_ans,*tail_1,*tail_2,*tail_ans,*q_1,*q_2,*q_ans,*q_ans_pre,*q_now;
    do
    {
        scanf("%d%d%c",&coe,&ind,&c);
        q_1=(struct multinomial *)malloc(sizeof(struct multinomial));
        q_1->coefficient=coe;
        q_1->index=ind;
        q_1->next=NULL;
        if(first_1==NULL)
            first_1=tail_1=q_1;
        else
        {
            tail_1->next=q_1;
            tail_1=tail_1->next;
        }        
        num1++;
        if(ind==0)  break;
    }while(c!='\n');
    do
    {
        scanf("%d%d%c",&coe,&ind,&c);
        q_2=(struct multinomial *)malloc(sizeof(struct multinomial));
        q_2->coefficient=coe;
        q_2->index=ind;
        q_2->next=NULL;
        if(first_2==NULL)
            first_2=tail_2=q_2;
        else
        {
            tail_2->next=q_2;
            tail_2=tail_2->next;
        }
        num2++;
        if(ind==0)  break;
    }while(c!='\n');
    q_1=first_1; q_2=first_2;//store 2 multinomial
    first_ans=q_ans=q_ans_pre=tail_ans=NULL;
    for(i=0;i<num1;i++)
    {
        for(j=0;j<num2;j++)
        {
            flag=0; flag1=0;
            if(first_ans==NULL)
            {
                q_ans=(struct multinomial *)malloc(sizeof(struct multinomial));
                q_ans->coefficient=q_1->coefficient*q_2->coefficient;
                q_ans->index=q_1->index+q_2->index;
                q_ans->next=NULL;
                if(q_ans->index<=ind_min)	ind_min=q_ans->index;
                first_ans=tail_ans=q_ans;
                q_2=q_2->next;
            }
            else if(first_ans->next==NULL)
            {
                q_now=(struct multinomial *)malloc(sizeof(struct multinomial));
                q_now->coefficient=q_1->coefficient*q_2->coefficient;
                q_now->index=q_1->index+q_2->index;
                q_now->next=NULL;
                if(q_now->index<=ind_min)	ind_min=q_now->index;
                if(q_2!=NULL)   q_2=q_2->next;
                else{
                    q_1=q_1->next;
                    flag_first=0;
                }
                first_ans->next=q_now;
                q_ans=first_ans;
            }
            else
            {
                ind_mid=q_1->index+q_2->index;
                if(ind_mid<=ind_min) ind_min=ind_mid;
                q_ans=first_ans;
                while(q_ans->index!=ind_mid)
                {
                	if(q_ans->next==NULL)
                	{
                		flag++; break;
					}
                    if(q_ans->index==ind_min){
                        flag++; break;}//flag remember to set 0
                    q_ans=q_ans->next;
                }
                if(flag==0)
                    q_ans->coefficient+=q_1->coefficient*q_2->coefficient;
                else
                {
                    q_now=(struct multinomial *)malloc(sizeof(struct multinomial));
                    q_now->coefficient=q_1->coefficient*q_2->coefficient;
                    q_now->index=q_1->index+q_2->index;
                    q_now->next=NULL;
                    q_ans=first_ans;
                    while(q_ans->index>ind_mid) 
                    {
                        q_ans_pre=q_ans;
                        q_ans=q_ans->next;
                        if(q_ans->next==NULL&&q_ans->index>ind_mid){
                        	flag1++; break;
						}
                    }
                    if(flag1==0){
	                    q_now->next=q_ans;
	                    q_ans_pre->next=q_now;}
                    else{
                    	q_ans->next=q_now;
					}
                }
                q_2=q_2->next;
                flag_first++;
            }
        }
        q_2=first_2;
        if(flag_first!=0)   q_1=q_1->next;
    }
    if(q_ans->next!=NULL)	q_ans=q_ans->next;
    q_now=(struct multinomial *)malloc(sizeof(struct multinomial));
    q_now->coefficient=1;
    q_now->index=-1;
    q_now->next=NULL;
    q_ans->next=q_now;
    q_ans=q_ans_pre=first_ans;
    if(q_ans->index==0)
    {
        q_ans_pre=q_ans;
        q_ans=q_ans->next;
        free(q_ans_pre);
    }
    else
    {
        q_ans=q_ans->next;
        while(q_ans->index>=ind_min)
        {
            if(q_ans->coefficient==0)
            {
                q_ans_pre->next=q_ans->next;
                free(q_ans);
            }
            else q_ans_pre=q_ans;
            q_ans=q_ans->next;
        }
    }
    q_ans=first_ans;
    while(q_ans->index>=ind_min)
    {
        printf("%d %d ",q_ans->coefficient,q_ans->index);
        q_ans=q_ans->next;
    }
    return 0;
}
