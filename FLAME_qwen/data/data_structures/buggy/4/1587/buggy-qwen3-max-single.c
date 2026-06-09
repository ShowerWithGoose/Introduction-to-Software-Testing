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
       list[i].cnt=0; // @@ [The count should be initialized to 1 after reading a complete word, not 0. Also, this assignment is misplaced—it runs before the full word is read.]
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
    list[i].cnt++; // @@ [This increments from 0 to 1, which works, but the earlier initialization to 0 is confusing and error-prone. However, the real issue is that 'ch' after the inner while loop is the first non-alpha character, but the outer loop doesn't reprocess it, causing potential missed characters if multiple non-alpha chars appear. But more critically, the logic for reading words skips non-alpha correctly, so this may not be the main bug.]
    i++;
    j=0;
    }
 }

qsort(list,i,sizeof(word),cmp);
int k=0;
while (k<i)
{
    if(strcmp(list[k].str,list[k+1].str)==1&&k+1<i){ // @@ [strcmp returns 0 for equal strings, <0 if first < second, >0 otherwise. Using ==1 is incorrect; it should be ==0 to check equality. This causes wrong grouping of identical words.]
        list[k+1].cnt+=list[k].cnt;
        k++;
        while (strcmp(list[k].str,list[k+1].str)==1&&k+1<i) // @@ [Same error: using ==1 instead of ==0 for string equality. This prevents proper aggregation of duplicate words.]
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