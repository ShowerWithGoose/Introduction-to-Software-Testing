#include<stdio.h>
#include<string.h>
void type(char a,char b)
{ int i=1;
if((a>='0'&&a<='9'&&b>='0'&&b<='9'&&a<b)||(a>='a'&&a<='z'&&b>='a'&&b<='z'&&a<b)||(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&a<b))
	{ while(a+i<b)
		{printf("%c",a+i);
		i++;
		}	
	}
else
printf("-");

}





int main()
{ char c[1005];
scanf("%s",c);
int a,i;
a=strlen(c);
for(i=0;i<=a-1;i++)
{ if(c[i]=='-')
type(c[i-1],c[i+1]);
else
printf("%c",c[i]);
}
return 0;
}



