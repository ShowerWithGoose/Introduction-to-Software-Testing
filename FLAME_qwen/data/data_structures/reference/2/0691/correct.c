#include<stdio.h>
#include<string.h>
int i;
int main()
{
	char first[85];
	gets(first);
	int second[85];
	int l;
	for(i=0;i<strlen(first);i++)
	{
		if(first[i]>='0'&&first[i]<='9')
		{
			second[l]=first[i]-'0';
			l++;
		}
		else if(first[i]=='+')
		{
			second[l]=-1;
			l++;
		}
		else if(first[i]=='-')
		{
			second[l]=-2;
			l++;
		}
		else if(first[i]=='*')
		{
			second[l]=-3;
			l++;
		}
		else if(first[i]=='/')
		{
			second[l]=-4;
			l++;
		}
		else if(first[i]=='=')
		{
			second[l]=-5;
			l++;
		}
	}
	//for(i=0;i<l;i++) printf("%d ",second[i]);printf("\n");
	for(i=0;i<l;i++)
	{
		if(second[i]>=0&&second[i+1]>=0)
		{
			second[i+1]=10*second[i]+second[i+1];
			second[i]=-10;
		}
	}
	//for(i=0;i<l;i++) printf("%d ",second[i]);
    int third[85];
    int t=0;
    for(i=0;i<l;i++)
    {
    	if(second[i]!=-10&&second[i]!=-5)
    	{
    		third[t]=second[i];
    		t++;
		}
	}
	//for(i=0;i<t;i++) printf("%d ",third[i]);printf("\n");
	for(i=0;i<t;i++)
	{
			if(third[i]==-3)
			{
				third[i+1]=third[i-1]*third[i+1];
				third[i]=-10;
				third[i-1]=-10;
			}
		    if(third[i]==-4)
			{
				third[i+1]=third[i-1]/third[i+1];
				third[i]=-10;
				third[i-1]=-10;
			}
	}
	//for(i=0;i<t;i++) printf("%d ",third[i]);printf("\n");
    int fourth[85];
    int f=0;
    for(i=0;i<t;i++)
    {
    	if(third[i]!=-10)
    	{
    		fourth[f]=third[i];
    		f++;
		}
	}
	//for(i=0;i<f;i++) printf("%d ",fourth[i]);printf("\n");
	int sum=fourth[0];
	for(i=1;i<=(f/2);i++)
	{
		if(fourth[2*i-1]==-1)
		{
			sum+=fourth[2*i];
		}
		if(fourth[2*i-1]==-2){
			sum-=fourth[2*i];
		}
	}
	printf("%d",sum);
	return 0;
}


