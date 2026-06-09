#include <stdio.h>
#include <string.h>
int IsAlpha(char x)
{
	if((x<='Z'&&x>='A')||(x<='z'&&x>='a'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char shift(char x)
{
	if(x<='Z'&&x>='A')
	{
		return x-'Z'+'z';
	}
	else
	{
		return x;
	}
}
int main()
{
	struct ttl{
		char w[25];
		int num;
	};
	FILE *in;
	int n,m,l,p,q,t=0,s=0;
	in=fopen("article.txt","r");
	char str[1024],now[25];
	struct ttl total[1000];
	while(fgets(str,1024,in)!=NULL)
	{
		n=0;
		m=0;
		p=0;
		l=strlen(str);
		while(n<l)
		{
			if(IsAlpha(shift(str[n]))==1)
			{
				m=1;
				now[p]=shift(str[n]);
				p++;
			}
			else if(m==1)
			{
				m=0;
				p=0;
				q=0;
				s=0;
				while(q<t||t==0)
				{
					if(t==0)
					{
						strcpy(total[t].w,now);
						total[t].num=1;
						t++;
						s=1;
						break;
					}
					else
					{
						if(strcmp(total[q].w,now)==0)
						{
							total[q].num=total[q].num+1;
							s=1;
							break;
						}
					}
					q++;
				}
				if(s==0)
				{
					strcpy(total[t].w,now);
					total[t].num=1;
					t++;
				}
				memset(now,'\0',25);
			}
			n++;
		}
	}
	ret:
	n=0;
	s=0;
	while(n<t-1)
	{
		if(strcmp(total[n].w,total[n+1].w)>0)
		{
			total[1000]=total[n+1];
			total[n+1]=total[n];
			total[n]=total[1000];
			s=1;
		}
		n++;
	}
	if(s==1)
	{
		goto ret;
	}
	n=0;
	while(n<t)
	{
		printf("%s %d\n",total[n].w,total[n].num);
		n++;
	}
	return 0;
} 

