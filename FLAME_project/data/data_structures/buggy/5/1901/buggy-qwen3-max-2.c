#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct y{
    int a;
    int b;
};
struct y yi[2000];
struct y er[2000];
struct y san[2000];
int i=0;
int cmp(const void*aaa,const void*bbb){
    struct y*pa=(struct y*)aaa;
    struct y*pb=(struct y*)bbb;
    if(pa->b<pb->b){
        return 1;
    }else{
        return -1;
    }
}
int main()
{
    char ai[1500];
    char bi[1500];
    char *aa;
    char *bb;
    //读入两行数据 
    aa=gets(ai); // @@ [Using `gets()` is unsafe and can cause buffer overflow; more critically, `gets()` was removed in C11 and may not be available, leading to runtime error or undefined behavior. Additionally, if input line is empty or too long, it causes memory corruption.]
    bb=gets(bi); // @@ [Same issue as above: `gets()` is dangerous and likely causes runtime error on modern systems or with large inputs like exponent 1000000000 which may result in long string representation.]
    int n;
    //将数据存入结构体 
    while(sscanf(aa,"%d %d%n",&yi[i].a,&yi[i].b,&n)!=EOF){ // @@ [If `aa` is NULL (e.g., if `gets` fails or returns NULL on EOF), this leads to dereferencing NULL pointer, causing runtime error. Also, `sscanf` returns number of successfully matched items, not EOF; condition should check for ==2, not !=EOF. This may cause infinite loop or reading garbage.]
        i++;
        aa+=n;
    }
    int j=0;
    while(sscanf(bb,"%d %d%n",&er[j].a,&er[j].b,&n)!=EOF){ // @@ [Same issues as above: incorrect loop condition and potential NULL dereference if `bb` is NULL.]
        j++;
        bb+=n;
    }
    //多项式相乘 
    int w=0;
    for(int x=0;x!=i;x++){
        for(int u=0;u!=j;u++){
            int o=yi[x].b+er[u].b;
            if(w==0){       /*第一次不用判断直接存入*/ 
                san[w].a=yi[x].a*er[u].a;
                san[w].b=o;
                w++;
                continue;
            }
            int pr=0;
            for(int r=0;r<w;r++){  /*之后遍历数组看是否已有该指数项*/ 
                if(san[r].b==o){
                    san[r].a+=yi[x].a*er[u].a;
                    pr=1;
                    break;
                }
            }                       
            if(pr==0){             /*若这是一个新指数项，则pr=0,新开一个结构体*/ 
                    san[w].a=yi[x].a*er[u].a;
                    san[w].b=o;
                    w++;
                }
        }
    }
    //排序输出 
    qsort(san,w,sizeof(struct y),cmp);
    for(int op=0;op<w;op++){
        printf("%d %d ",san[op].a,san[op].b);
    }
    return 0;
}