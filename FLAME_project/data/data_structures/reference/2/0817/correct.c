#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int a=0,b,c;
	char x='+',y,z;
	while(x!='='){
		scanf("%d %c",&b,&y);
		while(y!='+'&&y!='-'&&y!='='){
			scanf("%d %c",&c,&z);
			if(y=='/'){
				b=b/c;
			}
			else{
				b=b*c;
			}
			y=z;
		}
		if(x!='*'&&x!='/'&&x!='='){
			if(x=='-'){
				a=a-b;
			}
			else{
				a=a+b;
			}	
		}
		x=y;
    }
	printf("%d",a);
	return 0;	
}

