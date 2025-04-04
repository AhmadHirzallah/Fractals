/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:53:04 by ahirzall          #+#    #+#             */
/*   Updated: 2025/03/24 20:53:44 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to convert a string to lowercase
char	*str_to_lower(const char *str)
{
	size_t	length;
	char	*lower_str;
	size_t	i;

	length = ft_strlen(str);
	lower_str = (char *)malloc((length + 1) * sizeof(char));
	if (lower_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		lower_str[i] = ft_tolower((unsigned char)str[i]);
		i++;
	}
	lower_str[i] = '\0';
	return (lower_str);
}
