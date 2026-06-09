#include<stdio.h>
char a[1000000];
char b[1000000];
int num[1000000];
int c[1000000]= {-1},k=1; @@ [Initialization of array 'c' with {-1} is invalid in C for large arrays; this causes a compilation error because C does not allow non-constant initializers for global arrays beyond simple zero-initialization or small compile-time constants.]
int k1,k2;
int op[100000],op2[100000];
int main()
{
    fgets(a,1000000,stdin);
    int t=0,l=strlen(a); @@ [strlen used without including <string.h>, causing compilation error due to implicit function declaration.]
    for(int i=0; i<l; i++)
        if(a[i]!=' ')
            b[t++]=a[i];
    for(int i=0; i<t; i++) {
        if(b[i]=='-'||b[i]=='+'||b[i]=='=') {
            c[k++]=i;
            op[k1++]=k-1;

        } else if(b[i]=='*'||b[i]=='/')
            c[k++]=i;

    }
    for(int i=1; i<k; i++) {
        char s[10]= {};
        int sn=0;
        for(int j=c[i-1]+1; j<c[i]; j++)
            s[sn++]=b[j];
        s[sn]='\0';
        sscanf(s,"%d",&num[i-1]); @@ [sscanf used without including <stdio.h> properly (though <stdio.h> is included, the lack of <string.h> may still cause issues in some environments, but primary issue is missing <string.h> for strlen). However, the main compilation errors are the global array initializer and missing header.]
    }

    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='*') {
            num[i]=num[i]*num[i-1]; @@ [Logic error: indices are inconsistent; should be num[i-1] *= num[i] or similar, but this is a runtime logic bug, not compilation. Compilation error already occurs earlier.]
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; @@ [Same as above: logic issue, not compilation.]
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1];
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1];
    }
    printf("%d",num[k-2]);
    return 0;
}