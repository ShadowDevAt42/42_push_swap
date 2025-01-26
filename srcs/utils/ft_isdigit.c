/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:58:21 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:53:01 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Vérifie si un caractère est un chiffre décimal
 * 
 * Cette fonction vérifie si le caractère passé en paramètre représente
 * un chiffre décimal (0-9) selon la table ASCII.
 * 
 * @param c Caractère à vérifier
 * @return 1 si le caractère est un chiffre, 0 sinon
 * 
 * @details Plutôt que d'utiliser des valeurs ASCII brutes, la fonction
 * utilise les caractères '0' et '9' pour une meilleure lisibilité et
 * portabilité. La comparaison s'effectue sur la plage complète des
 * caractères numériques dans la table ASCII.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
