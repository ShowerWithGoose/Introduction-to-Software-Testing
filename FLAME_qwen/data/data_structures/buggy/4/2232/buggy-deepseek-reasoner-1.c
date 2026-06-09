#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node{
    char word[100];
    int count;
}node;
node list[10000];
 char buffer[3000],tmp[100];
 int cmp_by_word(const void* p1,const void* p2)
{
    return strcmp(((node*)p1)->word,((node*)p2)->word);
}
int main(){
    
    FILE *filein= fopen("article.txt", "r"); 
    if(filein==NULL){
      printf("Fail!\n");
      return 1;
    } 
    int i,u,num=0,flag=0;
     while(fgets(buffer, sizeof(buffer), filein)!=NULL) {
        int j=0,sig=0;
        for(i =0; buffer[i] != '\0'&&buffer[i]!='\n'; i++){ // @@ The loop condition skips the newline character, preventing the last word in each line from being processed. This causes words at line endings to be omitted.
            
               if(buffer[i]>='A'&&buffer[i]<='Z'){
                   buffer[i]+=32;
               }
             if(buffer[i]>='a'&&buffer[i]<='z'){
                   tmp[j++]=buffer[i];
                   sig=1;
               }
            if(sig==1&&(buffer[i]<'A'||buffer[i]>'Z')&&(buffer[i]<'a'||buffer[i]>'z')){
                flag=0;
                for(u=0;u<num;u++){
                    if(strcmp(list[u].word,tmp)==0){
                        list[u].count++;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    strcpy(list[u].word,tmp);
                    list[u].count=1;
                    if(list[u].word[0]='b'&&list[u].word[1]='u'&&list[u].word[2]='y'){ // @@ Uses assignment '=' instead of comparison '=='. This sets word[0]='b', word[1]='u', word[2]='y' and results in a true condition (non‑zero), so every new word gets count set to 5, which is incorrect.
                        list[u].count=5;
                    }
                    num++;
                }
                j=0;
                memset(tmp,0,sizeof(tmp));
                sig=0;
            }
    }
}
    qsort(list,num,sizeof(list[0]),cmp_by_word);
    for(i=0;i<num;i++){
        printf("%s %d\n",list[i].word,list[i].count);
    }
    fclose(filein);
        return 0;
}