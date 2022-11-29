/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:36:52 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/11/07 01:09:17 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>


int main(void)
{
	char	src[10] = "123456789";

	printf("%s\n", ft_strrchr(src, 0));
	printf("%s\n", strrchr(src, 0));

	// char	*s1 = "Hello";
	// char	*s2 = "Hello";

	// printf("%s\n", ft_strnstr(s1, "", 0));
	// printf("%s\n", strnstr(s1, "", 0));

	// char *result = ft_strtrim(0, " x");
	// if (result == NULL)
	// 	printf("OK\n");
	// free(result);

	// result = ft_strtrim("asd", 0);
	// if (strcmp(result, "asd") == 0)
	// 	printf("OK\n");
	// free(result);

	return (0);
}

// int main(void)
// {
// 	char dest[30]; memset(dest, 0, 30);
// 	char * src = (char *)"AAAAAAAAA";
// 	dest[0] = 'B';

// 	size_t res1 = ft_strlcat(dest, src, 0);
// 	printf("%zu %lu\n", res1, strlen(src));
// 	if (ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");

// 	if (strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");

// 	memset(dest, 0, 30);
// 	if (ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");

// 	if (strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	return (0);
// }

// int main(void)
// {
// 	// void * p = ft_calloc(2, 2);
// 	char e[] = {0, 0, 0, 0};
// 	// /* 1 */ check(!memcmp(p, e, 4));
// 	// /* 2 */ mcheck(p, 4); free(p); showLeaks();

// 	if (ft_calloc(SIZE_MAX, SIZE_MAX) == NULL)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");

// 	if (calloc(SIZE_MAX, SIZE_MAX) == NULL)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	return (0);
// }


// int main(void)
// {
// 	char s[] = "tripouille";

// 	// /* 1 */ check(ft_strchr(s, 't') == s); showLeaks();
// 	// /* 2 */ check(ft_strchr(s, 'l') == s + 7); showLeaks();
// 	// /* 3 */ check(ft_strchr(s, 'z') == 0); showLeaks();
// 	// /* 4 */ check(ft_strchr(s, 0) == s + strlen(s)); showLeaks();

// 	/* 5 */
// 	char *res = ft _strchr(s, 't' + 256);
// 	char *res2 = strchr(s, 't' + 256);
// 	printf("%s\n", res);
// 	printf("%s\n", res2);
// 	if (res == s)
// 		printf("OK");
// 	else
// 		printf("KO");
// 	write(1, "\n", 1);
// 	return (0);
// }
