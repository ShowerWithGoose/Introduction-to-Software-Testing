#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct sta{
	char word[60];
	int cnt;
}; 
int getWord(FILE *  ,char *);
//int searchWord(struct sta [],char *);
int N=0;//N用来统计wordlist中有多少个词 
int main(){
	FILE *in;
	struct sta wordlist[1200];
	struct sta p;
	char word[60];
	int i=0;
	int j=0;
	int sign;
	in=fopen("article.txt","r");
	while((getWord(in,word))!=EOF){//读入了一个单词
	    strcpy(wordlist[N].word ,word);
	    wordlist[N].cnt =1;
	    N++;
	}//读入所有的单词
	N--;
	for(i=0;i<N;i++){
		for(j=0;j<N-i;j++){
			sign=strcmp(wordlist[j].word ,wordlist[j+1].word );
			if(sign>0){
			    p=wordlist[j];
			    wordlist[j]=wordlist[j+1];
			    wordlist[j+1]=p;
			}
		}//冒泡排序 
    }
	 
    for(i=0;i<N;i++){
    	for(j=i+1;j<=N;j++){
    		if(strcmp(wordlist[i].word  ,wordlist[j].word)==0  ){
    			wordlist[i].cnt  =wordlist[i].cnt  +wordlist[j].cnt  ;
    			wordlist[j].cnt  =0;
			}
		}
	}
    
	for(i=0;i<=N;i++){
		if(wordlist[i].cnt !=0)
		printf("%s %d\n",wordlist[i].word ,wordlist[i].cnt );
	}
	
return 0;
}

int getWord(FILE *fp,char *w){
	int c;
	while(!isalpha(c=fgetc(fp))){
		if(c==EOF) return c;
		else continue;
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
return 1;
}
/*
int searchWord(struct sta wordlist[],char *w){
	int low=0,mid=0,high=N-1;
	while(low<=high){
		mid=(low+high)/2;
		if(strcmp(w,wordlist[mid].word)<0){
			high=mid-1;
		}
		else if(strcmp(w,wordlist[mid].word)>0){
			low=mid+1;
		}
		else if(strcmp(w,wordlist[mid].word)==0){
			wordlist[mid].cnt++;
			return -1;//表示已经找到了 
		}		
	}
	return low;
	
}
*/

