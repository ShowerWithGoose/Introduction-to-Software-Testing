#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char temp[10005];
char ch[10005][30];
void arr_sort(char [][30],int );
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    char k;
    int len=0,sign=0,j=0;
    while((k=fgetc(in))!=EOF){
        //printf("%c",k);
        while(isalpha(k)){ // @@ [Error: isalpha is used without including <ctype.h>, causing implicit function declaration error]
            k=tolower(k); // @@ [Error: tolower is used without including <ctype.h>, causing implicit function declaration error]
        }
        if(k>='a'&&k<='z'){
            ch[len][j++]=k;
            sign=1;
        }
        else{
            if(sign==1){
                ch[len][j++]='\0';
                j=0;
                len++;
                sign=0;
            }
        }
    }
    arr_sort(ch,len);
    int ans=1,i=0;
    for(i=0;i<len;i++){
        if(i<len-1){
            if(strcmp(ch[i],ch[i+1])==0){
                ans++;
                continue;
            }
            else{
                printf("%s %d\n",ch[i],ans);
                ans=1;
            }
        }
        else{
            printf("%s %d\n",ch[i],ans);
        }
    }
    return 0;
} 

void arr_sort(char ch[][30],int len){
    int i=1,j;
    for(i=1;i<len;++i){
        int index=0;
        for(j=i;j>0;--j){
            if(strcmp(ch[j-1],ch[j])>0){
                strcpy(temp,ch[j]);
                strcpy(ch[j],ch[j-1]);
                strcpy(ch[j-1],temp);
            }
        }
    }
}