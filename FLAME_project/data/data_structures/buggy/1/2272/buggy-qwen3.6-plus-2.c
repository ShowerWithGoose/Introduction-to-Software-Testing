#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1");
        return 0;
    } else if (n == 2) {
        printf("1 2\n");
        printf("2 1"); // @@ The output for the last permutation "2 1" is missing a newline character at the end. While some judges are lenient, strict formatting usually requires each line to end with a newline. More importantly, looking at the expected output "1 2 ", it seems there might be a trailing space or newline expectation mismatch in the problem description vs test case, but typically "2 1" should be followed by a newline to match the format of previous lines. However, the specific error here is likely that the judge expects a newline after the last line or the comparison is strict. Let's look closer. Expected: "1 2 ". Buggy: "1 2\n2 1". Wait, the expected output provided in the prompt is "1 2 ". This looks like a truncated expected output or a specific format issue. Actually, looking at the provided "Expected Output: 1 2 ", it contains a trailing space. But standard permutation problems output full sets. For N=2, permutations are "1 2" and "2 1". The buggy code outputs both. The expected output shown is just "1 2 ". This implies the test case might actually be expecting ONLY the first line? No, that contradicts the problem description "Output N! lines". It is highly likely the "Expected Output" displayed in the prompt is incomplete or formatted strangely. However, a common error in these hardcoded solutions is missing newlines. Let's look at the N=1 case: `printf("1");` no newline. N=2: `printf("2 1");` no newline. N=3: ends with `\n`. N=4: no trailing `\n`. Inconsistent. The most likely logical error causing a "Wrong Answer" on a strict judge for N=2 when the output is "1 2\n2 1" vs expected "1 2\n2 1\n" is the missing final newline. 
    } else if(n==3){
        printf("1 2 3\n");
        printf("1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    } else if(n==4){
        printf("1 2 3 4\n"
               "1 2 4 3\n"
               "1 3 2 4\n"
               "1 3 4 2\n"
               "1 4 2 3\n"
               "1 4 3 2\n"
               "2 1 3 4\n"
               "2 1 4 3\n"
               "2 3 1 4\n"
               "2 3 4 1\n"
               "2 4 1 3\n"
               "2 4 3 1\n"
               "3 1 2 4\n"
               "3 1 4 2\n"
               "3 2 1 4\n"
               "3 2 4 1\n"
               "3 4 1 2\n"
               "3 4 2 1\n"
               "4 1 2 3\n"
               "4 1 3 2\n"
               "4 2 1 3\n"
               "4 2 3 1\n"
               "4 3 1 2\n"
               "4 3 2 1");
    }


}