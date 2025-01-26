/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:53:58 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:49:00 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Trouve l'index de l'élément minimal dans une pile
 * 
 * Cette fonction parcourt l'ensemble de la pile pour identifier la position
 * de l'élément ayant la plus petite valeur. Elle est fondamentale pour
 * les stratégies de tri qui nécessitent de localiser et manipuler le
 * minimum.
 * 
 * @param stack Pointeur vers la pile à analyser
 * @return Index de l'élément minimal dans la pile
 * 
 * @details L'algorithme suit une approche classique de recherche de minimum :
 *          1. Initialise le premier élément comme minimum
 *          2. Parcourt séquentiellement le reste de la pile
 *          3. Met à jour l'index minimal si un élément plus petit est trouvé
 *          4. Retourne l'index final du minimum
 * 
 * Exemple détaillé :
 *     Pour une pile [3,1,4,2] :
 *     - min_index initial = 0 (valeur 3)
 *     - Comparaison avec index 1 : 1 < 3 → min_index = 1
 *     - Comparaison avec index 2 : 4 > 1 → pas de changement
 *     - Comparaison avec index 3 : 2 > 1 → pas de changement
 *     - Retourne 1 (index de la valeur 1)
 * 
 * Complexité : O(n) où n est la taille de la pile
 * 
 * @note Cette fonction est cruciale pour de nombreuses opérations de tri,
 *       particulièrement dans les stratégies qui commencent par isoler
 *       les plus petits éléments.
 * 
 * @warning La fonction suppose que la pile n'est pas vide. Dans une
 *          implémentation plus robuste, il faudrait ajouter une
 *          vérification de la taille de la pile.
 */
int	find_min_index(t_stack *stack)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < stack->data[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

/**
 * @brief Déplace l'élément minimal au sommet de la pile A
 * 
 * Cette fonction calcule et exécute la séquence optimale d'opérations
 * (ra ou rra) pour amener l'élément minimal au sommet de la pile A.
 * Elle minimise le nombre total d'opérations nécessaires.
 * 
 * @param a Pointeur vers la pile A à manipuler
 * 
 * @details L'algorithme procède en plusieurs étapes :
 *          1. Trouve la position de l'élément minimal
 *          2. Calcule le nombre d'opérations nécessaires dans chaque direction :
 *             - ra_steps : nombre de rotations vers le haut
 *             - rra_steps : nombre de rotations vers le bas
 *          3. Choisit la séquence la plus courte
 *          4. Exécute les rotations nécessaires
 * 
 * Exemple d'optimisation :
 *     Pour pile [3,4,1,2] :
 *     - Position du minimum (1) : index 2
 *     - ra_steps = 2 (deux rotations vers le haut)
 *     - rra_steps = 2 (deux rotations vers le bas)
 *     - Dans ce cas, choisit arbitrairement ra
 *     → [4,1,2,3] → [1,2,3,4]
 * 
 * @note Cette fonction est particulièrement utile dans les algorithmes
 *       de tri qui commencent par isoler les plus petits éléments,
 *       comme le tri de piles de taille 4 ou 5.
 * 
 * Optimisation :
 *     - La fonction choisit systématiquement ra en cas d'égalité
 *       du nombre d'opérations, ce qui peut être important pour
 *       la prédictibilité du comportement dans certains cas.
 *     - Le calcul préalable du nombre d'opérations évite d'avoir
 *       à prendre des décisions pendant l'exécution des rotations.
 * 
 * @warning La fonction modifie directement l'état de la pile A et
 *          écrit les opérations sur la sortie standard via les
 *          fonctions ra() et rra().
 */
void	move_min_to_top_a(t_stack *a)
{
	int	min_index;
	int	ra_steps;
	int	rra_steps;

	min_index = find_min_index(a);
	ra_steps = min_index;
	rra_steps = a->size - min_index;
	if (ra_steps <= rra_steps)
	{
		while (ra_steps-- > 0)
			ra(a);
	}
	else
	{
		while (rra_steps-- > 0)
			rra(a);
	}
}
