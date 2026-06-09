#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    } // @@ [The loop reads until EOF but does not null-terminate the array, and 'i' ends up being one past the last valid character index. Also, when using <=i in the next loop, it accesses uninitialized memory beyond the input.]
    for(j=0;j<=i;j++){ // @@ [Loop condition should be j < i, not j <= i, because 'i' is the count of characters read (equal to the index after the last character), so a[i] is uninitialized or contains garbage (like the null byte shown in output). This causes printing an extra unintended character at the end.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ [The condition checks only upper bounds for the second character and lower bounds for the first, but doesn't ensure both characters are of the same category. For example, 'a' (lowercase) and 'F' (uppercase) could pass if mistakenly compared due to ASCII values, but more critically, it allows mixed-type cases like '9' and 'a' if a[j-1]='9' and a[j+1]='a', since '9'<'a' and '9'>='0' and 'a'<='z' — which violates the requirement that both must be same type. However, in this specific test case, this bug doesn't trigger, so the main issue is the loop bound.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}