#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101]; // @@ [Mixed storage of numbers and operators in array y causes type confusion; y is int array but stores char operators]
    gets(x); // @@ [Use of unsafe gets() function which may cause buffer overflow; also, gets() is deprecated and may not be available in some compilers leading to compilation error]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [Incorrect condition: assumes number ends only when next char is space; fails when number is followed by operator or '=' without space]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [Storing char operator into int array y; this corrupts data and leads to incorrect arithmetic later]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ [Comparing int array element with char literal; since operator was stored as its ASCII value, this comparison may fail]
            z[k-1]=z[k-1]*y[i+1]; // @@ [Using uninitialized z array; z is never initialized with parsed numbers, only y contains mixed data]
            i++;
        }
        else if(y[i]=='/'){ // @@ [Same issue: comparing int with char, and using uninitialized z]
            z[k-1]=z[k-1]/y[i+1];
            i++;
        }
        else z[k++]=y[i]; // @@ [Copying mixed number/operator data from y to z without separating them properly]
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [Incorrect evaluation order and indexing; modifies future operands and uses wrong indices]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ [Same issue: incorrect indexing and logic for subtraction]
    }
    printf("%d" , z[k-1]); // @@ [Result may be in wrong location due to flawed evaluation logic]
    return 0;
}