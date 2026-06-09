#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef enum Status { Success = 0, FullStruct = 1, EmptyStruct = -1 } Status;

typedef struct SeqStack {
    ElemType *data;
    ssize_t top;
    size_t capacity;
} SeqStack;

SeqStack *InitSeqStack(SeqStack **S, size_t capacity);

bool IsEmptySeqStack(SeqStack *S);
bool IsFullSeqStack(SeqStack *S);

Status PushSeqStack(SeqStack *S, ElemType e);
ElemType PopSeqStack(SeqStack *S);

SeqStack *DestroySeqStack(SeqStack **S);


int main()
{
    SeqStack *S = InitSeqStack(&S, 100);
    int op = 0, e = 0;
    while (1) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &e);
            if(IsFullSeqStack(S)) {
                printf("error ");
            }
            else {
                PushSeqStack(S, e);
            }
        }
        else if (op == 0) {
            if (IsEmptySeqStack(S)) {
                printf("error ");
            }
            else {
                printf("%d ", PopSeqStack(S));
            }
        }
        else if (op == -1) {
            break;
        }
    }
    S = DestroySeqStack(&S);
    return 0;
}


SeqStack *InitSeqStack(SeqStack **S, size_t capacity)
{
    *S = (SeqStack *)malloc(sizeof(SeqStack)); // @@ [If malloc fails, *S will be NULL, leading to undefined behavior in subsequent operations. However, the immediate error causing "gcc: not found" is not in this code—it's an environment issue. But based on logic errors relevant to problem: no check for allocation failure.]
    (*S)->data = (ElemType *)malloc(capacity * sizeof(ElemType)); // @@ [Similarly, no check if malloc returns NULL; using (*S)->data when it's NULL leads to crash.]
    (*S)->top = -1;
    (*S)->capacity = capacity;
    return *S;
}

bool IsEmptySeqStack(SeqStack *S)
{
    return S->top == -1;
}

bool IsFullSeqStack(SeqStack *S)
{
    return S->top == S->capacity - 1;
}

Status PushSeqStack(SeqStack *S, ElemType e)
{
    if (IsFullSeqStack(S))return FullStruct;
    S->data[++S->top] = e;
    return Success;
}

ElemType PopSeqStack(SeqStack *S)
{
    return S->data[S->top--]; // @@ [This function does not check if the stack is empty before popping. If called on an empty stack, it accesses invalid memory (S->top = -1 => S->data[-1]), causing undefined behavior. The caller checks emptiness, but if that check were bypassed or incorrect, this would fail. However, in this program the caller does check, so this may not be the direct cause. But per problem spec, pop on empty should print "error", which is handled in main—so this line is safe only if IsEmptySeqStack works correctly. Still, the function itself is unsafe by design.]
}

SeqStack *DestroySeqStack(SeqStack **S)
{
    free((*S)->data);
    free(*S);
    *S = NULL;
    return *S;
}