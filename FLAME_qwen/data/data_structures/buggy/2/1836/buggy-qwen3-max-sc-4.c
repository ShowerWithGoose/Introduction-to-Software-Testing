#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101]; // @@ [y is used to store both numbers and operators (char), but declared as int array, causing type confusion and incorrect parsing]
    gets(x); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, the parsing logic below is flawed]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [only checks for space after digit to finalize number; fails when next char is operator or '=' without space]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [storing char operator into int array y; later treated as int, leading to incorrect values (e.g., '+' becomes 43)]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ [comparing int y[i] (which holds ASCII value of operator) with char literal '*', which works numerically but logic is broken due to mixed storage]
            z[k-1]=z[k-1]*y[i+1]; // @@ [y[i+1] is an int that may hold a number OR an operator ASCII; accessing it as number is wrong if it's an operator]
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ [same issue: y[i+1] might not be a number]
            i++;
        }
        else z[k++]=y[i]; // @@ [copying mixed-type data (numbers and operator codes) into z, leading to corrupted expression evaluation]
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [evaluation order is wrong: should accumulate left-to-right; also accesses z[i-1] which may be out-of-bounds on first iteration]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ [same issues: incorrect indexing and evaluation logic]
    }
    printf("%d" , z[k-1]); // @@ [final result location is incorrect due to flawed evaluation and storage]
    return 0;
}