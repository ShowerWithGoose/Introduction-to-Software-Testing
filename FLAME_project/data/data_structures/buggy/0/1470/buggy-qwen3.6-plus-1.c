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
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ The condition does not check if i > 0 and i < strlen(a) - 1, leading to out-of-bounds access when '-' is at the start or end. Also, it doesn't verify that the characters are of the same type before expanding, although the inner if does this, the outer if logic is flawed for boundary cases. More critically, when expansion happens, it prints the full range including endpoints, but the 'else' branch below prints the current character. If expansion occurs, the endpoints (a[i-1] and a[i+1]) are printed by the expansion loop, but a[i-1] was already printed in a previous iteration. The main issue is that when expansion is valid, the code prints the sequence from a[i-1]+1 to a[i+1], but a[i-1] was already printed. Wait, looking at the loop: if a[i] is '-', it enters this block. It does NOT print a[i] ('-'). It prints the expansion. But a[i-1] was printed in the previous iteration (when i was i-1). So the expansion should start from a[i-1]+1. The reference code prints from a[i-1]+1 to a[i+1]-1. This code prints from a[i-1]+1 to a[i+1]. This means a[i+1] is printed here. Then in the next iteration, when i becomes i+1, a[i+1] (the character after '-') will be processed. If it's not part of another expansion, it will be printed again. This causes duplication of the end character.
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ The loop condition j <= a[i+1]-a[i-1] causes the loop to include the end character a[i+1]. Since a[i+1] will be printed again in its own iteration (unless it's part of another expansion), this leads to duplicate output of the end character. It should be j < a[i+1]-a[i-1] or j <= a[i+1]-a[i-1]-1 to exclude the end character, matching the reference behavior which prints up to a[i+1]-1.
                    printf("%c",a[i-1]+j);
                }
            }
            else{
                printf("-");
            }
        }
        else{
            printf("%c",a[i]);
        }
    }
    return 0;
}