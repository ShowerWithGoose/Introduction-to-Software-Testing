#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct num{
    int coe;
    int exp;
};
int cmp(const void *e1,const void *e2){
    struct num *p1=(struct num*)e1;
    struct num *p2=(struct num*)e2;
    return -(p1->exp-p2->exp);
}
int main()
{   struct num in1[200],in2[200],out[500];
    int i,j,k;
    for(i=0;;i++){
        scanf("%d %d",&in1[i].coe,&in1[i].exp);
        if(in1[i].exp==0)
        break;
    }
    int cnt1=i; @@ [The loop breaks when exponent is 0, but the constant term (exp=0) is valid and should be included. This causes the last term (with exp=0) to be read but then immediately break, so cnt1 becomes the index of the term with exp=0, which is correct. However, the next loop has the same issue but more critically, the multiplication loop uses <=cnt1 and <=cnt2, which leads to out-of-bound access because arrays are 0-indexed up to cnt1-1 and cnt2-1.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; @@ [Same issue as above: cnt2 is set to j which is the index of the term with exp=0, so valid terms are from 0 to cnt2. But in the multiplication loop, using <=cnt2 will access in2[cnt2+1] which is uninitialized.]
    for(i=0,k=0;i<=cnt1;i++){ @@ [Loop condition should be i < cnt1, not i <= cnt1. Because cnt1 is the number of terms (since i was incremented after reading the last term), valid indices are 0 to cnt1-1. Using <=cnt1 accesses in1[cnt1], which is uninitialized. Same for j<=cnt2.]
        for(j=0;j<=cnt2;j++,k++){ @@ [Same error: j should go up to cnt2-1, not cnt2. This causes reading beyond the input data and writing garbage into out[].]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ @@ [Accesses out[k+1] when k = cnt3-1, which is out-of-bounds. Also, merging logic is flawed: it only merges consecutive duplicates after sorting, but doesn't handle multiple same exponents properly. Moreover, it prints before merging all duplicates.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}