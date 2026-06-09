#include <stdio.h>
#include <stdlib.h>

struct vocab{
    char a[111];
    int t;
} s[100000];
int s1 = 0;

int cmp(const void * a, const void * b){
	struct vocab * a1=(struct vocab*)a;
	struct vocab * b1=(struct vocab*)b;
	return strcmp(a1->a, b1->a);
}

int main()
{
    FILE *in = fopen("article.txt","r");
    char a[111] = {0};
    char c; int start = 0;
    c = fgetc(in);
    while(c != EOF){
        if(start > 0){
            if(isalpha(c)){
                a[start++] = tolower(c);
            }
            else{
                strcpy((s[s1].a), a);
                s[s1].t = 1;
                s1++;
                memset(a, 0, sizeof(a));
                start = 0;
            }
        }
        else if(start == 0){
            if(isalpha(c)){
                a[start++] = tolower(c);
            }
        }
        c = fgetc(in);
    }
    qsort(s, s1, sizeof(s[0]), cmp);
    int k = 1;
    for(int i = 0; i < s1-1;){
        while(strcmp(s[i].a, s[i+k].a) == 0){
            s[i].t += s[i+k].t;
            s[i+k].t = 0;
            k++;
        }
        i += k;
        k = 1;
    }
    for(int i = 0; i < s1; i++){
        if(s[i].t > 0) printf("%s %d\n", s[i].a, s[i].t);
    }
    fclose(in);
    return 0;
}

//if(isalpha(s[i])) s[i] = tolower(s[i]);

