#include<stdio.h>
#include<string.h>
int main()
{
	char a[101];
	char *p=NULL;
	char b={'.'};
	int l,m,i=0;
	scanf("%s",a);
	l=strlen(a);
	p=strchr(a,b);
	if(p==NULL){//无小数点情况 
		puts(a);
	}
	else if(p-a==1){//不大于10情况 
		if(a[0]=='0'){
			for(i=2;i<l;i++){
				if(a[i]!='0'){
					m=i;
					break;
				}
				
		}
		
		
		if(m==l-1){//0.00000002情况 
				printf("%c",a[m]);
				printf("e-%d",m-1);
			
			
		}
		else//0.00012345情况
		{
			
			printf("%c",a[m]);
			printf(".");
			for(i=m+1;a[i]!='\0';i++){
				printf("%c",a[i]);
			}
			printf("e-%d",m-1);
		 } 
	}
	else//整数部分大于一小于十
	{
		for(i=0;i<l;i++){
			printf("%c",a[i]);
		}
		printf("e0");
	 } 
	
	
    }
    else//整数部分大于十
	{
		printf("%c",a[0]);
		printf(".");
		for(i=1;i<p-a;i++){
			printf("%c",a[i]);
		}
		for(i=p-a+1;i<l;i++){
			printf("%c",a[i]);
		}
		printf("e%d",p-a-1);
	 } 
	 return 0;
}



