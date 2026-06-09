#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000],c[1000];
	int d,e,f=-1,g,h,i=0,j=0,k,l,m,n;
	gets(a);
	d=strlen(a);
	for(e=0;e<d;e++)
	{
		if(a[e]=='.')
		{
			f=e;
		}
	}
	if(a[0]=='-')
	{
		
	}
	else
	{
		if(a[0]=='0')
		{
			for(g=0,j=0;g<d;g++)
			{
				if(a[g]=='0')
				{
					h=g;
				}
				else
				{
					i++;
				}
			}
			for(j=2;a[j]=='0';j++)
			{
			}
			j=j-1;
			if(h!=0)
			{
				h=j;
			}
			
			//printf("%d\n%d\n",j,h);
			if(h==0)
			{
				if(i==2)
				{
					printf("%ce-1\n",a[2]);
				}
				else
				{
					printf("%c.",a[2]);
					for(k=3;k<d;k++)
					{
						printf("%c",a[k]);
					}
					printf("e%d\n",-1);
				}
			}
			else
			{
				if(i==2)
				{
					printf("%ce%d\n",a[d-1],-d+f+1);
				}
				else
				{
					printf("%c.",a[h+1]);
					for(k=h+2;k<d;k++)
					{
						printf("%c",a[k]);
					}
					printf("e%d\n",-h);
				}
			}
		}
		else
		{
			if(f==-1)
			{
				for(h=d-1;a[h]=='0';h--)
				{
				}
				//printf("%d",h);
				printf("%c.",a[0]);
				for(g=1;g<=h;g++)
				{
					printf("%c",a[g]);
				}
				printf("e%d\n",d-1);
			}
			else
			{
				printf("%c.",a[0]);
				for(h=1;h<d;h++)
				{
					if(h==f)
					{
						continue;
					}
					printf("%c",a[h]);
				}
				printf("e%d\n",f-1);
			}			
		}
		
	}
	
	
	
	//printf("%d",i);
		return 0;
}


