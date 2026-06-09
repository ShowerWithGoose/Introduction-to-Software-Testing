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
    while(c=fgetc(in)){ // @@ [The loop condition is incorrect: fgetc() returns EOF on end-of-file or error, which is typically -1. The condition should be 'while((c = fgetc(in)) != EOF)' and c should be declared as int to properly handle EOF. Also, using char for c may cause infinite loop or undefined behavior when EOF is returned.]
        if((c>='a')&&(c<='z')){
                c=tolower(c); // @@ [Redundant: c is already lowercase if it's between 'a' and 'z'. Also, tolower() should be applied to uppercase letters, not lowercase. Moreover, the logic misses converting uppercase letters because the condition only checks for lowercase.]
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
                for(t=0;t<30;t++){ // @@ [Loop bound 30 may exceed actual word length stored in d[i], leading to comparison of uninitialized/garbage characters. Should loop up to d[i] instead.]
                if(a[i][t]==a[j][t]){
                    m+=1;
                }else{
                    m=0;
                    break;
                }
                if(m==d[i]){ // @@ [This check is inside the t-loop, so it may trigger prematurely before full word comparison. It should be after the loop.]
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
            for(t=0;t<30;t++){ // @@ [Again, using fixed bound 30 instead of actual word length (d[i] or d[j]) may compare garbage data beyond the word, causing incorrect lexicographical ordering.]
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){ // @@ [Swapping entire 30-character arrays regardless of actual word length wastes time and may swap garbage; should only swap up to max(d[i], d[j]) or use strcpy.]
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=d[i]; // @@ [Bug: d[j] is assigned d[i] after d[i] was overwritten. Should store original d[i] in temp variable. This causes loss of original d[j] value.]
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