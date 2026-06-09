#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#define max 1024
char s[max];
struct a{
	char name[20];
	int num;
	int flag;
}word[max];
int cmp(const void* p1,const void* p2){
	return strcmp(((struct a*)p1)->name,((struct a*)p2)->name);
}
int main()
{
	int i,j,p=0,q=0;
	FILE *in;
	in=fopen("article.txt","r"); 
	while(fgets(s,max,in)!=NULL){
		for(i=0;s[i];i++){
			if(s[i]>='A'&&s[i]<='Z'){
				word[p].name[q]=s[i]+32;
			    q++;
			} 
			else if(s[i]>='a'&&s[i]<='z'){
			    word[p].name[q]=s[i];
			    q++;
			}
		    else{
			   	p++;q=0;
			}
		}
		if(!q)
		word[p].name[0]='\0';
		else
		word[p].name[++q]='\0';
		p++;q=0; 
	}
	for(i=0;i<p;i++){
		word[i].flag=0;
		word[i].num=1;
	}
	for(i=0;i<p;i++){
		if(!word[i].flag){
			for(j=1;j<p;j++){
				if(!word[j].flag&&!strcmp(word[i].name,word[j].name)&&i!=j){
				    word[i].num++;
			        word[j].flag=1;	
			    }
			} 
		}
	}
	qsort(word,p,sizeof(struct a),cmp);
	for(i=0;i<p;i++){
		if(!word[i].flag&&word[i].name[0]>='a'&&word[i].name[0]<='z')//flag=0²Å½øÈë 
			printf("%s %d\n",word[i].name,word[i].num);
	}
	return 0;
}



