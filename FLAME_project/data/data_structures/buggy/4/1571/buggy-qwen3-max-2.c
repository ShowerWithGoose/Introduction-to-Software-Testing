#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxn 100005
#define m 105

int num,i;//单词个数
struct WORD{
    int time,sum;//词频，长度 
    char word[105];
}a[maxn];
char s[maxn],c;//c：从文件中读取的字符 
int cnt,i,len;//存储的单词个数，，字符串的长度 

int cmp(const void *p,const void *q){
    struct WORD *a=(struct WORD *)p;
    struct WORD *b=(struct WORD *)q;
    return strcmp(a->word+1,b->word +1);
} // @@ [The comparison function skips the first character of each word by using `word+1`, but words are stored starting at index 1, so this is inconsistent with how words are printed and compared. However, the real issue is that words should be stored from index 0, not 1.]

int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `!=` has higher precedence than `=`, so this assigns the result of `(fgetc(in) != EOF)` (which is 0 or 1) to `c`, not the actual character. This causes all characters to be lost and replaced by 0 or 1.]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [This converts uppercase to lowercase correctly, but note that `s[i]` might be non-alphabetic here due to loop condition relying on `isalpha(s[i])` before entering, but after increment in `while(isalpha(s[++i]))`, it may go out of bounds or process non-alpha. Also, storing starts at index 1, which is unconventional and leads to wasted space and off-by-one issues.]
            a[cnt].word[++a[cnt].sum]=c;
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [This increments `i` inside the condition, which may cause skipping characters or reading beyond valid data. Also, after the last word, `i` may exceed `len`, leading to undefined behavior when accessing `s[i]`.]
    }
    
    qsort(a+1,cnt,sizeof(a[0]),cmp);
    
    int ans=0;
    for(i=1;i<=cnt;i++){
        if(i==1||strcmp(a[i].word +1,a[i-1].word +1)!=0){
            if(i!=1)
                printf("%s %d\n",a[i-1].word +1,ans); // @@ [When a new word is found, it prints the previous word with accumulated count, but the count `ans` was never updated for the previous group properly because `ans` is only reset to 1, not incremented during grouping. Also, the final word group is handled after the loop, but intermediate groups may miss updates.]
            ans=1;
        }else if(strcmp(a[i].word+1,a[i-1].word +1)==0) ans++;
    }
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [This prints the last word, but if there are no words (`cnt == 0`), this accesses `a[0]` which is uninitialized, leading to garbage output like " 0". Also, the logic for counting frequencies is flawed: it doesn't aggregate counts correctly across duplicates because it assumes sorted input groups consecutive duplicates, but the initial parsing stores every token as a separate entry without combining, and then tries to count during output — but the count variable `ans` is not tracking the actual frequency from the array, just the run-length in the sorted list. However, since every word occurrence is stored individually in `a[]`, this run-length *should* work — but only if parsing is correct. The main failure is due to the fgetc assignment bug causing no real words to be read.]

    return 0;
}