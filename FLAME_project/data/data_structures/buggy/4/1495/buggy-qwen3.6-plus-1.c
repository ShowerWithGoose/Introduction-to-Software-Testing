#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define tolower(c)     (c>='A'&&c<='Z'?'a'-'A'+ c : c)
char new[1000000],w[1000][100000];
int count[1000];
/*int searchElem(struct line list[ ],struct line ){
    int low=0, high=n-1, mid;
    while(low<=high){
        mid=(high+low)/2;
        if(item<list[mid]) high=mid-1;
        else if(item>list[mid]) low=mid+1;
        else return (mid);
    }
    return low ;
}*/
int rise(const void *p,const void *q){
    char *a = (char *)p;
    char *b = (char *)q;
    if(strcmp(a,b)>0) return 1; //第一个元素a<b，返回1表示p指向的行应该在q指向的行的后面
    else if(strcmp(a,b)<0) return -1; //第一个元素a>b，返回-1表示p指向的行应该在q指向的行的前面
    else return 0; //第一个，第二个元素均相等，返回0表示p指向的行和q指向的行无确定前后关系
}
int main(){
    int i=0,n=0,k,j,o=0;
    FILE *p;
    p=fopen("article.txt","r");
    while(fgets(new,1000000,p)!= NULL){
        //printf("%s",new);
        i=0;
        while(1){
            i++; @@ The loop starts incrementing i before checking the character at index 0, causing the first character of each line to be skipped. It should be i++ after processing or initialize i=-1.
            if(new[i]>='A'&&new[i]<='Z'){
                new[i]+=32;
            }
            if(new[i]>='a'&&new[i]<='z'){
                w[n][o++]=new[i];
            }
            else if(new[i]<'a'||new[i]>'z'){
                count[n]=1; @@ This logic incorrectly increments n (word count) for every non-letter character, creating empty or invalid words when multiple non-letters appear consecutively or at the end of a word. It should only create a new word entry if a word was just being formed (o > 0).
                n++;
                o=0;
            }
            //printf("%s\n",w[n]);
            /*else*/ if(new[i]=='\0') break;
        }
    }
    qsort(w,n,sizeof(char[100000]),rise);
    for(i=0;i<n;i++){
        //for(k=i;k<n;k++){
        if(strcmp(w[i],w[i+1])==0){ @@ This comparison accesses w[i+1] which is out of bounds when i == n-1. Also, the logic for merging counts is flawed because it doesn't handle the last element correctly and relies on sorted order but modifies the array in place without proper cleanup of merged entries.
            count[i+1]+=count[i];       
            w[i][0]='\0';
        }
        //}
    }
    for(i=0;i<n;i++){
        if(w[i][0]!='\0') printf("%s %d\n",w[i],count[i]);
    }
    fclose(p);
    return 0;
}