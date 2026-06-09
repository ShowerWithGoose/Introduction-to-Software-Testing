#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define tolower(c)     (c>='A'&&c<='Z'?'a'-'A'+ c : c) // @@ Redefining the standard library macro 'tolower' from <ctype.h> causes a compilation error or warning.
char new[1000000],w[1000][100000]; // @@ 'new' is a reserved keyword in C++. If compiled with a C++ compiler, this causes a compilation error. Additionally, the array size is excessively large.
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
    else if(strcmp(a,b)<0) return -1; //第一个元素a>b，返回-1表示p指向的行的应该在q指向的行的前面
    else return 0; //第一个，第二个元素均相等，返回0表示p指向的行和q指向的行无确定前后关系
}
int main(){
    int i=0,n=0,k,j,o=0;
    FILE *p;
    p=fopen("article.txt","r"); // @@ Missing NULL check for the file pointer. If the file does not exist, p will be NULL, causing a runtime error when passed to fgets.
    while(fgets(new,1000000,p)!= NULL){
        //printf("%s",new);
        i=0; // @@ i is initialized to 0 but immediately incremented in the loop, causing the first character of each line (new[0]) to be skipped.
        while(1){
            i++; // @@ Increments i before processing, skipping new[0] and potentially causing out-of-bounds access if the line is empty.
            if(new[i]>='A'&&new[i]<='Z'){
                new[i]+=32;
            }
            if(new[i]>='a'&&new[i]<='z'){
                w[n][o++]=new[i];
            }
            else if(new[i]<'a'||new[i]>'z'){ // @@ This condition triggers for all non-lowercase characters (including spaces, punctuation, and '\0'), incorrectly incrementing n and creating empty/invalid words.
                count[n]=1;
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
        if(strcmp(w[i],w[i+1])==0){ // @@ Out-of-bounds array access when i equals n-1, as w[i+1] is uninitialized and accessing it causes undefined behavior.
            count[i+1]+=count[i]; // @@ Incorrect frequency counting logic. It adds the current word's count to the next word instead of accumulating duplicates correctly.
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