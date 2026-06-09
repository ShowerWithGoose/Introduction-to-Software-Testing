#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101];
    gets(x); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` due to security risks. Should use `fgets` instead.]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [Incorrect condition: assumes multi-digit numbers end only before a space, but numbers may be followed by operator or '=' without space. This causes incomplete number parsing.]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [Storing operators in the same array `y` as numbers (which are ints), causing type confusion. Operators should be stored in a separate char array.]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ [Comparing int array element `y[i]` (which holds ASCII value of operator) with char literal '*', which works numerically but is logically flawed due to mixed types and incorrect data structure design.]
            z[k-1]=z[k-1]*y[i+1]; // @@ [Using `z[k-1]` before `z` is properly initialized with numbers; also `y[i+1]` may be an operator (char) cast to int, not a number.]
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ [Same issue: `y[i+1]` is likely an operator or uninitialized, not a parsed number.]
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [Incorrect accumulation logic: modifies future element instead of reducing left-to-right; also accesses `z[i-1]` which may be out of intended sequence.]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ [Same flawed logic; final result taken from `z[k-1]` which may not hold correct value due to improper reduction order.]
    }
    printf("%d" , z[k-1]); // @@ [Result may be incorrect due to all above logical errors in parsing and evaluation.]
    return 0;
}