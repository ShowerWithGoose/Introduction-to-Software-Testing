#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i,j=0;
	gets(a);
	int len=strlen(a);
	int bit;
	if(a[0]=='0')
	{
		for(i=2;a[i]=='0';i++);
    	if(i+1==len)
        printf("%ce-%d\n",a[i],len-2);
		else
		{
			bit=i-1;
			int k=i;
			b[0]=a[i++];
			b[1]='.';
			for(j=2;a[i]!='\0';i++,j++)
			{
				b[j]=a[i];
			}
			for(j=0;j<len-k+1;j++)
			{
				printf("%c",b[j]);
			}
			printf("e-%d",bit);
			
		}		
	}
	else if(a[1]=='.')
	{
		a[len]='e';
		a[len+1]='0';
		puts(a);
	}
	else
	{
		for(bit=0;a[bit]!='.';bit++);
		bit--;
		b[0]=a[0];
		b[1]='.';
		printf("%c%c",b[0],'.');
		for(j=2,i=1;a[i]!='\0';j++,i++)
		{
			if(a[i]=='.')
			i++;
			b[j]=a[i];
			printf("%c",b[j]);
		}
		printf("e%d",bit);		
	}
	return 0;	
}

