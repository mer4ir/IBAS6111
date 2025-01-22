#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LENGTH 100
#define MAX_MORSE_LENGTH 10

struct morse {
    const char* code;
    char letter;
};

struct morse alphabet[] = {
    {".-", 'А'}, {"-...", 'Б'}, {".--", 'В'}, {"--.", 'Г'},
    {"-..", 'Д'}, {".", 'Е'}, {"...-", 'Ж'}, {"--..", 'З'},
    {"..", 'И'}, {".---", 'Й'}, {"-.-", 'К'}, {".-..", 'Л'},
    {"--", 'М'}, {"-.", 'Н'}, {"---", 'О'}, {".--.", 'П'},
    {".-.", 'Р'}, {"...", 'С'}, {"-", 'Т'}, {"..-", 'У'},
    {"..-.", 'Ф'}, {"....", 'Х'}, {"-.-.", 'Ц'}, {"---.", 'Ч'},
    {"----", 'Ш'}, {"--.-", 'Щ'}, {"--.--", 'Ъ'}, {"-.--", 'Ы'},
    {"-..-", 'Ь'}, {"..-..", 'Э'}, {"..--", 'Ю'}, {".-.-", 'Я'},
    {NULL, '\0'}
};

int check(const char* text) {
    for (int i = 0; text[i]; i++) {
        if (text[i] != '.' && text[i] != '-' && text[i] != ' ')
            return 0;
    }
    return 1;
}

char findletter(const char* morse) {
    for (int i = 0; alphabet[i].code != NULL; i++) {
        if (strcmp(alphabet[i].code, morse) == 0) {
            return alphabet[i].letter;
        }
    }
    return '\0';
}

void morse2text(const char* morsetext) {
    if (!check(morsetext)) {
        printf("Неверный формат входных данных\n");
        return;
    }

    char result[MAX_LENGTH] = "";
    char curr[MAX_MORSE_LENGTH] = "";
    int pos = 0;
    int spacecount = 0;


    for (int i = 0; morsetext[i]; i++) {
        if (morsetext[i] == ' ') {
            spacecount++;
            if (pos > 0) {
                curr[pos] = '\0';
                char letter = findletter(curr);
                if (letter == '\0') {
                    printf("Неизвестный код Морзе '%s'\n", curr);
                    return;
                }
                char temp[2];
                temp[0] = letter;
                temp[1] = '\0';
                strcat(result, temp);
                pos = 0;
            }
            if (spacecount >= 2) {
                strcat(result, " ");
                spacecount = 0;
            }
        }
        else {
            spacecount = 0;
            curr[pos] = morsetext[i];
            pos++;
            if (pos >= MAX_MORSE_LENGTH - 1) {
                printf("Слишком длинный код Морзе\n");
                return;
            }
        }
    }
    if (pos > 0) {
        curr[pos] = '\0';
        char letter = findletter(curr);
        if (letter == '\0') {
            printf("Неизвестный код Морзе '%s'\n", curr);
            return;
        }
        char temp_str[2];
        temp_str[0] = letter;
        temp_str[1] = '\0';
        strcat(result, temp_str);
    }
    printf("%s\n", result);
}

int main() {
    setlocale(LC_ALL, "");
    char choice;
    char morse_text[MAX_LENGTH];
    do {
        printf("Введите текст в формате азбуки Морзе: ");
        gets_s(morse_text, MAX_LENGTH);
        morse2text(morse_text);

        printf("\nХотите ввести новый текст? (y/n): ");
        scanf("%c", &choice);
        while (getchar() != '\n');
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
