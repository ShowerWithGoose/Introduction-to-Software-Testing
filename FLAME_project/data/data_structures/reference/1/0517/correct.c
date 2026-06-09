#include <stdio.h>
#include <string.h>
int n;
int a[10]={0};
int jc(int n)
{
    int nn=1, i;
    for(i = 0; i < n; i++){
        nn *= (n-i);
    }
    return nn;
}
void pl(int x,int num)
{
    int i,j,tem = num, del;
    char numc[14] = {0};
    char *p = numc, *q = numc;
    for(j = 0; tem != 0; j++){
        del = tem % 10;
        numc[j] = del + '0';
        tem -= del;
        tem /= 10;
    }
    q += (strlen(numc) - 1);
    while(p < q){
        tem = *p;
        *p = *q;
        *q = tem;
        p++;
        q--;
    }
    if(x == n+1){
        for(j = 0; numc[j] != '\0'; j++){
            printf("%c ", numc[j]);
        }
        printf("\n");
        return;
    }
    for(i = 1; i <= n; i++){
        if(0 == a[i]){
            a[i] = 1;
            pl(x+1, num*10+i);
            a[i] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    pl(1,0);
    return 0;
}

