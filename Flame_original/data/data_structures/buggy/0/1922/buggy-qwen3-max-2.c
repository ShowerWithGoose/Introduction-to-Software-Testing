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
    }//将是s 的东西赋给a  @@ [Loop copies one extra character (null terminator) into 'a', but more critically, 's' was initialized with " " and then overwritten by scanf, so the initial space is irrelevant. However, the real issue is that 'b' is uninitialized and accessed with index 'flag+i' which may be out of sync.]
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Indexing into 'b' as 'flag+i' is incorrect because 'flag' accumulates expansion offsets but is not properly synchronized with the current position in 'b'. This leads to overwriting or skipping positions in 'b'. Also, when no '-' is processed, 'flag' remains 0, but after processing '-', 'flag' is set incorrectly (see below).]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition checks upper bound only (e.g., a[i+1] <= 'z') but does NOT check lower bound for the second character (e.g., a[i+1] >= 'a'). Similarly, it doesn't ensure both characters are of the same type. For example, 'a'-'Z' could pass if 'Z' > 'a' numerically, which it isn't, but logic is flawed. Also, accessing a[i+1] when i == strlen(s) causes out-of-bounds read.]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ [Index calculation 'i+flag+m' is wrong. The base position in 'b' should be tracked independently, not derived from original string index 'i' plus 'flag'. This causes misplacement of expanded characters.]
                }
                flag=a[i+1]-a[i-1]-2; @@ ['flag' is assigned an absolute value instead of being incremented. This breaks accumulation for multiple expansions. Should be 'flag += ...' or better yet, use a separate output index. Also, the value is off by one: number of inserted chars is (a[i+1]-a[i-1]-1), so offset should increase by that amount, not minus 2.]
                sum+=flag; @@ ['sum' is updated with possibly negative 'flag' (if a[i+1]-a[i-1]-2 < 0), and logic is inconsistent. Also, 'sum' is used later as loop bound but includes invalid adjustments.]


            }
            else {
                b[i+flag]=a[i]; @@ [Same indexing issue: 'i+flag' does not represent the correct next position in 'b'.]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop runs to 'sum' inclusive, but 'sum' was modified incorrectly. Also, 'b' is not null-terminated, so printing via %c loop may output garbage beyond intended length. Moreover, if no expansion happened, 'sum' = original length, but loop goes to <=sum, printing one extra (uninitialized) character.]
        printf("%c",b[i]);
    }

    return 0;

}