#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct nev{
	int r1,r2;
	struct nev *next;
};
typedef struct nev *TRUE;
typedef struct nev tru;
TRUE getint(char s[],int l,int x)
{
	TRUE first[2],tail=NULL,kin;
	first[0]=NULL;
	first[1]=NULL;
	int i,j=0,k[100]={0};
	for(i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			k[j]=k[j]*10+(s[i]-'0');
		else
			j++;
	}
	for(i=0;i<j;i++)
	{
		kin=(TRUE)malloc(sizeof(tru));
		kin->r1=k[i++];
		kin->r2=k[i];
		kin->next=NULL;
		if(first[x]==NULL)
		{
		first[x]=kin;
		tail=kin;}
		else 
		{
			tail->next=kin;
			tail=tail->next;
		}
	}
	return first[x];
}
int main()
{
	TRUE firstt=NULL,tail,pre,kins1=NULL,kins2=NULL,first1=NULL,first2=NULL,jud1=NULL,jud2=NULL;
	char a1[1000],a2[1000];
	int l1,l2,mi,ma;
	gets(a1);
	l1=strlen(a1);
	gets(a2);
	l2=strlen(a2);
	first1=getint(a1,l1,0);
	first2=getint(a2,l2,1);	
	pre=first1;
	while(pre!=NULL)
	{
		tail=first2;
		while(tail!=NULL){
		mi=(pre->r1)*(tail->r1);
		ma=(pre->r2)+(tail->r2);
		kins1=(TRUE)malloc(sizeof(tru));
		kins1->next=NULL;
	    kins1->r1=mi;  kins1->r2=ma;mi=0,ma=0;
		if(firstt==NULL)
		{
		    jud1=firstt=kins1;
			firstt->next=NULL;
		}
		else {jud1->next=kins1;
		jud1=jud1->next;
	}tail=tail->next;
	}
	kins2=pre;
	pre=pre->next;
	free(kins2);
	}
	pre=firstt;
	while(pre!=NULL){
	    kins1=pre;
		tail=pre->next;
		while(tail!=NULL){
			if((tail->r2)==(pre->r2))
			{
				pre->r1=(pre->r1)+(tail->r1);
				kins2=tail;
				kins1->next=tail->next;
				tail=tail->next;
				free(kins2);
			}
			else {kins1=tail;
			tail=tail->next;}
		}
		pre=pre->next;
	}
	while(firstt!=NULL)
	{
		pre=firstt;tail=firstt->next;jud1=NULL;jud2=firstt;
		mi=pre->r1;ma=pre->r2;
		while(tail!=NULL)
		{
			if((tail->r2)>ma)
			{mi=tail->r1;ma=tail->r2;
			jud1=tail;kins1=jud2;
			}
			jud2=tail;
			tail=tail->next;
		}
		printf("%d %d ",mi,ma);
		if(jud1==NULL){firstt=firstt->next;free(pre);
		}else{
		kins1->next=jud1->next;
		free(jud1);}
	}
	while(first2!=NULL)
	{
		pre=first2;
		first2=first2->next;
		free(pre);
	}
	return 0;
}

