#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define N 60
void belower(char*,int);
int cmp(const void*,const void*);
int cmp2(const void*,const void*);
int new_strcmp(char*,int,char*,int);
void clear(char*,int);//将某一长度的字符串中非字母元素转换成空格

typedef struct{
    char one[100];
    int sum;
} dword;

int main(){
    FILE *in = fopen("article.txt","r");
    int i = 0,lock = 0,lentem = 0,j,cn = 0,k,temint = 0;
    dword words[10000];
    char *all[10000],tem[10000] = {0},tem2[10000] = {0},*t = NULL;
    while(fgets(tem,10000,in) != NULL){
        //printf("!\n");
        temint = 0;
        lentem = strlen(tem);
        clear(tem,lentem);
        for(j = 0;j < lentem;j++){
            if(isalpha(tem[j]) != 0) break;
        }
        if(j == lentem) continue;
        t = tem;
        while(1){
            j = 0;
            all[i] = (char*)malloc(N);
            for(;(t-tem) < lentem && isalpha(*t) == 0;t++){
                
            }
            for(;(t-tem) < lentem && isalpha(*t) != 0;t++){
                *(all[i]+(j++)) = *t;
            }
            if(j != 0) {
                *(all[i]+j) = '\0';
                i++;
            }else free(all[i]);
            if((t-tem) >= lentem) break;
            
            /*sscanf(tem + temint,"%s",all[i]);
            printf("all[%d]:",i); puts(tem);
            if(0 == strlen(all[i])) break;
            while(temint++){
                if(lock==0 && isalpha(*(tem+temint)) != 0){
                    lock = 1;
                }
                if(lock == 1 && *(tem+temint) == ' '){
                    lock = 2;
                    break;
                }
            }sscanf指针偏移
            lock = 0;*/
        }
        
    }
    all[i] = NULL;
    /*all[0] = (char*)malloc(N);
    while((fscanf(in,"%s",all[i++])) != EOF){
        clear(all[i-1],strlen(all[i-1]));
        if(0 == strlen(all[i-1])){
            free(all[i-1]);
            i--;
        }
        all[i] = (char*)malloc(N);
    }
    i -= 1;
    all[i] = NULL;*/
    for(j = 0;j < i;j++){
        belower(all[j],strlen(all[j]));
    }
    qsort(all,i,sizeof(char*),cmp);
    for(j = 0;j < i;j++){
        for(k = j;all[k] != NULL && new_strcmp(all[j],strlen(all[j]),all[k],strlen(all[k])) == 1;k++){
        
        }
        strcpy(words[cn].one , all[j]);
        //belower(words[cn].one , strlen(words[cn].one));
        words[cn++].sum = k-j;
        j = k-1;
    }
    qsort(words,cn,sizeof(dword),cmp2);

    for(i = 0;i < cn;i++){
        printf("%s %d\n",words[i].one,words[i].sum);
    }
    fclose(in);
    return 0;
}


int cmp(const void *p,const void *q){
    char **m = (char**)p,**n = (char **)q;
    return (strcmp(*m,*n) > 0)?1:-1;
}

void belower(char *str,int len){
    int i;
    for(i = 0;i < len;i++){
        *(str+i) = islower(*(str+i))?(*(str+i)):(*(str+i)+'a'-'A');
    }
    return ;
}

int new_strcmp(char *a,int lena,char *b,int lenb){
    if(lena != lenb) return 0;
    int i;
    for(i = 0;i < lena;i++){
        if(!((a[i] == b[i])||(fabs(a[i]-b[i]) == 'a'- 'A')))
        return 0;
    }
    return 1;
}

int cmp2(const void *p,const void *q){
    dword *m = (dword*)p,*n = (dword*)q;
    return (strcmp(m->one,n->one) > 0)?1:-1;
}

void clear(char *str,int len){
    int i = 0;
    for(i = 0;i < len;i++){
        if(0 == isalpha(str[i])){
            str[i] = ' ';
        }
    }
    str[i] = '\0';
    return ;
}
