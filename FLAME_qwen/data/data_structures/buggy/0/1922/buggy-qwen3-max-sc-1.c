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
    }//将是s 的东西赋给a  @@ [Loop condition should be i < strlen(s) to avoid copying null terminator unnecessarily and potential out-of-bound if s is full; also, using <= copies one extra character beyond string length]
    i=0;
    for(i; i<=strlen(s); i++) { @@ [Loop runs one past the null terminator; should be i < strlen(s). Accessing a[i+1] when i == strlen(s) leads to out-of-bounds read]
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Indexing with flag+i is incorrect; flag tracks inserted chars but isn't updated properly, leading to wrong positions and overwrites]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition checks a[i+1] <= 'z' etc., but doesn't ensure a[i-1] is in same category (e.g., a[i-1] could be 'A' and a[i+1] 'z', which passes but shouldn't). Also, ==1 is redundant and misleading]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ [Index i+flag+m may exceed array bounds; also, overlapping writes possible due to incorrect indexing]
                }
                flag=a[i+1]-a[i-1]-2; @@ [flag is overwritten instead of accumulated; should be flag += ..., and -2 is wrong—it should reflect number of inserted chars, which is (a[i+1]-a[i-1]-1)]
                sum+=flag; @@ [sum is increased by possibly negative or incorrect flag value, leading to wrong final loop bound]


            }
            else {
                b[i+flag]=a[i]; @@ [Again, indexing with i+flag is flawed; flag not maintained correctly across iterations]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop goes to <= sum, but sum may be invalid due to earlier errors; also, b is not null-terminated, so printing via %c loop may output garbage beyond intended string]
        printf("%c",b[i]);
    }

    return 0;

}