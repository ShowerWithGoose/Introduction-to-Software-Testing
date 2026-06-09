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
            b[flag+i]=a[i]; // @@ [Error: The index calculation is incorrect. When flag is updated after expansion, the index for subsequent non-dash characters does not account for the expanded characters properly, leading to overwriting or gaps in array b.]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) {
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ [Error: flag should be the total number of inserted characters, not the difference minus 2. This incorrect assignment causes subsequent index calculations to be wrong.]
                sum+=flag; // @@ [Error: sum is updated incorrectly because flag is wrong, and sum is used later to print the array, leading to incorrect output length.]

            }
            else {
                b[i+flag]=a[i]; // @@ [Error: When no expansion occurs, the dash should be copied to b, but the index i+flag may be incorrect if flag was previously modified incorrectly.]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) {
        printf("%c",b[i]);
    }

    return 0;

}