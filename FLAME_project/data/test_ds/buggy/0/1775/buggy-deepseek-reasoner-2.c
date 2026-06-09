#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s);
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i];
        if(s[i]=='-'&&s[i+1]>s[i-1]){
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){ // @@ Error: In the digit condition, `s[i+1]-'\0'<=9` should be `s[i+1]-'0'<=9`. Using `'\0'` (ASCII 0) instead of `'0'` (ASCII 48) causes the check to compare the raw ASCII value against 9, which always fails for digit characters (e.g., '8' is 56 > 9). This prevents expansion of digit ranges like '0-8'.
                for(int k=1;k<s[i+1]-s[i-1];k++){
                    b[j]=s[i-1]+k;
                    j++;
                }
                b[j]=s[i+1];
                i++;
            }    
            
        }
    }
    puts(b);
    return 0;
}