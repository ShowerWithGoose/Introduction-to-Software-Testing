#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100];
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ gets() is deprecated and completely removed in the C11 standard, causing a compilation error in modern compilers. It should be replaced with fgets().
    
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
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ Using pow() for integer arithmetic is inefficient, prone to floating-point precision loss, and may cause compilation/linker errors if the math library is not properly linked.
            }
        }
        else{
            m=b[i]-b[i-1]-1;
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ Using pow() for integer arithmetic is inefficient, prone to floating-point precision loss, and may cause compilation/linker errors if the math library is not properly linked.
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1];
            *b[k]=*b[i+1]; // @@ Potential out-of-bounds array access when i equals n-1, as b[n] is uninitialized. This causes undefined behavior and potential runtime crashes.
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1];
            *b[k]=*b[i+1]; // @@ Potential out-of-bounds array access when i equals n-1, as b[n] is uninitialized. This causes undefined behavior and potential runtime crashes.
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
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}