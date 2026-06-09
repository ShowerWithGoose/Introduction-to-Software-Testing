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
            b[flag+i]=a[i]; // @@ [Error: The index calculation is incorrect. When flag is non-zero (after expansion), the index should be based on the current position in b, not simply flag+i. This will cause overwriting or gaps in b.]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ [Error: The condition is incorrect. It should check that both characters are within the same range, not just that one is in a range. For example, a[i-1] could be 'a' and a[i+1] could be '9', which would pass this condition incorrectly. Also, the comparison with 1 is unnecessary and may cause logical issues.]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m; // @@ [Error: The index calculation is flawed. After expansion, the position in b should account for the expanded characters, but using i+flag+m does not correctly track the current write position in b, leading to incorrect output.]
                }
                flag=a[i+1]-a[i-1]-2; // @@ [Error: flag should represent the number of additional characters inserted (i.e., a[i+1]-a[i-1]-1), but subtracting 2 is incorrect. This will cause subsequent indices to be off.]
                sum+=flag; // @@ [Error: sum is updated incorrectly. It should be updated to reflect the new total length of b, but the logic here is flawed because sum is used in the final loop but not properly maintained.]


            }
            else {
                b[i+flag]=a[i]; // @@ [Error: Similar index issue as above. When no expansion occurs, the index should be based on the current write position, but i+flag may not be correct if previous expansions have shifted positions.]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { // @@ [Error: The loop condition i<=sum may cause an off-by-one error, and sum may not correctly represent the final length of b due to earlier incorrect updates.]
        printf("%c",b[i]);
    }

    return 0;

}