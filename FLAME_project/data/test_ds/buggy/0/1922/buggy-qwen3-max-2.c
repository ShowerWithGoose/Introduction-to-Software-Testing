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

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ [The condition incorrectly checks mixed-type ranges (e.g., 'a' and 'Z') as valid because it doesn't ensure both characters are of the same type. Also, boundary checks like a[i-1] >= 'a' && a[i+1] <= 'z' allow invalid cross-type cases like 'Z'-'a'.]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ [This assignment overwrites previous flag value instead of accumulating inserted characters, causing incorrect indexing in subsequent expansions.]
                sum+=flag;


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { // @@ [Loop runs to i<=sum, which accesses b[sum], but b has only sum+1 elements indexed 0..sum; however, due to incorrect flag handling and off-by-one logic, this often prints garbage beyond the actual string. Also, sum was modified during expansion but not correctly tracking final length.]
        printf("%c",b[i]);
    }

    return 0;

}