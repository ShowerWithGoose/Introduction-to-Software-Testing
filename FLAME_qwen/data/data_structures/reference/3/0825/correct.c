#include<stdio.h>
#include<string.h>
void delete(char s[]){
	int i,j;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!='.')s[j++]=s[i];
	}
	s[j]='\0';
}
char s[110];
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	if(s[0]=='0'){
		delete(s);
//		printf("%s\n",s);
		int x=0;
		for(x=0;s[x]=='0';x++);//得到前面0的个数
		int x1=x;
		printf("%c",s[x1]);
		x1++;
		if(s[x1]!='\0')printf(".");
		for(x1;s[x1]!='\0';x1++){
			printf("%c",s[x1]);
		} 
		printf("e-%d",x);	
	} else{
		int i,j;
		for(i=0;s[i]!='.'&&i<l;i++);//小数点左边位数
		int x=i-1;//科学计数法的次数
//		printf("%d",x); 
		delete(s);
//		printf("%s\n",s);
		if(s[1]!='\0'){//多位数字情况 
			printf("%c",s[0]);
			printf(".");
			int k=1;
			for(k;s[k]!='\0';k++){
				printf("%c",s[k]);
			}
			printf("e%d\n",x);
		}else{//只有一位数字 
			printf("%ce%d\n",s[0],x);
		}
		
	}
	return 0;
}



