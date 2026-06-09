#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101]; @@ [y is used to store both numbers and operators (char), but declared as int array, causing type confusion and logic errors]
    gets(x); @@ [gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ @@ [Incorrect condition: number may end not only with space but also with operator or '='; misses last digit if not followed by space]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; @@ [Storing char operator into int array y; this corrupts data because later code treats y[i] as integer operands]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ @@ [Comparing int array element with char literal; since y stores operators as their ASCII values, this may work numerically but logic is flawed due to mixed types]
            z[k-1]=z[k-1]*y[i+1]; @@ [y[i+1] is an ASCII value of a digit character or operator, not the actual number; should use parsed numbers, not raw chars]
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; @@ [Same issue: y[i+1] is not the numeric operand but possibly ASCII code]
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; @@ [Incorrect accumulation: modifies z[i+1] instead of combining left-to-right; also accesses z[i-1] which may be operator or number inconsistently]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; @@ [Same structural flaw; logic does not correctly evaluate left-associative addition/subtraction]
    }
    printf("%d" , z[k-1]); @@ [Result may be incorrect due to all above issues; also, if expression ends with '=', it's not handled, and final number might not be stored]
    return 0;
}