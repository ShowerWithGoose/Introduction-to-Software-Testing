/*#include<stdio.h>
char a[1000],b[1000];int c[1000],d[1000];
int main()
{
	gets(a);
	int i,j,k=0,l,m=0,n=1,p,q,x=0,sum,w=0;
	for(i=0,j=0;a[i]!='=';i++)//去空格 
	{
		if(a[i]!=' ')
		{
			a[j]=a[i];
			j++;
		}
		else continue;
	}
	for(i=0;i<j;i++)//符号存b[]中，数字存到c[]中 
	{
		if(a[i]=='+')
		{
			b[n]='+';
			n=n+2;
			for(l=k;l<i;l++)
			{
				x=x*10+a[l]-'0';
			}
			c[m]=x;
			x=0;m=m+2;k=i+1;
		}
		else if(a[i]=='-')
		{
			b[n]='-';
			n=n+2;
			for(l=k;l<i;l++)
			{
				x=x*10+a[l]-'0';
			}
			c[m]=x;
			x=0;m=m+2;k=i+1;
		}
		else if(a[i]=='*')
		{
			b[n]='*';
			n=n+2;
			for(l=k;l<i;l++)
			{
				x=x*10+a[l]-'0';
			}
			c[m]=x;
			x=0;m=m+2;k=i+1;
		}
		else if(a[i]=='/')
		{
			b[n]='/';
			n=n+2;
			for(l=k;l<i;l++)
			{
				x=x*10+a[l]-'0';
			}
			c[m]=x;
			x=0;m=m+2;k=i+1;
		}
		
	}
	for(i=1;i<n;i=i+2)//计算连乘连除，并讲乘号除号在d[]中标记为1 
	{
		if(b[i]=='*')
		{
			c[i+1]=c[i-1]*c[i+1];
			d[i-1]=1;
		}
		else if(b[i]=='/')
		{
			c[i+1]=c[i-1]/c[i+1];
			d[i-1]=1;
		}
	}
	for(i=1;i<n;i=i+2)//计算结果 
	{
		if(b[i]=='+')
		{
			w=i+1;
			while(d[w]==1)
			{
				w=w+2;
			}
			c[w]=c[w]+b[i-1];
			
		
		}
		else if(b[i]=='-')
		{
			while(d[w]==1)
			{
				w=w+2;
			}
			c[w]=c[i-1]-c[w];
		}
	}
	printf("%d",c[w-2]);
	return 0;
}*/
/*#include<stdio.h>
char a[1000],b[1000];int c[1000],flag[1000];
int main()
{
	gets(a);
	int i,j,k=1,l,m,n=0,x=0,sum=0,w=1;
	for(i=0,j=0;a[i]!='=';i++)
	{
		if(a[i]!=' ')
		{
			a[j]=a[i];j++;
		}
		else continue;
	}
	for(i=0;i<j;i++)
	{
		if(a[i]=='+')
		{
			flag[k]=1;k=k+2;
		}
		else if(a[i]=='-')
		{
			flag[k]=2;k=k+2;
		}
		else if(a[i]=='*')
		{
			flag[k]=3;k=k+2;
		}
		else if(a[i]=='/')
		{
			flag[k]=4;k=k+2;
		}
		
	}
	for(i=0;i<j;i++)
	{
		while(flag[i]==0)
		{
			x=x*10+a[i]-'0';i++;
		}
		c[n]=x;n=n+2;x=0;
	}
	for(i=1;i<j;i=i+2)
	{
		if(flag[i]==3)
		c[i+1]=c[i-1]*c[i+1];
		else if(flag[i]==4)
		c[i+1]=c[i-1]/c[i+1];
	}
	for(i=1;i<j;i=i+2)
	{
		if(flag[i]==1)
		{
			while(flag[i+2]==3||flag[i+2]==4)
			{
				i=i+2;
			}
			
		}
		if(flag[i]==2)
		{
			while(flag[i+2]==3||flag[i+2]==4)
			{
				i=i+2;
			}
			sum=sum-c[i];
		}
	}
	printf("%d",sum);
	return 0;
}*/
/*#include<stdio.h>
char a[1000],c[1000];
int b[1000],d[1000];
int main()
{
    gets(a);
    int i,j,k=0,m=0,n=1,l=0,s=0,w=0;
    for(i=0,j=0;a[i]!='=';i++)
    {
    	
        if(a[i]!=' ')
		{
            a[j]=a[i];
            j++;
        }
        else continue;
    }

    for(i=0;i<j;i++){
    if(a[i]=='+'){
    c[n]='+';
    n+=2;
   
    for(l=k;l<i;l++){
    s=10*s+a[l]-'0';
    } 
    b[m]=s;
    s=0;
    k=i+1;
  
    m+=2;
   
    }
    else if(a[i]=='-'){
    c[n]='-';
    n+=2;
    for(l=k;l<i;l++){
    s=10*s+a[l]-'0';
    }
    b[m]=s;
    s=0;
    k=i+1;
    m+=2;
    }
    else if(a[i]=='*'){
    c[n]='*';
    n+=2;
    for(l=k;l<i;l++){
    s=10*s+a[l]-'0';
    }
    b[m]=s;
    s=0;
    k=i+1;
    m+=2; 
    }
    else if(a[i]=='/'){
    c[n]='/';
    n+=2;
    for(l=k;l<i;l++){
    s=10*s+a[l]-'0';
    }
    b[m]=s;
    s=0;
    k=i+1;
    m+=2; 
    }
	}
    for(l=k;l<j;l++){
    s=10*s+a[l]-'0';
    }
    b[m]=s;m+=2;
  for(i=1;i<=n-2;i+=2){
   if(c[i]=='*'){
    b[i+1]=b[i-1]*b[i+1];
    d[i-1]++;
   }
   else if(c[i]=='/'){
    b[i+1]=b[i-1]/b[i+1];
    d[i-1]++;
   }
   
  }
  for(i=1;i<=n-2;i+=2){
   if(c[i]=='+'){
    w=i+1;
    while(d[w]!=0){
     w+=2;
    }
    b[w]+=b[i-1];
    
   }
   else if(c[i]=='-'){
    w=i+1;
    while(d[w]!=0){
     w+=2;
    }
    b[w]=b[i-1]-b[w]; 
   }
  }
  printf("%d",b[m-2]);
  
  return 0;
 }*/

