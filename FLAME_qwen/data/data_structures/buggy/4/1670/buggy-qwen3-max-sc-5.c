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
        while(isalpha(k)){ @@ [This loop will run infinitely if k is alphabetic because k is never updated inside the loop. Also, it incorrectly converts k to lowercase but doesn't store it or advance input.]
            k=tolower(k);
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
        int index=0; @@ [The variable 'index' is declared and initialized but never used, which is harmless but indicates flawed logic; however, the real issue is that the sorting algorithm is a broken insertion sort that doesn't correctly maintain order due to missing break or proper shifting. But more critically, the program lacks #include <ctype.h>, causing implicit declaration of isalpha() and tolower(), which leads to compilation errors on strict compilers. However, since the error type is "Compilation Error" and the test shows "gcc: not found", that's environment-related—but per problem context, the actual code has semantic/logic errors. Yet note: the immediate compilation issue in many environments would be missing <ctype.h>. But the instruction says to mark lines with errors in the given code. The infinite loop is the critical runtime/logic flaw. Also, the condition `if(k>='a'&&k<='z')` after the while loop is redundant and wrong because if k was alphabetic, the while loop either infinite-loops or exits only when k is non-alpha, making this condition always false. So the word reading logic is fundamentally broken.]
        for(j=i;j>0;--j){
            if(strcmp(ch[j-1],ch[j])>0){
                strcpy(temp,ch[j]);
                strcpy(ch[j],ch[j-1]);
                strcpy(ch[j-1],temp);
            }
        }
    }
}