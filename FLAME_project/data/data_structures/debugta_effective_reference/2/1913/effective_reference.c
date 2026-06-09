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
    	int fir,sec,thi;
		char left,right;
		fir=readint();
		left=readchar();
		if(left=='=') printf("%d",fir);
		else {
			sec=readint();
			right=readchar();
			if(right=='=') printf("%d",intcal(fir,left,sec));
			else{
				while(right!='=')
				{
					thi=readint();
					if((right=='*'||right=='/')&&(left=='+'||left=='-')){
						sec=intcal(sec,right,thi);
					}
					else{
						fir=intcal(fir,left,sec);
						left=right;
						sec=thi;
					}
					right=readchar();
				}
				printf("%d",intcal(fir,left,sec));
			}
		}
    	return 0;
		
    	
	}

