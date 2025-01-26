/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:58:56 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:53:13 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Écrit une chaîne de caractères sur la sortie standard
 * 
 * Cette fonction affiche une chaîne de caractères sur la sortie standard
 * en utilisant l'appel système write.
 * 
 * @param s Pointeur vers la chaîne à afficher
 * 
 * @details La fonction :
 * 1. Vérifie si la chaîne n'est pas NULL
 * 2. Utilise write avec le descripteur 1 (stdout)
 * 3. Calcule la longueur avec ft_strlen pour l'écriture
 * 
 * @note La fonction retourne silencieusement si s est NULL, évitant
 * ainsi les comportements indéfinis.
 */
void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
