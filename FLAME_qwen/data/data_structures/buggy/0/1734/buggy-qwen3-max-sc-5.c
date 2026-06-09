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
                for(int m=1;s[j-1]<os[i+1]-1;j++){ @@ [The loop condition is incorrect: it compares s[j-1] (last written char in output) with os[i+1]-1, but should compare a running variable with os[i+1]. Also, 'm' is unused and the logic doesn't increment correctly. This leads to infinite loop or wrong expansion.]
                   s[j]=s[j-1]+m;//扩展 @@ [This uses 'm' which is always 1, so it just adds 1 repeatedly, but the loop condition is broken so it may never terminate or produce wrong output.]
                }

            }
            else{
                s[j]=os[i];
                j++;
            }
        }
    }
    
    printf("%s",s); @@ [The output string 's' is not null-terminated, which can cause undefined behavior when printing.]
    return 0;
}