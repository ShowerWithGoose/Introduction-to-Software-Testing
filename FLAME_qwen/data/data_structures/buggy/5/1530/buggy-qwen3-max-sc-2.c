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
    } @@ [Accessing ans[i+1] when i == num-1 leads to out-of-bounds read, causing undefined behavior]
    for(int i=0;i<num;i++){
        if(ans[i].coe==0&&ans[i].index==0)
            continue;
        else
            printf("%d %d ",ans[i].coe,ans[i].index);
    } @@ [Fails to combine all like terms correctly; only merges adjacent duplicates once and leaves zero-coefficient terms that should be omitted entirely]
return 0;
}