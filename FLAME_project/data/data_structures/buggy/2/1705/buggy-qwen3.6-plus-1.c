#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ Error: b is declared as an array of pointers to char, but later used incorrectly. It should likely be an array of chars or indices to store operators. Also, using gets is dangerous and deprecated.
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ Error: 'gets' is deprecated and removed in C11. Use 'fgets' instead. This causes compilation warnings/errors in strict environments.
    
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
            b[n]=&a[i]; // @@ Error: b is an array of char pointers. Storing addresses here is valid syntax but logic depends on how it's used later. However, the subsequent logic treats b as holding operator characters via dereferencing, which is consistent with this assignment.
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0]; // @@ Logic: Calculates the number of digits before the first operator.
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ Error: Linker error 'undefined reference to pow'. The math library (-lm) is not linked. Also, using floating point pow for integer arithmetic is inefficient and prone to precision issues, though logically acceptable if linked.
            }
        }
        else{
            m=b[i]-b[i-1]-1; // @@ Logic: Calculates the number of digits between current and previous operator.
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ Error: Linker error 'undefined reference to pow'. Same as above.
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1];
            *b[k]=*b[i+1]; // @@ Logic: Updates the operator at position k to the next operator. This collapses the expression.
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
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}