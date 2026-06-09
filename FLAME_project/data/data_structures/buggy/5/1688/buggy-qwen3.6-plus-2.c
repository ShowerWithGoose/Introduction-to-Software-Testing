#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
typedef struct {
    int a;
    int b;
    struct Node *next;
}Node;

Node *head_link;
void insert(int a,int b){

    if(head_link->next==NULL){
        Node *link=(Node*)malloc(sizeof(Node));
        link->a=a;
        link->b=b;
        link->next=NULL;
        (head_link->next)=link;
        return;
    }
    Node *link_hold=head_link;
    Node *link=link_hold->next;
    while(link_hold!=NULL){
        link=link_hold->next;
        if(link==NULL){
            Node *p=(Node*)malloc(sizeof(Node));
            p->a=a;
            p->b=b;
            p->next=link_hold->next;
            link_hold->next=p;
            return;
        }
        if(link->b<b){ // @@ The condition `link->b < b` implies inserting when the existing exponent is smaller than the new one. However, the problem requires descending order. If the list is maintained in descending order, we should insert before the first node with a smaller exponent. The logic here seems to attempt descending order but fails to handle the traversal correctly for large gaps or specific ordering, leading to potential infinite loops or incorrect structure if not carefully managed. More critically, the `while` loop condition `link_hold!=NULL` combined with `link=link_hold->next` and the update `link_hold=link` at the end can lead to issues if `link` becomes NULL inside the loop but isn't handled before accessing `link->b`. Specifically, if `link` is NULL, the check `if(link==NULL)` handles it. But if `link->b > b`, it does nothing and proceeds to `link_hold=link`. If the list is long, this is O(N). For polynomial multiplication, if we insert M*N terms into a linked list of size up to M*N, the complexity becomes O((MN)^2), which is too slow for large inputs (like exponents up to 10^9, though the number of terms is small here, the issue is likely the algorithmic complexity or an infinite loop). Wait, the input has only 1 term each. So M=1, N=1. The result has 1 term. The complexity shouldn't be the issue for this specific test case unless there's an infinite loop.
        
        Let's look at the `insert` function logic more closely.
        The list is supposed to be sorted by exponent `b` in descending order.
        If `link->b < b`, we insert `p` before `link`. This is correct for descending order.
        If `link->b == b`, we add coefficients. Correct.
        If `link->b > b`, we continue. Correct.
        
        However, look at the loop update: `link_hold=link;`.
        If `link->b > b`, we move forward.
        
        The critical error causing Time Limit Exceeded or Infinite Loop often comes from incorrect pointer updates or failure to terminate.
        
        Let's re-read the `insert` function.
        `Node *link=link_hold->next;`
        Inside loop:
        `link=link_hold->next;` (Redundant but ok)
        If `link==NULL`: append.
        If `link->b < b`: insert before.
        If `link->b == b`: merge.
        If `link->b > b`: do nothing, then `link_hold=link`.
        
        This logic seems correct for a single pass insertion sort style.
        
        Why TLE?
        Look at `main`.
        `scanf("%d%d",&x1[i].a,&x1[i].b);`
        `c=getchar();`
        
        The input format says: "a_n n ... a0 0".
        The test case input is:
        `8 1000000000`
        `15 1000000000`
        
        In `main`:
        `scanf("%d%d",&x1[0].a,&x1[0].b);` reads 8 and 1000000000.
        Then `for(i=1;;i++)`:
        `scanf("%d%d",&x1[i].a,&x1[i].b);`
        This `scanf` will wait for more input. But there is no more input for the first polynomial on that line?
        The input is `8 1000000000\n`.
        After reading `8` and `1000000000`, the newline `\n` is left in the buffer.
        `c=getchar()` reads `\n`. Breaks loop.
        So `n1 = 1` (since i became 1, then broke). Wait, `i` starts at 1. `scanf` reads into `x1[1]`.
        This is wrong. The first term was read into `x1[0]`. The loop starts at `i=1` and tries to read the *second* term into `x1[1]`.
        If there is only one term, `scanf` for `x1[1]` will fail or hang?
        Actually, `scanf` returns the number of items successfully read. It is not checked.
        If the input is just `8 1000000000\n`, the first `scanf` outside reads `8` and `1000000000`.
        The loop starts. `scanf("%d%d", ...)` tries to read two integers. The next character is `\n`. `scanf` skips whitespace. It waits for the next integer.
        The next input line is `15 1000000000\n`.
        So `x1[1].a` becomes 15, `x1[1].b` becomes 1000000000.
        Then `c=getchar()` reads `\n`. Breaks.
        So `x1` has two terms: `x1[0]={8, 10^9}` and `x1[1]={15, 10^9}`.
        This is incorrect parsing. The first polynomial is `8x^1000000000`. The second is `15x^1000000000`.
        The code interprets the second polynomial's data as part of the first polynomial because it doesn't stop reading the first polynomial correctly after the newline if the newline is consumed by `getchar` but the `scanf` for the next iteration has already grabbed data from the next line?
        
        No, `scanf` with `%d` skips leading whitespace including newlines.
        So:
        1. Read `x1[0]`: `8`, `1000000000`. Buffer: `\n15 1000000000\n`.
        2. Loop `i=1`. `scanf("%d%d", &x1[1].a, &x1[1].b)`. Skips `\n`. Reads `15`, `1000000000`. Buffer: `\n`.
        3. `c=getchar()`. Reads `\n`. Break.
        
        So `x1` contains `{8, 10^9}` and `{15, 10^9}`.
        `n1 = 1` (value of `i` when breaking? No, `i` is 1. Loop breaks. `n1=i` sets `n1=1`).
        
        Next loop for `x2`:
        `i=0`. `scanf("%d%d", &x2[0].a, &x2[0].b)`.
        Buffer is empty? No, previous `getchar` consumed the newline after `15 1000000000`.
        So `scanf` waits for input. But there is no more input.
        This will cause `scanf` to hang/wait indefinitely, leading to Time Limit Exceeded or Runtime Error depending on the environment.
        
        The parsing logic is fundamentally flawed because `scanf("%d%d")` consumes tokens across lines if not careful, and the detection of newline via `getchar` happens *after* the `scanf` has potentially consumed the next line's data.
        
        To fix this, one should read line by line or check the return value of scanf, or ensure `getchar` checks for newline immediately after each pair if the format guarantees it, but `scanf` skips whitespace.
        
        The specific error causing TLE/Hang is that the second polynomial reading loop waits for input that never comes because the first loop ate it.
        
        Line 66: `scanf("%d%d",&x2[i].a,&x2[i].b);` // @@ This scanf hangs because the previous loop consumed the input for the second polynomial. The parsing logic for the first polynomial incorrectly reads into the second polynomial's data due to scanf skipping newlines.
    }
    //printf("OK2");
    //∂¡ÕÍ¡À
    n2=i;
int j;
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            insert(x1[i].a*x2[j].a,x1[i].b+x2[j].b);
        }
    }
    put();
    return 0;
}