#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; @@ // Using gets() is unsafe and deprecated; also, b stores pointers into a which may become invalid after modification
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); @@ // gets() is dangerous and removed in C11; causes undefined behavior on buffer overflow; should use fgets()
    
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
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; @@ // Using pow() for integer powers introduces floating-point inaccuracies; should use integer arithmetic
            }
        }
        else{
            m=b[i]-b[i-1]-1;
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; @@ // Same issue: pow() causes precision errors in integer conversion
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1];
            *b[k]=*b[i+1]; @@ // Overwriting operator in original string corrupts parsing logic for subsequent operations
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1];
            *b[k]=*b[i+1]; @@ // Same issue: modifying original operator array breaks later logic
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1];
        }
        else if(*b[i]=='='){
            *b[k]=*b[i]; @@ // Unnecessarily modifies operator; also logic for handling '=' is flawed
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
        else if(*b[i]=='='){ @@ // Loop may not reach '=' if k is not properly set; also, output should happen after loop, not inside
            printf("%d",c[0]);
        }
    }
    
    return 0;
}