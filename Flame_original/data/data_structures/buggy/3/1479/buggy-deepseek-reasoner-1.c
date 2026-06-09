#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char num[1024]; 
char ans[1024];

int main()
{
    gets(num);
    int i;
    int ansCount=0;
    if(num[0]=='0'){//数字小于1 
        int count=1;
        int flag=0;
        for(i=2;i<strlen(num);i++){
            if(num[i]=='0'){
                count++;
            }
            else{
                flag=1;
                ans[ansCount]=num[i];
                ansCount++;
            }
        }
        printf("%c",ans[0]);//第一位数字 
        if(ans[1]!=0){//一位数字没小数点  // @@ 应使用ansCount>1判断是否有多位数字，且ans[1]可能未初始化
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){//小数点以后的数字  // @@ 应使用ansCount作为循环上限，因为ans未以'\0'结尾，strlen结果不确定
            printf("%c",ans[i]);
        }
        printf("e-%d",count);
    }
    else{//数字大于1 
    int eCount=0;
        for(i=0;i<strlen(num);i++){
            if(num[i]!='.'){
                ans[ansCount]=num[i];
                ansCount++;
                eCount++;
            }
            else{
                break;
            }
        }
        for(i=ansCount;i<=strlen(num);i++){ // @@ 循环条件i<=strlen(num)导致数组越界
            ans[i]=num[ansCount+1]; // @@ ansCount递增导致源索引不正确，且可能越界
            ansCount++;
        }
        printf("%c",ans[0]);
        if(ans[1]!='\0'){
            printf(".");
        }
        for(i=1;i<strlen(ans);i++){ // @@ 应使用ansCount代替strlen
            printf("%c",ans[i]);
        }
        printf("e%d",eCount-1);
    }
    return 0;
}