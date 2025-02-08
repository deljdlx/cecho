#include <stdio.h>
#include <string.h>

const char *color_names[] = {
    "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white",
    "bright_black", "bright_red", "bright_green", "bright_yellow",
    "bright_blue", "bright_magenta", "bright_cyan", "bright_white", NULL
};

const char *color_codes[] = {
    "\033[30m", "\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m",
    "\033[90m", "\033[91m", "\033[92m", "\033[93m",
    "\033[94m", "\033[95m", "\033[96m", "\033[97m"
};

const char *style_names[] = {
    "bold", "underline", "blink", "inverse", "italic", NULL
};

const char *style_codes[] = {
    "\033[1m", "\033[4m", "\033[5m", "\033[7m", "\033[3m"
};

const char *get_code(const char *input, const char **names, const char **codes) {
    for (int i = 0; names[i] != NULL; i++) {
        if (strcmp(input, names[i]) == 0) {
            return codes[i];
        }
    }
    return "\033[0m";
}

void print_colored(const char *color, const char *style, const char *message) {
    const char *color_code = get_code(color, color_names, color_codes);
    const char *style_code = get_code(style, style_names, style_codes);

    printf("%s%s%s\033[0m\n", style_code, color_code, message);
}

int main(int argc, char *argv[]) {
    char color[20] = "white";
    char style[20] = "";
    char message[256] = "";

    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "--color=", 8) == 0) {
            strncpy(color, argv[i] + 8, sizeof(color) - 1);
        } else if (strncmp(argv[i], "--style=", 8) == 0) {
            strncpy(style, argv[i] + 8, sizeof(style) - 1);
        } else {
            strncat(message, argv[i], sizeof(message) - strlen(message) - 1);
            strncat(message, " ", sizeof(message) - strlen(message) - 1);
        }
    }

    if (strlen(message) == 0) {
        printf("Usage: %s --color=<color> --style=<style> <message>\n", argv[0]);
        printf("Colors: black, red, green, yellow, blue, magenta, cyan, white, bright_* (ex: bright_red)\n");
        printf("Styles: bold, underline, blink, inverse, italic\n");
        return 1;
    }

    print_colored(color, style, message);
    return 0;
}
