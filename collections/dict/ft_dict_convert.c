/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 02:07:01 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/30 02:24:08 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int	to_ntarr_rec(char **arr, int *len, t_dict_ent *ent)
{
	int		ret;

	ret = 0;
	if (!ent)
		return (0);
	ret += to_ntarr_rec(arr, len, ent->left);
	ft_asprintf(arr + *len, "%s=%s", ent->key, ent->value);
	(*len)++;
	ret += 1 + to_ntarr_rec(arr, len, ent->right);
	return (ret);
}

char		**ft_dict_to_ntarr(t_dict *dict)
{
	int		size;
	char	**ret;

	if (!dict)
		return (NULL);
	size = ft_dict_count_entries(dict);
	ret = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	size = 0;
	to_ntarr_rec(ret, &size, dict->head);
	return (ret);
}
