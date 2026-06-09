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
    while(c=fgetc(in)){ // @@ [The loop condition is incorrect: fgetc() returns EOF on end-of-file or error, which is typically -1, not 0. The loop should continue while c != EOF, but here it stops when c is 0 (null character), which may occur in the middle of a file or not at all. Also, the assignment inside while should be compared to EOF.]
        if((c>='a')&&(c<='z')){
                c=tolower(c); // @@ [Redundant: c is already lowercase if it's between 'a' and 'z'. Also, uppercase letters are not handled because the condition excludes them. Should convert uppercase to lowercase, but this only processes lowercase.]
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
                for(t=0;t<30;t++){ // @@ [Loop bound 30 is arbitrary and may exceed actual word length stored in d[i], leading to comparison of uninitialized/garbage characters. Should loop up to d[i] instead.]
                if(a[i][t]==a[j][t]){
                    m+=1;
                }else{
                    m=0;
                    break;
                }
                if(m==d[i]){ // @@ [This check is inside the t-loop, so it may trigger prematurely before full comparison. Also, m is not reset properly across comparisons.]
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
            for(t=0;t<30;t++){ // @@ [Again, using fixed bound 30 instead of actual word length (d[i] or d[j]) may compare garbage data beyond the word, causing incorrect lexicographical comparison.]
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){ // @@ [Swapping entire 30-character arrays regardless of actual word length wastes time and may swap garbage; also, d[i] and d[j] should be swapped consistently.]
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=d[i]; // @@ [This line is wrong: it sets d[j] to the new value of d[i] (which is old d[j]), so both become d[j]. Should use a temp variable correctly: d[j] = p;]
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