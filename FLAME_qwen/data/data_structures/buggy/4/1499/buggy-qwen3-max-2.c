#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char word[30];
    int times;
}set;

typedef struct node{
    set term;
    struct node *link;
}lnode,*linklist;

int compare(const void * a, const void * b){
    set *p1=(set*)a;
    set *p2=(set*)b;
    return strcmp(p1->word,p2->word);
}

int main(void){
    char tempstore[30]={'\0'},c='\0';
    FILE *in;
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(in) leads to undefined behavior. However, this is a runtime issue, not a compilation error. The actual compilation error stems from missing #include <stdlib.h> required for malloc().]
    linklist list,p=NULL,add=NULL,cycle;
    list=(linklist)malloc(sizeof(lnode)); // @@ [Missing #include <stdlib.h> causes 'malloc' to be undeclared, leading to a compilation error.]
    p=list;
    int count=0,length=0;
    while((c=fgetc(in))!=EOF){
        if(65<=(int)c&&(int)c<=90){//大写转小写
            int asc=(int)c;
            asc=asc+32;
            c=(char)asc;
        }
        if(97<=(int)c&&(int)c<=122){//遇到小写字母就开始记录单词
            tempstore[count]=c;
            count++;
        }else//如果遇到了不是小写字母的东西说明这个单词结束了
            if(count!=0){
                int flag=2;
                cycle=list->link;//cycle遍历查这个单词之前有没有出现过
                for(int i=0;i<length;i++){//遍历的过程，length存已经出现的不同单词的个数
                    flag=strcmp(tempstore,cycle->term.word);
                    if(flag==0){
                        break;
                    }else{
                        cycle=cycle->link;
                    }
                }
                if(flag!=0){//flag!=0代表链表里没有和这个单词相同的东西，所以用新节点挂上去
                    add=(linklist)malloc(sizeof(lnode)); // @@ [Missing #include <stdlib.h> causes 'malloc' to be undeclared, leading to a compilation error.]
                    for(int i=0;i<30;i++){
                        add->term.word[i]='\0';
                    }
                    memmove(add->term.word,tempstore,strlen(tempstore));
                    add->term.times=1;
                    add->link=NULL;
                    p->link=add;
                    p=add;
                    length++;//已有不同单词个数+1
                }else if(flag==0){//频数+1
                    cycle->term.times++;
                }
            }
            for(int i=0;i<count;i++){
                tempstore[i]='\0';
            }
            count=0;//一个单词处理完毕，count归零重新开始取单词
        }
    }
    //allright
    p=list->link;//把链表里的东西copy到结构体数组里，方便qsort
    set cpy[length];
    for(int i=0;i<length;i++){
        for(int j=0;j<30;j++){
            cpy[i].word[j]='\0';
        }
    }
    for(int i=0;i<length;i++){
        memmove(cpy[i].word,p->term.word,strlen(p->term.word));
        cpy[i].times=p->term.times;
        p=p->link;
    }

    qsort(cpy,length,sizeof(set),compare);

    p=list->link;//输出
    for(int i=0;i<length;i++){
        printf("%s %d\n",cpy[i].word,cpy[i].times);
    }
    fclose(in);
}