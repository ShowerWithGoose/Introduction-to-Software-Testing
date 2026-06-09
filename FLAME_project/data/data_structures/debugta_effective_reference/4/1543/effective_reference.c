#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024
struct lnode {
    char w[MAXWORD];
    int count;
};
int getWord(FILE *in,char *w);
int searchWord(struct lnode list[], char *w);
int insertWord(struct lnode list[],  int pos, char *w);
int N=0; //单词表中单词的实际个数
int main()
{
    struct lnode wordlist[MAXSIZE];	/*单词表*/
    int i;
    char filename[MAXWORD], w[MAXWORD];
    FILE *in;

    //scanf("%s", filename); if((
	in = fopen("article.txt", "r");  /* ) == NULL){
        fprintf(stderr, "%s  can’t open!\n",filename);
        return -1;
    }                         */

    while( getWord(in,w) != -1)    //EOF
        searchWord(wordlist, w)  ;
		/*== -1) {           //清除非字母的字符
            fprintf(stderr, "Wordlist is full!\n");
            return -1;
        }   */
    for(i=0; i<= N-1; i++)
        printf("%s %d\n", wordlist[i].w, wordlist[i].count);
	fclose(in);
    return 0;
}

int getWord(FILE *fp, char *w){       //从文件读入一个单词 仅由字母组成的串，并转换成小写字母
	int c;
	while(!isalpha(c=fgetc(fp))){
		if(c == EOF) return c;
		else continue;
	}

	do {
		*w++= tolower(c);
	} while(isalpha(c=fgetc(fp))) ;
	*w='\0';
	return 1;

}

 /*在表中相应位置插入一个单词，同时置次数为1*/
int insertWord(struct lnode list[ ], int pos, char *w) {
	int i;
	if(N==MAXSIZE) return -1 ;
	for(i=N-1;i>=pos;i--){
		strcpy(list[i+1].w, list[i].w) ;
		list[i+1].count = list[i].count;
	}
	strcpy(list[pos].w,w);
	list[pos].count=1;
	N++ ;
	return 1;
}

 /*在表中查找一单词，若找到，则次数加1:否则将该单词插入到有序表中相应位置。同时次数置1*/
int searchWord(struct lnode list[], char *w) {
	int low=0,high=N-1,mid=0;
	while(low <= high){
		mid=(high + low) / 2;
		if(strcmp(w, list[mid].w)<0)   high =mid -1;
		else if(strcmp( w, list[mid].w)>0)  low=mid+1;
		else{
			list[mid].count++;
			return 0;
		}
 	}
	return insertWord(list, low, w);
}
/*在本程序中:查找算法复杂度为O(log2n)
插入算法复杂度为O(n)*/

