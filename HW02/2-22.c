#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_CANDIDATES 10
#define USERNAME_LEN 8
#define PASSWORD_LEN 8
#define EMAIL_LEN 30
#define MAX_VOTES 100

typedef struct {
    char username[USERNAME_LEN + 1];
    char password[PASSWORD_LEN + 1];
    char email[EMAIL_LEN + 1];
    int voted; // 0: 未投票, 1: 已投票
} User;

typedef struct {
    int number;
    char name[20];
    int votes;
} Candidate;

User users[MAX_USERS];
int userCount = 0;

Candidate candidates[MAX_CANDIDATES];
int candidateCount = 0;

int validateUsername(char *username) {
    if (strlen(username) != USERNAME_LEN) return 0;
    // Add more validation rules if necessary
    return 1;
}

int validatePassword(char *password) {
    if (strlen(password) < 1 || strlen(password) > PASSWORD_LEN) return 0;
    // Add more validation rules if necessary
    return 1;
}

void addUser(char *username, char *password, char *email) {
    if (!validateUsername(username) || !validatePassword(password)) {
        printf("Add user error\n");
        if (!validateUsername(username)) printf("username error\n");
        if (!validatePassword(password)) printf("password error\n");
        return;
    }
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    strcpy(users[userCount].email, email);
    users[userCount].voted = 0;
    userCount++;
    printf("Add user successful\n");
}

void addCandidate(char *username, char *password, int number, char *name) {
    // Simulate admin login validation
    // For simplicity, skip implementing real admin check
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].number == number || strcmp(candidates[i].name, name) == 0) {
            printf("Candidate data error\n");
            return;
        }
    }
    candidates[candidateCount].number = number;
    strcpy(candidates[candidateCount].name, name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Add candidate successful\n");
}

void vote(char *username, char *password, int number) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].voted) {
                printf("Voting error\n");
                return;
            }
            for (int j = 0; j < candidateCount; j++) {
                if (candidates[j].number == number) {
                    candidates[j].votes++;
                    users[i].voted = 1;
                    printf("Voting successful\n");
                    return;
                }
            }
            printf("Candidate error\n");
            return;
        }
    }
    printf("Login error\n");
}

void query(char *username, char *password) {
    for (int i = 0; i < candidateCount; i++) {
        printf("(%d,%s,%d)", candidates[i].number, candidates[i].name, candidates[i].votes);
        if (i < candidateCount - 1) printf(",");
    }
    printf("\n");
}

int main() {
    char command;
    char username[USERNAME_LEN + 1], password[PASSWORD_LEN + 1], email[EMAIL_LEN + 1];
    int number;
    char name[20];

    while (scanf(" %c", &command) && command != 'E') {
        switch (command) {
            case 'A':
                scanf("%[^,],%[^,],%s", username, password, email);
                addUser(username, password, email);
                break;
            case 'M':
                scanf("%[^,],%[^,],%d,%s", username, password, &number, name);
                addCandidate(username, password, number, name);
                break;
            case 'V':
                scanf("%[^,],%[^,],%d", username, password, &number);
                vote(username, password, number);
                break;
            case 'Q':
                scanf("%[^,],%s", username, password);
                query(username, password);
                break;
        }
    }
    printf("Exit\n");
    return 0;
}
