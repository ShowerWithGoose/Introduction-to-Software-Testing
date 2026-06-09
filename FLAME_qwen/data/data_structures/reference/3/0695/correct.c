#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];  
	scanf("%s",&a);
	int i,j,o;
	int l=strlen(a);
	for(i=0;a[i]!='.';i++);
	if(a[0]=='0')
	{
		for(o=0,j=2;a[j]=='0';j++)
		o++;
		if(o==l-3)
		{
			printf("%ce-%d",a[j],l-2);
		}else{
			printf("%c.",a[j]);
			for(j++;j<l;j++)printf("%c",a[j]);
			printf("e-%d",o+1);
		}
	}
	else{
		if(i==1){
			printf("%se0",a);
		}else if(i>1)
		{
			printf("%c.",a[0]);
			for(j=1;a[j]!='.';j++)
			printf("%c",a[j]);
			for(j++;j<l;j++)
			printf("%c",a[j]);
			printf("e%d",i-1);	
		}
		
	}
	return 0;
}

