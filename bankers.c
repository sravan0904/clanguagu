#include <stdio.h>
int main() {
    int n, r;
    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &r);
    int alloc[n][r], max[n][r], need[n][r], avail[r];
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    printf("Enter maximum matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    printf("Enter available resources:\n");
    for (int i = 0; i < r; i++)
        scanf("%d", &avail[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int finish[n], safe[n], count = 0;
    for (int i = 0; i < n; i++) finish[i] = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < r; j++)
                    if (need[i][j] > avail[j])
                        break;
                if (j == r) {
                    for (int k = 0; k < r; k++)
                        avail[k] += alloc[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    if (count == n) {
        printf("Safe sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safe[i]);
        printf("\n");
    } else {
        printf("System is in unsafe state\n");
    }
    return 0;
}
