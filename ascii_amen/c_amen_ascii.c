#include <stdio.h>
#include <unistd.h> // For usleep()

// ANSI Escape Codes for Vibrant Styling
#define BOLD_CYAN "\x1b[1;36m"
#define RESET     "\x1b[0m"

// Function to print text with a smooth typewriter typing effect
void print_typewriter(const char *str, unsigned int delay_us) {
    while (*str) {
        putchar(*str++);
        fflush(stdout); // Forces the buffer to output immediately
        usleep(delay_us); // Controls the speed of the animation
    }
}

int main(void) 
{
    // Clear the terminal screen for a clean presentation
    printf("\033[H\033[J");

    // Turn on Bold Cyan color
    printf(BOLD_CYAN);

    // Multi-line ASCII art string (Clean & Readable)
    const char *amen_art = 
        "    /\\    \n"
        "   /  \\   \n"
        "  / /\\ \\  \n"
        " / ____ \\ \n"
        "/_/    \\_\\\n\n"
        " |\\    /| \n"
        " | \\  / | \n"
        " |  \\/  | \n"
        " | |  | | \n"
        " |_|  |_| \n\n"
        "  ______  \n"
        " |  ____| \n"
        " | |__    \n"
        " |  __|   \n"
        " | |____  \n"
        " |______| \n\n"
        "  _   _   \n"
        " | \\ | |  \n"
        " |  \\| |  \n"
        " | |\\  |  \n"
        " |_| \\_|  \n\n";

    // Play the typewriter animation (12,000 microseconds = 12ms per character)
    print_typewriter(amen_art, 12000);

    // Reset terminal colors back to default
    printf(RESET);

    return 0;
}