#include <stdio.h>
#include <string.h>

char num[105]={};
int main(){
	scanf("%s",num);
	//找到小数点并统计前有无非零
	int pointLoca=0,nonZero=0,lastNum=0,flag=0,pointflag=0,pf=0;
	for(int i=0;i<=105;i++){
		if(num[i]!=0&&num[i]!='0'&&num[i]!='.') nonZero=1;
		if(num[i]=='.'){
			pointLoca=i;break;
		}
	}
	
	for(int i=pointLoca+1;i<=105;i++){
		if(num[i]!='0'&&num[i]!=0) lastNum=i;
	}
	//
	if(pointLoca==0)
		pointLoca=strlen(num);
	
	if(nonZero==1){
		printf("%c",num[0]);
		if(lastNum!=0)	printf(".");
		for(int i=1;i<=lastNum;i++){
			if(i!=pointLoca)
				printf("%c",num[i]);
		}
		printf("e%d",pointLoca-1);
	}else{
		for(int i=pointLoca+1;i<=lastNum;i++){
			if(num[i]!='0') {
				flag=1;
				if(pointflag!=0&&pointflag!=i&&pf==0){
					printf(".");pf=1;
				}
			}
			if(flag==1){
				if(pointflag==0){
					printf("%c",num[i]);
					pointflag=i;
				}else{
					printf("%c",num[i]);
				}
			}
		}
		printf("e");
		if(pointflag-pointLoca>=1) printf("-");
		printf("%d",pointflag-pointLoca);
	}
	
	return 0;
}

