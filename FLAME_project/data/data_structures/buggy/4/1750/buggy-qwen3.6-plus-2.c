#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
struct statistic
    {
        char w[50] ;
        int time;
        struct statistic *next;
    };
typedef struct statistic sta;
typedef struct statistic *stap;
int main()
{
    char tem[50],tp;
    int m=0,g=0,same=0;
    stap head=NULL,p,q,t;
    FILE *in;
    in=fopen("article.txt","r");
    
    
    
    while ((fscanf(in,"%c",&tp))!=EOF)
    {
        while (tp<'A'||tp>'z'||(tp<'a'&&tp>'Z')) // @@ Logic error: The condition `tp > 'z'` is always false for standard ASCII letters if we assume valid input range, but more importantly, the loop condition logic for skipping non-alpha characters is flawed. It should check `!isalpha(tp)`. Also, `tp > 'z'` doesn't skip characters like `[`, `\`, `]`, etc., correctly if they appear. However, the bigger issue is that this loop consumes characters until it finds a letter or EOF. If the file ends with non-letters, `same=1` breaks the outer loop. This part is logically messy but might work for simple cases.
        {
           if(fscanf(in,"%c",&tp)==EOF)
           {
            same=1;
            break;
           }
        }
        if (same==1)
        {
            break;
        }
        
        
        while ((tp>='A'&&tp<='Z')||(tp>='a'&&tp<='z'))
        {
            if (tp>='A'&&tp<='Z')
            {
                tp=tp+'a'-'A';
            }
            tem[m]=tp;
            m++;
            fscanf(in,"%c",&tp);
        }
        
        if (head==NULL)
        {
            p=(struct statistic *)malloc(sizeof(struct statistic));
            strcpy(p->w,tem);
            p->time=1;
            head=p;
            q=head;
            g++;
        }
        else
        {
            for (int i = 0; i < g-1; i++) // @@ Logical Error: The loop runs `g-1` times, checking nodes from `head` up to the second-to-last node. It fails to check the last node in the list if the word matches there. Additionally, `q` is not reset to `head` before this loop starts in subsequent iterations (though it is reset at the end of the outer while loop, inside the `else` block `q` retains its value from previous operations or initialization). Wait, `q` is set to `head` at the very end of the `while` loop. But inside the `else` block, `q` is used. If `g=1`, `g-1=0`, loop doesn't run. Then it checks `q->w`. `q` is still `head` from initialization or previous reset. This seems okay for g=1. But for g>1, it misses the last element.
            {
                if(strcmp(q->w,tem)==0)
                {
                    q->time=1+q->time;
                    same=1;
                    break;
                }
                q=q->next;
            }
            if(strcmp(q->w,tem)==0&&same==0) // @@ Logical Error: If the match was found in the loop above, `same` is 1, so this is skipped. If not found in loop, it checks the current `q`. Since the loop stopped before the last element (if g>1), `q` points to the node *before* the last one? No, the loop increments `q`. If `g=2`, loop runs `i=0` once. Checks `head`. If no match, `q` becomes `head->next` (the last node). Then this line checks the last node. So actually, the loop `i < g-1` combined with this check outside *does* cover all nodes IF `q` traverses correctly. 
            // HOWEVER, there is a critical flaw: if the word is NOT found, `same` remains 0. The code proceeds to `if (same==0)`.
            // Inside `if (same==0)`, it does `p->next = ...`. `p` is currently pointing to the LAST node in the list (from the previous insertion). This correctly appends.
            // BUT, look at the traversal logic again. `q` starts at `head` (reset at end of previous iteration).
            // If `g=3`, loop runs for `i=0, 1`.
            // i=0: check head. q becomes head->next.
            // i=1: check 2nd node. q becomes 2nd->next (3rd node).
            // Loop ends.
            // Check `strcmp(q->w, tem)`. This checks the 3rd (last) node.
            // So the search logic actually covers all nodes.
            
            // The real error is likely in the sorting or output phase, or memory corruption.
            // Let's look closer at `p`. `p` is used to append new nodes. `p` always points to the last node added.
            // When `same==0`, we do `p->next = malloc...`, `p=p->next`. This maintains `p` as the tail.
            
            // Is there an error in `q` initialization?
            // At the start of `else`, `q` is whatever it was left as from the previous iteration's end (which was `head`).
            // So `q` starts at `head`. Correct.
            
            // Let's re-read the loop condition: `i < g-1`.
            // If `g=1`, loop doesn't run. `q` is `head`. Check `head`. Correct.
            // If `g=2`, loop runs `i=0`. Check `head`. `q` becomes `head->next`. Check `head->next`. Correct.
            
            // So the search logic seems technically correct for finding existing words.
            
            // What about the variable `same`? It is reset to 0 at the end of the while loop.
            
            // Let's look at the sorting algorithm.
                {
                    q->time=1+q->time;
                    same=1;
                }
            if (same==0)
            {
                p->next=(struct statistic *)malloc(sizeof(struct statistic));
                p=p->next;
                p->time=1;
                strcpy(p->w,tem);
                g++;
            }
        }
        q=head;
        m=0;
        memset(tem,'\0',sizeof(tem));
        same=0;
    }
    
    
    for (int i = 0; i < g; i++)
    {
        p=head;
        q=p;    
        t=q;
        p=p->next;
        for (int j = 0; j < g-i; j++) // @@ Runtime Error / Logic Error: Bubble sort implementation is flawed.
        // 1. Inner loop bound `j < g-i` is incorrect for bubble sort which usually goes up to `n-i-1`.
        // 2. Accessing `p->next` and `q->next` without checking for NULL can cause segfaults if `p` or `q` become NULL.
        // Specifically, `p` is initialized to `head->next`. If `g=1`, `p` is NULL. The inner loop runs `j < 1`.
        // Inside, `strcmp(q->w, p->w)` dereferences `p` which is NULL -> Segfault.
        {
            if (strcmp(q->w,p->w)>0)
            {
                if (strcmp(t->w,q->w)==0)
                {
                    q=head;
                    q->next=p->next;
                    p->next=head;
                    head=p;
                    p=q->next;
                    t=head;
                }
                else
                {
                    t->next=p;
                    q->next=p->next;
                    p->next=q;
                    
                    t=p;
                    p=q->next;
                }
            }
            else
            {
                t=q;
                q=p;
                p=p->next;
            }
        }
    }
    p=head;
    for (int i = 0; i < g; i++)
    {
        printf("%s %d\n",p->w,p->time);
        p=p->next;
    }
    
    
return 0;
}