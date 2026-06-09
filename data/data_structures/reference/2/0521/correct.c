#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int com(int a,int b,char sign)
{
	switch (sign)
		{
			case '+':
				a+=b;
				break;
			case '-':
				a-=b;
				break;
			case '*':
				a*=b;
				break;
			case '/':
				a/=b;
				break;
		}
	return a;
}
void at_sp(char *a,int len)
{
	int i=0,j=0;
	char *b=a;
	for(i=0;i<=len;i++)
	if(a[i]!=' ')
		b[j++]=a[i];

}
int main(int argc, char *argv[]) {
	char sen[100],si1,si2; 
	gets(sen);
	at_sp(sen,strlen(sen));
	int i=0,numsi=0,a=0,b=0,c=0,len=strlen(sen);
	for(i=0;i<len;i++)
	if(sen[i]>'9'||sen[i]<'0')
	numsi++;
	i=0;
	while(sen[i]<='9'&&sen[i]>='0')
		a=a*10+(int)(sen[i++]-'0');
	if(numsi==1)
	printf("%d\n",a);
	else if(numsi==2)
	{
		si1=sen[i++];
		while(sen[i]<='9'&&sen[i]>='0')
			b=b*10+(int)(sen[i++]-'0');
		printf("%d\n",com(a,b,si1));
	}else
	while(1){
		si1=sen[i++];
		while(sen[i]<='9'&&sen[i]>='0')
			b=b*10+(int)(sen[i++]-'0');
		si2=sen[i];i++;
		while(sen[i]<='9'&&sen[i]>='0')
			c=c*10+(int)(sen[i++]-'0');			
		numsi-=3;
	flag:	if((si1=='+'||si1=='-')&&(si2=='*'||si2=='/'))
			{
				b=com(b,c,si2);
				c=0;
			}
		else
		{
			a=com(a,b,si1);
			b=c;c=0;
			si1=si2;
		}
		
		if(numsi>0)
		{	
			si2=sen[i];
			i++;
			while(sen[i]<='9'&&sen[i]>='0')
			c=c*10+(int)(sen[i++]-'0');			
			numsi--;
			goto flag;
		}
		else
		{
			printf("%d\n",com(a,b,si1));
			break;	
		}
		
	}
	
	return 0;
}

