#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str); // @@ [gets is deprecated and unsafe; may cause compilation error in C11 or later]
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ [loop condition is incorrect; should use i<leng-1 to properly traverse entire string, and the algorithm's handling of dashes after expansion is flawed]
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [condition incorrectly checks only one side of the range; should require both characters to be within the same valid set (digits, lowercase, uppercase)]
            {
                int flag=str[i+2]-str[i]; // @@ [flag should be the number of characters to print including both ends? But actual expansion should print characters between, exclusive of ends; also flag is used incorrectly in loop]
                    for(int j=0;j<flag;j++){ // @@ [loop should run j<flag-1 to avoid printing the starting character again; it prints one extra character]
                        printf("%c",str[i]+j); // @@ [prints starting character instead of next character; should be str[i]+j+1]
                    }
                    i++; // @@ [this increment combined with the for loop increment causes double increment, skipping characters]
            }
            else{
                printf("%c",str[i]);
                printf("-");
                i++; // @@ [same double increment issue]
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [unconditionally prints the last two characters, which may have already been printed during expansion, causing duplication]
}