#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101];
    gets(x);
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ @@ // This condition fails to capture numbers at the end of expression or before operators like '/', etc., because it only checks for space after digit. It misses cases where next char is operator or '='.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; @@ // Storing operator as integer (char cast to int), which corrupts numeric values later when used in arithmetic.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ @@ // Comparing integer value (which is ASCII code of operator) with character literal; this works by coincidence but logic is flawed due to mixed storage.
            z[k-1]=z[k-1]*y[i+1]; @@ // y[i+1] is either an operator (as int) or number, but since operators were stored as their ASCII values, this causes wrong multiplication.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; @@ // Same issue: y[i+1] may be an operator's ASCII value instead of actual number.
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; @@ // Incorrect accumulation: modifies future operand instead of maintaining running total; also accesses z[i-1] which may be out of intended logic flow.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; @@ // Same structural flaw: assumes alternating operands and operators starting with operand, but indexing leads to incorrect evaluation order and overwrites needed values.
    }
    printf("%d" , z[k-1]); @@ // Assumes final result is last element, but due to flawed processing above, this value is incorrect.
    return 0;
}