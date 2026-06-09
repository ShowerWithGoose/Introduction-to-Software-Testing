#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
//int范围：2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0,num[1007],mark[1007];
	memset(num,0,sizeof(num));
	memset(mark,0,sizeof(mark));
	char word[1007][20],c,temp[20];
	while((c=fgetc(in))!=EOF){
		c=tolower(c);
		if(c>='a'&&c<='z'){
			word[i][j]=c;
			j++;
		}
		else if((j>0)&&(c<'a'||c>'z')&&(word[i][j-1]>='a'&&word[i][j-1]<='z')){
			word[i][j]='\0';
			j=0;
			i++;
		}
	}//输入
	
	for(int m=0;m<i;m++){
		for(int n=0;n<i-m-1;n++){
			if(strcmp(word[n],word[n+1])>0){
				strcpy(temp,word[n]);
				strcpy(word[n],word[n+1]);
				strcpy(word[n+1],temp);
			}
		}
	}//排序
	
	num[0]=1;
	for(int n=1;n<i;n++){
		for(int m=0;m<n;m++){
		if(strcmp(word[m],word[n])==0){
			num[m]++;
			mark[n]++;
			break;
		}
		}
		if(mark[n]==0){
			num[n]++;
		}
	}//计数
	
	for(int k=0;k<i;k++){
		if(num[k]!=0){
			printf("%s ",word[k]);
			printf("%d\n",num[k]);
		}
	}//输出
	
	fclose(in);
	return 0;	
}

