/*#include<stdio.h>
#include<stdlib.h>
#define ll long long
ll n = 0,cn = 0,rec = 1;
ll step[12] = {0,1,2,6,24,120,720,5040,40320,362880,3628800};
ll foll[36288010] = {0},iel = 1;
void f(ll,ll*);
int isz(double);
void copy(ll*,ll*,ll,ll);
ll main(){
    ll i,j;
    ll *p = (ll*)malloc(sizeof(ll)*12);
    scanf("%lld",&n);
    for(i = 0;i < n;i++) *(p+i) = i+1;
    f(n,p);
}

void f(ll len,ll *p){//输出p指向的数组的全排列
    ll i,j;
    ll *tem = (ll*)malloc(sizeof(ll)*12);
    if(len == 1){
        printf("%lld\n",*p);foll[iel++] = *p;
        cn++;
        if(cn % n == 0&&cn != n*step[n]&&(!((cn/n)%step[n-1] == 0))) {
            rec = foll[1+(cn/(step[n-1]*n))*step[n-1]*n];
            printf("rec:%d\n",rec);
            printf("%lld ",rec);foll[iel++] = rec;
            cn++;
        }
        return ;
    }
    for(i = 0;i < len;i++){
        printf("%lld ",*(p+i));foll[iel++] = *(p+i);
        cn++;
        if(isz(1.0*(cn-1)/n) && ((cn-1)/n)%step[n-1] == 0) rec = *(p+i);
        copy(tem,p,i,len);
        f(len-1,tem);
    }
}

void copy(ll *tem,ll *p,ll i,ll plen){//将数组p除下标i以外的元素按原顺序复制给tem
    ll j1,j2;
    for(j1 = j2 = 0;j2 < plen;j1++,j2++){
        if(j2 == i)j2++;
        *(tem+j1) = *(p+j2);
    }
}

int isz(double x){
    if(x-(int)x < 1e-11) return 1;
    return 0;
}*/

/*---------------------------------------------分界线------------------------------------------------*/

//以上为错误的做法（不知如何改进），以下为正确的做法,直接暴力枚举

/*---------------------------------------------分界线------------------------------------------------*/
//1 2 3 4 5 6

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int wait[12]={0};
int ind[12];
void allsorted(int len,int *p,int loc);
int main(){
    int n,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++) wait[i] = i+1;
    allsorted(n,wait,0);
    return 0;
}
// 1 2 3
void allsorted(int len,int *p,int loc){//该函数的功能是打印出数组p从下标loc开始及以后的数组元素的全排列
    int i,i1,cn;
    if(len == loc){
        for(i = 0;i < len;i++)
            printf("%d ",wait[ind[i]]);
        printf("\n");
        return ;
    }
    for(i = 0;i < len;i++){
        cn = 0;
        for(i1 = 0;i1 < loc;i1++){
            if(ind[i1] != i){
                cn++;
            }
        }
        if(cn == loc){
            ind[loc] = i;
            allsorted(len,p,loc+1);
        }
    }
    return ;
}

