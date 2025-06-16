#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, size, dir;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter requests: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &size);
    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &dir);
    req[n++] = head;
    req[n++] = (dir == 0) ? 0 : size - 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int t = req[i]; req[i] = req[j]; req[j] = t;
            }
    int total = 0, pos;
    for (int i = 0; i < n; i++)
        if (req[i] == head) { pos = i; break; }

    if (dir == 0) {
        for (int i = pos; i > 0; i--) total += abs(req[i] - req[i - 1]);
        for (int i = pos + 1; i < n - 1; i++) total += abs(req[i + 1] - req[i]);
    } else {
        for (int i = pos; i < n - 1; i++) total += abs(req[i + 1] - req[i]);
        for (int i = pos - 1; i > 0; i--) total += abs(req[i] - req[i - 1]);
    }
    printf("Total head movement: %d\n", total);
    return 0;
}
