#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
void separate(int n)
{
	int i=1;
	if(n<10000)
	{
		while(i<=1000)
		{
			printf("%d ",n*i/1000);
			n=n%(1000/i);i*=10;
		}
		printf("\n");
	}
		if(n>=10000)
	{
		while(i<=10000)
		{
			printf("%d ",n*i/10000);
			n=n%(10000/i);i*=10;
		}
		printf("\n");
	}
}
int main()
{
	int m;
	int c[130],i=0;
	scanf("%d",&m);
	if(m==5){
		for(int w=1;w<=5;w++)
		{
			for(int q=1;q<=5;q++)
			{
				if(q==w) continue;
				for(int b=1;b<=5;b++)
				{
					if(b==q||b==w) continue;
					for(int s=1;s<=5;s++)
					{
						if(s==w||s==q||s==b) continue;
						for(int g=1;g<=5;g++)
						{
							if(g==w||g==q||g==b||g==s) continue;
							c[i]=w*10000+q*1000+b*100+s*10+g;i++;
						}
					}
				}
			}
		}
	
	 for(int n=0;n<120;n++)
	 {
	 	separate(c[n]);
	 }
	 }
	
	 else if(m==4)
	 { 
	 i=0;
	 	for(int q=1;q<=4;q++)
			{
				for(int b=1;b<=4;b++)
				{
					if(b==q) continue;
					for(int s=1;s<=4;s++)
					{
						if(s==q||s==b) continue;
						for(int g=1;g<=4;g++)
						{
							if(g==q||g==b||g==s) continue;
							c[i]=q*1000+b*100+s*10+g;i++;
						}
					}
				}
			}
			for(int n=0;n<24;n++)
			{
				separate(c[n]);
			}
	 }
	 else if(m==3)
	 {
	 	printf("1 2 3\n\
1 3 2\n\
2 1 3\n\
2 3 1\n\
3 1 2\n\
3 2 1\n");
	 }
	else if(m==2)
	{
		printf("1 2\n\
2 1\n");
	}
	else if(m==1)
	{
		printf("1");
	}

}


