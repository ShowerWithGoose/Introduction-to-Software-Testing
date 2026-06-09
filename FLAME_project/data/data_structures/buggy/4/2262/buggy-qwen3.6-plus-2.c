#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct stu{
    char ss[1000];
    int num;
};
int cmp(const void*a,const void *b){
    struct stu*p1=(struct stu*)a;
    struct stu*p2=(struct stu*)b;
    return (strcmp(p1->ss,p2->ss));
}
int main()
{
    struct stu s[1000];
    FILE*in;
    in=fopen("article.txt","r");
    int cnt=0;
    char mid[1000]= {};
    while(~fscanf(in,"%s",mid)) {
        int len=strlen(mid);
        int pos=0;
        for(int i=0; i<len; i++) {
            mid[i]=tolower(mid[i]);
            if(mid[i]<='z'&&mid[i]>='a')
                s[cnt].ss[pos++]=mid[i];
            else{
                if(pos > 0) { // @@ The original code resets pos and increments cnt even if no word was being formed (e.g., consecutive non-alpha chars or leading punctuation), creating empty or invalid entries. It should only finalize a word if pos > 0.
                    s[cnt].ss[pos]='\0'; // @@ The original code fails to null-terminate the string before moving to the next word.
                    cnt++;
                }
                pos=0;
            }
        }
        if(pos > 0) { // @@ After the loop, if a word ended at the end of the string (without trailing punctuation), it needs to be finalized. The original code unconditionally increments cnt, which is incorrect if the last characters were non-alpha or if no word was formed.
            s[cnt].ss[pos]='\0'; // @@ Null-terminate the last word if it exists.
            cnt++;
        }
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]=='\0') continue; // @@ The original code checks for space ' ', but empty strings are initialized to '\0' or might be empty due to logic errors. Checking for empty string is safer to skip invalid entries.
        int t=0;
        for(int j=i;j<cnt;j++){
            if(strcmp(s[i].ss,s[j].ss)!=0) break;
            else t++;
        }
        printf("%s %d\n",s[i].ss,t);
        i=i+t-1;
    }
    return 0;
}