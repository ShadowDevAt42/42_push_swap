/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:52:39 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:46:38 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Trie une pile de deux éléments
 * 
 * Cette fonction implémente un tri simple pour une pile de deux éléments
 * en effectuant une seule comparaison et potentiellement un swap.
 * 
 * @param a Pointeur vers la pile à trier
 * 
 * @details L'algorithme est très simple :
 *          1. Compare les deux premiers éléments
 *          2. Si le premier est plus grand que le second, effectue un swap
 * 
 * Nombre maximum d'opérations : 1 (sa)
 * 
 * Exemple :
 *     État initial : [3,1]
 *     Après sa : [1,3]
 * 
 * @note    Cette fonction suppose que la pile contient exactement deux éléments.
 *          Aucune vérification de taille n'est effectuée.
 */
void	sort_two(t_stack *a)
{
	if (a->data[0] > a->data[1])
		sa(a);
}

/**
 * @brief Trie une pile de trois éléments
 * 
 * Cette fonction implémente un tri optimisé pour trois éléments en utilisant
 * une approche basée sur les cas possibles de désordre.
 * 
 * @param a Pointeur vers la pile à trier
 * 
 * @details L'algorithme identifie 5 cas de désordre possibles :
 *          1. [2,1,3] → sa
 *          2. [3,2,1] → sa + rra
 *          3. [3,1,2] → ra
 *          4. [1,3,2] → sa + ra
 *          5. [2,3,1] → rra
 *          (Le cas [1,2,3] est déjà trié)
 * 
 *          Pour faciliter la lecture, les variables sont nommées :
 *          - t (top) : premier élément
 *          - m (middle) : deuxième élément
 *          - b (bottom) : troisième élément
 * 
 * Nombre maximum d'opérations : 2
 * 
 * @note    L'utilisation de const pour les variables temporaires garantit
 *          qu'elles ne seront pas modifiées accidentellement pendant
 *          l'exécution des opérations.
 */
void	sort_three(t_stack *a)
{
	const int	t = a->data[0];
	const int	m = a->data[1];
	const int	b = a->data[2];

	if (t > m && m < b && t < b)
		sa(a);
	else if (t > m && m > b)
	{
		sa(a);
		rra(a);
	}
	else if (t > m && m < b)
		ra(a);
	else if (t < m && m > b && t < b)
	{
		sa(a);
		ra(a);
	}
	else if (t < m && m > b && t > b)
		rra(a);
}

/**
 * @brief Trie une pile de quatre éléments
 * 
 * Cette fonction implémente une stratégie de tri pour quatre éléments en
 * isolant le plus petit élément puis en triant les trois restants.
 * 
 * @param a Pointeur vers la pile principale
 * @param b Pointeur vers la pile auxiliaire
 * 
 * @details L'algorithme procède comme suit :
 *          1. Déplace le plus petit élément au sommet de la pile A
 *          2. Pousse cet élément vers la pile B
 *          3. Trie les trois éléments restants dans A
 *          4. Ramène le plus petit élément de B vers A
 * 
 * Exemple de déroulement :
 *     A:[4,1,3,2] B:[]
 *     → A:[1,4,3,2] B:[] (après move_min_to_top)
 *     → A:[4,3,2] B:[1] (après pb)
 *     → A:[2,3,4] B:[1] (après sort_three)
 *     → A:[1,2,3,4] B:[] (après pa)
 * 
 * @note    Cette approche garantit un tri optimal en termes de nombre
 *          d'opérations pour quatre éléments.
 */
void	sort_four(t_stack *a, t_stack *b)
{
	move_min_to_top_a(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

/**
 * @brief Trie une pile de cinq éléments
 * 
 * Cette fonction implémente une stratégie de tri pour cinq éléments en
 * isolant les deux plus petits éléments puis en triant les trois restants.
 * 
 * @param a Pointeur vers la pile principale
 * @param b Pointeur vers la pile auxiliaire
 * 
 * @details L'algorithme procède en plusieurs étapes :
 *          1. Trouve la position du plus petit élément
 *          2. Déplace cet élément au sommet de A
 *          3. Pousse le plus petit élément vers B
 *          4. Déplace et pousse le deuxième plus petit élément vers B
 *          5. Trie les trois éléments restants dans A
 *          6. Ramène les deux plus petits éléments de B vers A
 * 
 * Exemple de déroulement :
 *     A:[4,1,5,3,2] B:[]
 *     → A:[1,4,5,3,2] B:[] (après move_to_top)
 *     → A:[4,5,3,2] B:[1] (après pb)
 *     → A:[5,3,2] B:[2,1] (après move_second_min et pb)
 *     → A:[2,3,5] B:[2,1] (après sort_three)
 *     → A:[1,2,3,5] B:[] (après pa x2)
 * 
 * @note    Cette méthode assure un tri optimal pour cinq éléments tout en
 *          respectant les contraintes d'opérations de push_swap.
 * 
 * @warning La fonction suppose que le tableau sorted dans la structure
 *          t_stack est correctement initialisé avec les éléments triés.
 */
void	sort_five(t_stack *a, t_stack *b)
{
	int	min1_pos;

	min1_pos = find_position(a, a->sorted[0]);
	move_to_top(a, min1_pos);
	pb(a, b);
	move_second_min(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
