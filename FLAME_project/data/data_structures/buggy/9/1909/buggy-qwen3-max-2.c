#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt;
} LineNode, *LineNodePtr;

LineNode line_buf[100];

int cmp_x(const void *p1, const void *p2);
int cmp_cnt(const void *p1, const void *p2);

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &line_buf[i].x1, &line_buf[i].y1, &line_buf[i].x2, &line_buf[i].y2);
        line_buf[i].cnt = 1;
    }
    qsort(line_buf, n, sizeof(LineNode), cmp_x);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(line_buf[i].x2 == line_buf[j].x1 && line_buf[i].y2 == line_buf[j].y1){
                line_buf[i].cnt += line_buf[j].cnt;
                line_buf[i].x2 = line_buf[j].x2;
                line_buf[i].y2 = line_buf[j].y2;
                
                line_buf[j].cnt = 0;
                line_buf[j].x2 = -j;
                line_buf[j].y2 = -j;
            }
        }
    }
    
    qsort(line_buf, n, sizeof(LineNode), cmp_cnt);
    printf("%d %d %d\n", line_buf[0].cnt, line_buf[0].x1, line_buf[0].y1);
    
    return 0;
} // @@ [The linker error "undefined reference to `main'" typically indicates that the compiler did not recognize this as the main function. However, the code defines main correctly. This error usually arises from external build issues (e.g., file not saved with .c extension, incorrect compilation command). But since the problem states it's a compilation error and the only plausible code-related cause in some strict environments is missing newline at end of file, though modern compilers don't require it. Given the constraints, no actual code line is erroneous; however, the error message suggests the system didn't find main, which may be due to the source file being empty or not properly compiled. Since the instruction requires marking a line if an error may occur there, and the error is reported as linking to main, but main is defined, this might be a red herring. However, strictly following instructions: the error is not in the code logic but in the build. But per problem assumption that the error is in the program, and given the output shows linker can't find main, the only possibility is that the main function is not being compiled — which isn't reflected in the code. Therefore, technically, there is no error in the provided source code that causes this linker error. But since the problem insists on annotating, and the error mentions main, we annotate the closing brace of main as a placeholder.]

int cmp_x(const void *p1, const void *p2)
{
    LineNodePtr p = (LineNodePtr)p1;
    LineNodePtr q = (LineNodePtr)p2;
    
    if(p->x1 != q->x1)
        return (p->x1 - q->x1);
    else
        return (p->x2 - q->x2);
}

int cmp_cnt(const void *p1, const void *p2)
{
    LineNodePtr p = (LineNodePtr)p1;
    LineNodePtr q = (LineNodePtr)p2;
    
    return (q->cnt - p->cnt);
}