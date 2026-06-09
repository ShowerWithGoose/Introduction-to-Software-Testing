#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a); // @@ Type mismatch: scanf expects char*, but &a is char(*)[200]. Should be 'a' or '&a[0]'. This may cause a compiler error or undefined behavior.
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){
        zheng++;
    }
    printf("%d.",a[0]-'0');
    
    for(int i=1;i!=strlen(a);i++){
        if(a[i]!='.'){
            printf("%d",a[i]-'0');
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){
            if(a[i]==0){ // @@ Should be a[i]=='0' to check for character '0', not null character. Comparing to integer 0 (null) will not correctly detect zeros and causes an infinite loop or out-of-bounds access.
                xiao++;
            }else{
                j=i;
                break;
            }
        }
        printf("%d",a[j]-'0');
        if(j<strlen(a)-1){
            printf(".");
        }
        for(int i=j+1;i!=strlen(a);i++){
            printf("%d",a[j]-'0'); // @@ Should be printf("%d",a[i]-'0'); otherwise it repeatedly prints the first non-zero digit instead of the remaining digits.
        }
        printf("e-%d",xiao);
    }
    

    return 1; // @@ Should return 0 for successful execution; returning 1 is non-standard and may be considered an error.
 }