#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of pointers to char, but it's used to point into a[], which is fine, however the logic that follows has multiple flaws]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is unsafe and deprecated; more critically, if input contains no spaces, j may not be properly bounded leading to issues later]
    
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
            b[n]=&a[i]; // @@ [b[n] stores pointer to operator, but number parsing assumes operators separate numbers correctly; fails when expression starts with negative number or has adjacent operators]
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0]; // @@ [m is length of first number, but if expression starts with operator (e.g., "-5+3="), this logic breaks because there's no number before first operator]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [uses floating-point pow() for integer arithmetic, which can introduce rounding errors; also, indexing may go out of bounds if m is 0]
            }
        }
        else{
            m=b[i]-b[i-1]-1; // @@ [assumes exactly one number between operators; fails if there are consecutive operators or missing operands]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [same floating-point precision issue and potential out-of-bound access]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1]; // @@ [c[i+1] may be uninitialized or out of valid range; indexing assumes c has at least i+2 elements, which may not hold]
            *b[k]=*b[i+1]; // @@ [*b[k] overwrites operator in original string a[], which corrupts later logic that reads *b[i]]
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1]; // @@ [same issue: c[i+1] may be invalid; also, division by zero not handled though problem says expression is valid]
            *b[k]=*b[i+1]; // @@ [corrupts operator data]
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1]; // @@ [again, c[i+1] may be beyond parsed numbers]
        }
        else if(*b[i]=='='){
            *b[k]=*b[i]; // @@ [overwrites operator again]
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1]; // @@ [c[i+1] may be uninitialized; also, after previous loop, c[] may not hold correct values due to incorrect indexing]
        }
        else if(*b[i]=='-'){
            c[0]=c[0]-c[i+1]; // @@ [same issue]
        }
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}