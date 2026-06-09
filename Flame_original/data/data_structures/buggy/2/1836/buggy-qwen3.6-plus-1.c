#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101];
    gets(x); // @@ [Compilation Error] 'gets' was removed from the C11 standard and causes compilation errors in modern compilers; use 'fgets' instead.
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ [Logical Error] This condition only pushes the number when followed by a space. It fails to parse numbers followed by operators, '=', or at the end of the string, causing the last number to be lost.
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
        if(z[i]=='+') z[i+1]+=z[i-1];
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1];
    }
    printf("%d" , z[k-1]);
    return 0;
}