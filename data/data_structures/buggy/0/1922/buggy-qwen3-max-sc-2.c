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
    }//将是s 的东西赋给a  @@ [Loop copies one character past the null terminator of s, causing undefined behavior; should be i < strlen(s)]
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Indexing b with flag+i is incorrect logic; flag is not properly maintained as an offset]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition checks a[i+1] <= 'z' etc. without verifying a[i-1] and a[i+1] are of same category; e.g., 'a'-'Z' could pass if 'Z' > 'a', which is false but logic flawed]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; @@ [flag is overwritten instead of accumulated; should be flag += ...]
                sum+=flag;


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop runs to i <= sum, which accesses b[sum], one past valid data; should be i < sum or adjusted based on actual length]
        printf("%c",b[i]);
    }

    return 0;

}