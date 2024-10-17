#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAXRANDOMVALUE 3
#define maxprevious 400
int arr[4][4] = { 0 }, c[4], score = 0,highscore = 0, count = 0,ch = 0,len=0,t=0; 

// Function to find the count of digits
int findlength(int n)
{

    if (n == 0) {

        return len;
    }
    else {
        len++;
        findlength(n/10);
    }
}

// Function to print the game board
void output()
{
     printf("\n\t\t\t~~~~~~~~~~~~~~~2048~~~~~~~~~~~~~~\n"); 
     printf("\t\t\t---------------------------------\n");
     int len1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                printf("\t\t\t|");
            }
            if (arr[i][j] != 0) {
                len1 = findlength(arr[i][j]);

                for (int k = 0; k < 4 - len1; k++) {
                    printf(" ");
                }
                printf("%d", arr[i][j]);
                for (int k = 0; k < 4 - len1; k++) {
                    printf(" ");
                }
                for (int k = 0; k < len1 - 1; k++) {
                    printf(" ");
                }
                printf("|");
            }
            else {
                for (int k = 0; k < 7; k++) {
                    printf(" ");
                }
                printf("|");
            }
            len = 0;
        }
        if (i != 3) {
            printf("\n");
            printf("\t\t\t---------------------------------\n");
        }
    }
     printf("\n\t\t\t---------------------------------\n");
     printf("\t\t\tYOUR SCORE=%d\n\t\t\t", score);
    if (score < highscore) {
        printf("HIGH SCORE=%d\t\t\t\n", highscore);
    }
    else {
        highscore = score;
        printf("HIGH SCORE=%d\t\t\t\n", highscore);
    }
    printf("\t\t\tPREVIOUS=> P\t\t\t\n");
    printf("\t\t\tRESTART=> R\t\t\t\n");
    printf("\t\t\tEXIT=> U\t\t\t\n");
    printf("\t\t\tENTER YOUR CHOISE => W(UP),S(DOWN),A(LEFT),D(RIGHT)\n\t\t\t");
}


// Function to shift values in the array
void shiftvalue(int k)
{
    if (k == 3) {
        return;
    }
    for (int i = k; i < 4; i++) {
        if (c[i] != 0) {
            shiftvalue(i + 1);
            for (; i < 4; i++) {
                if (c[i + 1] != 0) {
                    break;
                }
                c[i + 1] = c[i];
                c[i] = 0;
            }
        }
    }
}


// Function to add  random number to array
void randomadd()
{
    int no;
    srand(time(NULL));
    int i,j;
    do {
        i = (rand()) % (MAXRANDOMVALUE + 1);
        j = (rand()) % (MAXRANDOMVALUE + 1);
    } while (arr[i][j] != 0);
    no = 2*((rand()%10)+1);
    if (no == 3 || no == 2) {
        arr[i][j] = 4;
    }
    else {
        arr[i][j] = 2;
    }
}


// Function to update the array after shifting  values
void updatearr()
{
    for (int i = 3; i > 0; i--) {
        if (c[i] == c[i - 1]) {
            c[i] += c[i - 1];
            score = score + c[i];
            if (score > highscore) {
            }
            t = 1;
            c[i - 1] = 0;
        }
        else if (c[i - 1] == 0 && c[i] != 0) {
            c[i - 1] = c[i];
            c[i] = 0;
            t = 1;
        }
        else if (c[i] == 0) {
            t = 1;
        }
    }
    shiftvalue(0);
}


// Function to create store history
void createhis(int*** pt)
{
    
    FILE* ptr;
    ptr = fopen("HISTORY.txt", "a");
    fprintf(ptr, "%d ", score);
    fclose(ptr);

    if (count == maxprevious + 1) {
        for (int i = maxprevious; i > 0; i--) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    pt[i][j][k] = pt[i - 1][j][k];
                }
            }
        }
        count = maxprevious;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            pt[maxprevious - count][i][j] = arr[i][j];
        }
    }
}

// Function to reset the game
void resetgame()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    system("clear || cls");
    score = 0;
    randomadd();
}

// Function to update the array of last move
void updatearrtoprev(int*** p)
{
    int data;
    if (count == 0) {
        printf("\nFURTHER NO MORE PREVIOUS POSSIBLE");
        return;
    }
    FILE* ptr = fopen("HISTORY.txt", "r+");
    for (int i = 0; i < count; i++) {
        fscanf(ptr, "%d ", &data);
    }
    score = data;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = p[maxprevious - count][i][j];
        }
    }
    count--;
}



