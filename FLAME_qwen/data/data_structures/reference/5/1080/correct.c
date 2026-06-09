//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{long long a[1000],a1[1000];
    long long b[1000],b1[1000],i=0,k=0,i1,p=0,flag,flag1,hold;
    long long ans[1000];
    long long ans1[1000];
    char c;
    while(scanf("%c",&c)!=EOF){
        if(c=='\n'){
            i++;
                if(i%2)b[(i-1)/2]=k;
                else a[(i-1)/2]=k;
                k=0;
            break;
        }
        if(c==' '){i++;
            if(i%2)b[(i-1)/2]=k;
            else a[(i-1)/2]=k;
            k=0;
        }
        else
            k=k*10+(c-'0');
    }
    k=0;i1=0;
    while(scanf("%c",&c)){
        if(c=='\n'){
            i1++;
                if(i1%2)b1[(i1-1)/2]=k;
                else a1[(i1-1)/2]=k;
                k=0;
            
            break;
        }
        if(c==' '){i1++;
            if(i1%2)b1[(i1-1)/2]=k;
            else a1[(i1-1)/2]=k;
            k=0;
        }
        else
            k=k*10+(c-'0');
    }
    
    for(int j=0;j<i/2;j++){
        for(k=0;k<i1/2;k++){
            flag1=a[j]+a1[k];
            flag=b[j]*b1[k];
            hold=0;
            for(int m=0;m<p;m++){
                if(ans[m]==flag1){ans1[m]+=flag;hold=1;break;}
            }
            if(hold==0){
                ans[p++]=flag1;ans1[p-1]=flag;
            }
        }
        }
    for(int m=0;m<p-1;m++){
        for(k=0;k<p-1-m;k++){
            if(ans[k]<ans[k+1]){
                hold=ans[k+1];ans[k+1]=ans[k];ans[k]=hold;
                hold=ans1[k+1];ans1[k+1]=ans1[k];ans1[k]=hold;}
        }
    }
    for(int m=0;m<p;m++){
        if(ans1[m]!=0){
            printf("%lld %lld ",ans1[m],ans[m]);
            
        }
        
    }
    
    
  return 0;
}


