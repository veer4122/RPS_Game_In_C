#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// writing this comment just to see how git works

void instrcutions(int);

void chosenThingPrint(char[], char[], int, int);

void table(char[], char[], int);
void printWinner(char[], char[], int, int, int);
void scoreBoard(int, int);

void lose(char[], char[], int);
void won(char[], char[], int);
void draw();

void symInRow(char, int);

void chosenThingPrint(char player1Name[], char player2Name[], int player1, int player2)
{
    char rock[20][40] = {{"|                   "},
                         {"|                   "},
                         {"|    _______        "},
                         {"|---'   ____)       "},
                         {"|      (_____)      "},
                         {"|      (_____)      "},
                         {"|      (____)       "},
                         {"|---.__(___)        "},
                         {"|                   "}},
         paper[20][40] = {{"|                   "},
                          {"|                   "},
                          {"|    ________       "},
                          {"|---'    ____)____  "},
                          {"|           ______) "},
                          {"|           ______) "},
                          {"|         _______)  "},
                          {"|---.__________)    "},
                          {"|                   "}},
         scissor[20][40] = {{"|                   "},
                            {"|                   "},
                            {"|    ________       "},
                            {"|---'    ____)____  "},
                            {"|           ______) "},
                            {"|       __________) "},
                            {"|      (____)       "},
                            {"|---.__(___)        "},
                            {"|                   "}};

    char rock2[20][40] = {{"                   |"},
                          {"                   |"},
                          {"        _______    |"},
                          {"       (____   '---|"},
                          {"      (_____)      |"},
                          {"      (_____)      |"},
                          {"       (____)      |"},
                          {"        (___)__.---|"},
                          {"                   |"}},
         paper2[20][40] = {{"                   |"},
                           {"                   |"},
                           {"       ________    |"},
                           {"  ____(____    '---|"},
                           {" (______           |"},
                           {" (_______          |"},
                           {"  (_______         |"},
                           {"    (__________.---|"},
                           {"                   |"}},
         scissor2[20][40] = {{"                   |"},
                             {"                   |"},
                             {"        _______    |"},
                             {"  _____(____   '---|"},
                             {" (_______          |"},
                             {" (__________       |"},
                             {"       (____)      |"},
                             {"        (___)__.---|"},
                             {"                   |"}};

    printf("                    ");
    symInRow('_', 40);
    printf("\n\n                        %s                %s\n", player1Name, player2Name);
    for (int i = 0; i < 9; i++)
    {
        if (player1 == 1)
            printf("                    %s", rock[i]);
        if (player1 == 2)
            printf("                    %s", paper[i]);
        if (player1 == 3)
            printf("                    %s", scissor[i]);

        if (player2 == 1)
            printf("%s", rock2[i]);
        if (player2 == 2)
            printf("%s", paper2[i]);
        if (player2 == 3)
            printf("%s", scissor2[i]);

        printf("\n");
    }
    printf("                    *");
    symInRow('-', 38);
    printf("*\n");
}
void symInRow(char sym, int lenOfRow)
{
    for (int i = 0; i < lenOfRow; i++)
    {
        printf("%c", sym);
    }
}
void won(char n1[], char n2[], int isTwo)
{
    printf("                    You won %s ", n1);
    if (isTwo)
        printf("         You lose %s \n\n", n2);
    else
        printf("           I lose XI \n\n");
}

void lose(char n1[], char n2[], int isTwo)
{
    printf("                    You lose %s ", n1);
    if (isTwo)
        printf("         You won %s \n\n ", n2);
    else
        printf("           I won XD \n\n");
}

void draw()
{
    printf("                              !!!!!!!!!Draw!!!!!!!!!\n\n");
}

void printWinner(char player1Name[], char player2Name[], int player1, int player2, int two)
{
    if (player1 == player2)
    {
        draw();
        scoreBoard(1, 1);
        return;
    }

    int Rock = 1, Paper = 2, Scssior = 3;

    if (player1 == Rock)
    {
        if (player2 == Paper)
        {
            lose(player1Name, player2Name, two);
            scoreBoard(0, 1);
        }
        else
        {
            won(player1Name, player2Name, two);
            scoreBoard(1, 0);
        }
    }

    if (player1 == Paper)
    {
        if (player2 == Scssior)
        {
            lose(player1Name, player2Name, two);
            scoreBoard(0, 1);
        }
        else
        {
            won(player1Name, player2Name, two);
            scoreBoard(1, 0);
        }
    }

    if (player1 == Scssior)
    {
        if (player2 == Rock)
        {
            lose(player1Name, player2Name, two);
            scoreBoard(0, 1);
        }
        else
        {
            won(player1Name, player2Name, two);
            scoreBoard(1, 0);
        }
    }
}

void instrcutions(int is)
{

    printf("Enter '0' to exit And '4' to see the scoreBoard \n");
    if (!is)
    {
        printf("Choose by entering number below : \n");
        printf("  1. Rock \n  2. Paper\n  3. Scissor \n\n");
    }
    else
        printf("Just press press enter\n");
}

