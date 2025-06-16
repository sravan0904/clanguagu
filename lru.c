#include <stdio.h>
int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++)
        if (time[i] < min) {
            min = time[i]; pos = i;
        }
    return pos;
}
int main() {
    int n, f, i, j, time[10], counter = 0, pf = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    int frames[f];
    for (i = 0; i < f; i++) frames[i] = -1;

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = ++counter;
                break;
            }
        }
        if (!found) {
            int pos = -1;
            for (j = 0; j < f; j++)
                if (frames[j] == -1) { pos = j; break; }
            if (pos == -1) pos = findLRU(time, f);
            frames[pos] = pages[i];
            time[pos] = ++counter;
            pf++;
        }
    }
    printf("Total Page Faults: %d\n", pf);
    return 0;
}
