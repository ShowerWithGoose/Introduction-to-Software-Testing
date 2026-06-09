#include<stdio.h> // @@ Missing #include <stdlib.h> and <string.h>, causing compilation errors for malloc, free, strcpy, and strcmp.
struct dic{
    char word[20];
    int num;
    struct dic *link;
};
int count = 1;
int isletter(char c)
{
    if(c >= 'a'&&c<='z')return 1;
    if(c>='A'&&c<='Z')return 2;
    return 0;
}
void lower(char s[])
{
    int i;
    for(i = 0;s[i]!='\0';i++){
        if(s[i]>='A'&&s[i]<='Z')s[i] = s[i]-'A'+'a';
    }
}
void keepletter(char s[])
{
    int i,j;
    for(i = 0,j = 0;s[i]!='\0';i++){
        if(isletter(s[i]) == 2)s[j++] = s[i] -'A'+'a';
        else if(isletter(s[i]) == 1)s[j++] = s[i];
    }
    s[j] = '\0';
}
struct dic *setdot(char s[])//建立新的链节
{
    struct dic* tmp = (struct dic*)malloc(sizeof(struct dic));
    strcpy(tmp->word,s);
    tmp->num = 1;
    tmp->link = NULL;
    return tmp;
}
void deletdot(struct dic *p)//删除p之后的节点
{
    struct dic *q = p->link;
    p->link = p->link->link;
    free(q);
    count--;
}

int main()
{
    int i,j;
    FILE *sourceFile; // 定义指向源文件的FILE对象
    char sourceFileName[] = "article.txt"; // 源文件名称
    int bufferSize = 1024; // 设置缓冲区大小为1KB
    char buffer[bufferSize]; // 创建缓冲区// 打开源文件并进行错误处理
    if ((sourceFile = fopen(sourceFileName, "rb")) == NULL) {
        printf("无法打开源文件\n");
        return -1;
    }// 创建或者清空目标文件（若已存在）并进行错误处理
    char tmp[20];
    struct dic *base = NULL,*p,*q;
    while (fgets(buffer, sizeof(buffer), sourceFile)) {
        lower(buffer);
        for(i = 0,j = 0;buffer[i]!='\0';i++){
            if(isletter(buffer[i])){
                tmp[j++] = buffer[i];
            }
            else{
                tmp[j] = '\0';
                if(j != 0){
                    q = setdot(tmp);
                    if(base == NULL){
                        base = q;
                        p = base;
                    }
                    else{
                        while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){
                            p = p->link;
                        }
                        if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
                            p->link->num++;
                            free(q);
                        }
                        else{
                            q->link = p->link;
                            p->link = q;
                            count++;
                        }
                        p = base;
                    }
                j=0;
                }
            }
        }
    }                //创建列表
    q = setdot(base->word); // @@ Logical error: Redundant and incorrect block that crashes if base is NULL (empty file) and incorrectly duplicates the first word.
    strcpy(tmp,base->word); // @@ Part of the erroneous block above, leads to undefined behavior.
    while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ Logical error: p is not reset to base before traversal, leading to incorrect list traversal or crash.
        p = p->link;
    }
    if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
        p->link->num++;
        free(q);
    }
    else{
        q->link = p->link;
        p->link = q;
        count++;
    }
    p = base->link; //边缘处理 // @@ Logical error: Skips the head node during output. Should be p = base; to print all words correctly.
    for(i = 0;i <count;i++){ // @@ Logical error: count is incorrectly initialized to 1 and not accurately maintained, causing wrong output count or segmentation fault.
        printf("%s %d\n",p->word,p->num);
        p=p->link;
    }
    if (fclose(sourceFile) != 0) {
        printf("无法正确关闭文件\n");
        return -1;
    }// 关闭文件并进行错误处理
    return 0;
}