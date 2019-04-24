/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libapi_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:48:48 by gfielder          #+#    #+#             */
/*   Updated: 2019/04/23 19:49:11 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ls.h"

t_file		*ft_get_file(const char *path, char *ftls_options)
{
	t_ls_options	options;
	t_file			*f;
	char			*filename;

	ftls_get_options(&options, (ftls_options ? ftls_options : ""));
	filename = ft_basename(path);
	f = ftls_new_file(path, filename, &options);
	free(filename);
	return (f);
}
