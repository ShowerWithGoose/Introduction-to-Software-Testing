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
        k=1; // @@ The counter k is reset to 1 at the start of every iteration of the outer loop, but it is only incremented inside the 'if' block. If the current word is not equal to the next one, k remains 1, which is correct for a single occurrence. However, the logic flow is flawed because if words are equal, i is incremented and k is incremented, but then the second 'if' checks the NEW i against i+1. This structure fails to accumulate counts for more than 2 consecutive identical words correctly or handles the transition incorrectly. Specifically, if word[i]==word[i+1], k becomes 2, i increments. Then it checks word[new_i] vs word[new_i+1]. If they are different, it prints word[new_i] with count 2. This misses the fact that the previous group might have had more matches if the logic was intended to group all. But the main error here is that `k` is not accumulated properly across multiple matches in a standard grouping loop. A standard approach would use a while loop to find the end of the group. Here, if we have 3 same words: i=0, word[0]==word[1], k=2, i=1. Next iter: i=1, k=1 (RESET!). word[1]==word[2], k=2, i=2. Next iter: i=2, k=1. word[2]!=word[3]. Print word[2] with count 1. The first two were effectively lost or printed incorrectly? No, wait. The print happens when they are DIFFERENT. So at i=0, if w[0]==w[1], it doesn't print. It goes to next i. At i=1, if w[1]==w[2], it doesn't print. It goes to next i. At i=2, if w[2]!=w[3], it prints w[2] with k=1. The previous occurrences were never printed. This logic is completely broken for counting frequencies.]
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
}
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
}