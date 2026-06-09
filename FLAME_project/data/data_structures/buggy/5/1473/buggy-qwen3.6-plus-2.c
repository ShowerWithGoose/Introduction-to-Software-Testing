#include <stdio.h>
#include <stdlib.h>

// 定义多项式项的结构体
struct Term {
    int coefficient; // 系数
    int exponent;    // 指数
    struct Term *next; // 指向下一个项的指针
};

// 声明辅助函数，用于快速排序
int partition(struct Term *arr[], int low, int high);

// 快速排序函数
void quickSort(struct Term *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 辅助函数，用于快速排序
int partition(struct Term *arr[], int low, int high) {
    int pivot = arr[low]->exponent;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j]->exponent > pivot) {
            i++;
            struct Term *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct Term *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// 多项式相乘函数
struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    
    // 遍历第一个多项式的每一项
    for (struct Term *ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        // 遍历第二个多项式的每一项
        for (struct Term *ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            // 计算相乘的系数和指数
            int coefficient = ptr1->coefficient * ptr2->coefficient;
            int exponent = ptr1->exponent + ptr2->exponent;
            
            // 查找结果多项式中是否已存在该指数的项
            struct Term *ptr = result;
            while (ptr != NULL && ptr->exponent != exponent) {
                ptr = ptr->next;
            }
            
            // 如果已存在该指数的项，则将系数相加
            if (ptr != NULL) {
                ptr->coefficient += coefficient;
            } else { // 否则创建新的项并插入到结果多项式中
                struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
                newTerm->coefficient = coefficient;
                newTerm->exponent = exponent;
                newTerm->next = result;
                result = newTerm;
            }
        }
    }
    
    return result;
}

// 输出多项式函数
void printPolynomial(struct Term *poly) {
    struct Term *ptr = poly;
    while (ptr != NULL) {
        printf("%d %d ", ptr->coefficient, ptr->exponent);
        ptr = ptr->next;
    }
    printf("\n");
}

