#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1; // @@ [Variable 'j' is used uninitialized in the first while loop, leading to undefined behavior when assigning to str2[j]]
    gets(str1); // @@ [Use of unsafe function 'gets' which can cause buffer overflow; also, 'gets' is removed in C11 standard]
    while(str1[i]!='\0'){
        while(str1[i]=='.'){ // @@ [This inner while loop skips all '.' characters but doesn't handle multiple decimal points correctly; also, it may skip non-'.' characters incorrectly due to logic flaw]
            i++;
        }
        str2[j]=str1[i]; // @@ [Uninitialized 'j' leads to writing to arbitrary memory location]
        j++;
        i++;
    }
    i=0;j=0;
    while(str1[i]!='\0'){
        if(str1[i]=='.'){
            m=i; // @@ ['m' is only assigned if a '.' is found; if input has no '.', 'm' remains uninitialized, causing undefined behavior later]
        }
        i++;
    }
    if(m==1&&str1[0]!='0'){ // @@ [If input has no decimal point, 'm' is uninitialized, leading to unpredictable condition evaluation]
        printf("%se0",str1);
    }
    if(m==1&&str1[0]=='0'){ // @@ [Same issue: 'm' might be uninitialized; also, multiple 'if' blocks instead of 'else if' may cause multiple outputs for same input]
        for(j=0;str2[j]!='\0';j++){
            if(str2[j]<='9'&&str2[j]>'0'){
                n=j;
                break;
            }
        }
        printf("%c",str2[n]); // @@ ['n' may be uninitialized if no non-zero digit is found in str2 (though problem states all digits are significant, logic still fragile)]
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
    if(m!=1){ // @@ [Again, 'm' may be uninitialized; also, this block executes even if previous 'if' executed, possibly producing duplicate output]
        printf("%c.",str2[0]);
        while(str2[z]!='\0'){
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1); // @@ ['m' may be uninitialized here too]
    }
    return 0;
}