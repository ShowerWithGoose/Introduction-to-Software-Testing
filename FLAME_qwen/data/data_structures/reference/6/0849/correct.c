/*
 * @Author: your name
 * @Date: 2022-02-21 23:40:19
 * @LastEditTime: 2022-04-14 21:16:47
 * @LastEditors: Please set LastEditors
 * @Description: ??koroFileHeader???? ????: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \c_code\1.c
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int operate,a,count;
    int array[100];
    while (scanf("%d",&operate)!=EOF&&operate!=-1)
    {
        if(operate==1)
        scanf("%d ",&a);

        if(count==0&&operate==0){
            printf("error ");
            continue;
        }
        else if(count==99&&operate==1){
            printf("error ");
            continue;
        }
        else if(operate==1){
            array[count++]=a;
        }
        else if(operate==0){
            printf("%d ",array[--count]);
        }
    }
    return 0;
    
}

