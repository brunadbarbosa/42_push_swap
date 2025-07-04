/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.5-split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:54:08 by brmaria-          #+#    #+#             */
/*   Updated: 2025/07/04 17:32:01 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	size_t			count;
	char			*d;
	int				i;

	count = 0;
	i = 0;
	while (s[i])
		i++;
	d = malloc((i + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		d[count] = s[count];
		count++;
	}
	d[count] = '\0';
	return (d);
}

int	ft_word_count(const char *s1, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (c == '\0')
		return (1);
	while (s1[i])
	{
		if (s1[i] != c && (i == 0 || s1[i -1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **split, int i, char *str)
{
	if (!str)
	{
		while (i >= 0)
			free(split[i--]);
		free(split);
	}
}

char	*ft_fill(int start, const char *s, int count)
{
	char	*str;
	int		i;

	str = malloc((count + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < count && s[start - count + i])
	{
		str[i] = s[start - count + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i[3];
	char	**split;

	split = ft_calloc((ft_word_count((char *)s, c) + 2), sizeof(char *));
	if (!split)
		return (NULL);
	split[0] = ft_strdup("./push_swap");
	i[1] = 0;
	i[0] = 0;
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		if (!s[i[0]])
			break ;
		i[2] = 0;
		while (s[i[0]] != c && s[i[0]])
		{
			i[2]++;
			i[0]++;
		}
		split[++i[1]] = ft_fill(i[0], s, i[2]);
		ft_free(split, i[1], split[i[1]]);
	}
	return (split);
}
