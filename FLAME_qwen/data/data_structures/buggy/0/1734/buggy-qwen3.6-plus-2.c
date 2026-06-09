#include <stdio.h>
#include <string.h>
int main()
{
    char os[200];//原字符串
    char s[300];//扩展后字符串
    scanf("%s",os);
    int n=strlen(os);
    int i,j;
    for(i=0,j=0;i<n;i++){
        if(os[i]!='-'){
            s[j]=os[i];
            j++;
        }
        else{
            if((os[i-1]>='0'&&os[i+1]<='9'&&os[i-1]<os[i+1])||(os[i-1]>='a'&&os[i+1]<='z'&&os[i-1]<os[i+1])||(os[i-1]>='A'&&os[i+1]<='Z'&&os[i-1]<os[i+1])){ // @@ Range check is logically flawed; it only verifies the lower bound for the left character and upper bound for the right character, failing to ensure both characters strictly belong to the same type range.
                //保证扩展符前后的字符同时为小写字母、大写字母或数字且后字符大于前字符
                for(int m=1;s[j-1]<os[i+1]-1;j++){ // @@ Loop variable 'm' is declared but never incremented or used correctly; the condition relies on the dynamically changing s[j-1], making the expansion logic error-prone and unclear.
                   s[j]=s[j-1]+m;//扩展 // @@ Since 'm' remains constant at 1, this relies on side-effects of s[j-1] updating, which is poor practice and should explicitly iterate through the character range.
                }

            }
            else{
                s[j]=os[i];
                j++;
            }
        }
    }

    printf("%s",s); // @@ The expanded string 's' is not null-terminated with '\0', causing printf to read past the valid data and output garbage or cause undefined behavior.
    return 0;
}