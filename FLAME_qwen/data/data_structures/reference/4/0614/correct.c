#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define len 25
#define MAXSIZE 1005
struct node {
    char word[len];
    int times;
} words[MAXSIZE];
int cnt = 0;
void insert(struct node num[],int size, int now, char *word)
{
    if(size == MAXSIZE) 
    {
        printf("FULL\n");
        return;
    }
    if(size == 0)
    {
        strcpy(num[now].word,word);
        num[now].times++;
        cnt++;
        return;
    }
    for(int i = size; i > now; i--)
    {
        strcpy(num[i].word,num[i-1].word);
        num[i].times = num[i-1].times;
    }
    strcpy(num[now].word,word);
    num[now].times = 1;
    cnt++;
    return;
    
}
int binarysearch(struct node num[], int size, char* word)
{
    int right = size - 1,left = 0;
    int mid;
    if(right >= MAXSIZE) return -1;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(strcmp(num[mid].word,word) == 0)
        {
            num[mid].times++;
            return 1;
        }
        else if(strcmp(num[mid].word,word) < 0)
        {
            left = mid + 1;
        } 
        else if(strcmp(num[mid].word,word) > 0)
        {
            right = mid - 1;
        }
    }
    insert(num,size,left,word);
    return 0;
}
char arr[MAXSIZE];
int getword(char source[], char word[],int size_word )
{
    int i,j;
    int n = MAXSIZE - 1;
    for(i = 0; (!isalpha(source[i])) &&(i < n); i++);
    if(i >= n) return -1;
    for(j = 0; isalpha(source[i]);i++,j++)
    {
        word[j] = tolower(source[i]);
        source[i] = '\0';
    }
    if(i >= n) return -1;
    return 1;
}
int main()
{
	FILE *in;
    in = fopen("article.txt","r");
    while(fgets(arr,1048,in) != NULL)
    {
        char word[len] = {0};
        while(getword(arr,word,len) != -1)
        {
            binarysearch(words,cnt,word);
            memset(word,'\0',sizeof(word));
        }
        memset(arr,'\0',MAXSIZE);
    }
	for(int i = 0; words[i].times != 0; i++)
    {
        printf("%s %d\n",words[i].word,words[i].times);
    }
	return 0;
} 


