 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>
 char s[10000]; 
 int shu[10000];
 char fuhao[10000];
 int main()
 {
 	int len,i,k,op=0,t;
 	fgets(s,10000,stdin);
 	len=strlen(s);
 	for(i=0;i<=len;i++)
 	{
 		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			fuhao[op]=s[i];
			op++;
		}
 		if(s[i]==' ')
 		{
 			for(k=i;k<=len;k++)
 			{
 				s[k]=s[k+1];
			 }
			i--;
		 }
	 }
	len=strlen(s);
	for(t=0,i=0;t<=op;i++)
	{
		if('0'<=s[i+1]&&s[i+1]<='9')
		{
			shu[t]=shu[t]*10+s[i]-'0';
		}
		else
		{
			shu[t]=shu[t]*10+s[i]-'0';
			t++;
			i++;
		}
	}
	for(i=0;i<op;i++)
	{
		if(fuhao[i]=='*')
		{
			shu[i+1]=shu[i]*shu[i+1];
		}
		else if(fuhao[i]=='/')
		{
			shu[i+1]=shu[i]/shu[i+1];
		}
	}
	for(i=0;i<op;i++)
	{
		if(fuhao[i]=='+')
		{
			for(t=1;fuhao[i+t]=='*'||fuhao[i+t]=='/';t++)
			{
			}
			shu[i+t]=shu[i]+shu[i+t];
		}
		else if(fuhao[i]=='-')
		{
			for(t=1;fuhao[i+t]=='*'||fuhao[i+t]=='/';t++)
			{
			}
			shu[i+t]=shu[i]-shu[i+t];
		}
	}
	printf("%d",shu[op]);
	return 0;
 }

 



