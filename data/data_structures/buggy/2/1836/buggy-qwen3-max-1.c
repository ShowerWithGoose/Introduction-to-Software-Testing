#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101]; // @@ [y is used to store both numbers and operators (char), but it's declared as int array, causing type confusion and incorrect parsing]
    gets(x); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, the parsing logic below is flawed]
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [only checks for space after digit to finalize number; fails if next char is operator or '=' without space]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ [storing char operator into int array y; this corrupts data because operator ASCII values are stored as integers, not as tokens]
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ [comparing int array element (which may be a number or an ASCII code of operator) to char literal; logic broken due to mixed types in y]
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
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [incorrect accumulation: uses z[i-1] and z[i+1] without proper left-to-right evaluation; also assumes alternating pattern that doesn't hold]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1];
    }
    printf("%d" , z[k-1]); // @@ [final result assumed to be at z[k-1], but due to flawed processing, this may not hold the correct answer]
    return 0;
}