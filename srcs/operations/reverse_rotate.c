/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:49:01 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:18:58 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Effectue une rotation inverse sur une pile
 * 
 * Cette fonction déplace le dernier élément d'une pile
 * vers sa première position,
 * en décalant tous les autres éléments d'une position vers le bas.
 * Elle maintient
 * la synchronisation entre les données (data) et leur mapping
 * d'index correspondant.
 * 
 * @param stack Pointeur vers la structure de pile à modifier
 * 
 * @details Le processus se déroule en plusieurs étapes :
 *          1. Sauvegarde temporaire du dernier élément et de son index
 *          2. Décalage de tous les autres éléments d'une position vers le bas
 *          3. Placement de l'élément temporaire au début de la pile
 * 
 * @note    La fonction vérifie d'abord si la pile contient au moins 2 éléments.
 *          Si ce n'est pas le cas, elle retourne sans effectuer d'opération.
 * 
 * @warning Cette fonction suppose que la structure de pile est
 * correctement initialisée
 *          et que les tableaux data et index_map ont une capacité suffisante.
 */
static void	reverse_rotate_stack(t_stack *stack)
{
	int	tmp_data;
	int	tmp_index;
	int	i;

	if (stack->size < 2)
		return ;
	tmp_data = stack->data[stack->size - 1];
	tmp_index = stack->index_map[stack->size - 1];
	i = stack->size - 1;
	while (i-- > 0)
	{
		stack->data[i + 1] = stack->data[i];
		stack->index_map[i + 1] = stack->index_map[i];
	}
	stack->data[0] = tmp_data;
	stack->index_map[0] = tmp_index;
}

/**
 * @brief Effectue une rotation inverse sur la pile A
 * 
 * Cette fonction applique une rotation inverse à la pile A,
 * déplaçant son dernier
 * élément vers le début de la pile. Elle écrit également l'opération "rra" sur
 * la sortie standard.
 * 
 * @param a Pointeur vers la pile A
 * 
 * @details La fonction utilise reverse_rotate_stack en interne pour effectuer
 *          la rotation, puis écrit l'opération correspondante.
 * 
 * @note    Si la pile contient moins de 2 éléments, la fonction retourne
 *          sans effectuer d'opération ni écrire de message.
 */
void	rra(t_stack *a)
{
	if (a->size < 2)
		return ;
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

/**
 * @brief Effectue une rotation inverse sur la pile B
 * 
 * Cette fonction applique une rotation inverse à la pile B, déplaçant
 * son dernier
 * élément vers le début de la pile. Elle écrit également l'opération "rrb" sur
 * la sortie standard.
 * 
 * @param b Pointeur vers la pile B
 * 
 * @details La fonction utilise reverse_rotate_stack en interne pour effectuer
 *          la rotation, puis écrit l'opération correspondante.
 * 
 * @note    Si la pile contient moins de 2 éléments, la fonction retourne
 *          sans effectuer d'opération ni écrire de message.
 */
void	rrb(t_stack *b)
{
	if (b->size < 2)
		return ;
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}

/**
 * @brief Effectue une rotation inverse simultanée sur les piles A et B
 * 
 * Cette fonction applique une rotation inverse aux deux piles simultanément,
 * si elles contiennent chacune au moins 2 éléments. Elle écrit l'opération
 * "rrr" sur la sortie standard une seule fois, même si une seule pile est
 * effectivement rotée.
 * 
 * @param a Pointeur vers la pile A
 * @param b Pointeur vers la pile B
 * 
 * @details La fonction :
 *          1. Vérifie indépendamment chaque pile pour la rotation
 *          2. Effectue les rotations nécessaires
 *          3. Écrit une seule opération "rrr"
 * 
 * @note    Contrairement aux opérations individuelles (rra, rrb), cette fonction
 *          écrira toujours "rrr" même si une seule pile est rotée. Cela diffère
 *          du comportement standard où l'on s'attendrait à ce que rrr ne soit
 *          écrit que si les deux piles sont effectivement rotées.
 */
void	rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
		reverse_rotate_stack(a);
	if (b->size >= 2)
		reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
