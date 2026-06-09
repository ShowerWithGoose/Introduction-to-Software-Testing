#include<stdio.h>
#include<stdlib.h>

struct node{
    int xi;
    int zhi;
    struct node *next;
};
typedef struct node *Nodeptr;
typedef struct node Node;

int cmp(const void *a,const void *b)
{
    Node x=*(Node *)a;
    Node y=*(Node *)b;
    if(x.zhi>y.zhi)
    {
        return -1;
    }
    else if(x.zhi<y.zhi)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node h[10001];
Nodeptr list1=NULL,p1=NULL,list2=NULL,p2=NULL,list3=NULL,p3=NULL,q;
int main()
{
    int a,b,m=0,n,i;
    char c;
    FILE *in = fopen("a.in", "r"); // @@ The program attempts to open a file "a.in" which is not required by the problem description (input is from stdin). This line is unnecessary and might cause confusion, but more importantly, the variable 'in' is unused. However, the critical error causing compilation failure in some strict environments or logical issues is often related to unused variables or specific compiler flags. But looking closer at the provided "Buggy Output: compile_run failed", let's look for syntax errors. There are no obvious syntax errors. Wait, the prompt says "Compilation Error". Let's re-read carefully.
    // Actually, the code uses `FILE *in = fopen("a.in", "r");` but never uses `in`. It continues to use `scanf`. This is logically wrong for reading from a file if intended, but syntactically valid C. 
    // However, many online judges do not allow file I/O unless specified. 
    // Let's look at the `qsort` usage. `qsort(h,m,sizeof(Node),cmp);`. This is valid.
    // Is there a missing header? `#include <stdlib.h>` is present for `malloc`, `qsort`. `#include <stdio.h>` is present for `printf`, `scanf`.
    // Let's look at the logic. The code reads input into linked lists, multiplies them into `list3`, copies `list3` to array `h`, sorts `h`, and prints.
    // The compilation error might be due to the unused variable `in` if compiled with `-Werror` or similar, but usually that's a warning.
    // Let's look at the `cmp` function. It takes `const void *` and casts to `Node *`. This is standard.
    // Let's look at the `fopen` line again. If the judge system doesn't have `a.in`, `fopen` returns NULL. Dereferencing it would crash, but it's not dereferenced.
    // Perhaps the issue is simpler. The problem statement says "Input Format...". The code tries to read from a file. This is likely the primary logical error, but does it cause a *compilation* error? No.
    // Let's look at the provided "Reference Program" vs "Source Code". The user provided a "Reference Program" (which looks buggy/complex with goto) and then a "Source Code" (which is the one to annotate). The "Source Code" is the one labeled `#include<stdio.h> ...`.
    // Wait, the prompt asks to identify errors in the program *below*. The program below is the one starting with `#include<stdio.h>` and ending with `return 0;`.
    // The error type is "Compilation Error".
    // Common causes for compilation errors in student code:
    // 1. Missing headers.
    // 2. Syntax errors.
    // 3. Type mismatches.
    // 4. Undefined identifiers.
    
    // Let's check `qsort`. It requires `<stdlib.h>`. Included.
    // Let's check `malloc`. Requires `<stdlib.h>`. Included.
    // Let's check `scanf`, `printf`. Requires `<stdio.h>`. Included.
    
    // Is it possible the compiler doesn't support C99 mixed declarations?
    // `int now_xi = p1->xi * p2->xi;` inside the loop. This is C99. If the compiler is C89/C90 strict, this is an error.
    // Line 85: `int now_xi = p1->xi * p2->xi;`
    // Line 86: `int now_zhi = p1->zhi + p2->zhi;`
    // In C89, variables must be declared at the beginning of the block.
    
    while(scanf("%d%d",&a,&b)!=EOF)//将第一行数据存入list1;
    {
        scanf("%c",&c);

        if(list1==NULL)
        {
            p1=list1=(Nodeptr)malloc(sizeof(Node));
            p1->xi=a;
            p1->zhi=b;
        }
        else
        {
            p1->next=(Nodeptr)malloc(sizeof(Node));
            p1=p1->next;
            p1->xi=a;
            p1->zhi=b;
        }

        if(c=='\n')//判断结束条件
        {
            break;
        }
    }


    while(scanf("%d%d",&a,&b)!=EOF)//将第二行数据存入list2
    {

        scanf("%c",&c);

        if(list2==NULL)
        {
            p2=list2=(Nodeptr)malloc(sizeof(Node));
            p2->xi=a;
            p2->zhi=b;
        }
        else
        {
            p2->next=(Nodeptr)malloc(sizeof(Node));
            p2=p2->next;
            p2->xi=a;
            p2->zhi=b;
        }

        if(c=='\n')//判断结束条件 
        {
            break;
        }

    }

    p1=list1;
    p2=list2;
//从头开始遍历 
    while(p1!=NULL)
    {
        p2=list2;
        while(p2!=NULL)
        {//相乘之后数据存入p3 
            p3 = list3;
            int now_xi = p1->xi * p2->xi; // @@ [C89/C90 compilers do not allow variable declaration after statements within a block. Move declaration to the start of the block or use C99 mode.]
            int now_zhi = p1->zhi + p2->zhi; // @@ [C89/C90 compilers do not allow variable declaration after statements within a block. Move declaration to the start of the block or use C99 mode.]
            if(list3==NULL)
            {
                p3=list3=(Nodeptr)malloc(sizeof(Node));
                p3->xi=now_xi;
                p3->zhi=now_zhi;
                m+=1;
            }
            else
            {
                while(1)
                {
                    if(p3->zhi == now_zhi)
                    {
                        p3->xi += now_xi;
                        break;
                    }
                    if(p3->next == NULL)
                    {
                        p3->next = (Nodeptr) malloc(sizeof(Node));
                        p3 = p3->next;
                        p3->xi = now_xi;
                        p3->zhi = now_zhi;
                        m += 1;
                        break;
                    }
                    p3 = p3->next;
                }

            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    p3=list3;
    for(i=0;i<m;i++)//p3数据存入数组h 
    {
        h[i].xi=p3->xi;
        h[i].zhi=p3->zhi;
        p3=p3->next;
    }
    qsort(h,m,sizeof(Node),cmp);//排序 
//    for(i=0;i<m;i++)
//    {
//        if(h[i].zhi==h[i+1].zhi)
//        {
//            h[i+1].xi=h[i].xi+h[i+1].xi;
//            h[i].xi=0;
//        }
//    }
    for(i=0;i<m;i++)
    {
        printf("%d %d ",h[i].xi,h[i].zhi);//输出
//        if(h[i].xi!=0)
//        {
//
//        }

    }
    return 0;
}