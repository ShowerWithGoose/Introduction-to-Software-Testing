#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	int coefficient;
	int index;

};
struct Node list1[50];
struct Node list2[50];
struct Node list3[100];
struct Node list4[100];
int cmp(const void*a,const void*b)
{
	struct Node*a1=(struct Node*)a;
	struct Node*b1=(struct Node*)b;
	return((b1->index)-(a1->index));
}



int main()
{
	char s1[200];
	char s2[200];
	gets(s1);
	gets(s2);
	char *p,*q;
	q=s1;
	int i=0;
	while((p=strchr(q,' '))!=NULL)
	{
		*p='\0';
		list1[i].coefficient=atoi(q);
		q=p+1;
		if((p=strchr(q,' '))==NULL)
			break;
		p=strchr(q,' ');
		*p='\0';
		list1[i].index=atoi(q);
		q=p+1;
//		printf("%d %d \n",list1[i].coefficient,list1[i].index);
		i++;
	}
	list1[i].index=atoi(q);
	
	q=s2;
	int j=0;
	while((p=strchr(q,' '))!=NULL)
	{
		*p='\0';
		list2[j].coefficient=atoi(q);
		q=p+1;
		if((p=strchr(q,' '))==NULL)
			break;
		p=strchr(q,' ');
		*p='\0';
		list2[j].index=atoi(q);
		q=p+1;
		j++;
	}
	list2[j].index=atoi(q);
	
//	int n1;
//	for(n1=0;n1<=i;n1++)
//	printf("%d %d ",list1[n1].coefficient,list1[n1].index);
//	printf("\n");
//
//	for(n1=0;n1<=j;n1++)
//	printf("%d %d ",list2[n1].coefficient,list2[n1].index);
//	printf("\n");


	int m,n,k=0;
	for(m=0;m<=i;m++)
	{
		for(n=0;n<=j;n++)
		{
			list3[k].coefficient=list1[m].coefficient * list2[n].coefficient;
			list3[k].index=list1[m].index+list2[n].index;
			k++;
		 } 
	}
	
	
//	int t;
//	for(t=0;t<k;t++)
//	printf("%d %d ",list3[t].coefficient,list3[t].index);
//	printf("\n");
	
	qsort(list3,k,sizeof(list3[0]),cmp);
	
//	int t1;
//	for(t1=0;t1<k;t1++)
//	printf("%d %d ",list3[t1].coefficient,list3[t1].index);
//	printf("\n");
	
	int first,last,num=0,sum=k;
	for(first=0;first<k;)
	{
		if(list3[first].index==list3[first+1].index)
		{
			for(last=first+1;list3[first].index==list3[last].index;last++)
			{
				list3[first].coefficient+=list3[last].coefficient;
				
			}
			list4[num]=list3[first];
			num++;
			first=last;
		}
		else
		{
			list4[num]=list3[first];
			num++;
			first++;
		}
		printf("%d %d ",list4[num-1].coefficient,list4[num-1].index);
	}
	
//	int t;
//	for(t=0;t<num;t++)
//	printf("%d %d ",list4[t].coefficient,list4[t].index);
	return 0;
}



