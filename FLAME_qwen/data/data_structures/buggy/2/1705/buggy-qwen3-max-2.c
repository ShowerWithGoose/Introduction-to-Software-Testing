#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of char pointers, but it's used to point into a[] which is fine; however, later logic assumes b[i] points to operator and uses b[i]-b[i-1] for distance, which may be okay, but the real issue is uninitialized or misaligned parsing]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is unsafe and deprecated; more critically, if input has no spaces, j may not be set correctly later. But main bug is elsewhere.]
    
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
            b[n]=&a[i]; // @@ [This records pointer to operator, but misses the first number before any operator. The number extraction logic assumes numbers are between operators, but the first number has no preceding operator.]
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0]; // @@ [This computes length of first number correctly]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Using pow() for integer powers is error-prone due to floating-point inaccuracies; e.g., pow(10,2) might be 99.999... leading to truncation to 99 instead of 100]
            }
        }
        else{
            m=b[i]-b[i-1]-1; // @@ [Distance between two operators gives length of number in between]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Same floating-point precision issue with pow()]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1]; // @@ [c[i+1] may be out of bounds: n is number of operators, so c has n elements (0..n-1), but c[i+1] accesses up to c[n], which is invalid]
            *b[k]=*b[i+1]; // @@ [Similarly, b[i+1] may be out of bounds when i = n-1]
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1]; // @@ [Same out-of-bounds access for c[i+1]]
            *b[k]=*b[i+1]; // @@ [Out-of-bounds for b[i+1]]
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1]; // @@ [Again, c[i+1] may be out of bounds]
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1]; // @@ [c[i+1] may be out of bounds; also, after previous loop, c array may not hold correct values due to earlier out-of-bounds writes]
        }
        else if(*b[i]=='-'){
            c[0]=c[0]-c[i+1]; // @@ [Same out-of-bounds risk]
        }
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}