int main()
{   
    int i, j, k, n, m, h = 0;
    char move, check,s=8;
    printf("~~~~~~~~~~~~~~~2048~~~~~~~~~~~~~~~~\n");
    printf("WELCOME TO THE GAME 2048\n");
    printf("  CONTROLS:- 'W'(UP),'S'(DOWN),'A'(LEFT),'D'(RIGHT)\n");
    printf("  GO BACKWARD:- 'P'\n");
    printf("  RESTART :- 'R'\n");
    printf("  EXIT:-'U'\n");
    printf("\nPRESS ANY KEY TO START THE GAME______");

    getchar();

    system("clear || cls");
    printf("\n~~~~~~~~~~~~~~~2048~~~~~~~~~~~~~~\n");
    printf("\nLOADING...\n");
    for (int i = 0, j; i < 35; i++) {
        printf("%c", s);
        j = i;
        if (i % 2 != 0 && i < 20) {
            usleep(1000);
        }
    }
    usleep(1000);
    system("clear || cls"); 
    int*** p;
    p = (int***)malloc(sizeof(int*) * (maxprevious + 1));
    for (int i = 0; i < maxprevious + 1; i++) {
        *(p + i) = (int**)malloc(sizeof(int*) * 4);
    }
    for (int i = 0; i < maxprevious + 1; i++) {
        for (int j = 0; j < 4; j++) {
            p[i][j] = (int*)malloc(sizeof(int) * 4);
        }
    }
    createhis(p);
 
    FILE* ptr;
    ptr = fopen("highscore.txt", "r");
    fscanf(ptr, "%d", &highscore);
    fclose(ptr);
    ptr = fopen("HISTORY.txt", "w");
    fclose(ptr);
    randomadd();
    output();
    while (1) {
        if (score > highscore) {

            ptr = fopen("highscore.txt", "w");
            fprintf(ptr, "%d", score);
            fclose(ptr);
        }
        move = getchar();
        while (getchar() != '\n');
         // Clear the input buffer
        if ( move == 'D') {
            count++;
            ch++;
            createhis(p);
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    c[j] = arr[i][j];
                }
                updatearr();
                for (k = 0; k < 4; k++) {
                    arr[i][k] = c[k];
                }
            }
        }
        else if ( move == 'A') {
            count++;
            ch++;
            createhis(p);
            for (i = 0; i < 4; i++) {
                for (j = 3; j >= 0; j--) {
                    c[3 - j] = arr[i][j];
                }
                updatearr();
                for (k = 0; k < 4; k++) {
                    arr[i][3 - k] = c[k];
                }
            }
        }
        else if ( move == 'S') {
            count++;
            ch++;

            createhis(p);
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    c[j] = arr[j][i];
                }
                updatearr();
                for (k = 0; k < 4; k++) {
                    arr[k][i] = c[k];
                }
            }
        }
        else if ( move == 'W') {
            count++;
            ch++;

            createhis(p);
            for (i = 0; i < 4; i++) {
                for (j = 3; j >= 0; j--) {
                    c[3 - j] = arr[j][i];
                }
                updatearr();
                for (k = 0; k < 4; k++) {
                    arr[3 - k][i] = c[k];
                }
            }
        }
        else if ( move == 'P') {

            updatearrtoprev(p);

            t = 8;
        }
        else if (move == 'R') {
            count = 0;
            resetgame();
            output();
            continue;
        }
        else if ( move == 'U') {
            exit(0);
        }
        
        if (t == 1) {
            t = 0;
            system("clear || cls");
            printf("\n%c\n", move);
            randomadd();
            output();
        }
        else if (t == 8) {
            t = 0;
            output();
        }
        else {
            for (m = 0; m < 4; m++) {
                for (n = 3; n > 0; n--) {
                    if (arr[m][n] == arr[m][n - 1] || arr[m][n] == 0 || arr[m][n - 1] == 0) {
                        h = 1;
                        break;
                    }
                    if (arr[n][m] == arr[n - 1][m] || arr[m][n] == 0 || arr[m][n - 1] == 0) {
                        h = 1;
                        break;
                    }
                }
                if (h == 1)
                    break;
            }
            if (h == 1) {
                printf("\n________________INVALID KEY_______________\n");
                h = 0;
            }
            else {
                printf(
                    "\n*************************GAME OVER");
                printf("\nDO YOU WANT TO PLAY MORE?? Y/N??\n");
                check = getchar();
                while (getchar() != '\n')
                    ; 
                switch (check) {
                case 'Y':
                case 'y':
                    resetgame();
                    output();
                    break;
                case 'n':
                case 'N':
                    exit(0);
                }
                continue;
            }
        }
    }
    return 0;
}