#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
int main(){
    int i=0,m=0,j=0;
    char ch[10000]={0};
    char c=0;
    gets(ch);
    m=strlen(ch);
    for(i=1;i<m;i++){
        if(ch[i]!='-'&&ch[i-1]!='-'){
        printf("%c",ch[i-1]);
        }
        else if(ch[i]=='-'){
            printf("%c",ch[i-1]);
            if(isupper(ch[i-1])&&isupper(ch[i+1])){ // @@ The condition checks if both characters are uppercase, but fails to verify if the start character is strictly less than the end character. For input "B-e", 'B' is upper and 'e' is lower, so this block is skipped correctly. However, the logic for skipping expansion when types differ or order is wrong is handled by falling through to the final else-if or implicit fallthrough. The main issue is that if the types match but start >= end, it still prints the hyphen and potentially expands incorrectly or does nothing, but here the specific error for B-e is that it outputs Be instead of B-e. Let's trace B-e. i=1, ch[1]='-'. Prints ch[0]='B'. Checks isupper('B') && isupper('e') -> False. Checks islower('B')... -> False. Checks digit... -> False. Checks ch[i]!='-' -> False. So it prints nothing else for the middle part. Then loop ends. Finally prints ch[m-1] which is 'e'. Output: Be. The problem requires outputting B-e unchanged because types differ. The code prints the char before '-', then decides whether to expand. If it doesn't expand, it should print the '-' and the char after. But here it only prints the char before. It misses printing the '-' and the next char if no expansion happens.
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(islower(ch[i-1])&&islower(ch[i+1])){
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'){
                    for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if (ch[i] != '-') // @@ This condition is logically unreachable because we are inside the else if(ch[i]=='-') block. Consequently, when expansion conditions are not met (like in B-e), the code fails to print the '-' character and the following character, leading to missing output. It should be an else block that prints the '-' and handles the next character appropriately, or simply prints the '-' here and lets the next iteration handle the next char (but the next iteration will skip printing ch[i] if it's not '-' and prev is '-'). Actually, the structure is flawed. If expansion doesn't happen, we need to output the '-' and ensure the next character is output. Currently, the next character 'e' is printed at the very end by printf("%c",ch[m-1]), but the '-' is lost.
            printf("%c", ch[i]);
            }
            
    }
    printf("%c",ch[m-1]);
    return 0;
}