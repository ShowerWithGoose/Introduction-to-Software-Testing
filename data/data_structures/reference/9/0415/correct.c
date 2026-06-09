#include <stdio.h>
int homo[10001][3];
int moca[10001][3];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d%d",&homo[i][1],&homo[i][2],&moca[i][1],&moca[i][2]);
	int sta,rt,shuo,bao,leng=0,len=0;
	int ma,x;
	for(int i=1;i<=n;i++)
	{
		sta=homo[i][1],rt=homo[i][2];
		shuo=moca[i][1],bao=moca[i][2];
		len=1;
		for(int s=1;s<=n;s++)
		{
			if((shuo==homo[s][1])&&(bao==homo[s][2]))
			{
				len++;
				shuo=moca[s][1];
				bao=moca[s][2];
				s=0;
			}
			if(len>leng)
			{
				leng=len;
				ma=sta;
				x=rt;
			}
		}
	}
	printf("%d %d %d",leng,ma,x);
}

