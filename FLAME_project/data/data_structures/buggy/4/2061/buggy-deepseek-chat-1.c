#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[100][100];
char A[100][100];
int b[100]={1};
int d[100];
char s[10000];
int main(){
    FILE*in,*out;
    in=fopen("article.txt","r");
    char c,u;
    int i=0,j=0,t,p,q,m=0,r,y,n,f=0;
    while(c=fgetc(in)){ // @@ The condition (c=fgetc(in)) will evaluate to false when fgetc returns EOF, but EOF is typically -1, which is non-zero, so the loop may never terminate or may read beyond EOF. Also, c should be int to detect EOF.
        if((c>='a')&&(c<='z')){
                c=tolower(c);
        }
        s[f]=c;
        if(f==0){
            if((s[f]>='a')&&(s[f]<='z')){
                a[i][j]=s[f];
                j++;
            }
        }else{
            if((s[f-1]>='a')&&(s[f-1]<='z')){
            if((s[f]>='a')&&(s[f]<='z')){
                a[i][j]=s[f];
                j++;
            }else{
                d[i]=j;
                j=0;
                i++;
            }
        }else if((s[f]>='a')&&(s[f]<='z')){
            a[i][j]=s[f];
            j++;
        }
        }
        f++;
}
    n=i;
    for(i=0;i<n;i++){
        if(b[i]!=0){
            for(j=i+1;j<n;j++){
            if(d[i]==d[j]){
                for(t=0;t<30;t++){ // @@ The loop bound 30 is arbitrary and may not cover the full word length; should use d[i] instead.
                if(a[i][t]==a[j][t]){
                    m+=1;
                }else{
                    m=0;
                    break;
                }
                if(m==d[i]){
                    b[i]+=1;
                    b[j]=0;
                    m=0;
                    break;
                }
            }
            }
            
        }
        }
        
    }
    for(i=0,r=0;i<n;i++){
        if(b[i]!=0){
            for(j=0;j<d[i];j++){
                A[r][j]=a[i][j];
            }
            d[r]=d[i];
            b[r]=b[i];
            r++;
        }
    }
    for(i=0;i<r;i++){
        for(j=i+1;j<r;j++){
            for(t=0;t<30;t++){ // @@ The loop bound 30 is arbitrary; should use the actual word length for comparison.
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){ // @@ Swapping 30 characters is arbitrary; should swap up to the maximum word length.
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=d[i]; // @@ This should be d[j]=p; to correctly swap the lengths.
                    q=b[i];
                    b[i]=b[j];
                    b[j]=q;
                    break;
                }else if(A[i][t]<A[j][t]){
                    break;
                }
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<d[i];j++){
            printf("%c",A[i][j]);
        }
        printf(" ");
        printf("%d\n",b[i]);
    }
    return 0;
}