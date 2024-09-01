/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:10:28 by user              #+#    #+#             */
/*   Updated: 2024/09/01 17:27:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int process_input(int argc, char **argv, char **input_str)
{
    int i;
    char *temp;

    *input_str = ft_strdup(argv[1]);
    if (!*input_str)
        return (-1);
    i = 2;
    while (i < argc)
    {
        temp = ft_strjoined(*input_str, argv[i]);
        if (!temp)
        {
            free(*input_str);
            return (-1);
        }
        *input_str = temp;
        i++;
    }
    return (0);
}

static int validate_and_split(char *input_str, char ***numbers)
{
    if (!ft_is_valid_input(input_str))
    {
        free(input_str);
        return (-1);
    }
    *numbers = ft_split(input_str, ' ');
    free(input_str);
    if (!*numbers)
        return (-1);
    if (!ft_split_input_check(*numbers))
    {
        ft_free_split(*numbers);
        return (-1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    char *input_str;
    char **numbers;
    int size;
    int result;

    if (argc < 2)
        return (-1);
    if (process_input(argc, argv, &input_str) == -1)
        return (-1);
    if (validate_and_split(input_str, &numbers) == -1)
        return (-1);
    size = ft_count_number(numbers);
    result = ft_push_swap(numbers, size);
    ft_free_split(numbers);
    return (result);
}


// int main(int argc, char **argv)
// {
//     char *input_str;
//     char **numbers;
//     int i;
//     int size;
//     int result;
//     char *temp;

//     if (argc < 2)
//         return (-1);

//     input_str = ft_strdup(argv[1]);
//     if (!input_str)
//         return (-1);

//     i = 2;
//     while (i < argc)
//     {
//         temp = ft_strjoined(input_str, argv[i]);
//         if (!temp)
//         {
//             free(input_str);
//             return (-1);
//         }
//         input_str = temp;  // Ne pas libérer input_str ici, car ft_strjoined s'en charge
//         i++;
//     }

//     if (!ft_is_valid_input(input_str))
//     {
//         free(input_str);
//         return (-1);
//     }

//     numbers = ft_split(input_str, ' ');
//     free(input_str);  // Cette libération est nécessaire
//     if (!numbers)
//         return (-1);

//     if (!ft_split_input_check(numbers))
//     {
//         ft_free_split(numbers);
//         return (-1);
//     }

//     size = ft_count_number(numbers);
//     result = ft_push_swap(numbers, size);

//     ft_free_split(numbers);
//     return (result);
// }

// void test_parsing(int argc, char **argv)
// {
//     char *input_str = NULL;
//     char **numbers = NULL;
//     int size = 0;
//     int i = 1;

//     if (argc < 2)
//     {
//         printf("Usage: %s <number1> <number2> ...\n", argv[0]);
//         return;
//     }
//     input_str = strdup(argv[1]);
//     while (++i < argc)
//     {
//         char *temp = ft_strjoined(input_str, argv[i]);
//         if (!temp)
//         {
//             printf("Error: ft_strjoined failed\n");
//             free(input_str);
//             return;
//         }
//         input_str = temp;
//     }
//     printf("Joined input: %s\n", input_str);
//     if (!ft_is_valid_input(input_str))
//     {
//         printf("Error: Invalid input\n");
//         free(input_str);
//         return;
//     }
//     printf("Input is valid\n");
//     numbers = ft_split(input_str, ' ');
//     if (!numbers)
//     {
//         printf("Error: ft_split failed\n");
//         free(input_str);
//         return;
//     }
//     if (!ft_split_input_check(numbers))
//     {
//         printf("Error: Split input check failed\n");
//         free(input_str);
//         ft_free_split(numbers);
//         return;
//     }
//     printf("Split input check passed\n");
//     size = ft_count_number(numbers);
//     printf("Number of integers: %d\n", size);
//     printf("Parsed numbers: ");
//     i = 0;
//     while (numbers[i])
//     {
//         printf("%s ", numbers[i]);
//         i++;
//     }
//     printf("\n");
//     free(input_str);
//     ft_free_split(numbers);
// }

// int main(int argc, char **argv)
// {
//     test_parsing(argc, argv);
//     return 0;
// }

