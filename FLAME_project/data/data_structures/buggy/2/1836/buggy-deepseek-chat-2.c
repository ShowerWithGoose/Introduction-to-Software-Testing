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
            if(x[i+1]==' '){ // @@ Error: This condition only handles spaces, but the input may have operators or '=' after digits without spaces. For example, "24/4" would not trigger this, so the number is not stored.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ Error: The number before the operator is not stored when the operator is encountered. The number should be stored before adding the operator.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ Error: y[i+1] is an ASCII character code, not the integer value. It should be the numeric value from the array.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ Error: Same issue as above, y[i+1] is an ASCII character code, not the integer value.
            i++;
        }
        else z[k++]=y[i]; // @@ Error: y[i] may be an operator character or a number stored as ASCII, but numbers are not properly stored in y[] as integers.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ Error: This logic is incorrect. It adds z[i-1] to z[i+1] but does not handle the order of operations correctly (left-to-right for + and -).
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ Error: Same issue, incorrect handling of subtraction order.
    }
    printf("%d" , z[k-1]);
    return 0;
}