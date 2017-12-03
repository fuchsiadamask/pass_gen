#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char fav_upper[] = "ACEFGIJPQRSUVWXZ";
const char lower[] = "abcdefghijklmnopqrstuvwxyz";
const char fav_lower[] = "abcefghijkpqrstuvwxz";
const char digits[] = "1234567890";
const char fav_digits[] = "3578";
const char symbols[] = "(){}[]~!@#$%^&*-_=+,.?'\";:";
const char fav_symbols[] = "~!^&*-_=+.:";

// - 1 to not reach null terminator of above strings:
const char upper_size = sizeof(upper) / sizeof(char) - 1;
const char fav_upper_size = sizeof(fav_upper) / sizeof(char) - 1;
const char lower_size = sizeof(lower) / sizeof(char) - 1;
const char fav_lower_size = sizeof(fav_lower) / sizeof(char) - 1;
const char digits_size = sizeof(digits) / sizeof(char) - 1;
const char fav_digits_size = sizeof(fav_digits) / sizeof(char) - 1;
const char symbols_size = sizeof(symbols) / sizeof(char) - 1;
const char fav_symbols_size = sizeof(fav_symbols) / sizeof(char) - 1;

const char *all[][2] = {{upper, &upper_size},
                        {fav_upper, &fav_upper_size},
                        {lower, &lower_size},
                        {fav_lower, &fav_lower_size},
                        {digits, &digits_size},
                        {fav_digits, &fav_digits_size},
                        {digits, &digits_size},
                        {fav_digits, &fav_digits_size},
                        {symbols, &symbols_size},
                        {symbols, &symbols_size},
                        {fav_symbols, &fav_symbols_size},
                        {fav_symbols, &fav_symbols_size}};

const char all_size = sizeof(all) / sizeof(all[0]);

char *generate_password(unsigned int length)
{
    char *password = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        unsigned int curr_set = rand() % all_size;
        unsigned int curr_sym = rand() % all[curr_set][1][0];

        password[i] = all[curr_set][0][curr_sym];
    }

    password[length] = '\0';

    return password;
}

int main()
{
    srand(time(0));

    unsigned int len;

    printf("Password length: ");
    scanf("%d", &len);

    printf("\nPress [Enter] to generate new password, [Space] to exit.\n\n");

    char g = '\r';

    do
    {
        switch (g)
        {
        case '\r':
            printf("%s\n", generate_password(len));

            g = getch();

            break;

        case ' ':
            break;

        default:
            g = getch();
        }

    } while (g != ' ');

    return 0;
}