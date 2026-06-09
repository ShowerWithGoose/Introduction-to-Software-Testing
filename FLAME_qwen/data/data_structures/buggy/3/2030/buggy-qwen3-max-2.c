#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1; // @@ [j and z are used uninitialized, leading to undefined behavior]
    gets(str1); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, in this context, it's likely causing compilation issues in modern environments where gets is removed]
    while(str1[i]!='\0'){
        while(str1[i]=='.'){ // @@ [This inner while loop skips all '.' characters, but the logic is flawed: it only increments i without storing anything, and then stores the next char. Also, j is uninitialized here.]
            i++;
        }
        str2[j]=str1[i]; // @@ [j is uninitialized; using it as an index leads to undefined behavior]
        j++;
        i++;
    }
    i=0;j=0; // @@ [j is initialized here, but too late—the previous loop already used it uninitialized]
    while(str1[i]!='\0'){
        if(str1[i]=='.'){
            m=i;
        }
        i++;
    }
    if(m==1&&str1[0]!='0'){ // @@ [m may be uninitialized if input has no '.', leading to undefined behavior]
        printf("%se0",str1);
    }
    if(m==1&&str1[0]=='0'){ // @@ [same issue: m might be uninitialized; also, multiple if blocks instead of else-if may cause multiple outputs]
        for(j=0;str2[j]!='\0';j++){
            if(str2[j]<='9'&&str2[j]>'0'){
                n=j;
                break;
            }
        }
        printf("%c",str2[n]); // @@ [n may be uninitialized if no non-zero digit is found (though problem states there are significant digits, but still risky)]
        if(str2[n+1]!='\0'){
            printf(".");
        }
        j=n;
        n=n+1;
        while(str2[n]!='\0'){
            printf("%c",str2[n]);
            n++;
        }
        printf("e-%d",j);
    }
    if(m!=1){ // @@ [again, m may be uninitialized; also, this block runs even if previous if ran, causing duplicate output]
        printf("%c.",str2[0]);
        while(str2[z]!='\0'){
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1);
    }
    return 0;
}