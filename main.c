#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User userDetails[MAX_USERS];
int isActive[MAX_USERS] = {0}; // Array to store the active status of each user
int numUsers = 0;

int registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", userDetails[numUsers].username);

    printf("Enter password: ");
    scanf("%s", userDetails[numUsers].password);

    printf("Set isActive flag (1 for true, 0 for false): ");
    scanf("%d", &isActive[numUsers]);

    numUsers++;
    printf("Registration successful.\n");
    return 1;
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, userDetails[i].username) == 0 &&
            strcmp(password, userDetails[i].password) == 0) {
            if (isActive[i]) { // Check if the user is active
                printf("Login successful.\n");
                return 1;
            } else {
                printf("User is not active.\n");
                return 0;
            }
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;

    do {
        printf("Enter 1 to Register:\n");
        printf("Enter 2 to Login:\n");
        printf("Enter 3 to Exit:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice);

    return 0;
}