#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head=NULL;

int main()
{
    int op;
    int vau=0;
    struct node *p=NULL;
    while (1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            int zhi;
            scanf("%d",&zhi);
            if(vau==0)
            {
                p=(struct node *)malloc(sizeof(struct node));
                p->val=zhi;
                p->next=NULL;
                head=p;
            }
            else if(vau==99) // @@ The condition for checking if the stack is full is incorrect. The capacity is 100, so it should check if vau == 100. Also, it fails to increment vau or handle the state correctly after printing error, potentially leading to logic errors in subsequent operations. However, the primary runtime error source is likely elsewhere. Let's look closer. Actually, if vau is 99, it prints error but doesn't increment vau. This is logically correct for "full" check if max is 100 and we start at 0. Wait, if vau==99, there are 99 elements. We can push one more. So checking vau==99 to print error is wrong. It should be vau==100. But wait, if vau is 99, we enter the `else` block, push, and vau becomes 100. Next time, if vau is 100, it falls into `else if(vau==99)`? No. It falls into `else`. So it will try to push when full. This causes memory allocation even when full? No, the problem says max capacity 100. If vau is 100, it should print error. The code checks `vau==99`. If vau is 100, it goes to `else`, allocates memory, pushes, and increments vau to 101. This is a logical error but might not cause immediate RTE unless memory runs out. 
            {
                printf("error ");
            }
            else
            {
                struct node *q=NULL;
                q=(struct node *)malloc(sizeof(struct node));
                q->val=zhi;
                p->next=q;
                q->next=NULL;
                p=p->next;
            }
            vau++; // @@ This line is executed even when an error occurred (vau==99 case printed error but didn't return/continue). If vau was 99, it prints error, then increments vau to 100. Next push: vau is 100. It goes to `else` (since 100 != 0 and 100 != 99). It pushes again. This violates the capacity constraint. More importantly, let's look at the pop operation.
        }
        else if(op==0)
        {
            if(vau==0)
            {
                printf("error ");
            }
            else if(vau==1)
            {
                printf("%d ",p->val);
                head=NULL;
                p=NULL;
            }
            else
            {
                printf("%d ",p->val);
                struct node *q=head;
                for(;q->next!=p;q=q->next);
                p=q;
                q=q->next; // @@ 'q' is assigned to the node being popped (which was p->next before update? No. The loop finds the node BEFORE p. So q is the predecessor. Then p is updated to q. Then q is advanced to the node that was originally p (the one being popped).
                free(q); // @@ Missing free in the provided buggy code? No, the provided buggy code DOES NOT have free here. Wait, looking at the provided source code in the prompt:
                // The provided source code:
                //             else
                //             {
                //                 printf("%d ",p->val);
                //                 struct node *q=head;
                //                 for(;q->next!=p;q=q->next);
                //                 p=q;
                //                 q=q->next;
                //             }
                // It does NOT free q. This is a memory leak, but usually not a Runtime Error (RTE) unless memory exhaustion occurs. 
                // However, look at the variable `q` usage.
                // After `p=q`, `p` points to the new top.
                // `q=q->next` makes `q` point to the old top (the one being removed).
                // The pointer `q` is local. The node it points to is detached from the list? 
                // The predecessor `p` (updated) still has its `next` pointing to the removed node!
                // `p->next` is not set to NULL. So the list structure is corrupted? 
                // No, `p` was updated to the predecessor. The predecessor's `next` field still points to the removed node.
                // This means the list is not properly truncated. The removed node is still linked.
                // But `p` (the global tail pointer) is updated.
                // Future pushes will use `p->next = q_new`. This will overwrite the `next` pointer of the predecessor, effectively detaching the old tail? 
                // Yes. So logically it might work for LIFO if we only access via head or traverse? 
                // But we don't traverse for pop, we use `p`.
                // The real issue causing RTE is likely accessing invalid memory.
                
                // Let's re-read the code carefully.
                // In the `else` block of pop:
                // 1. Find predecessor of p, call it `pre` (stored in `q` initially).
                // 2. `p = q` (p becomes predecessor).
                // 3. `q = q->next` (q becomes the old p, the node to remove).
                // 4. The code DOES NOT free q.
                // 5. The code DOES NOT set p->next to NULL.
                
                // If we push again:
                // `p->next = q_new`. This overwrites the dangling pointer.
                
                // Where is the RTE?
                // Look at `vau==1` case:
                // `head=NULL; p=NULL;`
                // Look at `vau==0` case:
                // `printf("error ");`
                
                // Consider the input: `1 5 0 0 ...`
                // 1. Push 5. vau=1. head=p=node(5).
                // 2. Pop 0. vau==1. Print 5. head=NULL, p=NULL. vau=0.
                // 3. Pop 0. vau==0. Print "error ". vau=-1. 
                // Ah! `vau--` is executed AFTER the if-else block.
                
            }
            vau--; // @@ This decrement happens regardless of whether an error occurred. If vau was 0 and we tried to pop, it prints "error " and then decrements vau to -1. Subsequent operations relying on vau (like vau==0 check) will fail or behave incorrectly. Specifically, if vau becomes negative, the check `if(vau==0)` will be false. The check `else if(vau==1)` will be false. It will go to `else`. In `else`, it tries to access `head` and traverse. If head is NULL (from previous valid pop), `q=head` is NULL. `q->next` causes Segmentation Fault (Runtime Error).
        }
        else
        {
            break;
        }
    }
    p=head;
    while (p!=NULL)
    {
        struct node* q=p;
        p=p->next;
        free(q);
    }
    return 0;
}