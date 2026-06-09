#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
        int coe;
        int pow;
    } P;
P a[2000],b[2000],c[2000]; // @@ Array c is too small. It should accommodate up to n1*n2 terms, e.g., c[10005].
int cmp(const void *p1,const void *p2);
int main(){
    int i,j,n1,n2,n3=0;
    char m;
    n1=0,n2=0;
    do{
        scanf("%d%d%c",&a[n1].coe,&a[n1].pow,&m);
        n1++;
    }while(m!='\n');
    do{
        scanf("%d%d%c",&b[n2].coe,&b[n2].pow,&m);
        n2++;
    }while(m!='\n');
    qsort(a,n1,sizeof(P),cmp);
    qsort(b,n2,sizeof(P),cmp);
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            c[n3].coe=a[i].coe*b[j].coe;
            c[n3].pow=a[i].pow+b[j].pow;
            n3++;
        }
    }
    qsort(c,n3,sizeof(P),cmp);
    for(i=0;i<n3;i++){ // @@ Loop bound should be i < n3 - 1 to avoid out-of-bounds access to c[i+1] when i = n3 - 1.
        if(c[i].pow==c[i+1].pow&&c[i].pow!=0){ // @@ The condition c[i].pow!=0 incorrectly skips combining constant terms. Also, this single-pass logic fails to correctly merge more than two terms with the same exponent.
            c[i].coe+=c[i+1].coe;
            c[i+1].coe=0;
        }
    }
    qsort(c,n3,sizeof(P),cmp);
    for(i=0;i<n3;i++){
        if(c[i].coe!=0)
        printf("%d %d ",c[i].coe,c[i].pow);
        else
        continue;
    }
    return 0;
}
int cmp(const void *p1,const void *p2){
 P *a=(P*)p1;
 P *b=(P*)p2;
    return b->pow-a->pow;
}