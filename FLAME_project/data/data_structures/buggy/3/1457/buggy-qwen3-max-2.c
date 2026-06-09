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
    gets(a); @@ // Using gets() is unsafe and may cause buffer overflow; also, it's deprecated. More critically, if input has no decimal point, 's' remains uninitialized, leading to undefined behavior.
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
    if(a[s-1]=='0'){ @@ // If the input has no decimal point (e.g., "123"), 's' remains 0, so a[s-1] accesses a[-1] → undefined behavior. Also, this condition assumes there's always a decimal point.
    for(int i=pos;i<len;i++){
        if(a[i]=='0')
            cnt++; 
        else break;
    }
    for(int i=pos+cnt+1,j=0;i<len;i++,j++){
        str1[j]=a[i];
    }
    int r=a[pos+cnt]-'0';//首位数字
    if(a[pos+1]=='\0'){ @@ // This checks if the character after the first non-zero digit is null, but if cnt pushes pos+cnt beyond string length, this causes out-of-bounds access. Also, logic fails when all digits after decimal are zero (but problem says no trailing zeros, so maybe safe, but still fragile).
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1); @@ // str1 is not null-terminated, so printf may print garbage beyond intended digits.
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){
        printf("%se0",a); @@ // This prints the whole original string with "e0", but scientific notation requires normalized form (one non-zero digit before decimal). E.g., input "5.67" should become "5.67e0", but according to spec, base must have one digit before decimal → correct, but if input is "12.3", this branch won't trigger (s=2), so handled in else. However, for "5.67", output is "5.67e0" which matches expected format? But problem says: if only one digit before decimal and it's non-zero, then it's okay. However, this branch prints entire 'a', which includes the decimal point and all digits — acceptable only if already normalized. But what if input is "5."? Then a = "5.", and output is "5.e0", which is invalid because after decimal there should be no trailing zeros, but here there's nothing — possibly acceptable? However, main issue: this branch assumes s==1 means one digit before decimal, which is true, but doesn't handle cases where there are more digits after decimal correctly per spec? Actually, spec allows one digit before decimal and any significant digits after. So "5.67e0" is okay. But the real bug is elsewhere.
    }
    else{
        printf("%d.",a[0]-'0');
        for(int i=1,j=0;i<pos-1;i++,j++){
            str2[j]=a[i];
        }
        for(int i=pos,j=0;i<len;i++,j++){
            str3[j]=a[i];
        }
        printf("%s",str2); @@ // str2 is not null-terminated → may print garbage.
        printf("%s",str3); @@ // str3 is not null-terminated → may print garbage.
        printf("e%d",s-1);
    }


return 0;
}