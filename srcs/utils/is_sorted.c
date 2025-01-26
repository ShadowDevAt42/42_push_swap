/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:00:24 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:54:35 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Vérifie si une pile est triée dans l'ordre croissant
 * 
 * @param a Pointeur vers la pile à vérifier
 * @return 1 si la pile est triée, 0 sinon
 * 
 * @details Compare chaque élément avec le suivant pour vérifier
 * l'ordre croissant
 */
int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
