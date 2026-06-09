#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s);
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [The condition checks only the lower bound for s[i-1] and upper bound for s[i+1], but does not ensure both are digits. For example, s[i-1]='a' (>= '0') and s[i+1]='5' (<= '9') would incorrectly pass. Both characters must be in the same category.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Same issue: s[i-1] could be uppercase or digit (still >= 'a' is false, but logic is flawed). Actually, this condition fails to check that s[i+1] >= 'a' and s[i-1] <= 'z'. So if s[i-1]='A' and s[i+1]='z', it might not trigger, but more critically, if s[i-1]='0' and s[i+1]='b', s[i-1] >= 'a' is false so it skips — however, the real bug is missing full range validation for both ends.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Same problem: does not verify that s[i+1] >= 'A' and s[i-1] <= 'Z'. Thus, mixed-type cases like 'B-e' may not be caught properly because the conditions are incomplete.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    }
    else{printf("%c",s[i]);
    }    
}
return 0;
}