#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1024
#define    MAX(A,B)   ((A)>(B)?(A):(B))
#define    MIN(A,B)   ((A)<(B)?(A):(B))
#define MAX_WORDS 100
#define MAX_WORD_LEN 50
struct link {
int xisu;
int zhisu;
struct link *next;
};

int extractWords(const char* str, char words[MAX_WORDS][MAX_WORD_LEN]) {
    int i = 0, j = 0, k = 0;
    int num=0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {num++;
            words[j][k] = '\0'; // 结束当前单词
            j++; // 移动到下一个单词
            k = 0; // 重置单词索引
        } else {
            words[j][k] = str[i]; // 将字符存入当前单词中
            k++; // 移动到单词的下一个字符
        }
        i++; // 移动到字符串的下一个字符
    }
    num++;
    words[j][k] = '\0'; // 结束最后一个单词
    return num;
}


// 交换节点数据
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}




// 对链表进行降序排列
void bubbleSortLinkedList(struct link *head) {
    struct link * current;
    struct link * nextNode = NULL;
    int swapped;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != nextNode) {
            if (current->zhisu < current->next->zhisu) {
                swap(&current->zhisu, &current->next->zhisu);
                swap(&current->xisu, &current->next->xisu);
                swapped = 1;
            }
            current = current->next;
        }
        nextNode = current;
    } while (swapped);
}




int main()
{
    char str1[100];
    char str2[100];
    gets(str1); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logical error is elsewhere.]
    gets(str2); // @@ [Same as above, but not the cause of WA in this case.]
    char words1[MAX_WORDS][MAX_WORD_LEN];
    
    
    
    int num1=extractWords(str1, words1);
    int i;
    struct link *first1=NULL, *p,*q;
    
    for(i=1; i<=(num1/2); i++){
    q = (struct link *)malloc(sizeof(struct link));
    q->xisu =  atoi(words1[2*i-2]); 
    q->zhisu=  atoi(words1[2*i-1]); 
    q->next = NULL;
    if(first1 == NULL)
        first1 = p = q;
    else {
        p->next = q;
        p = p->next;    
    }
    }
    //printf("%d\n",num1);
    
    
        char words2[MAX_WORDS][MAX_WORD_LEN];
        int num2=extractWords(str2, words2);
        struct link *first2=NULL    ;
    for(i=1; i<=(num2/2); i++){
    q = (struct link *)malloc(sizeof(struct link));
    q->xisu =  atoi(words2[2*i-2]); 
    q->zhisu=  atoi(words2[2*i-1]); 
    q->next = NULL;
    if(first2 == NULL)
        first2 = p = q;
    else {
        p->next = q;
        p = p->next;    
    }
    }
    
    
//    printf("%d %d",num1,num2);
    int j;
    struct link* first=NULL    ;
    for(i=1;i<=num1/2;i++)
     {
     
     for(j=1;j<=num2/2;j++)
{
        q = (struct link *)malloc(sizeof(struct link));
    q->xisu =  atoi(words1[2*i-2])*atoi(words2[2*j-2]); 
    q->zhisu=  atoi(words1[2*i-1])+atoi(words2[2*j-1]); 
    q->next = NULL;
    if(first == NULL)
        first = p = q;
    else {
        p->next = q;
        p = p->next;    
         }     
         }         

    }
         
        bubbleSortLinkedList(first);
        
     struct link *current=first;
    while(current->next!=NULL)
    {
        if(current->zhisu==current->next->zhisu)
        {current->xisu+=current->next->xisu;
        p=current;
        q = p->next;
        p->next = p->next->next;
        free(q);
        }
        current=current->next;
    } // @@ [This loop only merges adjacent duplicate exponents once. If after merging, the new coefficient becomes zero, it should be removed. Also, if multiple terms with same exponent exist non-adjacently before sorting, they won't be merged—but since we sort first, adjacency is ensured. However, the bigger issue: after merging two terms, the resulting term might now match the next one, but the loop moves forward and skips checking again. So it doesn't fully collapse all same-exponent terms. In the test case, "142 26" and "15 26" become "157 26", but the buggy output shows "142 26 15 26", meaning merging didn't happen correctly—actually, wait: expected has "157 26", buggy has "142 26 15 26". That means the merging step failed to combine them. Why? Because after sorting, are they adjacent? Yes. But the loop condition is `while(current->next != NULL)`, and inside, after merging, it does `current = current->next`. However, after merging, the next node is deleted, so current->next is now the node after the deleted one. But if there are three same exponents, it would miss the third. However, in this case, only two. Let's check logic: suppose nodes A(142,26) -> B(15,26) -> C(...). current = A. A->zhisu == B->zhisu → merge: A.xisu=157, A.next = B.next = C. Then free(B). Then current = current->next → current = C. So it works for two. Then why in buggy output both appear? Because the merging loop runs AFTER sorting, but in the buggy output, "142 26" and "15 26" are consecutive, meaning they were NOT merged. So the issue must be that the merging loop did not run correctly. Wait: look at the loop:

    while(current->next!=NULL)
    {
        if(current->zhisu==current->next->zhisu)
        {current->xisu+=current->next->xisu;
        p=current;
        q = p->next;
        p->next = p->next->next;
        free(q);
        }
        current=current->next;
    }

