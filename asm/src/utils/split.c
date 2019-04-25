/*
** EPITECH PROJECT, 2019
** split.c
** File description:
** str to word tab
*/

#include "asm.h"
#include "op.h"
#include <stdlib.h>

int separator(char c)
{
    if (c == ' ' || c == '\t' || c == SEPARATOR_CHAR)
        return (1);
    return (0);
}

char **putstr_array(char **table, char *buf)
{
    int m;
    int n = 0;
    char *str;

    for (int k = 0; buf[k] != '\0'; k += 1) {
        (str = malloc(sizeof(char) * (1 + my_strlen(buf)))) == NULL?exit(84):0;
        m = 0;
        while (buf[k] != '\0' && buf[k] != '\n' && !separator(buf[k])) {
            str[m] = buf[k];
            k += 1;
            m += 1;
        }
        m?str[m] = '\0':0;
        m?table[n] = str:0;
        m?n += 1:0;
        if (buf[k] == '\0')
            break;
    }
    table[n] = NULL;
    return (table);
}

char **my_str_to_word_tab(char *str)
{
    int j = 0;
    char **table;

    for (int i = 0; str[i] != '\0'; i += 1)
        (!i && !separator(str[i])) || (i && separator(str[i - 1]) &&
        !separator(str[i])) ? j += 1 : 0;
    (table = malloc(sizeof(char *) * (j + 1))) == NULL ? exit(84) : 0;
    return (putstr_array(table, str));
}