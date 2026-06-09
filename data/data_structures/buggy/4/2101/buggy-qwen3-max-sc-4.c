#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000],word[1000][100];
int num,i,j,k;
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
    for(i=0;i<num;i++){
        for(j=0;j<num-i-1;j++){
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
    for(i=0;i<num;){
        k=1;
        if(strcmp(word[i],word[i+1])==0){
            k++;
            i++;
        }//如果相同的话，向后走 
        if(strcmp(word[i],word[i+1])!=0){
            sprintf(newword,"%s %d",word[i],k);
            strcpy(word[i],newword);
            puts(word[i]);
            i++;
        }//如果不同了，就输出最多的相同的数目和单词 
    }
} // @@ [The function accesses word[i+1] when i may be num-1, leading to out-of-bounds access. Also, it fails to count frequencies correctly because it only checks consecutive duplicates after sorting but doesn't aggregate all identical words properly. Additionally, it modifies the original word array by overwriting words with formatted strings like "word count", which breaks further processing and output format.]

int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(s,sizeof(s),in)!=NULL){
//        gets(s);
        changeword(s);
        readword(s);
    }
    sortword(word);
    sameword(word);
    return 0;
} // @@ [Global variables i, j, k, num are used without initialization (except where locally set), leading to undefined behavior. Specifically, 'j' and 'k' are not initialized to 0 before readword() is called, so word indexing starts from garbage values. Also, 'num' is incremented but never initialized to 0 at the start of main().]