#include <stdio.h>

int main() {
    int pages[100], frames[10], n, f, i, j, k, hit = 0, miss = 0, pos = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                hit++;
                found = 1;
                break;
            }
        }
        if(!found) {
            frames[pos] = pages[i];
            pos = (pos + 1) % f;
            miss++;
        }

        printf("Frames: ");
        for(k = 0; k < f; k++) {
            if(frames[k] != -1) printf("%d ", frames[k]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("Total Hits: %d\nTotal Misses: %d\n", hit, miss);
    return 0;
}
