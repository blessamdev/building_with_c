#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GREEN  "\033[1;32m"
#define DIM    "\033[2;32m"
#define CYAN   "\033[1;36m"
#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"

#define PASSWORD     "blessam"
#define MAX_ATTEMPTS 3

void delay(int ms) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);
}

void type(const char *text, int speed) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        delay(speed);
    }
}

void loading(const char *label) {
    int i;

    printf(CYAN "%s " RESET "[", label);
    for (i = 0; i < 20; i++) {
        printf(GREEN "#" RESET);
        fflush(stdout);
        delay(50);
    }
    printf("] " GREEN "OK\n" RESET);
}

/* fake memory dump for that "hacking" look */
void memory_dump(int lines) {
    int i;
    int j;

    for (i = 0; i < lines; i++) {
        printf(DIM "0x%04X  ", rand() % 0xFFFF);
        for (j = 0; j < 8; j++) {
            printf("%02X ", rand() % 256);
        }
        printf("\n" RESET);
        fflush(stdout);
        delay(70);
    }
}

/* skill bar: percent from 0 to 100 */
void skill_bar(const char *label, int percent) {
    int filled = percent / 5;   /* 20 slots total */
    int i;

    printf(CYAN "[+] %-14s" RESET "[", label);
    for (i = 0; i < 20; i++) {
        if (i < filled) printf(GREEN "#" RESET);
        else            printf(DIM "." RESET);
        fflush(stdout);
        delay(40);
    }
    printf("] %3d%%\n", percent);
}

int login(void) {
    char input[50];
    int attempt;

    for (attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf(YELLOW "> ENTER PASSWORD: " RESET);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';   /* remove the newline */

        if (strcmp(input, PASSWORD) == 0) {
            return 1;
        }
        printf(RED "> ACCESS DENIED (%d/%d)\n" RESET, attempt, MAX_ATTEMPTS);
    }
    return 0;
}

int main() {
    char name[]     = "Blessam";
    char language[] = "C Programming";
    char status[]   = "Developer in Progress";
    char mission[]  = "Build real-world projects";

    system("");            /* enables colors on Windows */
    srand(time(NULL));     /* random seed for the memory dump */

    printf(GREEN);
    type("> BOOTING SECURE TERMINAL...\n", 25);
    printf(RESET);
    memory_dump(6);

    printf("\n");
    if (!login()) {
        printf(RED "\n> INTRUDER DETECTED. SYSTEM LOCKED.\n" RESET);
        return 1;
    }

    printf(GREEN "\n> AUTHENTICATION SUCCESSFUL\n\n" RESET);
    loading("> Decrypting profile ");
    loading("> Loading skills     ");

    time_t now = time(NULL);
    printf(DIM "\n> SESSION START: %s" RESET, ctime(&now));

    printf(GREEN "\n+--------------------------------------+\n");
    printf("|" RESET "        " RED "[ DEVELOPER PROFILE ]" RESET "         " GREEN "|\n");
    printf("+--------------------------------------+\n\n" RESET);

    printf(CYAN "[+] NAME     : " RESET); type(name, 40);     printf("\n");
    printf(CYAN "[+] LANGUAGE : " RESET); type(language, 40); printf("\n");
    printf(CYAN "[+] STATUS   : " RESET); type(status, 40);   printf("\n");
    printf(CYAN "[+] MISSION  : " RESET); type(mission, 40);  printf("\n\n");

    printf(GREEN "---------- SKILL PROGRESS ----------\n" RESET);
    skill_bar("C Programming", 40);
    skill_bar("Logic", 50);
    skill_bar("Problem Solving", 45);

    printf(GREEN "\n> SESSION ACTIVE. KEEP BUILDING_\n" RESET);
    return 0;
}