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
}
void readword(char s[]){
    i=0;
    while(s[i]){
        if(s[i]>='a'&&s[i]<='z'){
            while(s[i]>='a'&&s[i]<='z'){
                word[j][k]=s[i];
                k++;
                i++;
            }
            word[j][k]='\0';
            j++;
            num++;
            k=0;            
        }
        else{
            i++;
        }
    }
}
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
}
void sameword(char word[][100]){
    char newword[100];
    for(i=0;i<num;){
        k=1;
        if(strcmp(word[i],word[i+1])==0){ // @@ Accessing word[i+1] may be out of bounds when i == num-1; also the logic fails to correctly count consecutive identical words and may skip the last group
            k++;
            i++;
        }
        if(strcmp(word[i],word[i+1])!=0){ // @@ Same out-of-bounds access; the loop never outputs the last group because there is no following different word
            sprintf(newword,"%s %d",word[i],k);
            strcpy(word[i],newword);
            puts(word[i]);
            i++;
        }
    }
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(s,sizeof(s),in)!=NULL){
        changeword(s);
        readword(s);
    }
    sortword(word);
    sameword(word);
    return 0;
}