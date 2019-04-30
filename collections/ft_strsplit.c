/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:58:25 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/30 00:44:58 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *str, char c, char *groupers)
{
	int		i;
	int		count;
	int		idx;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		idx = ft_strchr_idx(groupers, str[i]);
		if (str[i] && idx >= 0 && ((idx & 1) == 0))
		{
			count++;
			while (str[++i] && (str[i] != groupers[idx + 1] || !(i++)))
				;
		}
		else if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	strsplit_fill(char **ret, char const *str, char c, char *groupers)
{
	int		i;
	int		j;
	int		idx;

	i = 0;
	j = -1;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		idx = ft_strchr_idx(groupers, str[i]);
		if (str[i] && idx >= 0 && ((idx & 1) == 0))
		{
			ret[++j] = ft_strdup_to(str + (++i), groupers[idx + 1]);
			i += ft_strlen(ret[j]);
			if (str[i] == groupers[idx + 1])
				i++;
		}
		else if (str[i])
		{
			ret[++j] = ft_strdup_to(str + i, c);
			i += ft_strlen(ret[j]);
		}
	}
}

char		**ft_strsplit_grouping(char const *s, char c, char *groupers)
{
	char	**ret;
	int		word_count;

	if (!s || !groupers)
		return (NULL);
	word_count = count_words(s, c, groupers);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	strsplit_fill(ret, s, c, groupers);
	ret[word_count] = NULL;
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	return (ft_strsplit_grouping(s, c, ""));
}
