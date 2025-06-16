#include <stdio.h>

void sort(int bt[], int p[], int pr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (pr[i] > pr[j]) {
                int temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], pr[n], wt[n], tat[n], p[n];
    printf("Enter burst time and priority:\n");
    for (i = 0; i < n; i++) {
        p[i] = i+1;
        printf("P%d - BT: ", i+1); scanf("%d", &bt[i]);
        printf("P%d - Priority: ", i+1); scanf("%d", &pr[i]);
    }

    sort(bt, p, pr, n);

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        printf("P%d\t%d\t\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }
    return 0;
}
