//Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

int compare(const void *a, const void *b) {
    struct Car *x = (struct Car *)a;
    struct Car *y = (struct Car *)b;
    return y->position - x->position;
}

int main() {
    int n, target;
    scanf("%d %d", &target, &n);

    struct Car cars[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].position);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    for (int i = 0; i < n; i++)
        cars[i].speed = cars[i].speed;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (cars[i].position < cars[j].position) {
                struct Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }

    double maxTime = 0.0;
    int fleets = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}

