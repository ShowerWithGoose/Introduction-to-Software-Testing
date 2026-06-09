#include<stdio.h>
#include<string.h>
int f(char x)
{
	if(x=='*'||x=='/') return 2;
	else if(x=='+'||x=='-') return 1;
	else if(x=='=') return 0;
}
int g(int y,char q,int z)
{
	if(q=='*') return y*z;
	else if(q=='/') return y/z;
	else if(q=='-') return y-z;
	else if(q=='+') return y+z;
}
int main()
{
	int i=0,j=0,a,b,c;
	char  s1=' ',s2;
	scanf("%d",&a);
	do{
	    scanf("%c",&s1);}
	while(s1==' ');
	if(f(s1)==0)printf("%d",a);
	else
	{
	    scanf("%d",&b);
	    do{
	        scanf("%c",&s2);}
	    while(s2==' ');
	    if(f(s2)=='=') printf("%d",g(a,s1,b));
	    else
	    {
	        do
	        {
		        scanf("%d",&c);
		        if(f(s1)>=f(s2))
		        {
		    	a=g(a,s1,b);
		    	s1=s2;b=c;
			    }
			    else
			    {
				b=g(b,s2,c);
			    }
			    do{
	            scanf("%c",&s2);}
	            while(s2==' ');
	        }
	        while(s2!='=');
	        printf("%d",g(a,s1,b));
        }
	}
	return 0;
}