#include<stdio.h>
int num()
{
	int num;
	scanf(" %d",&num);
	return num;
}
char op()
{
	char op;
	scanf(" %c",&op);
	return op;
}
int main()
{
	int a[5];
	char b[5];
	a[0]=num();b[0]=op();
	if(b[0]!='=')a[1]=num();
	while(b[0]!='=')
	{
		if(b[0]=='*')
		{
			a[0]=a[0]*a[1];
			b[0]=op();
			if(b[0]!='=')a[1]=num();
		}
		else if(b[0]=='/')
		{
			a[0]=a[0]/a[1];
			b[0]=op();
			if(b[0]!='=')a[1]=num();
		}
		else if(b[0]=='+')
		{
			b[1]=op();
			if(b[1]=='+'||b[1]=='-')
			{
				a[0]=a[0]+a[1];b[0]=b[1];
				a[1]=num();
			}
			else if(b[1]=='*')
			{
				a[2]=num();a[1]=a[1]*a[2];
			}
			else if(b[1]=='/')
			{
				a[2]=num();a[1]=a[1]/a[2];
			}
			else if(b[1]=='=')
			{
				a[0]=a[0]+a[1];b[0]=b[1];
			}
		}
		else if(b[0]=='-')
		{
			b[1]=op();
			if(b[1]=='+'||b[1]=='-')
			{
				a[0]=a[0]-a[1];b[0]=b[1];
				a[1]=num();
			}
			else if(b[1]=='*')
			{
				a[2]=num();a[1]=a[1]*a[2];
			}
			else if(b[1]=='/')
			{
				a[2]=num();a[1]=a[1]/a[2];
			}
			else if(b[1]=='=')
			{
				a[0]=a[0]-a[1];b[0]=b[1];
			}
		}
		
	}
	printf("%d",a[0]);
	return 0;
}


