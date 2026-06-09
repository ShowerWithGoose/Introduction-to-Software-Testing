#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>

int main(){
    char a[150];
    char str1[100],str2[100],str3[100];
    gets(a);
    int len=strlen(a);
    int cnt=0;
    int pos=0; 
    int s=0; 
    for(int i=0;i<len;i++){
        if(a[i]=='.'){
            s=i;//前面数字个数 
            pos=i+1;//下一数字位置 
            break;}
    }
    
    //前有0 带负号 
    if(a[s-1]=='0'){ // @@ [Error: If the input is "0.1", s is 1, so a[s-1] is a[0] which is '0', but this condition also triggers for inputs like "0.001" where s is 1, which is correct. However, if the input is "0.0" (though not allowed per spec), it would fail. More critically, if the input has no decimal point (e.g., "123"), the loop to find '.' will not set s, leaving s=0, and then a[s-1] accesses a[-1] which is out-of-bounds, causing undefined behavior.]
    for(int i=pos;i<len;i++){
        if(a[i]=='0')
            cnt++; 
        else break;
    }
    for(int i=pos+cnt+1,j=0;i<len;i++,j++){ // @@ [Error: If cnt is 0 (e.g., input "0.1"), then pos+cnt+1 = pos+1, which skips the first digit after the decimal point. For "0.1", pos=2, cnt=0, so i starts at 3, but len=3, so the loop doesn't execute, leaving str1 empty. The correct approach should start from pos+cnt to include the first non-zero digit.]
        str1[j]=a[i];
    }
    int r=a[pos+cnt]-'0';//首位数字
    if(a[pos+1]=='\0'){ // @@ [Error: This condition checks if the character after the decimal point is the null terminator, which would mean the input has no digits after the decimal (e.g., "0."), but the problem states there are digits after the decimal. For valid inputs like "0.1", a[pos+1] is '1', not '\0', so this branch is never taken. The intended check should be whether there are no more digits after the first non-zero digit, i.e., if pos+cnt+1 >= len.]
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1);
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){ // @@ [Error: This condition checks if the digit before decimal is non-zero and s==1 (meaning only one digit before decimal). But if the input is "12.34", s=2, so this branch is skipped, which is correct. However, if the input is "1.23", s=1, and a[0]='1'!='0', so it enters this branch and prints "1.23e0", which is correct. But if the input is "10.5", s=2, a[0]='1'!='0', but s!=1, so it goes to else, which is correct. The issue is that this condition does not handle cases where the number has more than one digit before the decimal and the first digit is non-zero (e.g., "12.34"), which goes to the else branch correctly, but the else branch has issues.]
        printf("%se0",a);
    }
    else{
        printf("%d.",a[0]-'0');
        for(int i=1,j=0;i<pos-1;i++,j++){ // @@ [Error: For input "12.34", pos=2, so this loop runs from i=1 to i<1, i.e., zero times, missing the digit '2'. The correct range should be from i=1 to i<pos (since pos is the index of the decimal point, digits before it are from 0 to pos-1, and we already printed a[0], so we need i from 1 to pos-1).]
            str2[j]=a[i];
        }
        for(int i=pos,j=0;i<len;i++,j++){ // @@ [Error: This loop includes the decimal point character '.' at index pos, which should not be printed. It should start from pos+1 to skip the decimal point.]
            str3[j]=a[i];
        }
        printf("%s",str2);
        printf("%s",str3);
        printf("e%d",s-1);
    }


return 0;
}