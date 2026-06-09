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
            if(x[i+1]==' '){ // @@ Assumes number is followed by a space; fails when followed by an operator or '=', causing last number to be missed.
                y[t++]=s; // @@ Storing numbers into the same array y as operators leads to type confusion; later comparisons cannot distinguish them.
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ Stores operator as its ASCII integer code into y, mixing with stored numbers and causing misinterpretation during operator detection.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ Although the comparison works with ASCII, due to previous parsing errors, y may not contain the correct sequence of numbers and operators.
            z[k-1]=z[k-1]*y[i+1]; // @@ z is uninitialized; using index k-1 is invalid when k=0; also y[i+1] may not be a numeric value.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ Same issues as above: uninitialized z, invalid index when k=0, and y[i+1] may not be numeric.
            i++;
        }
        else z[k++]=y[i]; // @@ Copies mixed‑type values (numbers and operator codes) into z, which later confuses addition/subtraction logic.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ Incorrect evaluation: should compute z[i-1] + z[i+1] and store back; also risks index out-of-bounds when i=0.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ Similar logic error and potential index out-of-bounds.
    }
    printf("%d" , z[k-1]); // @@ May output garbage due to previous errors; also final number lost due to parsing flaw.
    return 0;
}