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
        for(i =0; buffer[i] != '\0'&&buffer[i]!='\n'; i++){
            
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
                    strcpy(list[u].word,tmp); // @@ [Error: After the for loop, u equals num, but if the loop completed without break, u is num, which is the correct index for the new word. However, if the loop broke early (flag==1), u is the index of the found word, but this branch is only entered when flag==0, so u should be num. This is correct, but the following line uses list[u].word[0]='b' which is assignment, not comparison. Also, the special case for "buy" is not part of the problem specification.]
                    list[u].count=1;
                    if(list[u].word[0]='b'&&list[u].word[1]='u'&&list[u].word[2]='y'){ // @@ [Error: Using assignment '=' instead of comparison '=='. This sets the characters to 'b', 'u', 'y' and always evaluates to true, causing every new word to have its count set to 5. Also, this special case for "buy" is not required by the problem.]
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