#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct words{
	char w[50];
	int number;
}word;
word a[1000000];
char t[50];
int main()
{
	freopen("article.txt","r",stdin);
	int temp=getchar(),sum=0,k,j;
	while(temp!=EOF)
	{
		int cnt=0,flag=0;
		while(temp>='A'&&temp<='Z'||temp>='a'&&temp<='z')
		{
			if(temp>='A'&&temp<='Z')
				t[cnt++]=temp-'A'+'a';
			else
				t[cnt++]=temp;
			temp=getchar();
			flag=1;			
		}
		if(flag)
		{
			for(k=0;k<sum;k++)
			{
				if(strcmp(t,a[k].w)==0)
				{
					a[k].number++;
					break;
				}	
				else if(strcmp(t,a[k].w)<0)
				{
					for(j=sum-1;j>=k;j--)
						a[j+1]=a[j];
					strcpy(a[k].w,t);
					a[k].number=1;
					sum++;
					break;
				}
			}	
			if(k==sum)
			{
				a[sum].number=1;
				strcpy(a[sum].w,t);
				sum++;
			}
			for(k=0;k<50;k++)
				t[k]=0;			
		}
		temp=getchar();
	}
	for(j=0;j<sum;j++)
		printf("%s %d\n",a[j].w,a[j].number);
	return 0;
}