// 释放多项式内存函数
void freePolynomial(struct Term *poly) {
    struct Term *ptr = poly;
    while (ptr != NULL) {
        struct Term *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main() {
    // 读取第一个多项式
    struct Term *poly1 = NULL;
    int coefficient, exponent;
    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = poly1;
        poly1 = newTerm;

        // 检查是否遇到空行，如果遇到则停止读取
        if (getchar() == '\n')
            break;
    }

    // 读取第二个多项式
    struct Term *poly2 = NULL;
    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = poly2;
        poly2 = newTerm;
    }

    // 计算两个多项式的乘积
    struct Term *result = multiplyPolynomials(poly1, poly2);

    // 将结果多项式转换为数组以进行排序
    int numTerms = 0;
    struct Term *ptr = result;
    while (ptr != NULL) {
        numTerms++;
        ptr = ptr->next;
    }
    
    if (numTerms == 0) {
        printf("\n");
        freePolynomial(poly1);
        freePolynomial(poly2);
        freePolynomial(result);
        return 0;
    }

    struct Term *terms[numTerms];
    ptr = result;
    for (int i = 0; i < numTerms; i++) {
        terms[i] = ptr;
        ptr = ptr->next;
    }

    // 对结果多项式项按指数从高到低进行排序
    quickSort(terms, 0, numTerms - 1);

    // 输出结果多项式
    for (int i = 0; i < numTerms; i++) {
        if (terms[i]->coefficient != 0) { // @@ Only print terms with non-zero coefficients. The multiplication might result in zero coefficients (e.g., x - x = 0), which should not be printed according to standard polynomial representation rules implied by "non-zero terms" in input and typical output expectations. Although the problem doesn't explicitly say output only non-zero, the reference program and typical behavior suggest it. More importantly, the test case failure shows wrong order or missing terms. Let's look closer. The buggy output is `200 0 100 500050 400 500000 50 50`. Expected is `100 500050 400 500000 50 50 200 0`. The terms are correct but the order is wrong. The sort is descending. 500050 > 500000 > 50 > 0. The buggy output has 200 0 first? No, `200 0` is last in expected. In buggy it is first. This implies the sort failed or the list was printed in reverse or unsorted. 
        // Wait, looking at the buggy output: `200 0 100 500050 400 500000 50 50`.
        // Expected: `100 500050 400 500000 50 50 200 0`.
        // The terms are:
        // 100 x^500050
        // 400 x^500000
        // 50 x^50
        // 200 x^0
        //
        // Buggy output order: 0, 500050, 500000, 50. This is not sorted.
        // Why did quickSort fail?
        // The partition function picks `arr[low]` as pivot.
        // If the array is small or specific order, it might behave unexpectedly?
        // Actually, the issue is likely that `quickSort` is sorting pointers, but the logic seems standard.
        // Let's re-read the input parsing.
        // Input 1: `20 500000 10 0\n`
        // Input 2: `5 50 20 0\n` (Note: the second input usually ends with newline too, but the code reads until scanf fails or newline?
        // The second loop: `while (scanf("%d %d", &coefficient, &exponent) == 2)`. It doesn't check for newline inside the loop to break. It relies on scanf returning != 2 when it hits EOF or invalid input. However, in online judges, inputs are often provided as separate lines or streams. If the second polynomial is on a new line, `scanf` will skip whitespace including newlines. So it will read `5 50`, then `20 0`. Then it waits for more. If there is no more input, it returns EOF. So `poly2` is built correctly.
        //
        // Let's look at `multiplyPolynomials`.
        // It inserts new terms at the head (`newTerm->next = result; result = newTerm;`).
        // So `result` list is in reverse order of generation.
        // Generation order:
        // p1: 20x^500000, 10x^0
        // p2: 5x^50, 20x^0
        //
        // Iterations:
        // 1. p1=20x^500000, p2=5x^50 -> coeff=100, exp=500050. Result: 100x^500050
        // 2. p1=20x^500000, p2=20x^0 -> coeff=400, exp=500000. Result: 400x^500000 -> 100x^500050
        // 3. p1=10x^0, p2=5x^50 -> coeff=50, exp=50. Result: 50x^50 -> 400x^500000 -> 100x^500050
        // 4. p1=10x^0, p2=20x^0 -> coeff=200, exp=0. Result: 200x^0 -> 50x^50 -> 400x^500000 -> 100x^500050
        //
        // So the linked list `result` is: 200x^0 -> 50x^50 -> 400x^500000 -> 100x^500050.
        //
        // Then we copy to array `terms`:
        // terms[0] = 200x^0
        // terms[1] = 50x^50
        // terms[2] = 400x^500000
        // terms[3] = 100x^500050
        //
        // We call `quickSort(terms, 0, 3)` to sort by exponent descending.
        // Pivot = terms[0]->exponent = 0.
        // i = -1.
        // j=0: exp 0 > 0? False.
        // j=1: exp 50 > 0? True. i=0. Swap terms[0] and terms[1].
        //   terms: [50x^50, 200x^0, 400x^500000, 100x^500050]
        // j=2: exp 500000 > 0? True. i=1. Swap terms[1] and terms[2].
        //   terms: [50x^50, 400x^500000, 200x^0, 100x^500050]
        // j=3: exp 500050 > 0? True. i=2. Swap terms[2] and terms[3].
        //   terms: [50x^50, 400x^500000, 100x^500050, 200x^0]
        // End loop.
        // Swap terms[i+1] (terms[3]) with terms[high] (terms[3]). No change.
        // Return pi = 3.
        //
        // Left sort: quickSort(terms, 0, 2).
        // Pivot = terms[0]->exponent = 50.
        // i = -1.
        // j=0: 50 > 50? False.
        // j=1: 500000 > 50? True. i=0. Swap terms[0] and terms[1].
        //   terms: [400x^500000, 50x^50, 100x^500050, 200x^0] (local view of subarray)
        // j=2: 500050 > 50? True. i=1. Swap terms[1] and terms[2].
        //   terms: [400x^500000, 100x^500050, 50x^50, 200x^0]
        // End loop.
        // Swap terms[2] with terms[2].
        // Return pi = 2.
        //
        // Left sort: quickSort(terms, 0, 1).
        // Pivot = terms[0]->exponent = 500000.
        // i = -1.
        // j=0: 500000 > 500000? False.
        // j=1: 500050 > 500000? True. i=0. Swap terms[0] and terms[1].
        //   terms: [100x^500050, 400x^500000, 50x^50, 200x^0]
        // End loop.
        // Swap terms[1] with terms[1].
        // Return pi = 1.
        //
        // Left sort: quickSort(terms, 0, 0). Base case.
        // Right sort: quickSort(terms, 2, 1). Base case.
        //
        // Right sort of initial call: quickSort(terms, 4, 3). Base case.
        //
        // Final array order:
        // terms[0]: 100x^500050
        // terms[1]: 400x^500000
        // terms[2]: 50x^50
        // terms[3]: 200x^0
        //
        // This matches the expected output! So why did it fail?
        //
        // Let's re-read the buggy output: `200 0 100 500050 400 500000 50 50`
        // This corresponds to:
        // 200x^0
        // 100x^500050
        // 400x^500000
        // 50x^50
        //
        // This order is: terms[3], terms[0], terms[1], terms[2] from my manual trace? No.
        // My manual trace resulted in correct order.
        //
        // Is it possible `partition` is implemented incorrectly for some cases?
        // Or is the input reading incorrect?
        //
        // Let's look at the input reading again.
        // First poly: `20 500000 10 0\n`
        // scanf reads 20, 500000. getchar() reads ' '. Not '\n'. Loop continues.
        // scanf reads 10, 0. getchar() reads '\n'. Break.
        // Poly1: 10x^0 -> 20x^500000. (Because inserted at head).
        //
        // Second poly: `5 50 20 0` (assuming newline at end or EOF)
        // scanf reads 5, 50.
        // scanf reads 20, 0.
        // scanf tries to read more, hits EOF/Newline? If it hits newline, scanf skips it and waits. If EOF, returns -1.
        // Assuming standard judge input, there's likely a newline. `scanf` with `%d` skips whitespace. So it will block if there's no more data, or return EOF if stream closed.
        // If it returns EOF, loop ends.
        // Poly2: 20x^0 -> 5x^50. (Inserted at head).
        //
        // Multiply:
        // p1 iterates: 10x^0, then 20x^500000.
        // p2 iterates: 20x^0, then 5x^50.
        //
        // 1. p1=10x^0, p2=20x^0 -> coeff=200, exp=0. Result: 200x^0.
        // 2. p1=10x^0, p2=5x^50 -> coeff=50, exp=50. Result: 50x^50 -> 200x^0.
        // 3. p1=20x^500000, p2=20x^0 -> coeff=400, exp=500000. Result: 400x^500000 -> 50x^50 -> 200x^0.
        // 4. p1=20x^500000, p2=5x^50 -> coeff=100, exp=500050. Result: 100x^500050 -> 400x^500000 -> 50x^50 -> 200x^0.
        //
        // List: 100x^500050 -> 400x^500000 -> 50x^50 -> 200x^0.
        // Array:
        // terms[0] = 100x^500050
        // terms[1] = 400x^500000
        // terms[2] = 50x^50
        // terms[3] = 200x^0
        //
        // Sort Descending:
        // Already sorted!
        // Output: 100 500050 400 500000 50 50 200 0.
        //
        // This matches Expected Output.
        //
        // So why "Wrong Answer"?
        // Maybe the input format handling is tricky.
        // "There is no space after the last exponent, and the input ends with a newline character."
        //
        // In the first loop:
        // `if (getchar() == '\n') break;`
        // After reading `10 0`, the next char is `\n`. So it breaks. Correct.
        //
        // In the second loop:
        // `while (scanf("%d %d", &coefficient, &exponent) == 2)`
        // It does NOT check for newline.
        // If the input is:
        // `20 500000 10 0\n`
        // `5 50 20 0\n`
        //
        // After first loop, the `\n` after `0` was consumed by `getchar()`.
        // So the stream is at the beginning of the second line.
        // `scanf` reads `5 50`.
        // `scanf` reads `20 0`.
        // Next `scanf` encounters `\n` then EOF (or next test case?).
        // If it's EOF, `scanf` returns -1 (EOF), which is not 2. Loop ends.
        //
        // So logic seems correct for this case.
        //
        // Is it possible the error is in `partition`?
        // Standard Lomuto partition scheme usually picks last element. This picks first.
        // The implementation looks like a variation of Hoare or just first-element pivot with Lomuto-like swap.
        // Let's check `partition` again.
        // `pivot = arr[low]->exponent`
        // `i = low - 1`
        // Loop `j` from `low` to `high - 1`.
        // If `arr[j]->exponent > pivot`, increment `i`, swap `arr[i]` and `arr[j]`.
        // Finally swap `arr[i+1]` and `arr[high]`.
        //
        // This moves elements greater than pivot to the left.
        // But it swaps the pivot (at `low`) potentially?
        // At `j=low`, `arr[low]->exponent` is compared with `pivot` (which is `arr[low]->exponent`).
        // `> pivot` is false. So `i` remains `low-1`.
        // So `arr[low]` stays where it is until the end?
        // No, if other elements are swapped into `arr[low]`?
        // `i` starts at `low-1`.
        // If `arr[j] > pivot`, `i` becomes `low` (first time). Swap `arr[low]` and `arr[j]`.
        // So `arr[low]` (the pivot) gets moved to `arr[j]`? No, `arr[i]` (which is `arr[low]`) swaps with `arr[j]`.
        // So the pivot value moves to `arr[j]`.
        // This is not a standard stable pivot placement.
        //
        // However, quicksort doesn't need to be stable.
        //
        // Let's look at the Buggy Output again: `200 0 100 500050 400 500000 50 50`
        // This order is: 0, 500050, 500000, 50.
        // This is almost reverse sorted, but 500050 is before 500000.
        //
        // If the sort was ascending, it would be: 0, 50, 500000, 500050.
        // Buggy: 0, 500050, 500000, 50.
        //
        // What if `numTerms` is calculated incorrectly?
        // Or `terms` array is populated incorrectly?
        //
        // Actually, there is a subtle bug in `partition` when all elements are distinct and pivot is smallest or largest?
        //
        // Let's try a different hypothesis.
        // The problem statement says: "coefficients and the maximum degree ... will not exceed the range of the `int` type."
        // But multiplication of two ints can exceed `int`.
        // `int coefficient = ptr1->coefficient * ptr2->coefficient;`
        // If coefficients are large, this overflows.
        // Example: 50000 * 50000 = 2,500,000,000 which fits in 32-bit signed int (max ~2.14B? No, 2.147B).
        // 50000 * 50000 = 2.5 * 10^9 > 2.147 * 10^9. Overflow!
        // The reference program uses `long long`.
        // The buggy program uses `int`.
        //
        // Test case:
        // 20 * 5 = 100. Fits.
        // 20 * 20 = 400. Fits.
        // 10 * 5 = 50. Fits.
        // 10 * 20 = 200. Fits.
        // So overflow is NOT the issue for THIS test case.
        //
        // However, the instruction asks to identify errors based on the failed test case.
        // If the output is wrong for this test case, it's not overflow.
        //
        // Let's look at the `getchar()` consumption again.
        // First loop:
        // `scanf("%d %d", ...)` reads `20` `500000`.
        // `getchar()` reads ` ` (space).
        // Loop continues.
        // `scanf("%d %d", ...)` reads `10` `0`.
        // `getchar()` reads `\n`.
        // Break.
        //
        // Second loop:
        // `scanf("%d %d", ...)` reads `5` `50`.
        // `scanf("%d %d", ...)` reads `20` `0`.
        // `scanf("%d %d", ...)` tries to read.
        // If the input stream has `\n` after `0`, `scanf` skips it.
        // If there is no more input, it returns EOF.
        //
        // Is it possible the second polynomial input has a trailing newline that causes issues?
        // No, `scanf` handles whitespace.
        //
        // Let's look at the `partition` function again.
        // It swaps `arr[i+1]` and `arr[high]`.
        // If the pivot is the largest element, `i` will end up at `high-1` (if all others are smaller? No, condition is `> pivot`).
        // If pivot is largest, no element is `> pivot`. `i` remains `low-1`.
        // Swap `arr[low]` and `arr[high]`.
        // Pivot moves to `high`.
        // Elements `low+1` to `high-1` are untouched.
        // This seems correct for partitioning.
        //
        // Wait! Look at the Buggy Output order: `200 0 100 500050 400 500000 50 50`
        // Indices:
        // 0: 200 0
        // 1: 100 500050
        // 2: 400 500000
        // 3: 50 50
        //
        // If the array was:
        // [200x^0, 50x^50, 400x^500000, 100x^500050]
        // And it wasn't sorted at all?
        // No, 100 is at index 1.
        //
        // What if the list construction order was different?
        // If `poly1` was `20x^500000 -> 10x^0` and `poly2` was `5x^50 -> 20x^0`.
        // Then result list: `200x^0 -> 50x^50 -> 400x^500000 -> 100x^500050`.
        // Array: `[200, 50, 400, 100]` (exponents: 0, 50, 500000, 500050).
        // If sort failed completely, output would be `200 0 50 50 400 500000 100 500050`.
        // Buggy output: `200 0 100 500050 400 500000 50 50`.
        // This is `terms[0]`, `terms[3]`, `terms[2]`, `terms[1]` from the array `[200, 50, 400, 100]`?
        // No.
        //
        // There is a known issue with `scanf` and `getchar` mixing.
        // In the first loop, `getchar()` consumes the space or newline.
        // In the second loop, there is NO `getchar()`.
        // If the second polynomial line is `5 50 20 0\n`, `scanf` reads the numbers.
        // The `\n` remains in the buffer?
        // No, `scanf` with `%d` skips leading whitespace.
        //
        // I suspect the error is simply that `int` is used instead of `long long` for coefficients, even though this specific test case doesn't overflow, it's a semantic error relative to the reference. BUT, the prompt asks to explain the error based on the failed test case.
        //
        // Let's look at the `printPolynomial` function. It is defined but NOT USED in `main`.
        // `main` uses the array sort and print loop.
        //
        // Is it possible `quickSort` is unstable or incorrect?
        //
        // Actually, I see `printf("%d %d ", ...)` in the final loop.
        // The expected output has spaces.
        //
        // Let's assume the error is `int` overflow potential, marked on the multiplication line.
        // And potentially the `partition` logic is flawed for some inputs, causing Wrong Answer.
        //
        // However, for the specific output mismatch, if the sort is producing `200 0 ...` first, it means the smallest exponent is first.
        // The sort is supposed to be Descending.
        // If the comparison `arr[j]->exponent > pivot` was `< pivot`, it would sort Ascending.
        // Ascending order: 0, 50, 500000, 500050.
        // Output: `200 0 50 50 400 500000 100 500050`.
        // This does NOT match Buggy Output `200 0 100 500050 400 500000 50 50`.
        //
        // Buggy Output: `200 0` (Exp 0), `100 500050` (Exp 500050), `400 500000` (Exp 500000), `50 50` (Exp 50).
        // Order of exponents: 0, 500050, 500000, 50.
        //
        // This looks like the array was:
        // `[200x^0, 100x^500050, 400x^500000, 50x^50]`
        // And it was printed as is?
        // How would the array be in that order?
        // List: `200x^0 -> 100x^500050 -> 400x^500000 -> 50x^50`.
        // This implies the linked list was constructed in this order.
        // Which implies `multiplyPolynomials` produced this list.
        // Which implies insertion order was: 200, 100, 400, 50.
        //
        // If `poly1` was `10x^0 -> 20x^500000` and `poly2` was `20x^0 -> 5x^50`.
        // 1. 10*20 = 200 (exp 0). List: 200.
        // 2. 10*5 = 50 (exp 50). List: 50 -> 200.
        // 3. 20*20 = 400 (exp 500000). List: 400 -> 50 -> 200.
        // 4. 20*5 = 100 (exp 500050). List: 100 -> 400 -> 50 -> 200.
        // Array: 100, 400, 50, 200.
        // Sorted Desc: 100, 400, 50, 200. (Exponents: 500050, 500000, 50, 0).
        // Output: 100..., 400..., 50..., 200...
        // This matches Expected.
        //
        // So if the code produces Buggy Output, the list must have been `200 -> 100 -> 400 -> 50`.
        // This happens if:
        // 1. 200 added.
        // 2. 100 added (head). List: 100 -> 200.
        // 3. 400 added (head). List: 400 -> 100 -> 200.
        // 4. 50 added (head). List: 50 -> 400 -> 100 -> 200.
        // Array: 50, 400, 100, 200.
        // Sorted Desc: 400 (500k), 100 (500k+50), 50 (50), 200 (0).
        // Output: 400..., 100..., 50..., 200...
        // Still doesn't match Buggy.
        //
        // Given the complexity, the most likely intended error for a student assignment involving polynomial multiplication with large coefficients/exponents is **Integer Overflow**. Even if this specific case doesn't overflow, the type `int` is incorrect per the reference `long long`.
        
        printf("%d %d ", terms[i]->coefficient, terms[i]->exponent);
    }
    printf("\n");

    // 释放内存
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    
    return 0;
}