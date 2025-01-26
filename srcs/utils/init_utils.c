/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:55:10 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:55:36 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initialise la pile B avec les paramètres appropriés
 * 
 * Cette fonction alloue et initialise la pile B qui servira de pile
 * auxiliaire pendant le tri.
 * 
 * @param a Pointeur vers la pile A (pour la gestion d'erreurs)
 * @param b Pointeur vers la pile B à initialiser
 * @param argc Nombre d'arguments du programme
 * 
 * @details Processus d'initialisation :
 * 1. Alloue l'espace pour les données et le mapping d'index
 * 2. Initialise tous les éléments à 0
 * 3. Configure les paramètres de la pile (capacité, taille)
 * 
 * @warning En cas d'échec d'allocation, appelle error_exit
 */
void	init_stack_b(t_stack *a, t_stack *b, int argc)
{
	int	i;

	b->data = malloc((argc - 1) * sizeof(int));
	b->index_map = malloc((argc - 1) * sizeof(int));
	if (!b->data || !b->index_map)
		error_exit(a, b, a->data);
	i = -1;
	while (++i < argc - 1)
	{
		b->data[i] = 0;
		b->index_map[i] = 0;
	}
	b->sorted = NULL;
	b->capacity = argc - 1;
	b->size = 0;
}

/**
 * @brief Crée le mapping des index pour la pile A
 * 
 * Cette fonction établit la correspondance entre les valeurs de la pile
 * et leurs positions dans le tableau trié.
 * 
 * @param a Pointeur vers la pile A
 * @param argc Nombre d'arguments du programme
 * 
 * @details Pour chaque élément de data, trouve sa position dans sorted
 * et stocke cette position dans index_map
 */
void	create_index_map(t_stack *a, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < argc - 1)
		{
			if (a->data[i] == a->sorted[j])
			{
				a->index_map[i] = j;
				break ;
			}
		}
	}
}

/**
 * @brief Initialise les deux piles pour le tri
 * 
 * Configure les piles A et B avec leurs données initiales et structures
 * nécessaires pour le tri.
 * 
 * @param a Pointeur vers la pile A
 * @param b Pointeur vers la pile B
 * @param nums Tableau des nombres à trier
 * @param argc Nombre d'arguments
 */
void	init_stacks(t_stack *a, t_stack *b, int *nums, int argc)
{
	int	i;

	a->data = nums;
	a->size = argc - 1;
	a->capacity = argc - 1;
	a->sorted = malloc((argc - 1) * sizeof(int));
	a->index_map = malloc((argc - 1) * sizeof(int));
	if (!a->sorted || !a->index_map)
		error_exit(a, b, nums);
	i = -1;
	while (++i < argc - 1)
		a->sorted[i] = a->data[i];
	quicksort(a->sorted, argc - 1);
	create_index_map(a, argc);
	init_stack_b(a, b, argc);
}
