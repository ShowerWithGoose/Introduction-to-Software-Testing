#include<stdio.h>
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
    q = setdot(base->word); // @@ [Logic Error: This block attempts to process the last word of the file again or incorrectly handles the end-of-file state. The previous loop already processes words when a non-letter is encountered. If the file ends with a letter, the last word is never processed inside the loop because the else block is not triggered. However, this specific implementation tries to re-insert the head node's word, which is logically incorrect and leads to duplication or corruption. Furthermore, if the file ends with a newline, the last word was already processed. If it doesn't, `tmp` holds the last word but `j` is not reset/processed. This block uses `base->word` which is just the first word, not the last unprocessed word.]
    strcpy(tmp,base->word); // @@ [Logic Error: Copying the first word instead of the potentially unprocessed last word from `tmp`. Even if we intended to process the last word, we should use the `tmp` buffer if it contains data, not `base->word`. ]
    while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ [Runtime Error: `p` might be NULL or uninitialized if `base` was NULL (empty file), leading to a crash. Also, `p` retains its value from the previous loop, which is `base`. If the list is empty or has only one element, logic might fail. More critically, if the previous loop finished and `p` was reset to `base`, this loop traverses again. But the main issue is that this whole block is conceptually wrong for handling the "last word" scenario properly without checking if `tmp` actually contains an unprocessed word.]
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
    p = base->link; //边缘处理 // @@ [Logic Error: If the list has only one node, `base->link` is NULL, so `p` becomes NULL. The subsequent loop prints nothing or crashes if it tries to access `p->word`. The loop condition `i < count` assumes `count` matches the number of nodes to print, but `p` starts at the second node. The first node is skipped entirely in the output.]
    for(i = 0;i <count;i++){ // @@ [Logic Error: The loop runs `count` times, but `p` starts at `base->link` (the second node). This means the first node is never printed, and if `count` is the total number of nodes, the loop will try to access memory beyond the last node (segfault) or print garbage/NULL. It should start at `base` and iterate `count` times, or start at `base` and go until NULL.]
        printf("%s %d\n",p->word,p->num);
        p=p->link;
    }
    if (fclose(sourceFile) != 0) {
        printf("无法正确关闭文件\n");
        return -1;
    }// 关闭文件并进行错误处理
    return 0;
}