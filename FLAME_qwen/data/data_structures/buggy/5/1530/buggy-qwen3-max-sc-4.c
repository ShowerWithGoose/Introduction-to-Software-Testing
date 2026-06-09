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
    for(int i=0;i<num;i++){
        if(ans[i].index==ans[i+1].index){
            ans[i].coe+=ans[i+1].coe;
            ans[i+1].coe=0;
            ans[i+1].index=0;
            continue;
        }
    } // @@ [This loop only merges adjacent duplicate exponents once; it fails to handle cases where more than two terms have the same exponent or where merging creates new duplicates later in the array.]
    for(int i=0;i<num;i++){
        if(ans[i].coe==0&&ans[i].index==0)
            continue;
        else
            printf("%d %d ",ans[i].coe,ans[i].index);
    } // @@ [This output loop prints terms with zero coefficient if their exponent is non-zero (e.g., due to cancellation), and also may access ans[num] (out-of-bounds) in the previous loop when i = num-1.]
return 0;
}