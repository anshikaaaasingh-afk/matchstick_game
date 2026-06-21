#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_STICKS 21

void clearScreen()
{
    printf("\033[2J\033[H");
}

void waitForEnter()
{
    printf("\nPress ENTER to continue...");
    while (getchar() != '\n')
        ;
    getchar();
}

void playerVsComputer()
{
    int sticks = TOTAL_STICKS;
    int player, computer;

    while (sticks > 1)
    {
        printf("\nMatchsticks left: %d\n", sticks);

        do
        {
            printf("Pick 1-4 sticks: ");
            scanf("%d", &player);
        } while (player < 1 || player > 4 || player >= sticks);

        sticks -= player;

        if (sticks == 1)
        {
            printf("\nComputer is forced to take the last stick.\n");
            printf("You win!\n");
            return;
        }

        do
        {
            computer = rand() % 4 + 1;
        } while (computer >= sticks);

        printf("Computer picked %d stick(s).\n", computer);

        sticks -= computer;

        if (sticks == 1)
        {
            printf("\nYou are forced to take the last stick.\n");
            printf("Computer wins!\n");
            return;
        }
    }
}

void playerVsPlayer()
{
    int sticks = TOTAL_STICKS;
    int move;
    char p1[50], p2[50];

    printf("Player 1 name: ");
    scanf("%49s", p1);

    printf("Player 2 name: ");
    scanf("%49s", p2);

    while (sticks > 1)
    {
        printf("\nMatchsticks left: %d\n", sticks);

        do
        {
            printf("%s pick 1-4 sticks: ", p1);
            scanf("%d", &move);
        } while (move < 1 || move > 4 || move >= sticks);

        sticks -= move;

        if (sticks == 1)
        {
            printf("\n%s wins!\n", p1);
            return;
        }

        printf("\nMatchsticks left: %d\n", sticks);

        do
        {
            printf("%s pick 1-4 sticks: ", p2);
            scanf("%d", &move);
        } while (move < 1 || move > 4 || move >= sticks);

        sticks -= move;

        if (sticks == 1)
        {
            printf("\n%s wins!\n", p2);
            return;
        }
    }
}

void playerVsAI()
{
    int sticks = TOTAL_STICKS;
    int player, ai;

    while (sticks > 1)
    {
        printf("\nMatchsticks left: %d\n", sticks);

        do
        {
            printf("Pick 1-4 sticks: ");
            scanf("%d", &player);
        } while (player < 1 || player > 4 || player >= sticks);

        sticks -= player;

        if (sticks == 1)
        {
            printf("\nAI is forced to take the last stick.\n");
            printf("You win!\n");
            return;
        }

        ai = 5 - player;

        if (ai >= sticks)
            ai = 1;

        printf("AI picked %d stick(s).\n", ai);

        sticks -= ai;

        if (sticks == 1)
        {
            printf("\nYou are forced to take the last stick.\n");
            printf("AI wins!\n");
            return;
        }
    }
}

int main()
{
    int choice;

    srand((unsigned int)time(NULL));

    while (1)
    {
        clearScreen();

        printf("=================================\n");
        printf("     21 MATCHSTICK GAME\n");
        printf("=================================\n\n");

        printf("Rules:\n");
        printf("1. There are 21 matchsticks.\n");
        printf("2. Pick 1 to 4 sticks each turn.\n");
        printf("3. Whoever is forced to take the last stick loses.\n\n");

        printf("1. Player vs Computer\n");
        printf("2. Player vs Player\n");
        printf("3. Player vs AI (Impossible)\n");
        printf("4. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        clearScreen();

        switch (choice)
        {
        case 1:
            playerVsComputer();
            waitForEnter();
            break;

        case 2:
            playerVsPlayer();
            waitForEnter();
            break;

        case 3:
            playerVsAI();
            waitForEnter();
            break;

        case 4:
            printf("Thanks for playing!\n");
            return 0;

        default:
            printf("Invalid choice.\n");
            waitForEnter();
        }
    }

    return 0;
}