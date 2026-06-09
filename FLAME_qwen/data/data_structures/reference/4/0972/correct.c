#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h> 
struct node{
    char word[100];
    int flag;
    int number;
}art[1000];
int cmp(const void *a,const void *b){
    return strcmp((*(struct node*)a).word,(*(struct node*)b).word);
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    for(int i=0;i<1000;i++){
        art[i].flag=1;
        art[i].number=1;
    }
    char s[100000];
    int c;
    int cnt=0;
    int k=0,j=0;
    while((c=fgetc(in))!=EOF){
        s[cnt++]=c;
    }
    for(int i=0;i<strlen(s);i++){
        if(!isalpha(s[i])){
            k++;
            j=0;
        }
        else if(isalpha(s[i])){
            art[k].word[j++]=tolower(s[i]);
        }
    }
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(art[i].flag==0){
                break;
            }
            if(strcmp(art[i].word,art[j].word)==0&&art[i].flag==1){
                art[i].number++;
                art[j].flag=0;
            }
        }
    }
    qsort(art,k,sizeof(art[0]),cmp);
    for(int i=0;i<k;i++){
        if(art[i].flag!=0&&isalpha(art[i].word[0])){
            printf("%s %d\n",art[i].word,art[i].number);
        }
    }
    fclose(in);
    return 0;
}
