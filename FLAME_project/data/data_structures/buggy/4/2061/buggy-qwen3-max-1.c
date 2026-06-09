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
    while(c=fgetc(in)){ // @@ [The loop condition is incorrect. fgetc() returns EOF on end-of-file, which is typically -1, but 'c' is a char (unsigned or signed). When char is unsigned, EOF (-1) becomes 255, so the loop never terminates properly. Also, the loop should check for EOF explicitly: while((c = fgetc(in)) != EOF). Additionally, 'c' should be declared as int to correctly handle EOF.]
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
                for(t=0;t<30;t++){ // @@ [Looping up to 30 is arbitrary and may exceed actual word length (stored in d[i]). Should loop only up to d[i] to compare valid characters. Also, comparing beyond d[i] may access uninitialized memory.]
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
            for(t=0;t<30;t++){ // @@ [Same issue: comparing up to 30 characters regardless of actual word length. This can lead to incorrect lexicographical comparison if words are shorter than 30 and trailing garbage affects result. Should compare up to min(d[i], d[j]) or use strcmp-style logic.]
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){ // @@ [Swapping entire 30-char arrays is inefficient and unnecessary; also, d[i] and d[j] may be less than 30, so swapping extra bytes is harmless but indicates flawed design. However, the real bug is in the next line:]
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=d[i]; // @@ [This line is wrong: it sets d[j] to d[i] after d[i] was already overwritten. Should be d[j] = p; to complete the swap. This causes incorrect word lengths to be stored, leading to output errors.]
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