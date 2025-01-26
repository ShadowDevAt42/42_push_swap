/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:47:31 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:10:51 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Déplace tous les éléments d'une pile vers le haut d'une position
 * 
 * Cette fonction déplace chaque élément de la pile d'une position vers le haut,
 * en commençant par le dernier élément. Elle met à jour à la fois le tableau
 * de données (data) et le tableau de mapping des index (index_map).
 * 
 * @param stack Pointeur vers la structure de pile à modifier
 * @details La fonction parcourt la pile du haut vers le bas, en déplaçant
 *          chaque élément d'une position vers le haut, créant ainsi un espace
 *          libre à l'index 0. Cette opération est nécessaire avant d'insérer
 *          un nouvel élément au début de la pile.
 * 
 * @warning Cette fonction suppose qu'il y a suffisamment d'espace dans la pile
 *          pour effectuer le déplacement (stack->size < stack->capacity)
 */
static void	move_elements_up(t_stack *stack)
{
	int	i;

	i = stack->size;
	while (i-- > 0)
	{
		stack->data[i + 1] = stack->data[i];
		stack->index_map[i + 1] = stack->index_map[i];
	}
}

/**
 * @brief Déplace tous les éléments d'une pile vers le bas d'une position
 * 
 * Cette fonction déplace chaque élément de la pile d'une position vers le bas,
 * en commençant par le premier élément. Elle met à jour à la fois le tableau
 * de données (data) et le tableau de mapping des index (index_map).
 * 
 * @param stack Pointeur vers la structure de pile à modifier
 * @details La fonction parcourt la pile du bas vers le haut, en déplaçant
 *          chaque élément d'une position vers le bas. Cette opération est
 *          utilisée après avoir retiré le premier élément de la pile pour
 *          combler l'espace vide créé.
 * 
 * @warning Cette fonction suppose que la pile contient au moins un élément
 *          (stack->size > 0)
 */
static void	move_elements_down(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		stack->index_map[i] = stack->index_map[i + 1];
		i++;
	}
}

/**
 * @brief Pousse le premier élément de la pile A vers le haut de la pile B
 * 
 * Cette fonction prend le premier élément de la pile A et le place au sommet
 * de la pile B, en préservant son index de mapping. Elle écrit également
 * l'opération "pb" sur la sortie standard.
 * 
 * @param a Pointeur vers la pile source (pile A)
 * @param b Pointeur vers la pile destination (pile B)
 * @details La fonction effectue les opérations suivantes :
 *          1. Vérifie les conditions de validité
 *          2. Sauvegarde l'index de mapping de l'élément à déplacer
 *          3. Fait de la place dans la pile B
 *          4. Transfère l'élément et son index
 *          5. Réorganise la pile A
 *          6. Met à jour les tailles des piles
 * 
 * @note La fonction retourne silencieusement si :
 *       - La pile A est vide
 *       - La pile B est pleine
 */
void	pb(t_stack *a, t_stack *b)
{
	int	temp_index;

	if (a->size == 0 || b->size >= b->capacity)
		return ;
	temp_index = a->index_map[0];
	move_elements_up(b);
	b->data[0] = a->data[0];
	b->index_map[0] = temp_index;
	move_elements_down(a);
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

/**
 * @brief Pousse le premier élément de la pile B vers le haut de la pile A
 * 
 * Cette fonction prend le premier élément de la pile B et le place au sommet
 * de la pile A, en préservant son index de mapping. Elle écrit également
 * l'opération "pa" sur la sortie standard.
 * 
 * @param a Pointeur vers la pile destination (pile A)
 * @param b Pointeur vers la pile source (pile B)
 * @details La fonction effectue les opérations suivantes :
 *          1. Vérifie les conditions de validité
 *          2. Sauvegarde l'index de mapping de l'élément à déplacer
 *          3. Fait de la place dans la pile A
 *          4. Transfère l'élément et son index
 *          5. Réorganise la pile B
 *          6. Met à jour les tailles des piles
 * 
 * @note La fonction retourne silencieusement si :
 *       - La pile B est vide
 *       - La pile A est pleine
 */
void	pa(t_stack *a, t_stack *b)
{
	int	temp_index;

	if (b->size == 0 || a->size >= a->capacity)
		return ;
	temp_index = b->index_map[0];
	move_elements_up(a);
	a->data[0] = b->data[0];
	a->index_map[0] = temp_index;
	move_elements_down(b);
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}
