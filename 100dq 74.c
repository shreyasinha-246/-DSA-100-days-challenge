//Problem Statement.Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.Input Format.First line contains an integer n representing number of votes.Second line contains n space-separated strings representing candidate names.Output Format.Print the name of the winning candidate followed by the number of votes received.Sample Input13.john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john.Sample Output.john 4.Explanation.Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner

#include <stdio.h>
#include <string.h>

int main() {
    int n, count[1000] = {0};
    char names[1000][100], winner[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int unique = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < unique; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            unique++;
        }
    }

    int maxVotes = 0;

    for (int i = 0; i < n; i++) {
        int votes = 0;

        for (int j = 0; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                votes++;
            }
        }

        if (votes > maxVotes ||
            (votes == maxVotes && strcmp(names[i], winner) < 0)) {
            maxVotes = votes;
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}

