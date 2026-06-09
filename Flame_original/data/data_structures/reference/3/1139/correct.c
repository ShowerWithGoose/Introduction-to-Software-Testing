#include<stdio.h>
#include<string.h>
int main(){
	int point=0,i,j=0,flag=1,len,num,length_s2=0;
	char s1[100],s2[100];
	scanf("%s",s1);
	len=strlen(s1);
	if(s1[0]=='0'){
		for(i=0;i<len;i++){
			if(s1[i]>'0'&&s1[i]<='9')break;
			if(s1[i]=='0')num--;
		}
		for(;i<len;i++){
		s2[j++]=s1[i];
		length_s2++;
		}
		s2[j]='\0';
	}
	else{
		for(i=0;i<len;i++){
			if(s1[i]=='.')break;
			num++;
		}
		num-=1;
		for(i=0;i<len;i++){
			if(s1[i]>='0'&&s1[i]<='9'){
			s2[j++]=s1[i];
			length_s2++;
			}
		}
		s2[j]='\0';
	}
	if(length_s2>1)printf("%d.",s2[0]-'0');
	else printf("%d",s2[0]-'0');
	for(i=1;s2[i]!='\0';i++)printf("%d",s2[i]-'0');
	printf("e%d",num);
	return 0;
}

