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
    char c ;
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
                alp[cnt].n = 1 ; // @@ [Error: When a new word is started, the count for the new word should be initialized to 1, but here it sets alp[cnt].n = 1 after incrementing cnt, which means the first word's count (alp[0].n) is never set to 1, and the new word's count is set correctly but the previous word's count remains uninitialized. Additionally, the first word's count should be set to 1 when it is first created, but it is never initialized.]
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
                          alp[j].n+=alp[i].n;
                          alp[i].n=0;
                          break;
                      }
                  }
              }
        //按字典序排序
        qsort(alp, cnt, sizeof(alp[0]), cmp) ; // @@ [Error: After merging duplicates, the array may have entries with alp[i].n == 0, but qsort still sorts all cnt elements including those with zero count. This can cause incorrect ordering and output of zero-count entries. The output loop checks for alp[i].n, but the sorting of zero-count entries may interfere with the order of valid entries.]
        //输出
        for (int i = 0; i < cnt; i++) {
            if(alp[i].n)
                printf("%s %d\n",alp[i].a, alp[i].n) ;
        }
        
    fclose(in);
    
    return 0 ;
}