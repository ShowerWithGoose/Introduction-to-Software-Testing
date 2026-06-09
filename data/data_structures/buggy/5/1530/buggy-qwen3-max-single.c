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
    } // @@ [This loop only merges adjacent duplicate exponents once, but after setting ans[i+1] to zero, it may still leave non-adjacent duplicates or fail to fully combine all like terms. Also, accessing ans[i+1] when i == num-1 leads to out-of-bounds read.]
    for(int i=0;i<num;i++){
        if(ans[i].coe==0&&ans[i].index==0)
            continue;
        else
            printf("%d %d ",ans[i].coe,ans[i].index);
    } // @@ [This output logic incorrectly skips only terms where both coefficient and exponent are zero. However, during merging, zero-coefficient terms with non-zero exponents (e.g., from cancellation) are not skipped, leading to incorrect output. Also, the previous merging step is flawed, so zero coefficients may remain unhandled.]
return 0;
}