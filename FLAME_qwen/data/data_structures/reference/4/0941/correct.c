#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word{
    char name[50];
    int times;
} list[200];
int getword(FILE *fp,char *str);
char tolower(char c);
int comp(const void *a,const void *b);
int main(){
    FILE *in;
    in = fopen("article.txt","r");//article
    char c,word[50];
    int num = 0,flag = 0;
    while(getword(in,word) != 0){
        flag = 0;
        for(int i = 0;i<num;i++){
            if(strcmp(list[i].name,word) == 0){
                list[i].times++;
                flag = 1;
                break;
            }
        }
        if(flag == 1) continue;
        else{
            list[num].times = 1;
            strcpy(list[num].name,word);
            num++;
        }
    }
    qsort(list,num,sizeof(list[0]),comp);
    for(int i = 0;i<num;i++){
        printf("%s %d\n",list[i].name,list[i].times);
    }
    system("pause");
    return 0;
}
char tolower(char c){
    if(c >= 'a' && c <= 'z') return c;
    return c-'A'+'a';
}
int getword(FILE *fp,char *str){
    char c;
    int counter = 0;
    while((c = fgetc(fp)) != EOF){
        if((c<'a' || c>'z') && (c<'A' || c>'Z') && counter == 0){
            continue;
        }
        else if((c<'a' || c>'z') && (c<'A' || c>'Z') && counter > 0){
            str[counter] = '\0';
            return 1;
        }
        str[counter++] = tolower(c);
    }
    return 0;
}
int comp(const void *a,const void *b){
    struct word *aa = (struct word*)a;
    struct word *bb = (struct word*)b;
    return(strcmp(aa->name,bb->name));
}
