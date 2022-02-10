/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:49 by gwinnink          #+#    #+#             */
/*   Updated: 2021/12/14 13:44:50 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		ret_index;
	int		i;
	void	*null;

	i = 0;
	ret_index = -1;
	null = 0;
	while (str[i])
	{
		if (str[i] == c)
			ret_index = i;
		i++;
	}
	if (!(str[i]) && c == 0)
		return ((char *)&str[i]);
	if (ret_index == -1)
		return (null);
	return ((char *)&str[ret_index]);
}
