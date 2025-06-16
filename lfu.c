#include <stdio.h>
int findLFU(int count[], int f) {
    int min = count[0], pos = 0;
    for (int i = 1; i < f; i++)
        if (count[i] < min) {
            min = count[i]; pos = i;
        }
    return pos;
}
int main() {
    int f, p;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &p);
    int pages[p], frame[f], count[f], faults = 0;
    printf("Enter page reference string: ");
    for (int i = 0; i < p; i++) scanf("%d", &pages[i]);
    for (int i = 0; i < f; i++) { frame[i] = -1; count[i] = 0; }

    for (int i = 0; i < p; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                count[j]++;
                found = 1; break;
            }
        }
        if (!found) {
            int pos = findLFU(count, f);
            frame[pos] = pages[i];
            count[pos] = 1;
            faults++;
        }
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
