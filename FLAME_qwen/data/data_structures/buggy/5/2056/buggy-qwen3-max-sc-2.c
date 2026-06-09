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
    int cnt1=i; @@ [The loop breaks when exponent is 0, but the constant term (exp=0) is valid and should be included. This causes the last term (with exp=0) to be read but then terminate, so cnt1 becomes the index of the last term, but the loop condition excludes further terms even if more exist after a zero exponent (though per problem only non-zero coefficients are given, but exp=0 is allowed). However, the real issue is that input may not end with exp=0, so this logic incorrectly assumes polynomial ends with x^0 term.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; @@ [Same error as above: assumes second polynomial ends with exponent 0, which may not be the case if the constant term is absent or if input doesn't include it last.]
    for(i=0,k=0;i<=cnt1;i++){ @@ [Loop runs from i=0 to i<=cnt1, but cnt1 is the index of the last valid term (since break happened at i where exp==0), so in1[cnt1] is valid, but the loop should run i < cnt1+1? Actually, since cnt1 = i after break, and i was incremented after reading the term with exp=0, the valid indices are 0 to cnt1 inclusive? But original read loop: for(i=0;;i++) reads into in1[i], then checks if exp==0 -> break. So if first term has exp=0, i=0, then break, cnt1=0, and in1[0] is valid. Then loop i<=cnt1 means i=0 only — correct. But if polynomial has terms: 2 3 1 0, then i=0: read 2 3 → no break; i=1: read 1 0 → break; cnt1=1. Then i<=cnt1 → i=0,1 → correct. So indexing may be okay. However, the bigger issue is assuming input always contains a term with exp=0 to terminate, which is not guaranteed by problem statement. Problem says: "Only terms with non-zero coefficients will appear", and exponents are non-negative integers. The polynomial might not have a constant term (e.g., 2x^2 + 3x^1), so exp never becomes 0, and loop never breaks → infinite loop or undefined behavior. This is a critical logic error.]
        for(j=0;j<=cnt2;j++,k++){ @@ [Same issue: assumes cnt2 correctly represents number of terms, but if second poly doesn't end with exp=0, cnt2 is wrong. Also, j<=cnt2 implies cnt2+1 terms, but if cnt2=j after break, and j was index of term with exp=0, then terms are 0..cnt2 inclusive → cnt2+1 terms. But if no exp=0, loop never breaks → undefined.]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ @@ [Accesses out[k+1] when k = cnt3-1 → out-of-bounds read. Also, merging logic is flawed: it only merges consecutive duplicates after sorting, but adds current to next and skips printing current via 'continue', yet prints every element regardless. This leads to incorrect combination and possible printing of zero-coefficient terms. Moreover, condition 'out[k+1].exp!=0' is arbitrary and wrong — terms with exp=0 should also be merged.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}