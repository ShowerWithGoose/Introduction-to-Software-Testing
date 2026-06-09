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
    int n;
    scanf("%d",&n);
    int a[10000],b[10000],c[10000],d[10000];
    int i=0,j;
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[j]<a[i]){
                tr(&a[j],&a[i]);
                tr(&b[j],&b[i]);
                tr(&c[j],&c[i]);
                tr(&d[j],&d[i]);
            }
        }
    }
    int s[10000];
    for(i=0;i<n-1;i++){
        int t=i+1,f=1,x=c[i],y=d[i];
        while(f){
            f=0;
            for(j=t;j<n;j++){
                if(a[j]==x&&b[j]==y){
                    f=1;
                    x=c[j];
                    y=d[j];
                    s[i]++;
                    t=j;
                    break;
                }
            }
        }
        s[i]++;
    }
    int k=0;
    for(i=1;i<n;i++){
        if(s[i]>s[k]){
            k=i;
        }
    }
    printf("%d %d %d",s[k],a[k],b[k]);
	return 0;
}/*
10
80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120
*/

