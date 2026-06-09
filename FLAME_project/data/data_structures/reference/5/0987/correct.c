#include<stdio.h>
#include<stdlib.h>

struct str{
	int fro;
	int mi;
	
}a[500],b[500],sc[500],po[500];

int cmp(const void* a,const void* b)
{
	struct str *aa=(struct str*)a;
	struct str *bb=(struct str*)b;
	return ((bb->mi)-(aa->mi)); 
}

int main()
{
	int n1,n2;
	int kl=0;
	char c,bv;
	int fg,mg;
	
	while(scanf("%d%c%d%c",&a[kl].fro,&bv,&a[kl].mi,&c)!=EOF)
	{
		kl++;
		if(c=='\n')	break;
	}
	fg=kl;
	kl=0;
	
	while(scanf("%d%d",&b[kl].fro,&b[kl].mi)!=EOF)
	{
		kl++;
	}
	mg=kl;
	int m=0;
	
	for(int i=0;i<fg;i++)
	{
		for(int j=0;j<mg;j++)
		{
			sc[m].fro=a[i].fro*b[j].fro;
			sc[m].mi=a[i].mi+b[j].mi;
			m++;
		}
	}
	qsort(sc,m,sizeof(sc[0]),cmp);
//	for(int rew=0;rew<m;rew++)
//	{
//		printf("%d %d\n",sc[rew].fro,sc[rew].mi);
//	}
	int yet=0;
	int k=0;
	while(k<m-1)
	{
		if(sc[k].mi==sc[k+1].mi)
		{
			po[yet].mi=sc[k].mi;
			po[yet].fro=sc[k].fro;
			while(sc[k].mi==sc[k+1].mi)
			{
				po[yet].fro+=sc[k+1].fro;
				k++;
			}
			yet++;
			k++;
		}
		else{
			po[yet].mi=sc[k].mi;
			po[yet].fro=sc[k].fro;
			k++;
			yet++;
		}
	}
	if(sc[k].mi!=sc[k-1].mi)
	{
		po[yet].mi=sc[k].mi;
		po[yet].fro=sc[k].fro;
		k++;
		yet++;
	}
	for(int re=0;re<yet;re++)
	{
		printf("%d %d ",po[re].fro,po[re].mi);
	}
	
	
	return 0;
 } 

