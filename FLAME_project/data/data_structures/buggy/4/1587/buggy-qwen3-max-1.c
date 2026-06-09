#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct words
{
    char str[50];
    int cnt;
}word;

int cmp(const void*a,const void*b){
    word*a1=(word*)a;
    word*b1=(word*)b;
    return strcmp(a1->str,b1->str);
}
int main(){
word*list=NULL;
 FILE*fp=fopen("article.txt","r");
 char ch;
 int i=0;
 int j=0;
 while((ch=fgetc(fp))!=EOF){
    if(isalpha(ch)){
       list=(word*)realloc(list,sizeof(word)*(i+1));
       if(isupper(ch)){
        list[i].str[j]=ch+32;
       }
       else{
        list[i].str[j]=ch;
        }
       list[i].cnt=0; // @@ [The count should be initialized to 1 for the first occurrence of the word, not 0.]
       j++;
    while(isalpha(ch=fgetc(fp))){
        if(isupper(ch)){
        list[i].str[j]=ch+32;
       }
       else{
        list[i].str[j]=ch;
       }
       j++;
      }
    list[i].str[j]='\0';
    list[i].cnt++; // @@ [This increments from 0 to 1, but due to previous initialization to 0, it's correct only if no prior increment happened. However, the real issue is in the merging logic later.]
    i++;
    j=0;
    }
 }

qsort(list,i,sizeof(word),cmp);
int k=0;
while (k<i)
{
    if(strcmp(list[k].str,list[k+1].str)==1&&k+1<i){ // @@ [strcmp returns >0 if first string is lexicographically greater, not necessarily 1. Also, this condition should check for equality (==0), not ==1. This causes incorrect grouping of duplicate words.]
        list[k+1].cnt+=list[k].cnt;
        k++;
        while (strcmp(list[k].str,list[k+1].str)==1&&k+1<i) // @@ [Same error: should check ==0 for equality, not ==1. This prevents proper accumulation of frequencies for repeated words.]
        {
            list[k+1].cnt+=list[k].cnt;
            k++;
        }
        printf("%s %d\n",list[k].str,list[k].cnt);
        k++;
    }
    else{
       printf("%s %d\n",list[k].str,list[k].cnt);
       k++;
    }
}
fclose(fp);
free(list);
    return 0;
}