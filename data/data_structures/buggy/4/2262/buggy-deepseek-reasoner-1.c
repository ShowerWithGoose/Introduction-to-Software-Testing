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
    while(~fscanf(in,"%s",mid)) { // @@ read using %s includes punctuation, and loop condition using ~ is error-prone; may cause infinite loop if fscanf returns 0
        int len=strlen(mid);
        int pos=0;
        for(int i=0; i<len; i++) {
            mid[i]=tolower(mid[i]);
            if(mid[i]<='z'&&mid[i]>='a')
                s[cnt].ss[pos++]=mid[i]; // @@ no null terminator added after the for loop; s[cnt].ss may not be null-terminated, causing undefined behavior in strcmp
            else{
                pos=0;cnt++; // @@ increments cnt each time a non-alpha is encountered, but does not null-terminate the current entry; may create many empty or uninitialized entries
            }
        }
        cnt++; // @@ extra increment at end of token; combined with increment inside else, leads to multiple increments per token and indexing errors
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue; // @@ condition does not properly skip empty strings; should check strlen(s[i].ss)==0, and uninitialized ss[0] may not be space
        int t=0;
        for(int j=i;j<cnt;j++){
            if(strcmp(s[i].ss,s[j].ss)!=0) break;
            else t++;
        }
        printf("%s %d\n",s[i].ss,t); // @@ printing s[i].ss may produce garbage if null terminator is missing
        i=i+t-1;
    }
    return 0;
}