char player1Arr[100][10];
char player2Arr[100][10];
int tot1 = 0, tot2 = 0;
int nthMatch = 0;
void scoreBoard(int player1Status, int player2Status)
{
    if (player1Status == player2Status)
    {
        strcpy(player1Arr[nthMatch], "draw");
        strcpy(player2Arr[nthMatch], "draw");
    }
    else if (player1Status)
    {
        tot1++;
        strcpy(player1Arr[nthMatch], "won");
        strcpy(player2Arr[nthMatch], "lose");
    }
    else if (player2Status)
    {
        tot2++;
        strcpy(player1Arr[nthMatch], "lose");
        strcpy(player2Arr[nthMatch], "won");
    }

    nthMatch++;
}
void totalWins()
{
    printf(" ");
    symInRow('_', 11);
    printf("\n|  %d  |  %d  |<==Total Wins\n*", tot1, tot2);
    symInRow('-', 11);
    printf("*\n");
}

void table(char firstEl[], char secondEl[], int isEnd)
{
    int cols = (strlen(firstEl) + strlen(secondEl)) + 5;
    printf(" ");
    symInRow('_', cols);
    printf("\n| %s | %s |\n", firstEl, secondEl);

    printf("|");
    symInRow('-', cols);
    printf("|");
    int spaces1 = strlen(firstEl) + 2, spaces2 = strlen(secondEl) + 2;
    for (int i = 0; i < nthMatch; i++)
    {
        int spacesf1 = (spaces1 - strlen(player1Arr[i])) / 2;
        int spacesf2 = (spaces2 - strlen(player2Arr[i])) / 2;
        // printf("\n| %s | %s |", *dataOfFirstEl, *dataOfSecEl);
        printf("\n|");
        symInRow(' ', spacesf1);
        printf("%s", player1Arr[i]);
        symInRow(' ', spacesf1);

        if ((strlen(player1Arr[i]) % 2) != (spaces1 % 2))
        {
            printf(" ");
        }
        printf("|");

        symInRow(' ', spacesf2);
        printf("%s", player2Arr[i]);
        symInRow(' ', spacesf2);

        if ((strlen(player2Arr[i]) % 2) != (spaces2 % 2))
        {
            printf(" ");
        }
        printf("|");
    }

    printf("\n");
    printf("*");
    symInRow('-', cols);
    printf("*");
    printf("\n");
    totalWins();
    if (isEnd)
    {
        if (tot1 > tot2)
        {
            printf("\n%s won this game\n\n", firstEl);
        }
        else if (tot1 < tot2)
        {
            printf("\n%s won this game\n\n", secondEl);
        }
        else
        {
            printf("\nNo one lost or won Its a draw\n\n");
        }
    }
    else
    {
        if (tot1 > tot2)
        {
            printf("\nLooks like %s is winning the game\n\n", firstEl);
        }
        else if (tot1 < tot2)
        {
            printf("\nLooks like %s is winning the game\n\n", secondEl);
        }
    }
}

int randomNo(int seed)
{
    srand(time(NULL) + seed);
    return (rand() % 3) + 1;
}
int main()
{
    srand(time(NULL));
    int n;
    printf("\nEnter : \n 1. To play alone\n 2. To play with your friend (computer will play for both side)\n");
    scanf("%d", &n);
    int two = 0;
    if (n == 2)
        two = 1;

    char player1Name[15], player2Name[15] = "Sanganak";
    printf("Enter the name player No 1 : \n");

    scanf("%s", player1Name);

    if (two)
    {
        printf("Enter the name player No 2 : \n");
        scanf("%s", player2Name);
    }
    else
        printf("Second player is Sangnak\n\n\n");
    getchar();

    int player1,
        player2, choice;
    char choice1;
    do
    {
        instrcutions(two);

        scanf("%c", &choice1);
        choice = choice1 - '0';
        system("cls"); // To clear the screen
        if (choice == 0)
        {
            continue;
        }
        else if (choice == 4)
        {
            table(player1Name, player2Name, 0);
            getchar();
            continue;
        }
        else if ((choice < 1 || choice > 4) && !two)
        {
            printf("some thing went wrong Did you enter something else then the numbers of instruction\n");
            continue;
        }

        if (two)
        {
            printf("Press enter again");
            getchar();
            player1 = randomNo(rand());
            for (int i = 0; i < 80; i++)
            {
                player1 = randomNo(i);
                chosenThingPrint(player1Name, player2Name, player1, player2);
                system("cls");
                player2 = randomNo(randomNo(time(NULL) + i));
                chosenThingPrint(player1Name, player2Name, player1, player2);
                printf("Wait.....");
                system("cls");
            }
            player2 = (rand() % 3) + 1;
            chosenThingPrint(player1Name, player2Name, player1, player2);
            printWinner(player1Name, player2Name, player1, player2, two);
        }
        else
        {
            for (int i = 0; i < 30; i++)
            {
                player1 = randomNo(i + 5);
                chosenThingPrint(player1Name, player2Name, player1, player2);
                system("cls");
                player2 = randomNo(i + 3);
                chosenThingPrint(player1Name, player2Name, player1, player2);
                printf("Wait.....");
                system("cls");
            }
            player1 = choice;
            chosenThingPrint(player1Name, player2Name, player1, player2);
            printf("\n");
            printWinner(player1Name, player2Name, player1, player2, two);
            getchar();
        }

    } while (choice != 0);
    system("cls");
    table(player1Name, player2Name, 1);
    return 0;
}
