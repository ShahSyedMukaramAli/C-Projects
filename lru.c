#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for(i = 1; i < n; i++) {
        if(time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[100], frames[10], time[10], n, f, count = 0, hit = 0, miss = 0;
    int i, j, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                count++;
                time[j] = count;
                hit++;
                found = 1;
                break;
            }
        }
        if(!found) {
            if(miss < f) {
                frames[miss] = pages[i];
                count++;
                time[miss] = count;
                miss++;
            } else {
                pos = findLRU(time, f);
                frames[pos] = pages[i];
                count++;
                time[pos] = count;
            }
        }

        printf("Frames: ");
        for(j = 0; j < f; j++) {
            if(frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("Total Hits: %d\nTotal Misses: %d\n", hit, n - hit);
    return 0;
}
