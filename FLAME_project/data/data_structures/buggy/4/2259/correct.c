#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[1000],ch0[1000];
char str[1000][1000],str_temp[1000][1000];
int str_num[1000];
void swap(char *x,char *y)
{
	char temp[100];
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
}
void swap_num(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    int num1=0,num2=0;
    while((fgets(ch,10000,in))!=NULL)//∂¡“ª–– 
    {
    	int t1=0,t2;
    	int len = strlen(ch);
    	for(int i=0;i<len;i++)
    	{
    		if(ch[i]>='A'&&ch[i]<='Z')
                ch[i]=ch[i]+32;
			else if(ch[i]>='a'&&ch[i]<='z')
                continue;
            else
            {
            	t2=i;
            	int k=0;
            	if(num1!=0)
            	for(int j=t1+1;j<t2;j++)
				{
					str_temp[num1][k]=ch[j];
					k++;
				}
				else
				for(int j=t1;j<t2;j++)
				{
					str_temp[num1][k]=ch[j];
					k++;
				}
				num1++;
				t1=t2;
			}
		}
		for(int i=0;i<num1;i++)
		{
			int judge=0;
			for(int j=0;j<num2;j++)
			{
				if(strcmp(str[j],str_temp[i])==0)
				{
					judge=1;
					str_num[j]++;
				}
				else
					continue;
			}
			if(judge==1)
			{
				continue;
			}
			else
			{
				strcpy(str[num2],str_temp[i]);
				num2++;
			}
		}
		for(int i=0;i<num1;i++)
		{
			int len0=strlen(str_temp[i]);
			for(int j=0;j<len0;j++)
			str_temp[i][j]='\0';
		}
		strcpy(ch,ch0);
		num1=0;
	}
    for(int i=0;i<num2;i++)
    {     
	  	for(int j=0;j<num2;j++)
       	if(strcmp(str[i],str[j])<0)
       	{
       		swap(str[i],str[j]);
       		swap_num(&str_num[i],&str_num[j]);
		}
	}
   	for(int i = 0; i<num2; i++)
    {
    	if(str[i][0]>='a'&&str[i][0]<='z')
        printf("%s %d\n",str[i],str_num[i]+1);
    }
    return 0;
}

