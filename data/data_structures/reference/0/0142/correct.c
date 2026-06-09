#include<stdio.h>

int main()
{
	int i=0,j=0;
	char stc[100],exp[100],a,b;
	gets(stc);
	for(i=0,j=0;stc[i]!='\0';i++,j++)
	{
		a=stc[i-1];b=stc[i+1];
			if(stc[i]!='-')
			exp[j]=stc[i];
			else
			{
				if(a>='0'&&a<='9'&&b>='0'&&b<='9'||a>='a'&&a<='z'&&b>='a'&&b<='z'||a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
				do{
				exp[j]=a+1;
				a+=1;
				j++;
			}while(b!=a+1);
			j--;
		}
			else
			exp[j]=stc[i];
		}
	}
	exp[j]='\0';
	for(j=0;exp[j]!='\0';j++)
	printf("%c",exp[j]);
	printf("\n");
	return 0;
}



