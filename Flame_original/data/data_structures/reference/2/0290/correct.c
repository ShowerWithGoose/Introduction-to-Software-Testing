#include<stdio.h>
#include<string.h>
int main()
{
	char s[100010]= {},ch[100010]={};
	int a[100010]= {};
	char op[100010]= {};
	gets(ch);
	int m,n=0;
	for(m=0;m<strlen(ch);m++)
	{
		if(ch[m]==' ')
			continue;
		s[n++]=ch[m];
	}
	s[n]='\0';
	int shu=0;
	int fu=0;
	for(int i=0; s[i]!='\0'; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int num=1,cnt=0;
			for(int j=1; s[i+j]>='0'&&s[i+j]<='9'; j++)
				num++;
			for(int k=0; k<num; k++)
				cnt=cnt*10+s[i+k]-'0';
			a[shu]=cnt;
			shu++;
			i+=num-1;
		}
		else
		{
			op[fu]=s[i];
			fu++;
		}
	}
	char jj[100010]={};
	int shuzu[100010]={};
	int k=0,o=0;
	for(int i=0; op[i]; i++)
	{
		if(op[i]=='+'||op[i]=='-')
		{
			jj[k++]=op[i];
			shuzu[o++]=a[i];
		}
		else
		{
			int num=a[i];
			int j;
			for(j=0;op[i+j]!='+'&&op[i+j]!='-';j++)
			{
				if(op[i+j]=='*')
					num*=a[i+j+1];
				else if(op[i+j]=='/')
					num/=a[i+j+1];
				else if(op[i+j] == '=')
					break;
			}
			shuzu[o++]=num;
			jj[k++]=op[i+j];
			i+=j;
		}
	}
	int zui=shuzu[0];
	for(int i=0;jj[i]!='=';i++)
	{
		if(jj[i]=='+')
			zui+=shuzu[i+1];
		else if(jj[i]=='-')
			zui-=shuzu[i+1];
	}
	printf("%d",zui);
	return 0;
}

