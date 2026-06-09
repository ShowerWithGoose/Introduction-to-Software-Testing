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
    *S = (SeqStack *)malloc(sizeof(SeqStack)); // @@ [If malloc fails, *S will be NULL, leading to undefined behavior in subsequent operations. However, the immediate error causing "gcc: not found" is not in this code—it's an environment issue. But since the problem states a compilation error and provides this source, the real issue is likely missing headers or types. The use of 'ssize_t' requires #include <sys/types.h> or equivalent, which is missing, causing a compilation error on systems where ssize_t is not defined by stdio.h or stdlib.h.]
    (*S)->data = (ElemType *)malloc(capacity * sizeof(ElemType));
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
    return S->data[S->top--]; // @@ [This function does not check for empty stack before popping. Although the caller checks IsEmptySeqStack, if called incorrectly, it would cause undefined behavior. However, in this program, the caller does check, so this is not the cause of the compilation error. The actual compilation error is due to undefined 'ssize_t'.]
}

SeqStack *DestroySeqStack(SeqStack **S)
{
    free((*S)->data);
    free(*S);
    *S = NULL;
    return *S;
}