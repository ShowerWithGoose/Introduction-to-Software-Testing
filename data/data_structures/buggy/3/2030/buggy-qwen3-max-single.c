#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1; // @@ [j is used uninitialized in the first while loop, leading to undefined behavior]
    gets(str1); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, not the direct cause of compilation error]
    while(str1[i]!='\0'){
        while(str1[i]=='.'){ // @@ [This inner while skips all '.' characters, but logic is flawed: it should copy non-'.' chars, but skips only consecutive dots starting at current i]
            i++;
        }
        str2[j]=str1[i]; // @@ [j is uninitialized; this writes to arbitrary memory location]
        j++;
        i++;
    }
    i=0;j=0;
    while(str1[i]!='\0'){
        if(str1[i]=='.'){
            m=i;
        }
        i++;
    }
    if(m==1&&str1[0]!='0'){
        printf("%se0",str1);
    }
    if(m==1&&str1[0]=='0'){ // @@ [m may be uninitialized if input has no '.', leading to undefined behavior]
        for(j=0;str2[j]!='\0';j++){
            if(str2[j]<='9'&&str2[j]>'0'){
                n=j;
                break;
            }
        }
        printf("%c",str2[n]); // @@ [n may be uninitialized if no non-zero digit found (though problem states all digits are significant, so maybe safe, but still risky)]
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
    if(m!=1){ // @@ [m may be uninitialized if input has no decimal point, causing undefined behavior]
        printf("%c.",str2[0]);
        while(str2[z]!='\0'){
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1);
    }
    return 0;
}