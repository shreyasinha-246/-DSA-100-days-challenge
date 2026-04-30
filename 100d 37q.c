#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int pq[100], size = 0;

    while (n--) {
        char op[10];
        scanf("%s", op);

        // INSERT
        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            pq[size++] = x;
        }

        // DELETE
        else if (op[0] == 'd') {
            if (size == 0) {
                printf("-1\n");
                continue;
            }

            int min = 0;
            for (int i = 1; i < size; i++) {
                if (pq[i] < pq[min])
                    min = i;
            }

            printf("%d\n", pq[min]);

            // Shift elements
            for (int i = min; i < size - 1; i++) {
                pq[i] = pq[i + 1];
            }
            size--;
        }

        // PEEK
        else if (op[0] == 'p') {
            if (size == 0) {
                printf("-1\n");
                continue;
            }

            int min = 0;
            for (int i = 1; i < size; i++) {
                if (pq[i] < pq[min])
                    min = i;
            }

            printf("%d\n", pq[min]);
        }
    }

    return 0;
}