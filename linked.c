#include <stdio.h>
int main() {
    int n, start, len;
    printf("Enter number of files: ");
    scanf("%d", &n);
    int mem[100] = {0};
    for (int i = 0; i < n; i++) {
        printf("Enter start and length for file %d: ", i+1);
        scanf("%d%d", &start, &len);
        int flag = 0;
        for (int j = start; j < start+len; j++) {
            if (mem[j]) { flag = 1; break; }
        }
        if (!flag) {
            for (int j = start; j < start+len; j++)
                mem[j] = 1;
            printf("File %d allocated via linked method.\n", i+1);
        } else {
            printf("File %d allocation failed.\n", i+1);
        }
    }
    return 0;
}
