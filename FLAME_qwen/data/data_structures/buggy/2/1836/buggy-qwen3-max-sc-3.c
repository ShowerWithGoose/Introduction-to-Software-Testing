#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101];
    gets(x); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [Incorrect condition: assumes number ends only before a space, but numbers may end before operators or '=' without space]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [Storing operator as integer in y[], which is meant for numbers; mixes types in same array causing logic errors]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ [y[i] contains mixed data: numbers and ASCII values of operators; comparing int to char literal is fragile and logic is broken]
            z[k-1]=z[k-1]*y[i+1];
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1];
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [Incorrect accumulation: modifies future operand instead of accumulating result; also accesses z[i-1] when i=0 leads to undefined behavior]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1];
    }
    printf("%d" , z[k-1]); // @@ [Result may not be at z[k-1] due to flawed evaluation logic; final answer location is unreliable]
    return 0;
}