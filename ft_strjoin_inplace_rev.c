/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_inplace_rev.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:18:03 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/09 20:19:22 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_strjoin_inplace_rev(const char *s1, char **s2)
{
	char *r;

	if (s1 == NULL || s2 == NULL || *s2 == NULL)
		return ;
	r = ft_strjoin(s1, *s2);
	if (!r)
		return ;
	free(*s2);
	*s2 = r;
}
