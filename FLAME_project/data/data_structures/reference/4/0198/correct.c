#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
struct w{
	char i[MAX];
	int x;
	int m;
}word[1000];
int main()
{
	FILE *fp1;int s,n,num1,num2;
	num1=0;num2=0;
	struct w al;
	fp1=fopen("article.txt","r");
	char p[MAX];
	while(!feof(fp1))
	{
		fgets(p,MAX,fp1);n=0;
		for(s=0;s<strlen(p);s++)
		{
			if(p[s]>='a'&&p[s]<='z')
			{
				word[num1].i[n]=p[s];
				word[num1].x=num2;word[num1].m=1;
				n++;
				if((p[s+1]<'a'&&p[s+1]>'Z')||p[s+1]<'A'||p[s+1]>'z')
				{
					num1++;n=0;
				}
			}
			else if(p[s]>='A'&&p[s]<='Z')
			{
				word[num1].i[n]=p[s]+'a'-'A';
				word[num1].x=num2;word[num1].m=1;
				n++;
				if((p[s+1]<'a'&&p[s+1]>'Z')||p[s+1]<'A'||p[s+1]>'z')
				{
					num1++;n=0;
				}
			}
		}
		num2++;
	} 
	int d,t,f;
	for(d=num1-1;d>=0;d--)
	{
		for(t=0;t<d;t++)
		{
			f=0;
			if(word[num1].x!=num2-1)
			{
				while(word[t].i[f]==word[t+1].i[f]&&f<strlen(word[t].i))
			    {
			    	f++;
			    }
			    if(word[t].i[f]>word[t+1].i[f]&&f!=strlen(word[t].i))
			    {
				    al=word[t];
				    word[t]=word[t+1];
				    word[t+1]=al;
			    }
			}
		}
	}
	int ll;
	for(d=0;d<num1;d+=ll)
	{
		if(word[d].x!=num2-1)
		{
			ll=1;
			while(strcmp(word[d].i,word[d+ll].i)==0&&d+ll<=num1&&word[d+ll].x!=num2-1)
		    {
			    word[d].m++;
			    word[d+ll].m=0;
		    	ll++;
		    }
		}
	}
	for(d=0;d<num1;d++)
	{
		if(word[d].x!=num2-1&&word[d].m!=0)
		{
			printf("%s %d\n",word[d].i,word[d].m);
		}
	}	
	return 0;
}

