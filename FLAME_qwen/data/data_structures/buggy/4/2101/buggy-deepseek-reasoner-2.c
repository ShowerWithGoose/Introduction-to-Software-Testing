#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000],word[1000][100];
int num,i,j,k; // @@ global variables shared across functions can cause unexpected side effects (e.g., sortword modifies i and j, breaking later loop logic)
void changeword(char s[]){
   i=0;
    while(s[i]!='\0'){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]+'a'-'A';
        }
        i++;
    }
}//将所有大写字母改为小写字母 
void readword(char s[]){
    i=0;
    while(s[i]){
        if(s[i]>='a'&&s[i]<='z'){
            while(s[i]>='a'&&s[i]<='z'){
                word[j][k]=s[i];
                k++;
                i++;
            }//每个单词读入 
            word[j][k]='\0';
            j++;
            num++;
            k=0;            
        }
        else{
            i++;
        }//进入下一个单词 
    }
}//读入单词 
void sortword(char word[][100]){
    char temp[100];
    for(i=0;i<num;i++){ // @@ uses global i, but i is also used in other functions; should use local variables
        for(j=0;j<num-i-1;j++){ // @@ uses global j, which will be overwritten and cause issues later
            if(strcmp(word[j],word[j+1])>0){
                strcpy(temp,word[j+1]);
                strcpy(word[j+1],word[j]);
                strcpy(word[j],temp);
            }
        }
    }
}//单词按字典序数排序 
void sameword(char word[][100]){
    char newword[100];
    for(i=0;i<num;){ // @@ global i, value may be corrupted by sortword; also i < num but i increments inside loop, potential infinite loop or out-of-bounds
        k=1;
        if(strcmp(word[i],word[i+1])==0){ // @@ when i == num-1, word[i+1] accesses out-of-bounds memory
            k++;
            i++;
        }//如果相同的话，向后走 
        if(strcmp(word[i],word[i+1])!=0){ // @@ again out-of-bounds for last element; also logic fails for sequences of more than two identical words
            sprintf(newword,"%s %d",word[i],k);
            strcpy(word[i],newword);
            puts(word[i]);
            i++;
        }//如果不同了，就输出最多的相同的数目和单词 
    }
}
int main(){
    FILE *in;
    in=fopen("article.txt","r"); // @@ missing check for NULL; if file does not exist, program crashes
    while(fgets(s,sizeof(s),in)!=NULL){
//        gets(s);
        changeword(s);
        readword(s);
    }
    sortword(word);
    sameword(word);
    return 0;
}