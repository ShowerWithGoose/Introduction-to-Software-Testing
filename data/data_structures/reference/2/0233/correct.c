#include<stdio.h>
#include<string.h>//5 - 1 * 2 * 3 + 12 / 2 / 2 =
	int q[100];//q为存了待机数的数组c
	char s[200],c[200],d[50];//c为存数字和运算符的字符串,d为存运算符的字符串 
	int a[200];//a记录第几位是运算符
	int i=0,j=0,n=0,x,o=0;//n为运算符个数 
int main(){
	gets(s);
	
	    for(i=0;i<strlen(s);i++)
		if(s[i]!=' ')c[j++]=s[i];	
    
	    i=1;a[0]=-1;
		for(j=0;j<=strlen(c)-1;j++)
		if(c[j]=='+'||c[j]=='-'||c[j]=='*'||c[j]=='/'||c[j]=='='){
		n++;
		a[i]=j;d[i]=c[j];//过滤符号(sign from 1)
		i++;
		}
		
	    for(i=0,j=1;j<=n;j++,i++){
	    for(x=1;x<a[i+1]-a[i];x++)
	    q[j]=q[j]*10+(c[o++]-'0');
	    
	    o++;}//我得找个办法读出前和后两个待计算的数字，用符号为间隔一个一个过滤 
	    
	    //n=7(n为一共有几个要计算的数字，运算符号有n-1个） 
	    for(i=1;i<=n-1;i++){
	    	if(d[i]=='*')
			{q[i+1]=e(q[i],q[i+1]);q[i]=-1000000;}
			if(d[i]=='/')
			{q[i+1]=u(q[i],q[i+1]);q[i]=-1000000;}
	    	}
	    
	    for(i=1;i<=n-1;i++){
	    	if(d[i]=='+')
	    	{j=i;o=i+1;
			while(q[j]==-1000000)j--;
	    	while(q[o]==-1000000)o++;
	    	q[o]=p(q[j],q[o]);q[j]=-1000000;}
	    	
	    	if(d[i]=='-')
	    	{j=i;o=i+1;
			while(q[j]==-1000000)j--;
	    	while(q[o]==-1000000)o++;
	    	q[o]=an(q[j],q[o]);q[j]=-1000000;}
		    }
	    
		printf("%d",q[n]);
		return 0;
}
int p(int a,int b){
	int c;
	c = a + b;
	return c;
}
int an(int a,int b){
	int c;
	c = a - b;
	return c;
}
int e(int a,int b){
	int c;
	c = a * b;
	return c;
}
int u(int a,int b){
	int c;
	c = a / b;
	return c;
}

