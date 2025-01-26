/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:01:38 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:54:58 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Vérifie la présence de doublons dans un tableau d'entiers
 * 
 * @param nums Tableau à vérifier
 * @param size Taille du tableau
 * @param error Pointeur vers le flag d'erreur
 * 
 * @details Compare chaque paire d'éléments possible pour détecter
 * les doublons
 */
static void	check_duplicates(int *nums, int size, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				*error = 1;
			j++;
		}
		i++;
	}
}

/**
 * @brief Parse les arguments de la ligne de commande en tableau d'entiers
 * 
 * Cette fonction convertit les arguments en entiers, vérifie leur validité
 * et l'absence de doublons.
 * 
 * @param argc Nombre d'arguments
 * @param argv Tableau des arguments
 * @param error Pointeur vers le flag d'erreur
 * @return Tableau d'entiers alloué dynamiquement, NULL en cas d'erreur
 * 
 * @details Processus de parsing :
 * 1. Alloue le tableau de résultat
 * 2. Convertit chaque argument en entier
 * 3. Vérifie l'absence de doublons
 * 4. Gère proprement les erreurs
 */
int	*parse_args(int argc, char **argv, int *error)
{
	int	*nums;
	int	i;

	nums = malloc((argc - 1) * sizeof(int));
	if (!nums)
	{
		*error = 1;
		return (NULL);
	}
	i = 0;
	while (i < argc - 1 && !*error)
	{
		nums[i] = ft_atoi(argv[i + 1], error);
		i++;
	}
	if (!*error)
		check_duplicates(nums, argc - 1, error);
	if (*error)
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
