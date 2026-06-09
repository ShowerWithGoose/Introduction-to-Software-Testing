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
            if((os[i-1]>='0'&&os[i+1]<='9'&&os[i-1]<os[i+1])||(os[i-1]>='a'&&os[i+1]<='z'&&os[i-1]<os[i+1])||(os[i-1]>='A'&&os[i+1]<='Z'&&os[i-1]<os[i+1])){
                //保证扩展符前后的字符同时为小写字母、大写字母或数字且后字符大于前字符
                for(int m=1;s[j-1]<os[i+1]-1;j++){ @@ The loop condition and update logic are incorrect. 'm' is initialized to 1 but never incremented, causing an infinite loop or incorrect character generation. Also, the loop should generate characters from start+1 to end-1. The current logic `s[j]=s[j-1]+m` adds 1 repeatedly if m was incremented, but m is static. More importantly, the loop doesn't terminate correctly relative to the target character `os[i+1]`. It should iterate while the generated character is less than `os[i+1]`. A correct approach would be `char c = os[i-1] + 1; while(c < os[i+1]) { s[j++] = c++; }`. The current for loop structure is fundamentally flawed for this expansion task.
                   s[j]=s[j-1]+m;//扩展
                }

            }
            else{
                s[j]=os[i];
                j++;
            }
        }
    }
    
    printf("%s",s);
    return 0;
}