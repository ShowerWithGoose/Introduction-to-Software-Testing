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
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ The original code uses independent 'if' statements. For input "B-e", the first 'if' (digits) is false, but the second 'if' (lowercase) checks if 'B' >= 'a' (false) and 'e' <= 'z' (true). However, the logic for determining whether to expand or print the hyphen is flawed because it doesn't handle the "else" case for the hyphen correctly when no expansion happens. More critically, the current structure prints the hyphen in the final 'else' block only if the character is not '-'. But if it IS '-', and none of the expansion conditions are met, the hyphen is never printed. We need to ensure the hyphen is printed if no expansion occurs.
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ Same issue as above. Independent 'if's mean multiple blocks could theoretically run (though mutually exclusive here due to char ranges), but more importantly, if none run, the hyphen is lost.
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        else { // @@ Added else block to handle cases where '-' is present but expansion conditions are not met (e.g., B-e). In these cases, the '-' itself must be printed.
            printf("%c", s[i]);
        }
    }
    else{printf("%c",s[i]);
    }    
}
return 0;
}