typedef struct {
    char ch;
    int count;
} CharCount;

int compare(const void *a, const void *b) {
    return ((CharCount *)b)->count - ((CharCount *)a)->count;
}

char* longestDiverseString(int a, int b, int c) {
    CharCount counts[3] = {{'a', a}, {'b', b}, {'c', c}};
    char *ans = (char *)malloc((a + b + c + 1) * sizeof(char));
    int index = 0;

    while (1) {
        qsort(counts, 3, sizeof(CharCount), compare);
        int added = 0;

        for (int i = 0; i < 3; i++) {
            if (counts[i].count == 0) continue;
            if (index >= 2 && ans[index - 1] == counts[i].ch && ans[index - 2] == counts[i].ch) {
                continue;
            }
            ans[index++] = counts[i].ch;
            counts[i].count--;
            added = 1;
            break;
        }

        if (!added) break;
    }

    ans[index] = '\0';
    return ans;
}
