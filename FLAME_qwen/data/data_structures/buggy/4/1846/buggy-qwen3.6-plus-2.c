#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//创建词频统计表
struct word{
    char a[200] ;
    int n ;
}alp[2000];

//qsort的比较函数
int cmp (const void *x, const void *y){
    struct word *p = (struct word *)x ;
    struct word *q = (struct word *)y ;
    return strcmp(p->a, q->a) ;
}

int main(){
    FILE *in ;
    in = fopen("article.txt", "r") ;
    char c ; // @@ 'c' should be declared as 'int' because fgetc() returns an int. Using 'char' can cause incorrect EOF comparison (especially if char is unsigned), leading to an infinite loop or compilation warning treated as error.
    int len = 0 ,cnt = 0 ,flag = 0 ;
    //读取单词并存入表中
    while((c= fgetc(in))!=EOF){
        if((c>='a' && c<='z')||(c>='A' && c<='Z')){
            c = tolower(c) ;
            alp[cnt].a[len++] = c ;
            flag = 1 ;
        }
        else{
            if(flag == 1){
                alp[cnt].a[len] = '\0' ;
                flag = 0 ;
                len = 0 ;
                cnt ++ ;
                alp[cnt].n = 1 ; // @@ This initializes the count for the next word (after cnt is incremented), leaving the current word's count as 0. It should be 'alp[cnt-1].n = 1;' or set before incrementing cnt. Also, if the file ends with a letter, this block is skipped, causing the last word to be lost.
            }
        }
        }
        qsort(alp, cnt, sizeof(alp[0]), cmp) ;
        //合并重复项并统计词频
        int num = 0 ; // @@ Variable 'num' is declared but never used, which may trigger a compilation error under strict compiler flags (-Werror).
 //       for (int i = 0; i < cnt; i++) {
 //           if(strcmp(alp[num].a, alp[i].a) == 0)
   //             alp[num].n++ ;
     //       else{
       //         alp[++num] = alp[i] ;
         //       alp[num].n++ ;
           // }
      //  }
              for(int i=1;i<cnt;i++)
              {
                  for(int j=0;j<i;j++)
                  {
                      if(strcmp(alp[j].a, alp[i].a) ==0 )
                      {
                          alp[j].n+=alp[i].n;
                          alp[i].n=0;
                          break;
                      }
                  }
              }
        //按字典序排序
        qsort(alp, cnt, sizeof(alp[0]), cmp) ;
        //输出
        for (int i = 0; i < cnt; i++) {
            if(alp[i].n)
                printf("%s %d\n",alp[i].a, alp[i].n) ;
        }
        
    fclose(in);
    
    return 0 ;
}