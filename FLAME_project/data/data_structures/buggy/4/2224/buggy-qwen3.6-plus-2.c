#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct WORD{
    char s[30];
    int n;
}word,*pword;
int aw(char c){
    if(c>=65&&c<=90){
        return 1;
    }else{
        if(c>=97&&c<=122){
            return 1;
        }else{
            return 0;
        }
    }
}
char bw(char c){
    if(c>=65&&c<=90){
        c=c+32;
    }
    return c;
}
int cmp(const void *p1,const void *p2){
    pword d1=(pword)p1;
    pword d2=(pword)p2;
    return strcmp(d1->s,d2->s);
}
int main(){
    word b[30000]={0};
    FILE *in;
    in=fopen("article.txt","r"); // @@ The program should read from the file pointer 'in', but the loop below reads from 'stdin'. Also, there is no check if fopen succeeded.
    char c=0;
    int n_i=0,j=0,d=1;
    while((c=fgetc(stdin))!=EOF){ // @@ Error: Reading from stdin instead of the file pointer 'in'. Should be fgetc(in).
        if(aw(c)>0){
            c=bw(c);
            b[n_i].s[j]=c;
            j++;
            d=0;
        }else{
            if(d==0){
                    b[n_i].n=1;
                n_i++;
            }
            d++; // @@ Logic error: 'd' is used as a flag (0 or 1) to indicate if we are inside a word. Incrementing it makes it >1, which is fine for the check d==0, but semantically confusing. However, the critical bug is below.
                j=0;
            }
    }
    // @@ Missing handling for the last word if the file does not end with a non-alpha character. The loop only adds a word when a non-alpha char is encountered after a word. If EOF is reached immediately after a word, the last word is lost.
    qsort(b,n_i,sizeof(word),cmp);
    int k=0;
    for(k=0;k<n_i;k++){
        if(strcmp(b[k].s,b[k+1].s)==0){ // @@ Potential out-of-bounds access when k == n_i - 1, accessing b[n_i].s which is uninitialized/zeroed but technically out of logical bounds. Though b is zero-initialized so strcmp might work safely against empty string, it's risky. More importantly, if the last element is part of a group, it won't be marked correctly if the next one doesn't exist.
            b[k+1].n=b[k+1].n+b[k].n;
            strcpy(b[k].s,"+");
        }
    }
    int h=0;
    for(h=0;h<n_i;h++){
        if(strcmp("+",b[h].s)!=0){
        printf("%s %d\n",b[h].s,b[h].n);    
        }
    }
    fclose(in);
    return 0;
}