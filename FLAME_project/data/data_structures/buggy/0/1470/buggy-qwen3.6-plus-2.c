#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[1010];
    int i,j;
    
    gets(a);
    
    for(i=0;i<strlen(a);i++){
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ The condition does not check if i > 0 and i < strlen(a) - 1, leading to out-of-bounds access when '-' is at the start or end. More importantly, it fails to verify that the characters are of the same type before expanding, although the inner if does this. However, the main logic error is in the expansion loop below.
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ The loop condition j <= a[i+1]-a[i-1] causes the last character (a[i+1]) to be printed again because when j equals the difference, a[i-1]+j equals a[i+1]. The previous character a[i-1] was already printed by the else block in the previous iteration (or will be handled incorrectly). Actually, looking at the structure: if we are at '-', we enter this block. The previous char a[i-1] was printed in the previous iteration's else block? No, if i-1 was part of a previous expansion, it might have been skipped? Let's trace 'a-u'. i=1 is '-'. a[0]='a' was printed at i=0. Then at i=1, we expand. We print 'b'..'u'. So 'u' is printed here. Then at i=2 ('u'), the else block prints 'u' again. This causes duplication of the end character.
                    printf("%c",a[i-1]+j);
                }
            }
            else{
                printf("-");
            }
        }
        else{
            printf("%c",a[i]); // @@ This prints the character after the expansion range (e.g., 'u' in 'a-u') which was already printed by the expansion loop, causing duplication. Also prints the start character if it wasn't part of a previous expansion.
        }
    }
    return 0;
}