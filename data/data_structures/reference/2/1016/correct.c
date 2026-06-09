#include <stdio.h>
#include <string.h>
int readint()
    {
    	int i;
    	scanf("%d",&i);
    	return i;
	}
char readchar()
    {
    	char ch;
    	do{
    		scanf("%c",&ch);
		}while(ch==' ');
		return ch;
	}
int intcal(int x,char y,int z)
    {
    	if(y=='+') return x+z;
    	if(y=='-') return x-z;
    	if(y=='*') return x*z;
    	if(y=='/') return x/z;
	}
int main()
    {
    	int a,b,c;
		char left,right;
		a=readint();
		left=readchar();
		if(left=='=') printf("%d",a);
		else {
			b=readint();
			right=readchar();
			if(right=='=') printf("%d",intcal(a,left,b));
			else{
				while(right!='=')
				{
					c=readint();
					if((right=='*'||right=='/')&&(left=='+'||left=='-')){
						b=intcal(b,right,c);
					}
					else{
						a=intcal(a,left,b);
						left=right;
						b=c;
					}
					right=readchar();
				}
				printf("%d",intcal(a,left,b));
			}
		}
    	return 0;
		
    	
	}

