/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** toto: Description
*/

#include <stdlib.h>
#include <stdio.h>
#include "bistromatic.h"

char *alloc(int size)
{
    char *result = malloc(sizeof(char) * size);

    result = my_memset(result, '0', size);
    result[size + 1] = '\0';
    return (result);
}

int compute_carry(int tmp)
{
    int carry = 0;

    if (tmp > 9)
        for (; tmp > 9; carry++)
            tmp -= 10;
    return (carry);
}

// 24691 75315 = 1859602665 => 01748492665
char *final_computing(int tmp, char *result, int pos, int *carry)
{
    printf("============\n %d\n", tmp);
    tmp += *carry;
    if (tmp > 9) {
        *carry = compute_carry(tmp);
        result[pos] = tmp % 10 + 48;
    } else {
        result[pos] = tmp + 48;
        *carry = 0;
    }
    return (result);
}

char *compute_columns(char **array, int size, char *result)
{
    int tmp = 0;
    int pos = size;
    int carry = 0;

    for (int j = size - 1; j >= 0; j--) {
        for (int i = 0; array[i] != 0; i++) {
            tmp += array[i][j];
        }
        result = final_computing(tmp, result, pos, &carry);
        pos -= 1;
        tmp = 0;
    }
    return (result);
}

char *mul(char *first, char *second)
{
    int size_first = my_strlen(first);
    int size_second = my_strlen(second);
    int size = size_first + size_second;
    char *result = alloc(size);
    char **array; // Array (change name btw)
    int r; // Current array in array (array)
    unsigned long long tmp; // Valeur tmp de cacul
    int sup = 0; // Ex 7777 777 => Retenue pour le prochain tour
    int carry = 0;
    int size_of_longer = size_first >= size_second ?
            size_first : size_second;

    // Allocates array
    array = malloc(sizeof(char *) * size_of_longer + 1);
    for (int i = 0; i < size_of_longer; i++) {
        array[i] = malloc(sizeof(char) * size + 1);
        array[i][size_of_longer + 1] = '\0';
    }

    // Ca calcul sévère !
    for (int i = size_first - 1; i >= 0; i--, r++) {
        for (int j = size_second - 1; j >= 0; j--) {
            tmp = (first[i] - '0') * (second[j] - '0') + sup;
            sup = 0;
            if (tmp % 10 + carry > 9) {
                array[r][i + j + 1] = (tmp + carry) % 10;
                sup = compute_carry(tmp) + 1;
                carry = 0;
            } else {
                array[r][i + j + 1] = tmp % 10 + carry;
                carry = compute_carry(tmp);
            }
            if (j == 0) {
                array[r][i + j] = tmp / 10;
            }
        }
        carry = 0;
        sup = 0;
    }
    // Show our array
    for (int i = 0; array[i] != 0; i++) {
        for (int j = 0; j < size; j++) {// ALED (condition)
            printf("%c ", array[i][j] + 48);
        }
        printf("\n");
    }
    result = compute_columns(array, size, result);
    my_putstr(result);
    return (result);
}


int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    mul(argv[1], argv[2]);
    return (0);
}
