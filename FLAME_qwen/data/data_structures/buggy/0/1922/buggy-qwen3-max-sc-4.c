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
    }//将是s 的东西赋给a  @@ [Loop copies one extra character beyond the null terminator, causing undefined behavior. Should be i < strlen(s).]
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Indexing into b uses flag+i which may skip positions or overwrite due to incorrect offset logic. Also, loop runs past string end.]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition checks a[i+1] <= 'z' etc., but doesn't ensure a[i-1] is in same category (e.g., a[i-1] could be 'Z' and a[i+1] 'a'). Also accesses a[i+1] when i may be at last index, causing out-of-bounds read.]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ [This writes expanded characters, but base index i+flag is unstable due to changing flag and overlapping writes. Also, no bounds checking on b[].]
                }
                flag=a[i+1]-a[i-1]-2; @@ [flag is overwritten instead of accumulated; should be +=. Also, value can be negative if expansion length <=1, leading to incorrect indexing.]
                sum+=flag; @@ [If flag is negative, sum decreases incorrectly.]


            }
            else {
                b[i+flag]=a[i]; @@ [Again uses i+flag which may not reflect actual current write position in b.]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop goes to i <= sum, which is one past valid indices (0 to sum-1), printing garbage or causing UB. Also, b is not null-terminated, so even correct loop might print extra garbage.]
        printf("%c",b[i]);
    }

    return 0;

}