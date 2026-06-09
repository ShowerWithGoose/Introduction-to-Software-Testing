#include <stdio.h>
#include <stdlib.h>//qsort函数使用 
#include <string.h> 
#define maxn 1005
struct multi{
    long long coe,pow;//系数，指数 
}a1[maxn],a2[maxn],a3[maxn],ans[maxn]; 
long long len1,len2,len3,lens;
char ch;
long long i,j,k,l,z,w;
int cmp(const void *p,const void *q){
    struct multi *a=(struct multi *)p;
    struct multi *b=(struct multi *)q;
    return ((a->pow > b->pow)?-1:1);// @@ 比较函数未正确处理相等情况，应返回0，例如 return (a->pow < b->pow) - (a->pow > b->pow); 或 return (b->pow - a->pow);
}

int main()
{
    //读入数据 
    do{
        len1++;
        scanf("%lld%lld%c",&a1[len1].coe ,&a1[len1].pow ,&ch);
    }while(ch!='\n');
    do{
        len2++;
        scanf("%lld%lld%c",&a2[len2].coe ,&a2[len2].pow ,&ch);
    }while(ch!='\n');
    //printf("%d %d",len1,len2);5 4
    //多项式相乘 
    if(len1>len2){
        for(k=1;k<=len1;k++){
            for(l=1;l<=len2;l++){
                len3++;
                a3[len3].coe =a1[k].coe *a2[l].coe ;
                a3[len3].pow =a1[k].pow +a2[l].pow ;    
            }
        }
    }
    else{
        for(k=1;k<=len2;k++){
            for(l=1;l<=len1;l++){
                len3++;
                a3[len3].coe =a2[k].coe *a1[l].coe ;
                a3[len3].pow =a2[k].pow +a1[l].pow ;
            }
        }
    }
    //printf("%d",len3);20
    //多项式排序后合并 
    qsort(a3+1,len3,sizeof(a3[0]),cmp);//待排序的数组 元素个数 所占空间 比较函数的指针 
    ans[++lens]=a3[1];
    for(i=2;i<=len3;i++){
        if(a3[i].pow ==ans[lens].pow ){
            ans[lens].coe +=a3[i].coe ;
        }
        else {
            ans[++lens]=ans[i]; // @@ 错误，应为 ans[++lens]=a3[i]; 此处将未初始化的ans[i]赋值给新项，导致丢失 a3[i] 的数据
        }
    }
    for(i=1;i<=lens;i++){
        printf("%d %d ",ans[i].coe ,ans[i].pow ); // @@ 应使用 %lld 匹配 long long 类型，否则输出可能错误
    }
    
    return 0;
}