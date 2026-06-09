#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024
struct lnode {
    char word[MAXWORD];
    int count;
};
int getWord(FILE *bfp,char *w);
int searchWord(struct lnode list[], char *w);
int insertWord(struct lnode list[ ],  int pos, char *w);
int N=0;
int main()
{
    struct lnode wordlist[MAXSIZE];	/*µ¥´Ê±í*/
    int i;	
    char  word[MAXWORD];
    FILE *bfp;

    bfp = fopen("article.txt","r");
    
    while( getWord(bfp,word) != EOF){

        if(searchWord(wordlist, word) == -1) {

            return -1;
        }
    }
    for(i=0; i<= N-1; i++)
        printf("%s %d\n", wordlist[i].word, wordlist[i].count);
    return 0;
}
int getWord(FILE *bfp,char *w){
	int c;
	while(isalpha(c=fgetc(bfp))==0)
	if(c==EOF)return c;
	else continue;
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(bfp))!=0);
	*w='\0';
	return 1;
}
int insertWord(struct lnode list[],int pos,char *w){
	int i;

	for(i=N-1;i>=pos;i--){
		strcpy(list[i+1].word,list[i].word);
		list[i+1].count=list[i].count;;
	}
	strcpy(list[pos].word,w);

		list[pos].count=1;
		N++;
		return 1;
	
}


int searchWord(struct lnode list[],char *w){
	int low=0,high=N-1,mid=0;
	while(low<=high){
		mid=(high+low)/2;
		if(strcmp(w,list[mid].word)<0)
			high=mid-1;
		else if(strcmp(w,list[mid].word)>0)
		low=mid+1;
		else {
			list[mid].count++;
			return 0;
		}
	}
	return insertWord(list,low,w);
	
}



