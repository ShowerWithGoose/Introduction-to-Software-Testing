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
            if(x[i+1]==' '){ // @@ The condition only checks for space, but the number may be followed by an operator or '=' without a space, causing the last number to not be stored.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ The operator is stored as an integer (ASCII value) in y, but later it is compared with character literals like '*', which works because of implicit conversion, but the number before the operator is not stored in y, causing misalignment.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ y[i+1] is the ASCII value of the next character (e.g., '5' is 53), not the integer value of the number, leading to incorrect multiplication.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ Same issue as above: y[i+1] is ASCII, not integer.
            i++;
        }
        else z[k++]=y[i]; // @@ When storing numbers, y[i] is the ASCII value of the digit character (e.g., '2' is 50), not the actual integer 2.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ This incorrectly adds z[i-1] to z[i+1] and does not handle the operator properly; also, z[i-1] may be an operator ASCII value.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ Same issue: uses z[i-1] which may be an operator, and the logic for subtraction is flawed.
    }
    printf("%d" , z[k-1]);
    return 0;
}