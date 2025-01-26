/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:59:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:53:24 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calcule la longueur d'une chaîne de caractères
 * 
 * Cette fonction compte le nombre de caractères dans une chaîne jusqu'au
 * caractère nul de terminaison.
 * 
 * @param s Pointeur vers la chaîne à mesurer
 * @return Nombre de caractères dans la chaîne
 * 
 * @note Utilise size_t pour gérer correctement les grandes chaînes
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
