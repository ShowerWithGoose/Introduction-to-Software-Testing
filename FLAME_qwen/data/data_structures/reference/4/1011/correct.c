#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct Inode{
	char word[32];
	int count;
};
int getWord(FILE *bfp,char *w);
int searchWord(struct Inode list[],char *w);
int insertWord(struct Inode list[],int pos,char *w);
int N=0;
int main(){
	struct Inode wordlist[1024];
	int i;
	char filename[32],word[32];
	FILE *bfp;
	
	scanf("%s",filename);
	if((bfp=fopen("article.txt","r"))==NULL)
	{
		fprintf(stderr,"%s can't open!\n",filename);
		return -1;
	}
	while(getWord(bfp,word)!=EOF){
		if(searchWord(wordlist,word)==-1)
		{
			fprintf(stderr,"Wordlist is full!\n");
			return -1;
		}
	}
	for(i=0;i<=N-1;i++)
	{
		printf("%s %d\n",wordlist[i].word ,wordlist[i].count );
	}
	return 0;
}
int getWord(FILE *fp,char *w){
	int c;
	while(!isalpha(c=fgetc(fp)))
		if(c==EOF) return c;
		else continue;
	do{
		*w++=tolower(c);
	} while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
int searchWord(struct Inode list[], char *w)
{
	int low=0, high=N-1, mid=0;
	while(low <= high){
		mid = (high + low) / 2;
		if(strcmp( w, list[mid].word)<0)
   			high = mid -1;
		else if(strcmp( w, list[mid].word)>0)
   			low = mid + 1;
		else { 
            list[mid].count++;
   			return 0;
		}
		}
	return insertWord(list, low, w);
}
int insertWord(struct Inode list[ ], int pos, char *w)
{
      int i;

      if  (N == 1024) return -1; 
              
     for(i=N-1; i>=pos; i--){
          strcpy(list[i+1].word, list[i].word);
          list[i+1].count = list[i].count;
     }
    strcpy(list[pos].word, w);
    list[pos].count = 1;
     N++;
     return 1;
}



