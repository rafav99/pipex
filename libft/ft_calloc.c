/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaldes- <rvaldes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:26:14 by rvaldes-          #+#    #+#             */
/*   Updated: 2023/04/04 19:44:24 by rvaldes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
    
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p; 

	p = malloc (nmemb * size);
	if (p == 0)
		return (p);
	ft_bzero (p, nmemb * size);
	return (p);
}
