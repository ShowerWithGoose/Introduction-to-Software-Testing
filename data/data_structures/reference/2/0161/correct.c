#include<stdio.h>
#include<string.h>
char start[100000];
void qk(char q[]);
int jisuan(char a[]);
void chengchu(char b[]);
void jiajian(char c[]);
int main()
{
	int i,j;
	gets(start);
	start[strlen(start)-1]='\0';
	qk(start);
	chengchu(start);
	jiajian(start);
	jiajian(start);
	if(start[0]=='-') start[0]=' ';
	qk(start);
	puts(start);
	return 0;
}
void qk(char q[])
{
	char w[100000]={};
	int i,j;
	for(i=0,j=0;i<strlen(q);i++)
	{
		if(q[i]!=' ')
		{
			w[j]=q[i];
			j++;
		}
	}
	memset(q,'\0',strlen(q));
	for(i=0;i<strlen(w);i++)
	q[i]=w[i];
} 
int jisuan(char a[])
{
	int one=0,two=0,i,flag,cf;
	for(i=0;a[i]>='0'&&a[i]<='9';i++);
	flag=i;
	for(i=flag-1,cf=1;i>=0;i--)
	{
		one=one+(a[i]-'0')*cf;
		cf*=10;
	}
	for(i=strlen(a)-1,cf=1;i>flag;i--)
	{
		two=two+(a[i]-'0')*cf;
		cf*=10;
	}
	switch(a[flag]){
		case '*' : return one*two; 
		case '/' : return one/two; 
		case '+' : return one+two; 
		case '-' : return one-two; 
	}
}
void chengchu(char b[])
{
	int i,j,k,flag,jg;
	char d[10000];
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]=='*'||b[i]=='/')
		{
			for(k=i-1;b[k]>='0'&&b[k]<='9'&&k!=0;k--);
			if(k>0) k=k+1;
			for(j=0;(b[k]>='0'&&b[k]<='9')||k==i;k++,j++){
			d[j]=b[k];b[k]=' '; }
			d[j]='\0';
		    jg=jisuan(d);
			k=k-1;
		    if(jg==0) b[k]=0+'0';
		    while(jg!=0)
		    {
		    	b[k]=jg%10+'0';jg=jg/10;
		    	k--;
			}
			qk(b);
			chengchu(b);
	    }
	    memset(d,'\0',strlen(d)); 
   }
   qk(b);
}
void jiajian(char b[])
{
	int i,j,k,flag,jg;
	char d[10000];
	for(i=0;i<strlen(b);i++)
	{
		flag=0;
		if(b[i]=='+'||b[i]=='-'&&i!=0)
		{
			for(k=i-1;(b[k]>='0'&&b[k]<='9')&&k!=0;k--);
			if(k>0) k=k+1;
			for(j=0;(b[k]>='0'&&b[k]<='9')||k==i;k++,j++){
			d[j]=b[k];b[k]=' '; }
			d[j]='\0';
		    jg=jisuan(d);k=k-1;i=k;
		    if(jg==0) b[k]=0+'0';
		    if(jg<0){
		    		jg=-jg;flag=-1;
				}
		    while(jg!=0)
		    {
		    	b[k]=jg%10+'0';jg/=10;
		    	k--;
			}
			if(flag==-1) b[k]='-';
			qk(b);
			jiajian(b);
	    }
	    if(b[0]=='-')
	    {
	    	for(i=1;b[i]>='0'&&b[i]<='9';i++);
	    	if(i<strlen(b))
	    	{
	    		b[0]=' ';
	    		if(b[i]=='-') b[i]='+';
	    		else b[i]='-';
			}
		}
	    qk(b);
	    memset(d,'\0',strlen(d));
   }
   qk(b);
}

