#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void tr(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    int c[100],d[100],e[100],f[100];
    int a,b,x,y,i=1,j=1;
    while(scanf("%d %d",&a,&b)!=EOF){
            if(i>=2&&b>=d[i-1]){
                e[j]=a;
                f[j]=b;
                j++;
                break;
            }
            else{
            c[i]=a;
            d[i]=b;
            i++;
            }
    }
    i--;
    while(scanf("%d %d",&x,&y)!=EOF){
            e[j]=x;
            f[j]=y;
            j++;
    }
    j--;
    int g[5000],h[5000];
    int p,q;
    for(p=1;p<=i;p++){
        for(q=1;q<=j;q++){
            g[(p-1)*j+q]=c[p]*e[q];
            h[(p-1)*j+q]=d[p]+f[q];
            }
        }
    for(p=1;p<j*i;p++){
        for(q=p+1;q<=j*i;q++){
            if(h[q]>h[p]){
                tr(&h[q],&h[p]);
                tr(&g[q],&g[p]);
            }
            if(h[q]==h[p]){
                g[p]+=g[q];
                g[q]=0;
            }
        }
    }
    for(p=1;p<=j*i;p++){
        if(g[p]==0){
            continue;
        }
        else{
        printf("%d %d ",g[p],h[p]);
        }
    }
	return 0;
}
/*
10 80000
2 6000
7 300
5 10
18 0
3 6000
5 20
8 10
6 0
*/



