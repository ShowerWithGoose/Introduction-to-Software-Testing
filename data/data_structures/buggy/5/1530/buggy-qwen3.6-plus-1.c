#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#define M 5000
typedef struct{
    int coe;
    int index;
//    p next;
}multinomial,*p;
int cmp(void*p1,void*p2){
    p a=(p)p1;
    p b=(p)p2;
    return(b->index-a->index);
}
int main(void)
{
    multinomial mul1[M],mul2[M],ans[M];
    char ch;
    int i_1=0,i_2=0,num=0;
    do{
        scanf("%d %d%c",&mul1[i_1].coe,&mul1[i_1].index,&ch);
        i_1++;
    }while(ch==' ');
    do{
        scanf("%d %d%c",&mul2[i_2].coe,&mul2[i_2].index,&ch);
        i_2++;
    }while(ch==' ');
    qsort(mul1,i_1,sizeof(mul1[0]),cmp);
    qsort(mul2,i_2,sizeof(mul2[0]),cmp);
    for(int i=0;i<i_1;i++){
        for(int j=0;j<i_2;j++){
            ans[num].coe=mul1[i].coe*mul2[j].coe;
            ans[num].index=mul1[i].index+mul2[j].index;
            num++;
        }
    }
    qsort(ans,num,sizeof(ans[0]),cmp);
    for(int i=0;i<num;i++){ // @@ Out-of-bounds access when i == num-1 (accessing ans[i+1]); loop condition should be i < num - 1. Additionally, this single-pass logic fails to correctly merge more than two consecutive terms with the same exponent.
        if(ans[i].index==ans[i+1].index){
            ans[i].coe+=ans[i+1].coe;
            ans[i+1].coe=0;
            ans[i+1].index=0;
            continue;
        }
    }
    for(int i=0;i<num;i++){
        if(ans[i].coe==0&&ans[i].index==0) // @@ Should only check ans[i].coe == 0 to skip zero-coefficient terms; checking index is redundant and may incorrectly skip valid constant terms or fail to skip zero-coefficient terms with non-zero exponents.
            continue;
        else
            printf("%d %d ",ans[i].coe,ans[i].index);
    }
return 0;
}