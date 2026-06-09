#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
FILE* f1;
char s[1000][30],n[30],ch[100000],a;
int i,j,len,k,m,x,flag,num[200],max,t,p;
int main(){
    f1=fopen("article.txt","r"); 
	for(i=0;(a=fgetc(f1))!=EOF;i++){
		if(!isalpha(a)) ch[i]=' ';
		else ch[i]=tolower(a);
	}
	
	for(i=0;ch[m]!='\0';i++){
		for(p=0;ch[m]!=' '&&ch[m]!='\0';m++){
			s[i][p++]=ch[m];
		}
		s[i][p]='\0';
		m++;
		len=strlen(s[i]);
		if(len==0){
			i--;continue;
		}
		flag=0;
		for(x=0;x<i;x++)
		    if(strcmp(s[i],s[x])==0){
				num[x]++;
			    flag=1;
			    break; 
				}//比对		
	    
		if(flag)
			i--; //旧单词，不开新单词数组 
		
			
		else
	        num[i]++;//是新单词，开一个新单词数组 
    
	}
	max=i;//一共多少个非重复单词 
	for(i=0;i<max-1;i++){
		for(j=i+1;j<max;j++){
			if(strcmp(s[i],s[j])>0){
				strcpy(n,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],n);
				t=num[i];
				num[i]=num[j];
				num[j]=t;
			}
		}
	}//排序 
	for(i=0;i<max;i++)
		printf("%s %d\n",s[i],num[i]);
	
	return 0;
}

