/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:51:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:48:01 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Trouve la position d'une valeur donnée dans une pile
 * 
 * Cette fonction parcourt la pile pour trouver la position (index) d'une valeur
 * spécifique. Elle est particulièrement utile pour localiser les éléments
 * minimaux lors du tri de petites piles.
 * 
 * @param a Pointeur vers la pile dans laquelle chercher
 * @param value Valeur à trouver dans la pile
 * @return Position de la valeur dans la pile (0 si non trouvée)
 * 
 * @details L'algorithme effectue une recherche linéaire :
 *          1. Parcourt séquentiellement les éléments de la pile
 *          2. Compare chaque élément avec la valeur recherchée
 *          3. Retourne l'index dès qu'une correspondance est trouvée
 * 
 * Exemple d'utilisation :
 *     Pour pile [4,2,1,3] et value = 1
 *     Retourne 2 car 1 est à l'index 2
 * 
 * Complexité : O(n) où n est la taille de la pile
 * 
 * @warning Cette implémentation retourne 0 si la valeur n'est pas trouvée,
 *          ce qui peut créer une ambiguïté si la valeur recherchée est
 *          effectivement à la position 0. Dans le contexte de push_swap,
 *          cela ne pose pas de problème car on cherche toujours des valeurs
 *          qu'on sait présentes dans la pile.
 */
int	find_position(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (i);
		i++;
	}
	return (0);
}

/**
 * @brief Déplace un élément à une position donnée vers le sommet de la pile
 * 
 * Cette fonction choisit la séquence optimale de rotations (ra ou rra) pour
 * amener un élément au sommet de la pile, en minimisant le nombre d'opérations.
 * 
 * @param a Pointeur vers la pile à manipuler
 * @param pos Position de l'élément à déplacer au sommet
 * 
 * @details L'algorithme détermine la direction optimale de rotation :
 *          1. Si pos <= 2 (élément dans la première moitié) :
 *             - Utilise ra pour rotation vers le haut
 *          2. Sinon (élément dans la seconde moitié) :
 *             - Utilise rra pour rotation vers le bas
 * 
 * Exemple d'optimisation :
 *     Pour pile [1,2,3,4,5] et pos = 4
 *     Au lieu de faire 4 ra, fait 1 rra
 * 
 * @note    Le seuil de 2 pour le choix de la direction est spécifiquement
 *          optimisé pour les petites piles (<=5 éléments) utilisées dans
 *          le contexte de ce projet.
 */
void	move_to_top(t_stack *a, int pos)
{
	if (pos <= 2)
		while (pos--)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

/**
 * @brief Déplace le deuxième plus petit élément vers la pile B
 * 
 * Cette fonction est spécifiquement conçue pour le tri de 5 éléments,
 * où elle optimise le déplacement du deuxième plus petit élément vers
 * la pile auxiliaire.
 * 
 * @param a Pointeur vers la pile principale
 * @param b Pointeur vers la pile auxiliaire
 * 
 * @details L'algorithme procède en trois étapes :
 *          1. Trouve la position du deuxième plus petit élément
 *             (utilise a->sorted[1] qui contient cette valeur)
 *          2. Choisit la séquence optimale de rotations :
 *             - ra si l'élément est dans la première moitié
 *             - rra si l'élément est dans la seconde moitié
 *          3. Pousse l'élément vers la pile B
 * 
 * Exemple de déroulement :
 *     A:[4,2,5,1,3] B:[]
 *     → A:[4,5,1,3,2] (après rotations pour amener 2 au sommet)
 *     → A:[4,5,1,3] B:[2] (après pb)
 * 
 * @note    Cette fonction suppose que a->sorted est correctement initialisé
 *          avec les valeurs triées, où sorted[1] est le deuxième plus
 *          petit élément.
 * 
 * @warning L'optimisation des rotations est spécifiquement calibrée pour
 *          des piles de 5 éléments. L'utiliser avec des piles plus grandes
 *          pourrait ne pas donner le nombre minimal d'opérations.
 */
void	move_second_min(t_stack *a, t_stack *b)
{
	int	min2_pos;

	min2_pos = find_position(a, a->sorted[1]);
	if (min2_pos <= 2)
		while (min2_pos--)
			ra(a);
	else
		while (min2_pos++ < a->size - 1)
			rra(a);
	pb(a, b);
}
