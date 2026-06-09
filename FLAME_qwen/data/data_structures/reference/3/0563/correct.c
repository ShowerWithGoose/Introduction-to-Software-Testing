#include<stdio.h>
int main()
{
	char s[200];
	scanf("%s",s);
	int i=0,j=0;
	for(i=0;s[i]!='.';i++);
	for(j=0;s[j]!='\0';j++);
	
	if(s[0]=='0'){
		int k=2;
		while(s[k]=='0')
		{
			k++;
		}
		
		printf("%c",s[k]);
		if(k!=j-1)printf(".");
		for(int u=k+1;u<j;u++){
			printf("%c",s[u]);
		}
		printf("e-");
		printf("%d",k-1);
	}
	else if(i==1){
		printf("%c.",s[0]);
		for(int u=2;u<j;u++)printf("%c",s[u]);
		printf("e0");
	}
	else{
		printf("%c.",s[0]);
		for(int u=1;u<i;u++)printf("%c",s[u]);
		for(int u=i+1;u<j;u++)printf("%c",s[u]);
		printf("e%d",i-1);
	}
	
	return 0;
}

