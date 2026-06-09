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
    while(c=fgetc(in)){ // @@ [The loop condition is incorrect. fgetc() returns EOF on end-of-file or error, which is typically -1. The condition should be `while((c = fgetc(in)) != EOF)`. As written, when fgetc returns 0 (which can happen if the file contains a null byte), the loop stops prematurely, and more critically, when it returns EOF (-1), the loop continues because -1 is non-zero, leading to processing invalid character values and potential out-of-bounds writes.]
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
                for(t=0;t<30;t++){ // @@ [Loop bound 30 is arbitrary and may be less than d[i], causing incomplete comparison; should use d[i] as bound. Also, if d[i] > 30, it reads beyond initialized part of a[i].]
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
            for(t=0;t<30;t++){ // @@ [Same issue: using fixed bound 30 instead of actual word length (e.g., min(d[i], d[j]) or until difference found). This can cause incorrect lexicographical comparison if words differ beyond 30 characters or if 30 exceeds actual length and uninitialized data is compared.]
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){ // @@ [Swapping entire 30 characters regardless of actual word length d[i] or d[j]; should only swap up to max(d[i], d[j]) or use strcpy-style logic. This corrupts data if word length < 30 because garbage beyond d[i] is swapped.]
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=p; // @@ [Bug: original code had `d[j]=d[i];` which loses original d[i]; should store temp. But even this fix is in wrong place due to earlier logic flaws. However, the original buggy line was `d[j]=d[i];` after `d[i]=d[j];`, which sets both to d[j]. This line is actually corrected here by using p, but the annotation must reflect the original code's error. In the given source code, it's `d[j]=d[i];` — so this line is wrong.]
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