But what if after merging, current->next becomes NULL? Then loop ends. That's fine. But the real bug: **the merging loop only makes one pass**. However, after sorting, all same exponents are adjacent, so one pass should suffice. Then why are "142 26" and "15 26" not merged?

Wait: look at how the product terms are generated. The first polynomial has terms: (10,38), (2,26), (7,13), (5,11), (18,9), (5,5)
Second: (30,47), (15,32), (3,21), (26,15), (6,0)

Now, which products give exponent 26?
- (2,26) * (6,0) → 2*6=12, 26+0=26
- (18,9) * (26,15) → 18*26=468, 9+15=24 → no
- (5,11) * (3,21) → 15, 32 → no
Wait, let's compute all terms that result in exponent 26:

We need p.power + q.power = 26.

From first poly powers: 38,26,13,11,9,5
From second: 47,32,21,15,0

Possible pairs:
26 + 0 = 26 → coeff: 2 * 6 = 12
11 + 15 = 26 → 5 * 26 = 130
13 + 13? but second has no 13.
9 + 17? no.
5 + 21 = 26 → 5 * 3 = 15

So total for exponent 26: 12 + 130 + 15 = 157.

But in the buggy output, we see "142 26" and "15 26". Where does 142 come from?

Wait, look at the buggy output snippet:
... 182 28 142 26 15 26 ...

So two terms with exponent 26: 142 and 15.

How is 142 formed?
Let’s see: 182 28 comes from (18,9)*(26,15)=468,24? No, 9+15=24. Wait, 28: 13+15=28 → 7*26=182 → correct.

Then 142 26: maybe 2*6=12 and 5*26=130 → 12+130=142? But then where is the 15 from 5*3=15 (5+21=26)?

Ah! So the program generated three terms for exponent 26: 12, 130, and 15. After sorting, they should be adjacent. But the merging loop only merges the first two into 142, then moves to the next (which is now 15), and since 142 != 15 in exponent? No—they are same exponent. Wait, after merging first two:

Initially: ... -> (12,26) -> (130,26) -> (15,26) -> ...

First iteration: current = (12,26). Merge with (130,26): becomes (142,26), and next points to (15,26). Then current = current->next → current = (15,26). Now current->next may be NULL or something else. But (142,26) and (15,26) are not compared because current moved past the merged node.

So the issue is: **after merging, the current node now has a new coefficient, but the next node may still have the same exponent, yet the loop advances current and never checks the merged node against its new next**.

Therefore, the merging loop is flawed—it should not advance current when a merge happens, because the current node might need to be merged again with the new next.

In the test case, three terms with exponent 26 are generated. The loop merges the first two into 142, then moves to the third (15), and stops. So 142 and 15 remain separate.

Hence, the error is in the merging loop: it doesn't handle multiple consecutive same exponents properly.

Additionally, note that the expected output has "157 26", which is 12+130+15=157.

So the fix would be: when merging, do not advance current, so it can check again with the new next. Only advance when no merge occurs.

But in the given code, it always does `current = current->next` regardless.

Thus, the error is on the line `current=current->next;` inside the merging loop—it should only advance if no merge happened.

But per instructions, we mark the line where the error occurs.

The problematic block is:

    while(current->next!=NULL)
    {
        if(current->zhisu==current->next->zhisu)
        {current->xisu+=current->next->xisu;
        p=current;
        q = p->next;
        p->next = p->next->next;
        free(q);
        }
        current=current->next; // @@ [This line causes the loop to skip checking the merged term against subsequent terms with the same exponent. After merging, current should not advance so it can compare the updated term with the new next node. This leads to incomplete merging of like terms, as seen in the test case where 142 and 15 (both exponent 26) remain separate instead of summing to 157.]
    }
    
    
    
    
    
    
      current=first;
      while (current != NULL) {
        printf("%d %d ", current->xisu,current->zhisu);
        // 在这里可以引用当前节点的值或其他属性
        // 例如：int value = current->data;
        current = current->next;
    }
    
    
    
    
    
    return 0;
    
}