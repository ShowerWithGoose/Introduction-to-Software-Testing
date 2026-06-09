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
            if(x[i+1]==' '){ // @@ [Error: only stores number when next character is space; should also store when next is an operator, '=', or end of string. Last number before '=' is missed.]
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i];
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ [Error: uses y[i+1] which may be an operator; also z[k-1] is uninitialized when k=0; logic does not handle precedence correctly.]
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ [Error: same issues as above; y[i+1] may not be a number; z[k-1] uninitialized.]
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ [Error: incorrect logic for addition; uses z[i-1] which is out of bounds for i=0; does not remove operator or combine numbers properly.]
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ [Error: similar issue; order of operands reversed; array indexing issues.]
    }
    printf("%d" , z[k-1]);
    return 0;
}