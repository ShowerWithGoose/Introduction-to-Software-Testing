#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    long long num;
    long long pow;
    struct node *link;
};
struct node *list,*p,*q,*start,tem[1000],res[1000];
int a,b,i,j;
long long e,f,c,d;
int main(int argc, char const *argv[])
{
    char s[1000],s1[1000];

    list=p=(struct node*)malloc(sizeof(struct node));
    start=q=(struct node*)malloc(sizeof(struct node));
    gets(s);
    gets(s1);
    long long flag=0,sum=0;;
    for(i=0;i<=strlen(s);i++)
    {
        
        if(s[i]>='0'&&s[i]<='9')
		{
			sum=10*sum+s[i]-'0';
		}
        if(!(s[i+1] >='0'&&s[i+1]<='9'))
		{
			if(flag==0&&sum!=0)
			{
				p->num=sum;
				sum = 0;
				flag = 1;
				continue;
			}
			else if(flag==1)
			{
				p->pow=sum;
				sum=0;
				flag=0;
                p->link=(struct node*)malloc(sizeof(struct node));
                p=p->link;
				continue;
			}
		}
    }
    p->link=NULL; 
    for(i=0;i<=strlen(s1);i++)
    {
        
        if(s1[i]>='0'&&s1[i]<='9')
		{
			sum=10*sum+s1[i]-'0';
		}
        if(!(s1[i+1] >='0'&&s1[i+1]<='9'))
		{
			if(flag==0&&sum!=0)
			{
				q->num=sum;
				sum = 0;
				flag = 1;
				continue;
			}
			else if(flag==1)
			{
				q->pow=sum;
				sum=0;
				flag=0;
                q->link=(struct node*)malloc(sizeof(struct node));
                q=q->link;
				continue;
			}
		}
    }
    q->link=NULL;
    p=list;
    int mark=0;
    i=0,j=0;
    while(p->link!=NULL)
    {
        q=start;
        while(q->link!=NULL)
        {
            e=p->num;
            f=q->num;
            tem[i].num=e*f;
            e=p->pow;
            f=q->pow;
            tem[i].pow=e+f;
            q=q->link; 
            i++;   
        }
        p=p->link;
    }
    int k=i;
    long long middle;
    for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			if(tem[j].pow <= tem[j+1].pow)
			{
				middle = tem[j+1].num;
				tem[j+1].num = tem[j].num;
				tem[j].num = middle;
				
				middle = tem[j+1].pow;
				tem[j+1].pow = tem[j].pow;
				tem[j].pow = middle;
				
			}
		}
	}
    res[0].num = tem[0].num;
	res[0].pow = tem[0].pow;
    j=0;
	for(i=1;i<k;i++)
	{	
		if(tem[i].pow == res[j].pow)
			res[j].num += tem[i].num;
		else {
			res[++j].num = tem[i].num;
			res[j].pow = tem[i].pow;
		}
	}
    for(i=0;i<=j;i++)
	{	
		printf("%lld %lld ",res[i].num,res[i].pow);
	}
    return 0;
}

