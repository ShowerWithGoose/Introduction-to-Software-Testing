#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//int范围：2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
int main(){
	int num[10007]={0},result=0,shu[1007]={0},fu[1007]={0},funum=0,location[1007]={0},m=0;
	char str[10007],str1[10007];
	gets(str);
	location[0]=-1;
	for(int i=0,j=0;str[i]!='\0';i++){
		if(str[i]!=' ') str1[j]=str[i],j++;
	}
	int l=strlen(str1);
	for(int i=0;i<l;i++){
		if(str1[i]=='+') funum++,fu[funum]=1,location[++m]=i;
		if(str1[i]=='-') funum++,fu[funum]=2,location[++m]=i;
		if(str1[i]=='*') funum++,fu[funum]=3,location[++m]=i;
		if(str1[i]=='/') funum++,fu[funum]=4,location[++m]=i;
		if(str1[i]=='=') funum++,fu[funum]=5,location[++m]=i;
		if(str1[i]<='9'&&str1[i]>='0'){
			num[i]=str1[i]-'0';
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=location[i]+1;j<location[i+1];j++){
			shu[i+1]=shu[i+1]*10+num[j];
		}
	}//算出所有数据的值 fu为运算符的类型 m为运算符的总数 n为数字的总数 
	if(m==1){
		printf("%d",shu[1]);
		return 0;
	}
	for(int i=1;i<m;i++){
		if(fu[i]==3) shu[i+1]=shu[i]*shu[i+1];
	 	if(fu[i]==4) shu[i+1]=shu[i]/shu[i+1];
	 }
	for(int i=1;i<=m;i++){
		if(fu[i]==2) {
			for(int j=i+1;j<=m;j++){
				if(fu[j]==1||fu[j]==2||fu[j]==5){
				shu[j]=0-shu[j];
				break;
				}
			}
			}
		if(fu[i]==1||fu[i]==2||fu[i]==5) result+=shu[i];
	}
	printf("%d",result);
	return 0;
}

