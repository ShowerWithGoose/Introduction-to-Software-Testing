#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101]; // @@ [y is used to store both numbers and operators (char), but it's declared as int array, causing type confusion and logic errors]
    gets(x); // @@ [gets() is unsafe and deprecated; may cause compilation error or warning in modern compilers, but primary issue is logical]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [only checks for space after digit; fails when number is followed by operator or '=' without space]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [storing char operator into int array y; later comparisons like y[i]=='*' work by coincidence but mixing types breaks logic]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ [y[i] is an int that holds either a number or the ASCII of an operator; comparing to '*' works, but then y[i+1] is next token which may be operator or number — logic flawed because tokens are not separated properly]
            z[k-1]=z[k-1]*y[i+1]; // @@ [z[k-1] may be uninitialized; also y[i+1] might be an operator (stored as int) instead of a number]
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ [same issue: z[k-1] uninitialized, y[i+1] may not be a number]
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [incorrect accumulation: modifies future element instead of reducing left-to-right; also accesses z[i-1] which may be out of intended logic]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ [same structural flaw; final result taken as z[k-1] but operations don't reduce expression correctly]
    }
    printf("%d" , z[k-1]); // @@ [result may be wrong due to incorrect parsing and evaluation order; also if expression ends with '=', it's ignored but number before '=' may not be stored]
    return 0;
}