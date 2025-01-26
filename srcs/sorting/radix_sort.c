/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:16:44 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:47:23 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Recherche la position d'un nombre dans un tableau trié
 * 
 * Cette fonction implémente une recherche binaire pour trouver l'index
 * correspondant à un nombre donné dans un tableau trié. Cette position
 * sera utilisée pour déterminer les bits du nombre lors du tri radix.
 * 
 * @param num Nombre à rechercher
 * @param sorted Tableau trié d'entiers où effectuer la recherche
 * @param size Taille du tableau
 * @return Index du nombre dans le tableau trié, 0 si non trouvé
 * 
 * @details L'algorithme utilise une approche par dichotomie :
 *          1. Maintient deux pointeurs (left et right) délimitant
 * la zone de recherche
 *          2. À chaque itération :
 *             - Calcule le point médian
 *             - Compare la valeur médiane avec le nombre recherché
 *             - Ajuste la zone de recherche en conséquence
 * 
 * Complexité : O(log n) où n est la taille du tableau
 * 
 * @note    Cette implémentation retourne 0 si le nombre n'est pas trouvé,
 *          ce qui est spécifique à l'utilisation dans le contexte du tri radix
 *          pour push_swap. Dans une implémentation classique, on retournerait
 *          généralement -1 pour indiquer l'absence de l'élément.
 */
static int	binary_search(int num, int *sorted, int size)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sorted[mid] == num)
			return (mid);
		if (sorted[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}

/**
 * @brief Calcule le nombre de bits nécessaires pour représenter
 * une taille donnée
 * 
 * Cette fonction détermine le nombre minimum de bits requis pour représenter
 * un nombre, utilisé pour définir le nombre d'itérations du tri radix.
 * 
 * @param size Taille pour laquelle calculer le nombre de bits
 * @return Nombre de bits nécessaires
 * 
 * @details L'algorithme :
 *          1. Décrémente size car on compte à partir de 0
 *          2. Effectue des décalages à droite successifs (>>= 1)
 *          3. Compte le nombre de décalages nécessaires
 * 
 * Exemple :
 *     Pour size = 8 :
 *     - 8-1 = 7 (0b0111)
 *     - Nécessite 3 bits pour représenter
 *     - Retourne 3
 * 
 * @note    Cette fonction est optimisée pour le tri radix dans push_swap,
 *          où nous traitons les positions des nombres plutôt que les
 *          nombres eux-mêmes.
 */
static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	size--;
	while (size)
	{
		size >>= 1;
		bits++;
	}
	return (bits);
}

/**
 * @brief Implémente le tri radix adapté pour push_swap
 * 
 * Cette fonction réalise un tri radix bit par bit sur une pile en utilisant
 * uniquement les opérations autorisées de push_swap. Elle utilise les positions
 * relatives des nombres plutôt que leurs valeurs absolues.
 * 
 * @param a Pointeur vers la pile principale à trier
 * @param b Pointeur vers la pile auxiliaire
 * 
 * @details L'algorithme procède comme suit :
 *          1. Vérifie les cas triviaux (pile déjà triée ou trop petite)
 *          2. Calcule le nombre de bits nécessaires basé sur la taille
 *          3. Pour chaque bit (de droite à gauche) :
 *             - Examine chaque nombre de la pile A
 *             - Trouve sa position relative via recherche binaire
 *             - Si le bit courant est 1 : rotate (ra)
 *             - Si le bit courant est 0 : push vers B (pb)
 *             - Une fois tous les nombres traités, ramène tout vers A (pa)
 * 
 * Complexité :
 * - Temps : O(n * log n * b) où :
 *   - n est le nombre d'éléments
 *   - b est le nombre de bits nécessaires (log n)
 *   - La recherche binaire ajoute un facteur log n
 * - Espace : O(n) pour la pile auxiliaire
 * 
 * @note    Cette implémentation est spécifiquement optimisée pour push_swap :
 *          - Utilise les positions relatives plutôt que les valeurs absolues
 *          - Minimise le nombre d'opérations nécessaires
 *          - S'arrête dès que la pile est triée
 * 
 * @warning La fonction suppose que la structure t_stack est correctement
 *          initialisée avec un tableau sorted valide contenant les mêmes
 *          nombres que data mais dans l'ordre croissant.
 */
void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	pos;

	if (a->size <= 1 || is_sorted(a))
		return ;
	size = a->size;
	max_bits = get_max_bits(size);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			pos = binary_search(a->data[0], a->sorted, size);
			if ((pos >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size)
			pa(a, b);
	}
}
