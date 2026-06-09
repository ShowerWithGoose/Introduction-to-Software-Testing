#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[100][100];
char A[100][100];
int b[100]={1}; // @@ Initializes only b[0]=1, all other b[i] are 0, causing frequency counts for subsequent words to start at 0.
int d[100];
char s[10000];
int main(){
    FILE*in,*out;
    in=fopen("article.txt","r"); // @@ No check if fopen() succeeded; if it fails, in is NULL and fgetc will cause segfault.
    char c,u;
    int i=0,j=0,t,p,q,m=0,r,y,n,f=0;
    while(c=fgetc(in)){ // @@ Using char to hold return of fgetc loses distinction of EOF; also loop condition treats EOF as true, causing infinite loop or storing EOF character. Should use int and check for EOF.
        if((c>='a')&&(c<='z')){ // @@ Condition is wrong: it only acts on lowercase letters, but should convert uppercase to lowercase. Should check c>='A' && c<='Z'.
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
    n=i; // @@ i is the number of completed words, but if the file ends with a letter, the last word is not counted; d[i] was never set and i not incremented.
    for(i=0;i<n;i++){
        if(b[i]!=0){
            for(j=i+1;j<n;j++){
            if(d[i]==d[j]){
                for(t=0;t<30;t++){ // @@ Loop runs to 30 regardless of word length, comparing uninitialized characters beyond the actual word, causing mismatches. Should loop up to d[i].
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
            for(t=0;t<30;t++){ // @@ Same issue: comparing up to 30 may include garbage beyond word length; should compare min(d[i],d[j]) characters.
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=d[i]; // @@ Swap bug: d[j] should be assigned p (original d[i]), not the already-changed d[i].
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