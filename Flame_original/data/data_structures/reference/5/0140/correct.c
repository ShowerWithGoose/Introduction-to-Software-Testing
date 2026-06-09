#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 10050
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define ll long long
typedef struct {
    int xishu,zhishu;
}nod;
nod a[N],b[N],d[N];
int v[N];
int k1,k2;
int cmp(void *a,void *b){
    nod *x=(nod*)a;
    nod *y=(nod*)b;
    return (x->zhishu<y->zhishu);
}
int main(){
    char c=getchar();
    int ans=0;
    while(c!='\n'){
        while(isdigit(c)){
            ans=ans*10+c-'0';
            c=getchar();
        }
        k1++;
        if(k1%2)a[(k1+1)/2].xishu=ans;
        else a[(k1+1)/2].zhishu=ans;
     //   printf("%d\n",ans);
        ans=0;
        if(c=='\n'){
            break;
        }
        c=getchar();
    }
    c=getchar();
   // printf("%c\n",c);
    while(c!='\n'){
        while(isdigit(c)){
            ans=ans*10+c-'0';
            c=getchar();
        }
        k2++;
        if(k2%2)b[(k2+1)/2].xishu=ans;
        else b[(k2+1)/2].zhishu=ans;
        if(c=='\n'){
            break;
        }
        //printf("%d\n",ans);
        ans=0;
        c=getchar();        
    }
   // printf("%d %d\n",k1,k2);
    int cnt=0;
    for(int i=1;i<=k1/2;i++){
        for(int j=1;j<=k2/2;j++){
            d[++cnt].xishu=a[i].xishu*b[j].xishu;
            d[cnt].zhishu=a[i].zhishu+b[j].zhishu;
        }
    }
    qsort(d+1,k1/2*k2/2,sizeof(d[0]),cmp);
    //for(int i=1;i<=(k1*k2)/4;i++)printf("%d %d\n",d[i].xishu,d[i].zhishu);
    for(int i=1;i<=(k1*k2)/4;i++){
        if(d[i].zhishu==d[i-1].zhishu){
            v[i-1]=1;
            d[i].xishu+=d[i-1].xishu;
        }
    }
    for(int i=1;i<=(k1*k2)/4;i++)if(!v[i])printf("%d %d ",d[i].xishu,d[i].zhishu);
    return 0;
} 
