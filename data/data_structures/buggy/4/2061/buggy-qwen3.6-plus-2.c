#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[100][100];
char A[100][100];
int b[100]={1}; // @@ Only initializes b[0] to 1, leaving other elements as 0. New words will incorrectly start with a frequency of 0 instead of 1.
int d[100];
char s[10000];
int main(){
    FILE*in,*out;
    in=fopen("article.txt","r");
    char c,u; // @@ 'c' should be declared as 'int' to properly store the return value of fgetc() and correctly detect EOF.
    int i=0,j=0,t,p,q,m=0,r,y,n,f=0;
    while(c=fgetc(in)){ // @@ Does not check for EOF, causing an infinite loop. Should be 'while((c = fgetc(in)) != EOF)'.
        if((c>='a')&&(c<='z')){ // @@ Only processes already lowercase letters, failing to convert uppercase letters to lowercase as required by the problem.
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
                d[i]=j; // @@ Missing null terminator assignment 'a[i][j] = '\0';' before moving to the next word, which will cause string operations to read garbage data.
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
            if(d[i]==d[j]){ // @@ Incorrectly restricts word comparison to only those with identical lengths. Words of different lengths will never be matched or counted together.
                for(t=0;t<30;t++){
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
            for(t=0;t<30;t++){
                if(A[i][t]>A[j][t]){
                    for(y=0;y<30;y++){
                        u=A[i][y];
                        A[i][y]=A[j][y];
                        A[j][y]=u;
                    }
                    p=d[i];
                    d[i]=d[j];
                    d[j]=d[i]; // @@ Swap logic error: assigns the already-updated 'd[i]' to 'd[j]' instead of the original value stored in 'p'. Should be 'd[j] = p;'.
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