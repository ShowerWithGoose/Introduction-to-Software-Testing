#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node{
	char word[26];
	int count;
};
int N=0;
int getword(FILE *fpin,char *word);
int main()
{
	struct node wordlist[100]; 
	struct node temp;
	FILE *fpin;
	char word[26];
	if((fpin=fopen("article.txt","r"))==NULL){
       printf("Can&rsquo;t open article.txt!");
       return 404;
    }
    int i=0,j=0;
    for(i=0;i<100;i++){
    	wordlist[i].count=0;
	}
	i=0;
    while(getword(fpin,word)!=EOF){
    	int flag=0;
    	for(j=0;j<100;j++){
    		if(strcmp(word,wordlist[j].word)==0){
    			wordlist[j].count++;
    			flag=1;
    			break;
			}
		}
		if(flag==0){
			strcpy(wordlist[i].word,word);
			wordlist[i].count++;
			i++;
		}
	} 
	N=i;
	for(i=0;i<N;i++){
		for(j=0;j<N-1-i;j++){
			if(strcmp(wordlist[j].word,wordlist[j+1].word)>0){
				temp=wordlist[j];
				wordlist[j]=wordlist[j+1];
				wordlist[j+1]=temp;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%s %d\n",wordlist[i].word,wordlist[i].count);
	}
	return 0;
}
int getword(FILE *fpin,char *word)
{
    int i=0;
    char c;
    while((c=fgetc(fpin))!=EOF){
        if(isalpha(c)){
            word[i]=tolower(c);
            i++;
        }
        else if(i>0){
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}
















