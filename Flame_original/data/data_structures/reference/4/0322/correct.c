#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    char word[30];
    int times;
};
struct node wordlist[1000];
int cmp(const void *e1, const void *e2){
    struct node *a = (struct node *)e1;
    struct node *b = (struct node *)e2;
    return (strcmp(a->word,b->word));
}

int main(){
    int c;
    int i=0,j=0,k,flag=0;
    int endings=0;

    FILE *in;
    in=fopen("article.txt","r");

    while(c=fgetc(in)){
    //while(c=getchar()){
        if(c!=EOF){
            if(c>=65 && c<=90){//大写全转小写
                c=c+32;
            }
            if(c>=97 && c<=122){
                if(j==0){
                    i++;
                    endings=0;
                }
                wordlist[i].word[j]=c;
                j++;
            }
            else{//读完了一个单词
                endings++;
                if(endings==1){//可能有多个停止标志字符
                    wordlist[i].word[j]='\0';
                    for(k=0;k<i;k++){
                        if(strcmp(wordlist[k].word,wordlist[i].word)==0){//新词与前相同
                            wordlist[k].times++;
                            memset(wordlist[i].word,0,strlen(wordlist[i].word));
                            i--;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){//新词第一次出现
                        wordlist[i].times=1;
                    }
                    flag=0;
                    j=0;
                }
                else{
                    endings--;
                    continue;
                }
            }
        }
        else
            break;
    }
    qsort(wordlist,i+1,sizeof(wordlist[0]),cmp);
    for(k=1;k<i+1;k++){
        if(k<i)
            printf("%s %d\n",wordlist[k].word,wordlist[k].times);
        else if(k==i)
            printf("%s %d",wordlist[k].word,wordlist[k].times);
    }
    fclose(in);
    return 0;
}
