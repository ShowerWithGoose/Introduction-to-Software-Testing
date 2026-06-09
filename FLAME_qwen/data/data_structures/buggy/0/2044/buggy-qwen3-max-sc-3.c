#include <stdio.h>
#include <string.h>

char s[100005];
int mk[100005];
int t(char a){
    if(a>='a'&&a<='z')return 1;
    if(a>='A'&&a<='Z')return 2;
    if(a>='0'&&a<='9')return 3;
    return -1;
}
int main() {
    scanf("%s",s+1); // @@ [Reading input into s+1 leaves s[0] uninitialized; this shifts the entire string by one, causing out-of-bounds access when checking s[i-1] for i=1 (i.e., s[0]) and s[i+1] for last character (i.e., beyond allocated range). Also, strlen(s+1) is inefficient and error-prone.]
    for(int i=1;i<=strlen(s+1);i++){ // @@ [Using strlen(s+1) in loop condition recomputes length every iteration; more critically, when i equals strlen(s+1), s[i] is '\0', and accessing s[i+1] (i.e., s[strlen(s+1)+1]) reads beyond the string boundary, leading to undefined behavior.]
        if(s[i]=='-'){
            if(t(s[i-1])!=-1&&t(s[i-1])==t(s[i+1])&&s[i-1]<=s[i+1]){ // @@ [When i=1, s[i-1] is s[0], which was never set by scanf("%s",s+1) — it's garbage. When i is at the last valid index (e.g., i = n where s[n] is last char), s[i+1] is out-of-bounds. This causes incorrect type checks or crashes.]
                mk[i-1]=mk[i]=mk[i+1]=1; // @@ [Writing to mk[i+1] may go out of bounds if i is near the end of the string, since mk array is sized same as s but indexing assumes extra space.]
            }
        }
    }
    for(int i=1;i<=strlen(s+1);i++){ // @@ [Same issue: strlen(s+1) recomputed each time; also, loop runs up to and including the null terminator index, which may cause printing unintended characters or skipping logic.]
        if(mk[i]==0)printf("%c",s[i]);
        else {
            int pos=i;
            while(mk[pos])pos++; // @@ [If mk[pos] is 1 near the end of the array, pos may increment beyond array bounds, leading to reading uninitialized memory or segmentation fault.]
            for(char j=s[i];j<=s[pos-1];j++)printf("%c",j); // @@ [This loop prints from s[i] to s[pos-1], but s[i] is the character before '-', and s[pos-1] is the character after '-'. However, due to shifted indexing (s+1), and possible out-of-bound reads earlier, s[i] and s[pos-1] may be invalid. Also, if s[i] > s[pos-1], loop condition fails, but problem requires expansion only when s[i-1] <= s[i+1], which was checked — however, due to indexing errors, this may not hold.]
            i=pos-1; 
        }
    }
    return 0;
}