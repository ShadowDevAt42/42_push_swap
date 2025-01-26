/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:50:27 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:32:47 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Effectue une rotation sur une pile
 * 
 * Cette fonction déplace le premier élément d'une pile vers
 * sa dernière position,
 * en décalant tous les autres éléments d'une position vers
 * le haut. Elle maintient
 * la synchronisation entre les données (data) et leur mapping d'index.
 * 
 * @param stack Pointeur vers la structure de pile à modifier
 * 
 * @details Le processus de rotation se déroule en plusieurs étapes :
 *          1. Vérification de la taille minimale (2 éléments)
 *          2. Sauvegarde du premier élément et de son index dans
 * des variables temporaires
 *          3. Décalage de tous les éléments d'une position vers le haut
 *          4. Placement de l'élément temporaire à la fin de la pile
 * 
 * Exemple de rotation sur une pile [1,2,3,4] :
 *          - État initial : [1,2,3,4]
 *          - Après rotation : [2,3,4,1]
 * 
 * @note La fonction utilise une approche avec préincrémentation (++i) pour
 *       optimiser légèrement les performances par rapport à
 * une post-incrémentation.
 * 
 * @warning Cette fonction suppose que la structure de pile est
 * correctement initialisée
 *          et que les tableaux data et index_map ont une capacité suffisante.
 */
static void	rotate_stack(t_stack *stack)
{
	int	tmp_data;
	int	tmp_index;
	int	i;

	if (stack->size < 2)
		return ;
	tmp_data = stack->data[0];
	tmp_index = stack->index_map[0];
	i = 0;
	while (++i < stack->size)
	{
		stack->data[i - 1] = stack->data[i];
		stack->index_map[i - 1] = stack->index_map[i];
	}
	stack->data[stack->size - 1] = tmp_data;
	stack->index_map[stack->size - 1] = tmp_index;
}

/**
 * @brief Effectue une rotation sur la pile A
 * 
 * Cette fonction applique une rotation à la pile A, déplaçant son premier
 * élément vers la fin de la pile. Elle écrit également l'opération "ra"
 * sur la sortie standard.
 * 
 * @param a Pointeur vers la pile A
 * 
 * @details La fonction :
 *          1. Vérifie si la pile contient au moins 2 éléments
 *          2. Effectue la rotation via rotate_stack
 *          3. Écrit l'opération "ra" sur la sortie standard
 * 
 * @note Si la pile contient moins de 2 éléments, la fonction retourne
 *       silencieusement sans effectuer d'opération ni écrire de message.
 */
void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	rotate_stack(a);
	write(1, "ra\n", 3);
}

/**
 * @brief Effectue une rotation sur la pile B
 * 
 * Cette fonction applique une rotation à la pile B, déplaçant son premier
 * élément vers la fin de la pile. Elle écrit également l'opération "rb"
 * sur la sortie standard.
 * 
 * @param b Pointeur vers la pile B
 * 
 * @details La fonction :
 *          1. Vérifie si la pile contient au moins 2 éléments
 *          2. Effectue la rotation via rotate_stack
 *          3. Écrit l'opération "rb" sur la sortie standard
 * 
 * @note Si la pile contient moins de 2 éléments, la fonction retourne
 *       silencieusement sans effectuer d'opération ni écrire de message.
 */
void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	rotate_stack(b);
	write(1, "rb\n", 3);
}

/**
 * @brief Effectue une rotation simultanée sur les piles A et B
 * 
 * Cette fonction applique une rotation aux deux piles simultanément si elles
 * contiennent chacune au moins 2 éléments. Elle écrit l'opération "rr" sur
 * la sortie standard une seule fois.
 * 
 * @param a Pointeur vers la pile A
 * @param b Pointeur vers la pile B
 * 
 * @details La fonction :
 *          1. Vérifie indépendamment la taille de chaque pile
 *          2. Effectue la rotation sur la pile A si possible
 *          3. Effectue la rotation sur la pile B si possible
 *          4. Écrit l'opération "rr" une seule fois
 * 
 * @note    Particularité importante : l'opération "rr" est écrite même si
 *          une seule pile a été rotée. Ce comportement diffère de la logique
 *          habituelle où "rr" ne devrait être écrit que si les deux piles
 *          ont effectivement été rotées.
 * 
 * @warning Cette fonction ne vérifie pas si les pointeurs a et b sont valides.
 *          Ils doivent pointer vers des structures t_stack correctement
 * initialisées.
 */
void	rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
		rotate_stack(a);
	if (b->size >= 2)
		rotate_stack(b);
	write(1, "rr\n", 3);
}
