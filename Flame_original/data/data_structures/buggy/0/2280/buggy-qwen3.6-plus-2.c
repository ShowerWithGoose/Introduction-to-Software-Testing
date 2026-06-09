#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str); // @@ `gets` is deprecated and removed in the C11 standard, which causes compilation errors in modern environments; `fgets` should be used instead.
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ Loop condition `i<leng-2` is incorrect; it terminates prematurely and relies on a flawed final print statement, causing missing or duplicated characters.
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ Type checking logic is flawed; it does not verify that both characters belong to the same specific range (e.g., both digits or both letters), only checking incorrect boundary conditions.
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ Loop condition `j<flag` excludes the end character of the expansion range; it should be `j<=flag` to correctly include the final character (e.g., 'd' in a-d).
                        printf("%c",str[i]+j);
                    }
                    i++; // @@ Manually incrementing `i` inside the loop interferes with the `for` loop's automatic increment, causing incorrect index traversal and potential character skipping or duplication.
            }
            else{
                printf("%c",str[i]);
                printf("-");
                i++; // @@ Same issue as above; manual increment disrupts the loop control flow, leading to incorrect processing of subsequent characters.
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ Unconditionally prints the last two characters, which causes duplication if they were already processed in the loop, and risks out-of-bounds access for strings shorter than 2 characters.

}