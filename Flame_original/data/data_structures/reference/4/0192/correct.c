#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

typedef struct Node
{
    char data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;
typedef struct{
    char word[50];
    int cnt;
}List;

int cmp_struct(const void *a ,const void *b ) //struct排序(单关键字) 
{
	List c=*(List*)a;
    List d=*(List*)b;
    if(strcmp(c.word,d.word)>0){
		return 1;
	}else{
		return -1;
	}
}
int find(List l[],char word[],int j){
    if(j<0)return -1;
    int max=j,min=0,mid;
    while(min<=max){
        mid=(max+min)/2;
        if(strcmp(word,l[mid].word)<0){
            max=mid-1;
        }else if(strcmp(word,l[mid].word)>0){
            min=mid+1;
        }else return mid;
    }
    return -1;
}

int main(void)
{
    FILE *fp;
    fp=fopen("article.txt","r");
    List l[10000];
    int i,j=-1;
    char line[1024],word[50];
    while(fgets(line,1024,fp)!=NULL){
        i=0;
        while(i<strlen(line)){
            if(!isalpha(line[i])){
                i++;
            }
            else{
                sscanf(&line[i],"%s",word);
                for(int i=0;i<strlen(word);i++){
                    if(!isalpha(word[i]))word[i]='\0';
                    word[i]=tolower(word[i]);
                }
                while(isalpha(line[i]))i++;
                int cnt=find(l,word,j);
                if(cnt==-1){
                    j++;
                    l[j].cnt=1;
                    strcpy(l[j].word,word);
                    qsort(l,j+1,sizeof(l[0]),cmp_struct);
                }else{
                    l[cnt].cnt++;
                }
            }
        }
    }
    for(int i=0;i<=j;i++){
        printf("%s %d\n",l[i].word,l[i].cnt);
    }
    return 0;
}
