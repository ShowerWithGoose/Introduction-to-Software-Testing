#include<stdio.h>
#include<string.h>
int k,fnum,lnum;
char ch[101];
int main()
{
	gets(ch);
	int len=strlen(ch);
	if(len==1&&ch[0]=='0')
	{
		printf("0e0");
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		if(ch[i]=='.')
			k=i;	
	}
	for(int i=0;ch[i]<='0'||ch[i]>'9';i++)
			fnum=i;
	for(lnum =len-1;ch[lnum]=='0';lnum--)
			lnum--;
	if(k==0)
	{	
		if(fnum==lnum)
			printf("%ce%d",ch[fnum],len-fnum-1);
		else
			{
			printf("%c.",ch[fnum]);	
			for(int i=fnum+1;i<=lnum;i++)
			{
				printf("%c",ch[i]);
			}
			printf("e%d",len-fnum-1);
			}
			
	}
	else
	{
		fnum++;
		if(fnum>k)
		{
			if(fnum==lnum)
				printf("%ce%d",ch[fnum],k-lnum);
			else
				{
					printf("%c.",ch[fnum]);
					for(int i=fnum+1;i<=lnum;i++)
					{
						printf("%c",ch[i]);
					}
					printf("e%d",k-fnum);
				}
		}
		else
		{
			fnum--;
			printf("%c.",ch[fnum]);
			for(int i=fnum+1;i<k;i++)
				printf("%c",ch[i]);
			for(int i=k+1;i<=lnum;i++)
				printf("%c",ch[i]);
			printf("e%d",k-fnum-1);
		}
	}
}


