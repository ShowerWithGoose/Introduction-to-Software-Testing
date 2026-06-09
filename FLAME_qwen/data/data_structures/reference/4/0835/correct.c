//
//  main.c
//  DS3-5
//
//  Created by  on 2022/3/27.
//
//  链表 结构体 文件读取 词频统计 字典序排序 大小写转换
//
//
//问题：
//1.每一次用q都要重新开，要不改变的是本身
//2.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word{
    char s[20];  //单词
    int n;   //次数
    struct word *next;  //指针
};

int main() {
    
    char c;
    int i=0,j=0,m=0;
    int num=0;
    
    struct word *first,*p,*q,*a,*b;
    first=(struct word*)malloc(sizeof(struct word));
    p=(struct word*)malloc(sizeof(struct word));
    q=(struct word*)malloc(sizeof(struct word));
    a=(struct word*)malloc(sizeof(struct word));
    b=(struct word*)malloc(sizeof(struct word));
    
    FILE *in;
    in=fopen("article.txt","r");
    if(NULL == in){
        printf("Failed to open the file !\n");
        exit(0);
    }
    while((c=fgetc(in))!=EOF){
        if(num==0){    //头节点
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){   //字母中的小写情况
                if(c>='a'&&c<='z'){
                    first->s[i]=c;
                    i++;
                }
                else if(c>='A'&&c<='Z'){    //字母中的大写情况
                    c=c+'a'-'A';
                    first->s[i]=c;
                    i++;
                }
            }
            else{    //非字母情况
                if(first->s[0]!='\0'){ //判断
                    first->n=1;
                    first->next=NULL;
                   // first->next=p; //连上下一个节点p
                    num++;
                    i=0;
                }
            }
        }
        else{   //非头节点情况
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
                if(c>='a'&&c<='z'){
                    q->s[i]=c;   //先用q存下来，进行判断后在挂在链表上
                    i++;
                }
                else if(c>='A'&&c<='Z'){
                    c=c+'a'-'A';
                    q->s[i]=c;
                    i++;
                }
            }
            else{    //此时q的字符串已经输完，开始进行排序、插入、编号
                if(q->s[0]!='\0'){
                    a=first;
                    for(j=0;j<num;j++){     //找相同字符串
                        if(strcmp(a->s,q->s)==0){  //找到了
                            a->n=(a->n)+1;
                            q=(struct word*)malloc(sizeof(struct word));//
                            break;
                        }
                        else if(strcmp(a->s,q->s)<0){
                            if(a->next!=NULL){  //首先判断下一个是否为空
                                b=a->next;  //如果不为空，判断q->s和下一个节点的字母
                                if(strcmp(q->s,b->s)<0){//下一个小，直接加在当前的后面
                                    q->next=a->next;
                                    a->next=q;
                                    q->n=1;
                                    num++;
                                    q=(struct word*)malloc(sizeof(struct word));//
                                    break;
                                }
                            else{  //下一个也大或相等，直接跳出，重新进下一次循环）
                                    a=a->next;
                                    continue;
                                }
                            }
                            //三种情况（下一个小，直接加在当前的后面，下一个也大或相等，直接跳出，重新进下一次循环）
                                
                            else{//如果为空，就直接接在当前最后一个节点的后面
                                q->next=a->next;
                                a->next=q;
                                q->n=1;
                                num++;
                                q=(struct word*)malloc(sizeof(struct word));//
                                break;
                            }
                        }
                        else if(strcmp(a->s,q->s)>0){
                            //可能要动头节点first
                            q->next=a;
                            a=q; //可能会有问题
                            first=a;
                            q->n=1;
                            num++;
                            q=(struct word*)malloc(sizeof(struct word));//
                            break;
                       
                        }
                    }
                }
                i=0;
            }
        }
        //读入，依次开结构体存进来
        //检查有无重复
        //统计出现数目
        //排序
    }
    
    p=first;
    for(m=0;m<num;m++){
        printf("%s %d",p->s,p->n);
        if(m<num-1){
            printf("\n");
        }
        p=p->next;
    }
    fclose(in);
          
    return 0;
}

//  包含大写字母的单词应将大写字母转换为小写字母后统计
//  将单词统计结果按单词字典序输出到屏幕上
//  只读取文件，没有写入
//  链表必须存一个排一个


//写了老半天的代码发现自己看错题了
//锻炼身体QAQ
//if(strcmp(a->s,q->s)==0){  //找到了
//    if((j+1)<num){    //如果链表当前节点后还有其他节点，继续往后找
//        b=a->next;   //（当前节点已经相等时下一个节点还有两种情况
//        if(strcmp(a->s,b->s)==0){  //下一个节点和当前节点相等
//            continue;
//        }
//        else{   //其他：下一个节点比当前节点小
//            q->next=a->next;
//            a->next=q;  //连在当前节点后
//            q->n=(a->n)+1;  //置n
//             break;
//        }
//    }
//    else{
//        q->next=a->next;
//        a->next=q;  //连在当前节点后
//        q->n=(a->n)+1;  //置n
//         break;
//        //直接接在当前节点的后面
//    }
//}
//else if(strcmp(a->s,q->s)>0){
//    if((j+1)<num){  //首先判断下一个是否为空
//        b=a->next;  //如果不为空，判断q->s和下一个节点的字母
//        if(strcmp(q->s,b->s)>0){//下一个小，直接加在当前的后面
//            q->next=a->next;
//            a->next=q;
//            q->n=1;
//        }
//        else{  //下一个也大或相等，直接跳出，重新进下一次循环）
//            continue;
//        }
//    }
//    //三种情况（下一个小，直接加在当前的后面，下一个也大或相等，直接跳出，重新进下一次循环）
//
//    else{//如果为空，就直接接在当前最后一个节点的后面
//        q->next=a->next;
//        a->next=q;
//        q->n=1;
//    }
//}
//else if(strcmp(first->s,q->s)<0){
//    //可能要动头节点first
//    q->next=first;
//    first=q; //可能会有问题
//    q->n=1;
//}

