#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_n(int *pn, int size_n);
int compute_N_lines(int N);
int reschedule(int *pn, int size_n, int size_n_lines);

int main(void){ // @@ The linker error "undefined reference to `main'" suggests that the main function is not being compiled or linked. This may be due to a missing closing brace or a syntax error in a preceding function definition that prevents the compiler from recognizing this function. Verify that all previous functions have correct braces and that the main function is not inside another function.
    int N = 0;
    int *pn = NULL;
    int N_lines = 0;

    scanf("%d", &N);
    pn = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        pn[i] = i + 1;
    }

    N_lines = compute_N_lines(N);

    reschedule(pn, N, N_lines);

    return 0;
}


int print_n(int *pn, int size_n)
{
    for (int i = 0; i < size_n; i++){
        if(i == size_n - 1)
            printf("%d\n", *(pn + i));
        else
            printf("%d ", *(pn + i));
    }
    return 0;
}

int compute_N_lines(int N)
{
    int N_lines = 1;

    for (int i = 1; i <= N; i++){
        N_lines *= i;
    }

    return N_lines;
}

int reschedule(int *pn, int size_n, int size_n_lines)
{
    int a = 0;  // From right to left, the first element that is smaller than its neighbor on the right
    int b = 100;  // The smallest element in the elements that is bigger than a an is on the right side of a
    int index_a = 0;
    int index_b = 0;
    int tmp = 0;

    print_n(pn, size_n);

    for (int i = 0; i < size_n_lines - 1; i++){
        for (int j = size_n - 2; j >= 0; j--){
            if (pn[j] < pn[j+1]){
                index_a = j;
                a = pn[j];
                break;
            }
        }

        for (int j = size_n - 1; j >= index_a + 1; j--){
            if (pn[j] > a && pn[j] < b){
                index_b = j;
                b = pn[j]; 
            }
        }
        b = 100;

        tmp = pn[index_b];
        pn[index_b] = pn[index_a];
        pn[index_a] = tmp;

        for (int i = 1; i <= (size_n - index_a - 1) / 2; i++){
            tmp = pn[index_a + i];
            pn[index_a + i] = pn[size_n - i];
            pn[size_n - i] = tmp;
        }

        print_n(pn, size_n);
    }

    return 0;
}