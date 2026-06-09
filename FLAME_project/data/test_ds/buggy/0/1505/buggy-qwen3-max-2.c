#include <stdio.h>
#include <string.h>

int range(int a,int b){
    if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        return 1;
    }
    else if(a>='a'&&a<='z'&&b>='a'&&b<='z'){
        return 1;
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char str[100];
    scanf("%s",str);
    int i;
    char j;
    for(i=0;i<=strlen(str)-2;i++){
        if(str[i]=='-'&&str[i-1]<str[i+1]&&range(str[i-1],str[i+1])==1){
            for(j=str[i-1]+1;j<=str[i+1]-1;j++){
                printf("%c",j);
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
} // @@ [The loop condition stops at strlen(str)-2, so the last character of the string is never printed. In the test case "a-uB-F", the final 'F' is at the last position and gets skipped. Additionally, when processing a '-', the code prints only the characters between the two endpoints but fails to print the right endpoint itself. For example, in "B-F", it prints C, D, E but not F. The reference program correctly includes the right endpoint by looping up to (but not including) the right endpoint in its own logic, but this buggy program excludes both endpoints due to starting at str[i-1]+1 and ending at str[i+1]-1.]