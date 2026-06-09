#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100];
    scanf("%s",s);
    int sum=strlen(s),flag=0;//flag代表插入的数据个数，sum来代表最后b的位数 
    int i=0; 
    for(i;i<=strlen(s);i++) {
        a[i]=s[i];
    }//将是s 的东西赋给a  
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i];
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ // The condition incorrectly checks range using mixed bounds (e.g., 'a' <= a[i-1] and a[i+1] <= 'z'), which allows invalid cross-type cases like 'a'-'Z'. It should ensure both characters are of the same type.
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; @@ // 'flag' is being overwritten instead of accumulated; it should track total inserted characters, not just the last expansion count.
                sum+=flag;


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ // Loop runs to 'sum' inclusive, but 'sum' was modified during expansion and may exceed actual valid indices; also, original string length already includes null terminator logic issues.
        printf("%c",b[i]);
    }

    return 0;

}