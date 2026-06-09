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
                for(int m=1;s[j-1]<os[i+1]-1;j++){ @@ [The loop condition is incorrect and leads to undefined behavior. It compares s[j-1] (which may be uninitialized or unrelated) instead of the starting character os[i-1]. Also, 'm' is unused and the increment logic is flawed.]
                   s[j]=s[j-1]+m;//扩展 @@ [This uses s[j-1] which may not be the correct base character; it should use os[i-1] as the base. Additionally, 'm' is never updated in the loop, so it always adds 1.]
                }

            }
            else{
                s[j]=os[i];
                j++;
            }
        }
    }
    
    printf("%s",s); @@ [The output string 's' is not null-terminated, which can cause undefined behavior when printed with %s.]
    return 0;
}