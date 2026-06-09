#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct wordnum{
 char word[1005];
 int num;
}list[1005];

int rank(const void *p1,const void *p2)
{
 int a;
 a=strcmp(((struct wordnum*)p1)->word,((struct wordnum*)p2)->word);
 return a;
}
int judge(char a){
 if((a>='a'&&a<='z')||(a>='A'&&a<='Z')){
  return 1;
 }
 return -1;
}
int main(){
    FILE*fp1;
    fp1=fopen("article.txt","r");
    char c;
    int i=0,j=0,k,t,a=0;
    char s[1000][1000];
    while((c=fgetc(fp1))!=EOF){  
     if(judge(c)==1){
        if(c>='a'&&c<='z'){
        	s[i][j]=c;
        }
        if(c>='A'&&c<='Z'){
        	s[i][j]=c+'a'-'A';
        }
        j++;
     }
     if(judge(c)==-1&&j>0){ 
        s[i][j]='\0';
        i++;
        j=0;
     }
    }
    
   //将s中的内容复制于list中并去重
    for(k=0;k<i;k++){
    	strcpy(list[k].word,s[k]);
    	list[k].num=1;
    }
	qsort(list,i,sizeof(struct wordnum),rank);
    for(j=0;j<i-a;j++){
		for(k=j+1;k<i-a;k++){
			if(strcmp(list[k].word,list[j].word)==0){
			   	list[j].num++;
				for(t=j;t<i-1;t++){
				   strcpy(list[t].word,list[t+1].word);
			    }
				a++;
			    j=j-1;
		     	     
			}
		}
	} 
    
    for(j=0;j<i-a;j++){
     printf("%s %d\n",list[j].word,list[j].num);
    }
    fclose(fp1);
    return 0; 
} 

