#include<stdio.h>
#include<string.h>
int main() {
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    int i,t=0,tt;
    if(a[1]=='.'&&a[0]!='0')
        printf("%se0",a);
    else if(a[1]=='.'&&a[0]=='0') { @@ // The condition assumes the input always has at least two characters and that the second character is '.', but if the input is just "0" or has no decimal point, this leads to undefined behavior. Also, 'tt' may be used uninitialized if all digits after '.' are zero (though problem states no trailing zeros, but still, robustness issue).
        for(i=2; i<len; i++) {
            if(a[i]!='0') {
                if(t==0)tt=i;
                t=1;                
            }
            if(t==1)printf("%c",a[i]);
            if(i==tt)printf("."); @@ // This prints '.' at position tt during the loop, but if tt is never set (e.g., all zeros after decimal), tt is uninitialized → undefined behavior. Also, printing '.' inside the digit loop disrupts output format (should print first digit, then '.', then rest).
        }
        printf("e-%d",tt-1); @@ // 'tt' might be uninitialized if no non-zero digit found (though problem says no trailing zeros, but if input is "0.0", it's invalid per problem, yet code doesn't validate input).
    } else {
        for(i=0; i<len; i++) {
            if(i==1)printf("."); @@ // Incorrectly prints '.' after first character regardless of original decimal position. Should only insert '.' after first significant digit, not at index 1.
            if(a[i]=='.') {
                tt=i;
                continue;
            }
            printf("%c",a[i]);
        }
        printf("e%d",tt-1); @@ // 'tt' may be uninitialized if there's no '.' in input (though problem states input has digits before and after decimal point, so '.' must exist, but code doesn't ensure that).
    }
    return 0;
}