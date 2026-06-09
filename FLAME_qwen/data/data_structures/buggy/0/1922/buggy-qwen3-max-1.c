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
    }//将是s 的东西赋给a  @@ [Loop copies one extra character (null terminator) unnecessarily, but not the main error]
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Incorrect indexing: 'flag+i' may skip positions or overwrite due to changing 'flag'; should use a running index like 'j']
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition is flawed: it doesn't ensure both ends are of the same type (e.g., allows 'a' and 'Z'); also accesses a[i+1] when i may be at last index]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; @@ [Wrong update of 'flag': should accumulate total inserted chars, not set to last expansion count minus 2]
                sum+=flag;


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop runs one past valid data; 'sum' was modified incorrectly and includes off-by-one errors; also prints uninitialized parts of b]
        printf("%c",b[i]);
    }

    return 0;

}