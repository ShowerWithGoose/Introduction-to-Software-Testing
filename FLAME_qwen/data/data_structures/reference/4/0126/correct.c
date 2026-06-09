#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 1024
typedef struct wtf{
    char a[50];
    int frequency;
}stuff;
typedef struct list{
    stuff words[MAXSIZE];
    int num;
}sqlist;

int cmp(const void *a , const void *b){
    stuff *p1 = (stuff*)a;
    stuff *p2 = (stuff*)b;
    return strcmp(p1->a , p2->a);
}

void lower_qu(char *a , char *b){
    int i , len = 0 ;
    for(i = 0 ; i < strlen(a) ; i++)//小写
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] - 'A' + 'a';
    for(i = 0 ; i < strlen(a) ; i++)//字母赋给b串
        if(a[i] >= 'a' && a[i] <= 'z')
            b[len++] = a[i];
}

void init(sqlist *b){
    for(int i = 0 ; i < MAXSIZE ; i++){
        memset(b->words[i].a , 0 , 50);
        b->words[i].frequency = 0;
    }
    b->num = 0;
}

int is_letter(int a){
    if( (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 1;
    return 0;
}
//读一个单词
int vvord(FILE *f , char *a ){
    char ch , liter;
    int len = 1 , flag = 2;
    while(!is_letter(liter = fgetc(f))){//跳过非字母
        flag++;
        if(flag >= 1000) break;
    }
    a[0] = liter;
    while(is_letter(ch = fgetc(f))){
        a[len++] = ch;
        flag = 1;
    }
    return (int)strlen(a);
}

int main(){
    FILE *fp = NULL;
    fp = fopen("article.txt", "r");
    sqlist file;
    init(&file);
    char hold1[50] , hold2[50] ;
    for( ; vvord(fp , hold1) != 0 ; memset(hold1 , 0 , 50 ) , memset(hold2 , 0  , 50)){
    /*int n;
    scanf("%d",&n);
    for(int j = 0 ; j < n ; j++){*/
        lower_qu(hold1 , hold2);
        if(file.num == 0){
            file.words[0].frequency++;//录入第一个
            strcpy(file.words[0].a, hold2);
            file.num++;
        }
        else{
            int flag = 0;
            for(int i = 0 ; i < file.num ; i++){//遍历顺序表
                if(strcmp(file.words[i].a, hold2) == 0){
                    file.words[i].frequency++;
                    break;
                }
                else if(strcmp(file.words[i].a, hold2) != 0)
                    flag++;
            }
            if(flag == file.num){//新单词
                file.words[file.num].frequency++;
                strcpy(file.words[file.num].a, hold2);
                file.num++;
            }
        }
        if(file.words[file.num - 1].frequency >=20)
            break;
    }
    qsort(file.words, file.num, sizeof(stuff), cmp);
    for(int i = 0 ; i < file.num ; i++){
        if(strcmp(file.words[i].a, "") != 0)
            printf("%s %d\n" , file.words[i].a , file.words[i].frequency);
    }
    fclose(fp);
    return 0;
}

