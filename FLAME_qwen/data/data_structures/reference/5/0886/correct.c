//
//  main.c
//  多项式相乘
//
//  Created by  on 2022/3/24.
//

#include <stdio.h>
#include <stdlib.h>
struct duo{
    long long xi;
    long long zhi;
}a[2001], b[2001], ans[4000001];
int compare(const void *a, const void *b){
    struct duo* ia=(struct duo*)a;
    struct duo* ib=(struct duo*)b;
    if((ia->zhi < ib->zhi)||((ia->zhi == ib->zhi)&&(ia->xi > ib->xi)))
        return 1;
    else
        return -1;
}
int main() {
    int i=0, j=0, i1, j1, k=0, k1;
    char c1, c2;
    while(1){
        scanf("%lld %lld", &a[i].xi, &a[i].zhi);
        c1 = getchar();
        i++;
        if(c1=='\n')
            break;
    }
    while(1){
        scanf("%lld %lld", &b[j].xi, &b[j].zhi);
        c2 = getchar();
        j++;
        if(c2=='\n')
            break;
    }
    i1=i;
    j1=j;
    for(i=0;i<i1;i++){
        for(j=0;j<j1;j++){
            ans[k].xi=a[i].xi*b[j].xi;
            ans[k].zhi=a[i].zhi+b[j].zhi;
            k++;
        }
    }
    k1=k;
    qsort(ans,k1-1,sizeof(struct duo),compare);
    for(i=0;i<k1;i++){
        for(j=1;j<k1&&i+j<k1;j++){
            if(ans[i+j].zhi==ans[i].zhi){
                ans[i].xi+=ans[i+j].xi;
                ans[i+j].zhi=0;
            }
            else
                break;
            }
    }
    for(i=0;i<k1-1;i++){
        if(ans[i].zhi!=0)
            printf("%lld %lld ", ans[i].xi, ans[i].zhi);
    }
    printf("%lld %lld ", ans[k1-1].xi, ans[k1-1].zhi);
    return 0;
}

