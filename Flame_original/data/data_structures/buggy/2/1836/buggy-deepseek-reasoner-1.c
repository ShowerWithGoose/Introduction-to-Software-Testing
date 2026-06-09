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
            if(x[i+1]==' '){  // @@ The condition should not require a space after a number. It fails for numbers followed by operators or '=', causing missing numbers.
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
            z[k-1]=z[k-1]*y[i+1];  // @@ Uses z[-1] when k=0 (uninitialized and out-of-bounds). Also assumes y[i+1] is a number, but it may be an operator.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1];  // @@ Same uninitialized/invalid index issue as above.
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1];  // @@ Incorrect indexing: z[i+1] and z[i-1] may be out-of-bounds or wrong operands.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1];  // @@ Same indexing issue.
    }
    printf("%d" , z[k-1]);
    return 0;
}