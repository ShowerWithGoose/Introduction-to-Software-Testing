#include<stdio.h>
#include<string.h>
#define max_word_len 20
#define max_word_num 100
struct word{
    char ch[max_word_len];
    int num;
};
int cmp(const void*a, const void*b)
{
    return strcmp((char*)a,(char*)b); // @@ [Comparator incorrect for sorting struct word; should dereference to struct and compare ch fields.]
}
int main(){
    FILE*in=fopen("article.txt","r");
    int i,j,k;
    int flag;
    char word_tem[max_word_len];
    struct word library[max_word_num];
    k=0;
    while(fscanf(in,"%c",&word_tem[0])!=EOF){
        if((word_tem[0]>='A'&&word_tem[0]<='Z')||(word_tem[0]>='a'&&word_tem[0]<='z')){
            flag=0;
            if(word_tem[0]>='A'&&word_tem[0]<='Z'){
                word_tem[0]=word_tem[0]+'a'-'A';
            }
            i=0;
            for(;(word_tem[i]>='A'&&word_tem[i]<='Z')||(word_tem[i]>='a'&&word_tem[i]<='z');){
                i++;
                fscanf(in,"%c",&word_tem[i]); // @@ [Reads next character without checking if it is a letter; may store non-letter into buffer, causing word to include punctuation.]
            }
            word_tem[i+1]='\0'; // @@ [Null terminator placed after the last read character (which might be a non-letter). Should overwrite the non-letter with null terminator.]
            for(j=0;j<=i;j++){
                if(word_tem[j]>='A'&&word_tem[j]<='Z'){
                    word_tem[j]=word_tem[j]+'a'-'A';
                }
            }
            for(j=0;j<k;j++){
                if(strcmp(word_tem,library[j].ch)==0){
                    flag=1;
                    library[j].num++;
                }
            }
            if(flag==0){
                strcpy(library[k].ch,word_tem);
                library[k].num=1;
                k++;
            }
        }
    }
    qsort(library[0].ch,k,sizeof(library[0]),cmp); // @@ [First argument should be pointer to array of struct, not a char array. Also missing #include <stdlib.h> for qsort. Comparator is also incorrect.]
    for(i=0;i<k;i++){
        printf("%s %d\n",library[i].ch,library[i].num);
    }
    fclose(in);
    return 0;
}