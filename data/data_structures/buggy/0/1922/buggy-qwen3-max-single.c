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
    }//将是s 的东西赋给a  @@ [Loop condition should be i < strlen(s) to avoid copying the null terminator unnecessarily and prevent potential out-of-bound access in later logic. Also, copying beyond string length is redundant.]
    i=0;
    for(i; i<=strlen(s); i++) { @@ [Loop runs one past the null terminator (i <= strlen(s)), which may cause reading a[i+1] beyond string bounds when i == strlen(s). Should be i < strlen(s).]
        if(a[i]!='-') {
            b[flag+i]=a[i]; @@ [Indexing b with flag+i is incorrect because flag changes dynamically; this leads to overwriting or gaps in output buffer. Should maintain a separate output index.]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { @@ [Condition checks a[i+1] <= 'z' etc., but doesn't ensure a[i-1] is also in the same category (e.g., a[i-1] could be 'A' and a[i+1] 'z', which passes the OR condition incorrectly). Also, accessing a[i+1] when i is at last character causes out-of-bound read.]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ [Same indexing issue: using i+flag+m assumes fixed offset, but flag changes per expansion, leading to incorrect placement in b.]
                }
                flag=a[i+1]-a[i-1]-2; @@ [flag is overwritten instead of accumulated; should be flag += (a[i+1]-a[i-1]-1) to track total inserted characters. Also, -2 is wrong; should be -1 for count of inserted chars.]
                sum+=flag; @@ [sum update uses incorrect flag value, leading to wrong final loop bound.]


            }
            else {
                b[i+flag]=a[i]; @@ [Again, indexing with i+flag is flawed due to dynamic flag and lack of proper output index management.]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { @@ [Loop condition i <= sum prints one extra character beyond intended (since sum was miscomputed and loop includes null terminator or garbage). Should be i < actual_output_length.]
        printf("%c",b[i]);
    }

    return 0;

}