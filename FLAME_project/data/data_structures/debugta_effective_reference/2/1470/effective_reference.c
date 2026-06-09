#include<stdio.h>
#include<string.h>

int main()
{
    char s[800],t[800]={0},fu[800]={0};
    int ls,lt,i,j=0,h=0,o=0,p=0;
    int a,b,re=0,zui=0;
    int num[800]={0};
    int zuihou[800]={0};
    char zuihou2[800]={0};
    char r[800]={0};
    gets(s);
    ls=strlen(s);
    for(i=0;i<=ls;i++)
    {
        if(s[i]!=' ')
        {t[j]=s[i];j++;}
		else continue; 
    }
//	for(j=0;t[j]!='\0';j++)
//	{
//		printf("%c",t[j]);
//	}
	lt=strlen(t);
    for(j=0;j<=lt;j++)
    {
    	if(t[j]>='0'&&t[j]<='9')
    	{
			r[h]=t[j];
			h++;
		}
		else
		{
		fu[p]=t[j];
		p++;
		r[h]='f';
		h++;
		}
	}
//	for(h=0;r[h]!='\0';h++)
//	{
//		printf("%c",r[h]);
//	}
//	for(p=0;fu[p]!='\0';p++)
//	{
//		printf("%c",fu[p]);
//	}
//bian:
	h=0;
	for(;r[h]!='f';h++)
	{
		num[o]=num[o]*10+r[h]-'0';
	
		
		if(r[h+1]=='f')
		{
			h++;
			o++;
			continue;
		}
		else continue;
	}
//	goto bian;
//	for(o=0;num[o]!='\0';o++)
//	{
//		printf("%d ",num[o]);
//	}
//	printf("\n");
//	for(p=0;fu[p]!='\0';p++)
//	{
//		printf("%c",fu[p]);
//	}
	for(p=0;fu[p]!='\0';p++)
	{
		if(fu[p]=='*')
		{
			num[p+1]=num[p]*num[p+1];
			num[p]=0;
		}
		if(fu[p]=='/')
		{
			num[p+1]=num[p]/num[p+1];
			num[p]=0;
		}
	}
//	for(p=0;fu[p]!='\0';p++)
//	{
//		printf("%d ",num[p]);
//	}
	for(p=0;fu[p]!='\0';p++)
	{
		if(num[p]!=0)
		{
			zuihou[zui]=num[p];
			zui++;
		}
		else continue;
		
	}
	zui=0;
	for(p=0;fu[p]!='\0';p++)
	{
		if(fu[p]!='*'&&fu[p]!='/')
		{
			zuihou2[zui]=fu[p];
			zui++;
		}
		else continue;
		
	}
//	for(i=0;i<zui;i++)
//	{
//		printf("%d ",zuihou[i]);
//	}
//	for(p=0;zuihou2[p]!='\0';p++)
//	{
//		printf("%c",zuihou2[p]);
//	}
	re=re+zuihou[0];
//	printf("%d",re);
	for(p=0;zuihou2[p]!='\0';p++)
	{
		if(zuihou2[p]=='+')
		{
//			printf("%d",p);
			re=re+zuihou[p+1];
		}
		if(zuihou2[p]=='-')
		{
//			printf("%d",p);
			re=re-zuihou[p+1];
		}
	}
    printf("%d",re);


    return 0;
}



