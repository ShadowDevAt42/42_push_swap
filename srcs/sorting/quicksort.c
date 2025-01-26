/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:42:30 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:47:19 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Échange les valeurs de deux entiers
 * 
 * Cette fonction utilitaire échange les valeurs pointées par deux pointeurs
 * d'entiers en utilisant une variable temporaire.
 * 
 * @param a Pointeur vers le premier entier
 * @param b Pointeur vers le deuxième entier
 * 
 * @details Le processus d'échange se fait en trois étapes :
 *          1. Sauvegarde de la première valeur dans une variable temporaire
 *          2. Copie de la deuxième valeur dans la première position
 *          3. Copie de la valeur temporaire dans la deuxième position
 * 
 * Exemple d'échange :
 *          Si *a = 5 et *b = 3
 *          Après l'échange : *a = 3 et *b = 5
 * 
 * @warning Cette fonction suppose que les pointeurs sont valides et ne vérifie
 *          pas s'ils sont NULL. La validation doit être faite avant l'appel.
 */
static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief Partitionne un tableau autour d'un pivot selon l'algorithme Quicksort
 * 
 * Cette fonction réorganise les éléments d'un tableau de sorte que tous les
 * éléments inférieurs au pivot soient placés avant lui, et tous les éléments
 * supérieurs après lui.
 * 
 * @param arr Tableau d'entiers à partitionner
 * @param low Index de début de la partition
 * @param high Index de fin de la partition (position du pivot)
 * 
 * @return L'index final du pivot après partitionnement
 * 
 * @details L'algorithme :
 *          1. Choisit le dernier élément comme pivot
 *          2. Maintient deux indices :
 *             - i : délimite la zone des éléments < pivot
 *             - j : parcourt le tableau pour comparer avec le pivot
 *          3. Pour chaque élément < pivot :
 *             - Incrémente i
 *             - Échange l'élément courant avec la position i
 *          4. Place le pivot à sa position finale
 * 
 * @note    Cette implémentation utilise toujours le dernier élément comme pivot,
 *          ce qui peut mener à des performances sous-optimales sur des tableaux
 *          déjà triés ou presque triés.
 */
static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
			swap(&arr[++i], &arr[j]);
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * @brief Implémente la partie récursive de l'algorithme Quicksort
 * 
 * Cette fonction applique récursivement l'algorithme de tri rapide sur
 * les sous-tableaux créés par le partitionnement.
 * 
 * @param arr Tableau d'entiers à trier
 * @param low Index de début de la section à trier
 * @param high Index de fin de la section à trier
 * 
 * @details L'algorithme récursif :
 *          1. Si low < high (condition d'arrêt de la récursion)
 *          2. Partitionne le tableau et obtient l'index du pivot
 *          3. Appelle récursivement sur la partie gauche (avant le pivot)
 *          4. Appelle récursivement sur la partie droite (après le pivot)
 * 
 * @note    La profondeur de récursion est logarithmique dans le meilleur cas,
 *          mais peut atteindre O(n) dans le pire cas (tableau déjà trié).
 */
static void	quick_sort_recursive(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort_recursive(arr, low, pi - 1);
		quick_sort_recursive(arr, pi + 1, high);
	}
}

/**
 * @brief Point d'entrée principal de l'algorithme Quicksort
 * 
 * Cette fonction publique initialise le tri rapide sur un tableau d'entiers
 * en vérifiant d'abord les cas triviaux.
 * 
 * @param arr Tableau d'entiers à trier
 * @param size Nombre d'éléments dans le tableau
 * 
 * @details La fonction :
 *          1. Vérifie si le tri est nécessaire (size > 1)
 *          2. Lance le tri récursif sur l'ensemble du tableau
 * 
 * Complexité :
 * - Temps moyen : O(n log n)
 * - Pire cas : O(n²) (rare avec un bon choix de pivot)
 * - Espace : O(log n) pour la pile d'appels récursifs
 * 
 * @warning Cette fonction modifie le tableau en place et ne fait pas de
 *          validation sur le pointeur arr. Il doit pointer vers un tableau
 *          valide de taille 'size'.
 */
void	quicksort(int *arr, int size)
{
	if (size <= 1)
		return ;
	quick_sort_recursive(arr, 0, size - 1);
}
