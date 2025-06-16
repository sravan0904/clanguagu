#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, size;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n + 2];
    printf("Enter requests: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &size);
    req[n++] = head;
    req[n++] = 0;
    req[n++] = size - 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int t = req[i]; req[i] = req[j]; req[j] = t;
            }
    int total = 0, pos;
    for (int i = 0; i < n; i++)
        if (req[i] == head) { pos = i; break; }

    for (int i = pos; i < n - 1; i++) total += abs(req[i + 1] - req[i]);
    total += abs(req[n - 1] - req[0]);
    for (int i = 0; i < pos - 1; i++) total += abs(req[i + 1] - req[i]);

    printf("Total head movement: %d\n", total);
    return 0;
}
