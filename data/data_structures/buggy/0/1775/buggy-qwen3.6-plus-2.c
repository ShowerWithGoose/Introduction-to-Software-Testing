#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s); // @@ gets() is removed in the C11 standard, causing a compilation error in modern compilers; use scanf("%s", s) or fgets() instead.
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i]; // @@ Unconditionally copies the current character including '-', which should be omitted during expansion. This should be handled in an else block.
        if(s[i]=='-'&&s[i+1]>s[i-1]){
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){ // @@ Typo: '\0' should be '0' to correctly check the digit range for s[i+1].
                for(int k=1;k<s[i+1]-s[i-1];k++){
                    b[j]=s[i-1]+k;
                    j++;
                }
                b[j]=s[i+1]; // @@ Missing j++ after assigning the end character, causing index misalignment. The expansion logic also fails to properly replace '-' as required.
                i++;
            }    
            
        }
    }
    puts(b);
    return 0;
}