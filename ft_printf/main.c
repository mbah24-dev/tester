/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:08:45 by mbah              #+#    #+#             */
/*   Updated: 2024/11/23 17:07:28 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// Couleurs ANSI
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

void display_test_result(const char *test_desc, int ret_ft, int ret_printf)
{
    printf(YELLOW BOLD "Test: " RESET "%s\n", test_desc);
    printf(CYAN "ft_printf: " RESET "%d\n", ret_ft);
    printf(GREEN "printf:    " RESET "%d\n", ret_printf);

    if (ret_ft == ret_printf)
        printf(GREEN "-> Test passed!\n" RESET);
    else
        printf(RED "-> Test failed!\n" RESET);
    printf("------------------------------------------------------------\n");
}

int main(void)
{
    int ret_ft, ret_printf;

    printf(BLUE UNDERLINE "\nStarting ft_printf tests:\n" RESET);
    printf("------------------------------------------------------------\n");

    // 1. Simple string test
    printf(BOLD MAGENTA "Running test: Simple string\n" RESET);
    ret_ft = ft_printf("Hello, %s!\n", "world");
    ret_printf = printf("Hello, %s!\n", "world");
    display_test_result("Simple string", ret_ft, ret_printf);

    // 2. Test character
    printf(BOLD MAGENTA "Running test: Single character\n" RESET);
    ret_ft = ft_printf("Character: %c\n", 'A');
    ret_printf = printf("Character: %c\n", 'A');
    display_test_result("Single character", ret_ft, ret_printf);

    // 3. Test integer
    printf(BOLD MAGENTA "Running test: Integer\n" RESET);
    ret_ft = ft_printf("Integer: %d\n", 12345);
    ret_printf = printf("Integer: %d\n", 12345);
    display_test_result("Integer", ret_ft, ret_printf);

    // 4. Test unsigned integer
    printf(BOLD MAGENTA "Running test: Unsigned integer\n" RESET);
    ret_ft = ft_printf("Unsigned: %u\n", 123456789);
    ret_printf = printf("Unsigned: %u\n", 123456789);
    display_test_result("Unsigned integer", ret_ft, ret_printf);

    // 5. Test hexadecimal
    printf(BOLD MAGENTA "Running test: Hexadecimal\n" RESET);
    ret_ft = ft_printf("Hexadecimal: %x\n", 255);
    ret_printf = printf("Hexadecimal: %x\n", 255);
    display_test_result("Hexadecimal", ret_ft, ret_printf);

    // 6. Test percent sign
    printf(BOLD MAGENTA "Running test: Percent sign\n" RESET);
    ret_ft = ft_printf("Percent sign: %%\n");
    ret_printf = printf("Percent sign: %%\n");
    display_test_result("Percent sign", ret_ft, ret_printf);

    // 7. Test pointer
    printf(BOLD MAGENTA "Running test: Pointer\n" RESET);
    int num = 42;
    ret_ft = ft_printf("Pointer: %p\n", &num);
    ret_printf = printf("Pointer: %p\n", &num);
    display_test_result("Pointer", ret_ft, ret_printf);

    // 8. Test negative integer
    printf(BOLD MAGENTA "Running test: Negative integer\n" RESET);
    ret_ft = ft_printf("Negative integer: %d\n", -12345);
    ret_printf = printf("Negative integer: %d\n", -12345);
    display_test_result("Negative integer", ret_ft, ret_printf);

    // 9. Test string with empty input
    printf(BOLD MAGENTA "Running test: Empty string\n" RESET);
    ret_ft = ft_printf("String: %s\n", "");
    ret_printf = printf("String: %s\n", "");
    display_test_result("Empty string", ret_ft, ret_printf);

    // 10. Test large unsigned integer
    printf(BOLD MAGENTA "Running test: Large unsigned integer\n" RESET);
    ret_ft = ft_printf("Large unsigned: %u\n", 4294967);
    ret_printf = printf("Large unsigned: %u\n", 4294967);
    display_test_result("Large unsigned integer", ret_ft, ret_printf);

	int a = 10, b = 20;
	ft_printf("ft_printf : Pointer a: %p\n", &a);
	printf("printf : Pointer a: %p\n", &a);
	ft_printf("ft_printf : Pointer b: %p\n", &b);
	printf("printf : Pointer b: %p\n", &b);

	ft_printf("ft_printf : Null pointer: %p\n", NULL);
	printf("printf : Null pointer: %p\n", NULL);

    printf(BLUE UNDERLINE "All tests completed!\n" RESET);
	return 0;
}
