#include<stdio.h>   // line1
#include<string.h>  // line2
char str[10086];    // line3
int main(){         // line4
    gets(str);      // line5
    int leng=strlen(str); // line6
    for(int i=0;i<leng-2;i++){ // line7 @@ [Loop condition stops before last two characters, causing them to be handled separately; but after expansion, the final print may print a dash that should have been consumed. Should iterate until the end or adjust logic.]
        if(str[i+1]!='-')      // line8
        printf("%c",str[i]);   // line9
        else{                  // line10
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // line11 @@ [Condition does not ensure both characters are of the same type and within the same range. For example, it incorrectly allows expansion of 'a' with 'A' or '0' with '9' across types. Should check each range separately for both characters.]
            {                   // line12
                int flag=str[i+2]-str[i]; // line13
                    for(int j=0;j<flag;j++){ // line14 @@ [Loop stops before including the last character. Should be j<=flag to include str[i+2].]
                        printf("%c",str[i]+j); // line15
                    }
                    i++;   // line17
            }
            else{           // line18
                printf("%c",str[i]); // line19
                printf("-");        // line20
                i++;                // line21
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // line24 @@ [Unconditionally prints last two characters, but after an expansion they may have already been printed or should be omitted. For example, in "a-uB-F", after expanding the last dash, the dash and 'F' should not be printed again.]
}