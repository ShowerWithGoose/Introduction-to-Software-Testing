#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ The condition incorrectly mixes bounds of str[i] and str[i+2]; it should verify both characters belong to the same category (e.g., both digits, both uppercase, or both lowercase).
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ The loop condition j<flag excludes the end character of the expansion; it should be j<=flag to include it.
                        printf("%c",str[i]+j);
                    }
                    i++; // @@ Incrementing i by 1 only skips the '-' symbol, causing the end character to be processed again in the next iteration; it should be i+=2 to skip both '-' and the end character.
            }
            else{
                printf("%c",str[i]);
                printf("-");
                i++;
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ This unconditionally prints the last two characters, which produces incorrect output when the string ends with an expansion; it should be removed or guarded.

}