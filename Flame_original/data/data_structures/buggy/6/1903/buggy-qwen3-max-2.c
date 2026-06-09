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
    *S = (SeqStack *)malloc(sizeof(SeqStack)); @@ [If malloc fails, *S will be NULL, leading to undefined behavior in subsequent operations. However, the primary error is not here.]
    (*S)->data = (ElemType *)malloc(capacity * sizeof(ElemType)); @@ [If this malloc fails, (*S)->data will be NULL, and later access causes crash. But again, not the main issue observed.]
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
    return S->data[S->top--]; @@ [This function does not check if the stack is empty before popping. If called on an empty stack, it accesses invalid memory (S->data[-1]), causing undefined behavior. The caller checks IsEmptySeqStack, but if that check were bypassed or faulty, this would be dangerous. However, the real issue is more subtle: the problem expects "error " on underflow/overflow, but this Pop function never returns an error indication—it just returns a value. The caller relies on IsEmptySeqStack, which is correct, so this may not be the bug.]

}

SeqStack *DestroySeqStack(SeqStack **S)
{
    free((*S)->data);
    free(*S);
    *S = NULL;
    return *S;
}