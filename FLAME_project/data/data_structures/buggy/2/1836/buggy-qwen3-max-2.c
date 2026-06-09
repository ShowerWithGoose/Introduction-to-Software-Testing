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
            if(x[i+1]==' '){ @@ // This condition fails to capture numbers at the end of expression or before operators like '/', '*', etc., because it only checks for space. It misses cases where a number is followed directly by an operator or '='.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; @@ // This stores operators as their ASCII values (e.g., '+' = 43), not as symbolic tokens, which later causes incorrect interpretation when used as array indices or operands.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ @@ // Since operators were stored as ASCII values, comparing with '*' (which is 42) may work, but the logic assumes y[i+1] is a number. However, y[] mixes numbers and ASCII operators, so y[i+1] might be an operator's ASCII value, not a number.
            z[k-1]=z[k-1]*y[i+1];
            i++;
        }
        else if(y[i]=='/'){ @@ // Same issue: y[i+1] may not be a number; also integer division is used correctly, but data representation is flawed.
            z[k-1]=z[k-1]/y[i+1];
            i++;
        }
        else z[k++]=y[i]; @@ // Numbers and ASCII operators are both pushed into z[], causing type confusion. For example, if y[i] is 43 ('+'), it's stored as 43 in z[], which later gets treated as an operand.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; @@ // This logic is fundamentally flawed: it modifies z[i+1] using z[i-1], but doesn't remove or skip processed elements. Also, it assumes alternating operands and operators starting with operand, but z[] contains mixed types due to earlier errors.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; @@ // Same structural flaw; also, this overwrites future operands without adjusting loop index or array structure, leading to incorrect accumulation.
    }
    printf("%d" , z[k-1]); @@ // Final result is taken from last element, but due to incorrect parsing and evaluation order (especially missing proper left-to-right precedence handling for + and - after * /), and type mixing, result is wrong.
    return 0;
}