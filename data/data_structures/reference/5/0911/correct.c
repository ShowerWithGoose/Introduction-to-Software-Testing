#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct number{
    int co; // coefficient
    int in; // index
}a[10001], b[10001], res[50001];
int rank[50001];
int main()
{
    char c = 'c';
    int i = 0, j = 0, k = 0, m = 0, n = 0, l = 0;
    int total = 0, temp = 0;
    int tmp_co = 0, tmp_in = 0;
    for(l=0;l<=50000;++l) res[l].co = res[l].in = 0;
    //input
    do{
        i += 1;
        scanf("%d %d", &a[i].co, &a[i].in);
        c = getchar(); // 读掉指数后面的字符
    }while(c != '\n');
    do{
        j += 1;
        scanf("%d %d", &b[j].co, &b[j].in);
        c = getchar(); // 读掉指数后面的字符
    }while(c != '\n');
    m = i;
    n = j;
    // compute
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            tmp_co = a[i].co * b[j].co;
            tmp_in = a[i].in + b[j].in;
            // insert
            if(!total){
                res[++total].co = tmp_co;
                res[total].in = tmp_in;
            }
            else{
                for(k=1;k<=total;++k){
                    if(res[k].in == tmp_in){
                        res[k].co += tmp_co;
                        k = total + 100;
                    }
                }
                if(k == total + 1){
                    res[k].co = tmp_co;
                    res[k].in = tmp_in;
                    total ++;
                }
            }
        }
    }
    for(i=1;i<=total;++i){
        rank[i] = i;
    }
    for(i=1;i<=total;++i){
        for(j=i;j<=total;++j){
            if(res[rank[j]].in > res[rank[i]].in){
                temp = rank[j];
                rank[j] = rank[i];
                rank[i] = temp;
            }
        }
    }
    for(i=1;i<=total;++i){
        printf("%d %d ",res[rank[i]].co, res[rank[i]].in);
    }
    system("pause");
    return 0;
}
