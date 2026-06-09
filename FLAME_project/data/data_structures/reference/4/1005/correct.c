#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
struct word{
	char l[30];
	int sum,t;
}word[1000];

int main()
{
    FILE *in=fopen("article.txt","r");
    int i,j=0,k,g,min;
    char s[1000],b[80];
    while(fgets(s,1000,in)!=NULL){
    	for(i=0;i<strlen(s);i++){
    		if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'){
    			sscanf(&s[i],"%[a-zA-Z]",word[j].l);
    			word[j].l[strlen(word[j].l)]='\0';
    			for(k=0;k<strlen(word[j].l);k++){
    				if(word[j].l[k]>='A'&&word[j].l[k]<='Z')
    					word[j].l[k]-='A'-'a';
    				
				}
				word[j].t=1;
				i+=strlen(word[j].l);
				j++;
			}
		}
	}

	for(i=0;i<j;i++){
		min=i;
		for(k=i+1;k<j;k++){
   			if(strcmp(word[min].l,word[k].l)>0){
    			min=k;
   			}
  		}
  		if(min!=i){
  			strcpy(b,word[min].l);
   			strcpy(word[min].l,word[i].l);
   			strcpy(word[i].l,b);
  		}
  	} 


	for(i=0;i<j;i++){
		for(k=i+1;k<j;k++){
			if(word[k].t!=0&&strcmp(word[i].l,word[k].l)==0){
				word[k].t=0;
				word[i].t++;
			}
		}
	}
	k=0;
	for(i=0;i<j;i++){
		if(word[i].t>0){
			printf("%s %d\n",word[i].l,word[i].t);
		}
	}
	 
	return 0;
}


