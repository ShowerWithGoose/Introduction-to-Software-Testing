#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101];
    gets(x); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` for security reasons.]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [Incorrect condition: assumes number ends only when next char is space, but numbers may end before operators or '=' without a space. Also accesses x[i+1] beyond string end if i==l-1.]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [Storing operator as integer in `y`, which is meant for numbers; mixes types in same array causing logic errors.]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ [Uses `z` uninitialized; `z` is never filled with initial numbers, so `z[k-1]` reads garbage. Also assumes `y[i+1]` is a number, but `y` contains mixed operators and numbers incorrectly.]
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ [Same issues as above: uninitialized `z`, incorrect data layout in `y`.]
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [Incorrect evaluation order and indexing: modifies future element using past elements, but doesn't accumulate result properly. Also accesses z[i-1] when i=0 leads to out-of-bound read.]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ [Same indexing issue: z[i-1] invalid when i=0; logic does not correctly reduce expression left-to-right for +/-.]
    }
    printf("%d" , z[k-1]); // @@ [Result may be in wrong index due to flawed evaluation logic; also if expression has only one number, k might be 1 but z[0] was never set correctly.]
    return 0;
}