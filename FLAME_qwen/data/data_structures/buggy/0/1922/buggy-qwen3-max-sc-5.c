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
    }//将是s 的东西赋给a  @@ [Loop condition should be i < strlen(s) to avoid copying the null terminator unnecessarily and prevent potential out-of-bounds if relying on exact size; but more critically, this loop copies one extra character (the '\0'), which may interfere with later logic. However, the major errors are elsewhere.]
    i=0;
    for(i; i<=strlen(s); i++) { @@ [Loop runs one past the last valid index (should be i < strlen(s)), leading to accessing a[strlen(s)] which is '\0', and then checking a[i+1] which is out-of-bounds when i == strlen(s). This causes undefined behavior.]
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Indexing into b as flag+i is incorrect because flag changes during expansion, causing misalignment and overwrites. The output array index should be tracked independently (e.g., with a separate index variable), not computed as flag+i.]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition checks a[i+1] <= 'z' etc., but does NOT ensure a[i-1] is within the same category. For example, if a[i-1] is '0' and a[i+1] is 'z', it passes the digit/lowercase mixed check incorrectly. Also, when i=0, a[i-1] is a[-1] → undefined behavior. Similarly, when i = strlen(s)-1, a[i+1] is out of bounds.]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ [Again uses i+flag+m which is an invalid indexing strategy. The position in b should not depend on original string index i after expansions have occurred.]
                }
                flag=a[i+1]-a[i-1]-2; @@ [This assignment overwrites flag instead of accumulating it. Should be flag += (a[i+1]-a[i-1]-1). Also, -2 is wrong; number of inserted chars is (a[i+1]-a[i-1]-1), so flag should increase by that amount.]
                sum+=flag; @@ [sum is updated with possibly negative or incorrect flag, leading to wrong final loop bound.]


            }
            else {
                b[i+flag]=a[i]; @@ [Same indexing issue: i+flag is not the correct next position in b.]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop condition i <= sum prints one extra character beyond the intended string (since sum was initialized to strlen(s) and modified incorrectly). Should be i < actual_length_of_b. Also, b is never null-terminated, so printing via %c loop must know exact length—but sum is miscalculated.]
        printf("%c",b[i]);
    }

    return 0;

}