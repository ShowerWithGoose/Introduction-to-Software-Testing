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
    return strcmp(a->word+1,b->word +1); // @@ [The comparison skips the first character of each word by using `word+1`, which is incorrect. Words should be compared from index 0. Also, words are stored starting at index 1 due to `++a[cnt].sum` below, but this leads to uninitialized `word[0]` and inconsistent handling.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `!=` has higher precedence than `=`, so this assigns the result of `(fgetc(in) != EOF)` (0 or 1) to `c`, not the character. Should be `while((c = fgetc(in)) != EOF)`]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [Incorrect case conversion: should use `tolower(s[i])`. Also, `'A'+'a'` logic is flawed; e.g., 'Z' becomes '{'.]
            a[cnt].word[++a[cnt].sum]=c; // @@ [Stores characters starting at index 1, leaving `word[0]` uninitialized (garbage), which causes undefined behavior in `strcmp` later.]
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [This increments `i` inside the loop condition, which may cause skipping non-alpha characters incorrectly and potential out-of-bound access if `i` exceeds `len`.]
    }
    
    qsort(a+1,cnt,sizeof(a[0]),cmp);
    
    int ans=0;
    for(i=1;i<=cnt;i++){
        if(i==1||strcmp(a[i].word +1,a[i-1].word +1)!=0){ // @@ [Again comparing from index 1, which is inconsistent and wrong. Also, `ans` is not initialized properly for the first unique word.]
            if(i!=1)
                printf("%s %d\n",a[i-1].word +1,ans);
            ans=1;
        }else if(strcmp(a[i].word+1,a[i-1].word +1)==0) ans++;
    }
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [Always prints last word even if `cnt == 0` (no words), leading to undefined behavior. Also uses `word+1` incorrectly.]

    return 0;
}