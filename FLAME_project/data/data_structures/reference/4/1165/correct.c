#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct Node{
	char word[100];
	int num;
}list[10000],tmp; 
int cmp(const void *a,const void *b);
int main(){
	int i=0,j=0,k=0,len=0,flg=0;
	char now,tag[100]={0};
	FILE *in;
	in=fopen("article.txt","r");
	while((now=fgetc(in))!=EOF){
		if(now>='A'&&now<='Z'){
			now='a'+now-'A';
			tag[i]=now;
			i++;
		}
		else if(now>='a'&&now<='z'){
			tag[i]=now;
			i++;
		}
		else{
			if(strcmp(tag,"\0")!=0){
				for(j=0;j<len;j++){
					if(strcmp(tag,list[j].word)==0){
						flg=1;
						list[j].num++;
						break;
					}
					else
						flg=0;
				}
				if(flg==0){
					strcpy(list[len].word,tag);
					list[len].num=1;
					len++;
				}
				for(k=0;k<100;k++)
					tag[k]='\0';
			}
			i=0;
		}
	}
	qsort(list,len,sizeof(list[0]),cmp);
	for(i=0;i<len;i++)
		printf("%s %d\n",list[i].word,list[i].num);
    fclose(in);	
	return 0;
}
int cmp(const void *a,const void *b){ 
	return strcmp((*(struct Node*)a).word,(*(struct Node*)b).word); 
} 

