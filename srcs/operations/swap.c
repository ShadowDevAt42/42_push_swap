/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:51:21 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:35:35 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Échange les deux premiers éléments d'une pile
 * 
 * Cette fonction échange les positions des deux premiers éléments d'une pile,
 * en maintenant la synchronisation entre les données (data) et leur mapping 
 * d'index correspondant.
 * 
 * @param stack Pointeur vers la structure de pile à modifier
 * 
 * @details Le processus d'échange se déroule en deux phases distinctes :
 *          1. Échange des données (data) :
 *             - Sauvegarde temporaire de la première valeur
 *             - Déplacement de la deuxième valeur en première position
 *             - Placement de la valeur temporaire en deuxième position
 *          2. Échange des index de mapping :
 *             - Même processus que pour les données
 * 
 * Exemple d'échange sur une pile [1,2,3,4] :
 *          - État initial : [1,2,3,4]
 *          - Après swap : [2,1,3,4]
 * 
 * @note    La fonction effectue une vérification préalable de la taille
 *          de la pile pour s'assurer qu'elle contient au moins 2 éléments.
 *          Si ce n'est pas le cas, elle retourne sans effectuer d'opération.
 * 
 * @warning Cette fonction suppose que la structure de pile est correctement
 *          initialisée et que les tableaux data et index_map sont valides.
 */
static void	swap_stack(t_stack *stack)
{
	int	tmp_data;
	int	tmp_index;

	if (stack->size < 2)
		return ;
	tmp_data = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp_data;
	tmp_index = stack->index_map[0];
	stack->index_map[0] = stack->index_map[1];
	stack->index_map[1] = tmp_index;
}

/**
 * @brief Échange les deux premiers éléments de la pile A
 * 
 * Cette fonction applique un swap aux deux premiers éléments de la pile A
 * et écrit l'opération "sa" sur la sortie standard.
 * 
 * @param a Pointeur vers la pile A
 * 
 * @details La fonction :
 *          1. Vérifie si la pile contient au moins 2 éléments
 *          2. Effectue l'échange via swap_stack
 *          3. Écrit l'opération "sa" sur la sortie standard
 * 
 * @note    Si la pile contient moins de 2 éléments, la fonction retourne
 *          silencieusement sans effectuer d'opération ni écrire de message.
 */
void	sa(t_stack *a)
{
	if (a->size < 2)
		return ;
	swap_stack(a);
	write(1, "sa\n", 3);
}

/**
 * @brief Échange les deux premiers éléments de la pile B
 * 
 * Cette fonction applique un swap aux deux premiers éléments de la pile B
 * et écrit l'opération "sb" sur la sortie standard.
 * 
 * @param b Pointeur vers la pile B
 * 
 * @details La fonction :
 *          1. Vérifie si la pile contient au moins 2 éléments
 *          2. Effectue l'échange via swap_stack
 *          3. Écrit l'opération "sb" sur la sortie standard
 * 
 * @note    Si la pile contient moins de 2 éléments, la fonction retourne
 *          silencieusement sans effectuer d'opération ni écrire de message.
 */
void	sb(t_stack *b)
{
	if (b->size < 2)
		return ;
	swap_stack(b);
	write(1, "sb\n", 3);
}

/**
 * @brief Échange simultanément les deux premiers éléments des piles A et B
 * 
 * Cette fonction applique un swap aux deux premiers éléments de chaque pile
 * (si possible) et écrit l'opération "ss" sur la sortie standard.
 * 
 * @param a Pointeur vers la pile A
 * @param b Pointeur vers la pile B
 * 
 * @details La fonction :
 *          1. Vérifie indépendamment chaque pile pour la possibilité de swap
 *          2. Effectue le swap sur la pile A si possible
 *          3. Effectue le swap sur la pile B si possible
 *          4. Écrit l'opération "ss" une seule fois
 * 
 * @note    Important : L'opération "ss" est écrite même si un seul swap
 *          a été effectué. Ce comportement pourrait être différent de ce
 *          qu'on attendrait normalement, où "ss" ne devrait être écrit
 *          que si les deux piles ont effectivement été modifiées.
 * 
 * @warning Cette fonction ne vérifie pas si les pointeurs a et b sont valides.
 *          Les structures t_stack doivent être correctement initialisées
 *          avant l'appel.
 */
void	ss(t_stack *a, t_stack *b)
{
	if (a->size >= 2)
		swap_stack(a);
	if (b->size >= 2)
		swap_stack(b);
	write(1, "ss\n", 3);
}
