#include<stdio.h>
#include<string.h>
int f(char m)
{
 if(m=='+'||m=='-'||m=='*'||m=='/')
 return 1;
 if(m<='9'&&m>='0')
 return -1;
 
 return 0;
}
int t(int a1,char q,int a2)
{
	int result;
 	if(q=='*'){
 		result = a1*a2;
	} else if (q=='+') {
		result = a1+a2;
	} else if (q=='-') {
		result = a1-a2;
	} else if (q=='/') {
		result = a1/a2;
	} else {
		result = -1;
	}
	return result;
}

int main()
{
 	char a[1000],b[1000],d[1000];
 	int k=0,i,j,m=0,n,flag=0;
 	int c[1000]={0},e[1000]={0};
 	gets(a);
 	for(i=0,j=0;a[i]!='=';i++)//去掉空格 ,把字符串存进b 
 	{
  		if(a[i]!=' ')
  		{
   			b[j++]=a[i];
  		}
  		else
  		{
   		continue;
  		}
 	}
 	b[j]='\0';
 	for(j=0,k=0,n=0;b[j]!='\0';j++){//符号和数字分别存两个数组里 
  		if(f(b[j])==-1)//是数字 
 		{
    		if(f(b[j+1])==-1)//是多位数字 
    		{
     			int m=0;
     			while(f(b[j])==-1){
      			m=m*10+(b[j]-'0');
      			j++;
  				}
  				c[n]=m;
  				n++;
  				j=j-1;
 			}
 			else
 			{//是单个数字 
  			c[n]=b[j]-'0';
  			n++;
 			}
 		}
  		else 
  		{ 
  			d[k]=b[j];
  			k++;
  		}
	}
	d[k]='\0';
	//puts(d); 
 	for(i=0;d[i]!='\0';i++)//乘法运算 
 	{
  		if(d[i]=='*'||d[i]=='/')
  		{
   			c[i+1]=t(c[i],d[i],c[i+1]);
  		}
  	}
  	int cnt=0;
  	for (i=0;i<n;i++) {
  		if(d[i]=='*'||d[i]=='/') {
  			continue;
		}else {
		e[cnt++]=c[i];
		}
  	}

  	cnt=0;
 	for (i=0;d[i]!='\0';i++) {
 		if(d[i]=='+'||d[i]=='-') {
 			e[cnt+1]=t(e[cnt],d[i],e[cnt+1]);
 			cnt++;
	 	}
 	} 
 
 	printf("%d\n",e[cnt]); 
}

