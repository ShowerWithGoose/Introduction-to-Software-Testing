#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1; // @@ [j and z are used uninitialized, leading to undefined behavior]
    gets(str1); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, in many modern environments it's not available, causing compilation error]
    while(str1[i]!='\0'){
        while(str1[i]=='.'){ // @@ [This inner while loop skips all '.' characters, but the problem states there's exactly one decimal point; also, this logic corrupts digit order by removing '.' without tracking original position properly]
            i++;
        }
        str2[j]=str1[i]; // @@ [j is uninitialized; writing to arbitrary memory location]
        j++;
        i++;
    }
    i=0;j=0; // @@ [j is initialized here, but too late—already used uninitialized above]
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
        printf("%c",str2[n]); // @@ [n may be uninitialized if no non-zero digit found (though problem says all digits are significant, so maybe safe, but still risky)]
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
        while(str2[z]!='\0'){ // @@ [z starts at 1, but str2 may not have that many digits; also, str2 construction skipped '.' but didn't handle cases correctly]
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1);
    }
    return 0;
}