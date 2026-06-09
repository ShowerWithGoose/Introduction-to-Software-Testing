#include<stdio.h> // @@ missing #include <stdlib.h> and <string.h> for malloc, free, strcpy, strcmp
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
    struct dic* tmp = (struct dic*)malloc(sizeof(struct dic)); // @@ implicit declaration of malloc - missing stdlib.h
    strcpy(tmp->word,s); // @@ implicit declaration of strcpy - missing string.h
    tmp->num = 1;
    tmp->link = NULL;
    return tmp;
}
void deletdot(struct dic *p)//删除p之后的节点
{
    struct dic *q = p->link;
    p->link = p->link->link;
    free(q); // @@ implicit declaration of free - missing stdlib.h
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
                        while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ implicit declaration of strcmp - missing string.h
                            p = p->link;
                        }
                        if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
                            p->link->num++;
                            free(q); // @@ implicit declaration of free
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
    q = setdot(base->word); // @@ logical error: redundant insertion of the first word, corrupts the list
    strcpy(tmp,base->word); // @@ redundant
    while(p->link != NULL&&strcmp(p->link->word,tmp) < 0){ // @@ redundant and uses p which may have been changed
        p = p->link;
    }
    if(p->link!=NULL&&strcmp(p->link->word,tmp)==0){
        p->link->num++;
        free(q);
    }
    else{
        q->link = p->link;
        p->link = q;
        count++; // @@ incorrect count increment
    }
    p = base->link; // @@ error: should be p = base; this skips the first word in output
    for(i = 0;i <count;i++){
        printf("%s %d\n",p->word,p->num);
        p=p->link;
    }
    if (fclose(sourceFile) != 0) {
        printf("无法正确关闭文件\n");
        return -1;
    }// 关闭文件并进行错误处理
    return 0;
}