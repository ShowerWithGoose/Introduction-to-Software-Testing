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
                pos=0;cnt++; // @@ [Error: When encountering a non-letter character, the code increments cnt and resets pos, but this incorrectly creates an empty word entry and fails to properly handle multiple non-letter characters in sequence, leading to incorrect word counting and potential out-of-bounds access.]
            }
        }
        cnt++; // @@ [Error: After processing each word from fscanf, cnt is incremented unconditionally, but the loop may have already incremented cnt for non-letter characters, causing extra empty entries and incorrect word counts.]
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue; // @@ [Error: The condition checks for a space character, but empty strings have a null terminator at index 0, not a space. This will not skip empty entries, causing incorrect output.]
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