#include <stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
    printf("\nFirst Fit:\nProcess\tBlock\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%s\n", i+1, allocation[i] != -1 ? "Allocated" : "Not Allocated");
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i])
                if (best == -1 || blockSize[j] < blockSize[best])
                    best = j;
        if (best != -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }
    printf("\nBest Fit:\nProcess\tBlock\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%s\n", i+1, allocation[i] != -1 ? "Allocated" : "Not Allocated");
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int worst = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i])
                if (worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;
        if (worst != -1) {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }
    printf("\nWorst Fit:\nProcess\tBlock\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%s\n", i+1, allocation[i] != -1 ? "Allocated" : "Not Allocated");
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);

    int bf[m], wf[m], ff[m];
    for (int i=0;i<m;i++) bf[i]=wf[i]=ff[i]=blockSize[i];

    firstFit(ff, m, processSize, n);
    bestFit(bf, m, processSize, n);
    worstFit(wf, m, processSize, n);

    return 0;
}
