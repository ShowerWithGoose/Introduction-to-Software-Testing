#include<stdio.h>
#include<string.h>
#include<math.h>
void squeez(char s[],char c)
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
		s[j++]=s[i];
	}
	s[j]='\0';
}
int main()
{
	int array[100]={};
	int numfuhao,num;
	int i,j,k,l,sum=0,a;
	char s[200],fuhao[100],c=' ';
	gets(s);
	squeez(s,c);
	
	
	for(i=0,j=0,k=0,l=0;s[i]!='\0';i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		fuhao[j++]=s[i];
		else if(s[i]>='0'&&s[i]<='9'&&!(s[i+1]>='0'&&s[i+1]<='9'))
		{
			for(l=0;s[i-l]>='0'&&s[i-l]<='9'&&l<=i;l++)
			array[k]+=(s[i-l]-'0')*pow(10,l);
			k++;
		}
	}
	numfuhao=j,num=k;
//	for(i=0;i<num;i++)
//	printf("%d\n",array[i]);
//	for(i=0;i<numfuhao;i++)
//	printf("%c\n",fuhao[i]);//debugÓÃ£¬¼ì²éÎÞÎó
	for(i=0;i<numfuhao;i++)
	{
		if(fuhao[i]=='-')
		array[i+1]*=-1;
	}
	for(i=0,a=0;i<numfuhao;i++)
	{
		if(fuhao[i]=='*'||fuhao[i]=='/')
		{
				a=array[i];
			for(j=i;fuhao[j]=='*'||fuhao[j]=='/';j++)
			{
				if(fuhao[j]=='*')
				a*=array[j+1];
				else if(fuhao[j]=='/')
				a/=array[j+1];
				array[j]=0;
				
			}
			array[j]=a;
			i=j-1;
			a=0;
		}
	 } 
//	 printf("%d",num);
	 for(i=0;i<num;i++)
	 {
	 	sum+=array[i];
	 }
	 printf("%d\n",sum);
	return 0;
}

