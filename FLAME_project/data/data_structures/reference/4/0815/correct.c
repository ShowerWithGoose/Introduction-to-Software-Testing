#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
struct word{
	char ph[50];
	int num;
}w[1000],tmp;
//int cmp(const void *d,const void *e){
//	return strcmp(((struct word *)d)->ph,((struct word *)e)->ph)>0?1:-1;
//}
int main(){
	int i=0,j,len=0,m,flag=0,q;
	char a,b[55]={'\0'};
	FILE *in;
	in =fopen("article.txt","r");
	while((a=fgetc(in))!=EOF){
//fgetc,读取文件,获取下一个字符
		if(a>='a'&&a<='z'){
			b[i]=a;
			i++;				
		} 
		else if(a>='A'&&a<='Z'){//大写转小写 
			b[i]=a-'A'+'a';
			i++;
		}	
		else{//句号，引号等 ,不是字母 
			if(strcmp(b,"\0")!=0){//b不是空的 (空的：两个连着都不是字母） 
				for(j=0;j<len;j++)
					if(strcmp(b,w[j].ph)==0){//一样
						w[j].num++;
						flag=1;
					}		
				if(flag==0){//没有一样的
					strcpy(w[len].ph,b);		
					w[len].num=1;	
					len++;					
				}				
				for(m=0;m<=50;m++)//清空b 
					b[m]='\0';	
				i=0;	
				flag=0;									
			}
		}	
	}
//	qsort(w,500,sizeof(w[0]),cmp);
//qsort排序错了		
	for(i=0;i<=len;i++){
		//flag=0;	
		for(j=i+1;j<len;j++)
			if(strcmp(w[i].ph,w[j].ph)>0){//前大于后
				tmp=w[i];
				w[i]=w[j];
				w[j]=tmp;
			//	flag=1;
			}	
		//if(flag==0)
		//	break;		
	}			
	for(i=0;i<len;i++)		
		printf("%s %d\n",w[i].ph,w[i].num);	
	fclose(in);	
	return 0;
} 

