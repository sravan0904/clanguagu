#include <stdio.h>
int main() {
    int index, blocks, i, memory[50] = {0};
    printf("Enter index block: ");
    scanf("%d", &index);
    printf("Enter number of blocks: ");
    scanf("%d", &blocks);
    int b[blocks];
    for (i = 0; i < blocks; i++) {
        printf("Enter block %d: ", i+1);
        scanf("%d", &b[i]);
        if (memory[b[i]]) {
            printf("Block already allocated. Aborting.\n");
            return 0;
        }
        memory[b[i]] = 1;
    }
    memory[index] = 1;
    printf("File allocated using indexed allocation.\n");
    return 0;
}
