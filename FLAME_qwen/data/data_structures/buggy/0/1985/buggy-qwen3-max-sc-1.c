#include<stdio.h>
#include<string.h>
int main() {
    char ch[100],s[100]="0";
    int j=0;
    scanf("%s",ch);
    for(int i=0; i<=strlen(ch); i++) { // @@ [Loop runs one iteration too far: i<=strlen(ch) accesses ch[strlen(ch)] which is '\0', and then ch[i+1] reads beyond the string, causing undefined behavior. Should be i < strlen(ch).]
        if(ch[i]=='-'&&ch[i-1]<ch[i+1]) { // @@ [When i=0, ch[i-1] accesses ch[-1], which is out-of-bounds. Also, when i is the last valid index, ch[i+1] is out-of-bounds. Need to check bounds before accessing ch[i-1] and ch[i+1].]
            if(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57) {
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90) { // @@ [Should use else if to avoid overlapping checks; otherwise, multiple expansions may occur or incorrect logic may follow.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            }
            if(ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122) { // @@ [Same issue: should be else if. Also, the following else block only applies to this last if, not the whole group, leading to incorrect handling of mixed-type cases.]
                for(int k=ch[i-1]+1; k<=ch[i+1]-1; k++) {
                    s[j]=k;
                    j++;
                }
            } else {
                i++; // @@ [This increments i again, skipping the next character. Also, it writes ch[i] (after increment) into s, but this logic is misplaced and breaks control flow.]
                s[j]=ch[i];
                j++;
            }
        } else {
            s[j]=ch[i];
            j++;
        }
    }
    printf("%s",s);
    return 0;
}