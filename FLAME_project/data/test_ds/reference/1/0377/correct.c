#include<stdio.h>
#include<math.h>
#include<string.h>
char in[10000];
int i,flag=0,k=0;
int deci(char a,char b)
{
	if((a-'A')>=0 && (b-'A')<=26)
		return 1;
	else if((a-'a')>=0 && (b-'a')<=26)
		return 2;
	else if((a-'0')>=0 && (b-'9')<=9)
		return 3;
	else
		return 0;
}
int jud(char a,char b)
{
	if((b-a)>=1 && (b-a)<=26)
		return b-a;
	else
		return 0;
}

int main()
{
	gets(in);
	int num;
	num=strlen(in);
	int fla,j;
	char out;
	for(i=0; i<num; i++)
	{
		if(in[i+1]=='-')
		{
			fla=deci(in[i],in[i+2]);
			j=jud(in[i],in[i+2]);
			if(j)
			{	
				if(fla==1)
				{	flag=in[i]-'A';
					for(k=0; k<j; k++)
					{
						out='A'+flag;
						printf("%c",out);
						flag++;
					}
					i=i+1; 
				 } 
				 else if(fla==2)
				{	flag=in[i]-'a';
					for(k=0; k<j; k++)
					{
						out='a'+flag;
						printf("%c",out);
						flag++;
					}
					i=i+1; 
				 }
				 else if(fla==3 && j<=9)
				{	flag=in[i]-'0';
					for(k=0; k<j; k++)
					{
						out='0'+flag;
						printf("%c",out);
						flag++;
					}
					i=i+1; 
				 } 
				 else
					printf("%c",in[i]); 
			}
			else
			printf("%c",in[i]);
		}
		else
		printf("%c",in[i]);
	}
		return 0;
}



