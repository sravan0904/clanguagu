#include <stdio.h>
int main() {
    int files, start, length;
    printf("Enter number of files: ");
    scanf("%d", &files);
    int memory[100] = {0};
    for (int i = 0; i < files; i++) {
        printf("Enter start and length for file %d: ", i+1);
        scanf("%d%d", &start, &length);
        int flag = 0;
        for (int j = start; j < start+length; j++) {
            if (memory[j]) { flag = 1; break; }
        }
        if (!flag) {
            for (int j = start; j < start+length; j++)
                memory[j] = 1;
            printf("File %d allocated.\n", i+1);
        } else {
            printf("File %d allocation failed.\n", i+1);
        }
    }
    return 0;
}
