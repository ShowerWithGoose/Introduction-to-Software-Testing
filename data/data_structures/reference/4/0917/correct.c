//先读入单词，重复出现的合并，排序，输出 
#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct word{
	char w[32];
	int num;
};
int main(){
	struct word c[500];
	int temp,n,i=0,j=0;
	char s[32];
	char str;
	FILE*in;
	in = fopen("article.txt","r");
	for(i=0;i<300;i++){
		c[i].num=0;
	}//给出现次数置零
	str=fgetc(in);
	i=0;
	while(str!=EOF){
		if(isalpha(str)!=0){
			c[i].w[j]=str;
			j++;
		}
		else{
			c[i].w[j]='\0';
			c[i].num++;//出现次数记一次 
			i++;
			j=0;
		}
		str=fgetc(in);
	}//读入每个单词 
	n=i;
	for(i=0;i<=n;i++){
		for(j=0;j<32;j++){
			if(c[i].w[j]>='A'&&c[i].w[j]<='Z'){
				c[i].w[j]+=('a'-'A');
			}
		}
	} //变成小写 
	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(strcmp(c[i].w,c[j].w)==0){
				c[i].num+=c[j].num;
				c[j].num=0;
			} 
		}
	}//合并相同的单词
	
	for(i=0;i<=n;i++){
		for(j=i;j<=n;j++){
			if(c[i].w[0]>c[j].w[0]){
				strcpy(s,c[i].w);
				strcpy(c[i].w,c[j].w);
				strcpy(c[j].w,s);
				temp=c[i].num;
				c[i].num=c[j].num;
				c[j].num=temp;
			}
			else if(c[i].w[0]==c[j].w[0]){
				if(strcmp(c[i].w,c[j].w)>0){
					strcpy(s,c[i].w);
					strcpy(c[i].w,c[j].w);
					strcpy(c[j].w,s);
					temp=c[i].num;
					c[i].num=c[j].num;
					c[j].num=temp;
				}
			}
		}
	}//交换位置 
	for(i=0;i<=n;i++){
		if(c[i].num!=0&&c[i].w[0]!='\0')
			printf("%s %d\n",c[i].w,c[i].num);
	}//输出 
	fclose(in);
	return 0;
}



