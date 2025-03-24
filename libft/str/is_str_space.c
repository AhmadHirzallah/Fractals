/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:09:03 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 22:09:11 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	is_str_space(int chr)
{
	return (chr == ' ' || chr == '\n' || chr == '\t' || chr == '\r'
		|| chr == '\f' || chr == '\v');
}
