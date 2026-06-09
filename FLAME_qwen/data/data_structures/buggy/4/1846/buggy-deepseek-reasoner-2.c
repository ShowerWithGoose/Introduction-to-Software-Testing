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
    char c ; // @@ The variable c is declared as char, but fgetc returns int. If char is unsigned, EOF (-1) will be incorrectly stored, causing an infinite loop and failure to detect end-of-file.
    int len = 0 ,cnt = 0 ,flag = 0 ;
    //读取单词并存入表中
    while((c= fgetc(in))!=EOF){ // @@ The condition uses char c, which may not correctly compare to EOF if char is unsigned. This is a common source of runtime error, though not strictly a compilation error. Additionally, the loop will never terminate correctly if char is unsigned.
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
                alp[cnt].n = 1 ; // @@ This line sets the count for the *next* (uninitialized) word to 1, leaving the current word's count alp[cnt-1].n as 0 (since it was never set). As a result, the first word and every word except the last will have a count of 0, causing incorrect frequency output.
            }
        }
        }
        qsort(alp, cnt, sizeof(alp[0]), cmp) ;
        //合并重复项并统计词频
        int num = 0 ;
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
                          alp[j].n+=alp[i].n; // Because the first word's n is 0, this addition does not correctly accumulate counts; many words will have artificially low frequencies.
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