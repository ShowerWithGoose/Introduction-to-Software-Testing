#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char ch[105];
	int len,num=0,k;
	gets(ch);
	len=strlen(ch);
	
	if(ch[0]=='0'){             //小于1的数 
		for(int i=2;i<len;i++){
			if(ch[i]=='0'){
				num++;
			}else break;
		}
		printf("%c",ch[num+2]);
		if(ch[num+3]!='\0')
			printf("."); 
		k=num+3;
		while(ch[k]!='\0'){
			printf("%c",ch[k]);
			k++;
		}
		printf("e-%d",num+1);	
	}else{
		printf("%c.",ch[0]);
		k=0;
		for(int i=1;i<len;i++){
			if(ch[i]!='.'){
				k++;
				printf("%c",ch[i]);
			}else{
				num=k;
			}
		}	printf("e%d",num);
	} 
	
//	puts(ch);
//	printf("%d",len);
}

