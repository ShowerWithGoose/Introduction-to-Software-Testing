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
            if(x[i+1]==' '){ // @@ The logic for parsing numbers is flawed. It only stores a number if followed by a space, failing to store the last number or numbers followed immediately by an operator. It also mixes numbers and operators in the same array `y` without distinction, leading to incorrect processing later.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ Storing character operators as integers in the same array as numbers causes ambiguity and incorrect calculations. For example, '+' (ASCII 43) might be treated as the number 43.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ Incorrectly accesses `y[i+1]` which might be an operator or out of bounds, and assumes `z` is populated correctly up to `k-1`. The logic for separating numbers and operators into `z` is broken because `y` contains mixed types.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ Same error as above: incorrect operand retrieval and mixed data types in `y`.
            i++;
        }
        else z[k++]=y[i]; // @@ This copies both numbers and operators from `y` to `z`. Since `y` contains ASCII values for operators, `z` will contain garbage values for calculation.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ Logic for addition/subtraction is flawed. It modifies `z[i+1]` but doesn't handle the reduction of the array size or shifting elements, leading to incorrect accumulation and accessing invalid indices.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ Same error as above: incorrect handling of subtraction and array state.
    }
    printf("%d" , z[k-1]);
    return 0;
}