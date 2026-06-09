#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of char pointers, but it's used to point into a[], which is fine, but later logic assumes operators and numbers alternate correctly; however, the main issue is use of gets() which is unsafe and may be disabled, and more critically, pow() from math.h returns double, causing precision issues in integer parsing]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is deprecated and removed in modern C standards (C11+), leading to compilation error if compiler enforces standard compliance; also unsafe]
    
    for(i=0;i<strlen(a);i++){
        if(a[i]==' '){
        }
        else{
            a[j]=a[i];
            j++;
        }
    }
    a[j]='\0';
    
    for(i=0;i<j;i++){
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
            b[n]=&a[i];
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0];
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Using pow() for integer exponentiation introduces floating-point inaccuracies; e.g., pow(10,2) might yield 99.999..., truncating to 99 instead of 100]
            }
        }
        else{
            m=b[i]-b[i-1]-1;
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Same floating-point precision issue with pow()]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1];
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1];
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1];
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1];
        }
        else if(*b[i]=='-'){
            c[0]=c[0]-c[i+1];
        }
        else if(*b[i]=='='){ // @@ [This loop only prints when encountering '=', but if '=' is at position k-1, the loop runs i from 0 to k-1, so it may print, but logic is fragile; however, primary errors are earlier]
            printf("%d",c[0]);
        }
    }
    
    return 0;
}