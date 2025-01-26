/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:46:50 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:56:58 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Libère proprement toutes les ressources et termine
 * le programme avec succès
 * 
 * Cette fonction assure une terminaison propre du programme en libérant
 * systématiquement toute la mémoire allouée dynamiquement pour les deux piles.
 * 
 * @param a Pointeur vers la pile A
 * @param b Pointeur vers la pile B
 * 
 * @details Le processus de nettoyage s'effectue méthodiquement :
 * 
 * 1. Pour la pile A :
 *    - Libération du tableau de données (data)
 *    - Libération du tableau trié (sorted)
 *    - Libération du tableau de mapping des index (index_map)
 * 
 * 2. Pour la pile B :
 *    - Libération du tableau de données (data)
 *    - Libération du tableau de mapping des index (index_map)
 *    - Noter que B n'a pas de tableau sorted car il n'en a pas besoin
 * 
 * 3. Termine le programme avec le code de succès (0)
 * 
 * @note Contrairement à error_exit, cette fonction :
 *       - N'affiche pas de message d'erreur
 *       - Utilise le code de sortie 0 (succès)
 *       - Ne libère pas de tableau nums supplémentaire
 */
static void	clean_exit(t_stack *a, t_stack *b)
{
	if (a->data)
		free(a->data);
	if (a->sorted)
		free(a->sorted);
	if (a->index_map)
		free(a->index_map);
	if (b->data)
		free(b->data);
	if (b->index_map)
		free(b->index_map);
	exit(0);
}

/**
 * @brief Sélectionne et exécute l'algorithme de tri approprié selon
 * la taille de la pile
 * 
 * Cette fonction implémente la stratégie globale de tri en choisissant
 * l'algorithme optimal en fonction du nombre d'éléments à trier.
 * 
 * @param a Pointeur vers la pile principale à trier
 * @param b Pointeur vers la pile auxiliaire
 * 
 * @details La sélection de l'algorithme suit une logique précise :
 * 
 * 1. Pour 2 éléments :
 *    - Utilise sort_two (maximum 1 opération)
 * 
 * 2. Pour 3 éléments :
 *    - Utilise sort_three (maximum 2 opérations)
 *    - Optimisé pour tous les cas possibles
 * 
 * 3. Pour 4 éléments :
 *    - Utilise sort_four
 *    - Stratégie : isole le plus petit, trie le reste
 * 
 * 4. Pour 5 éléments :
 *    - Utilise sort_five
 *    - Stratégie : isole les deux plus petits, trie le reste
 * 
 * 5. Pour 6 éléments ou plus :
 *    - Utilise radix_sort
 *    - Algorithme efficace pour les grandes séries
 * 
 * Cette approche garantit une performance optimale pour chaque taille
 * de pile, minimisant le nombre d'opérations nécessaires.
 */
static void	handle_sorting(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

/**
 * @brief Point d'entrée principal du programme push_swap
 * 
 * Cette fonction coordonne l'ensemble du processus de tri, de la validation
 * des arguments jusqu'à l'exécution de l'algorithme approprié.
 * 
 * @param argc Nombre d'arguments reçus
 * @param argv Tableau des arguments
 * @return 0 en cas de succès
 * 
 * @details Le programme suit un flux d'exécution précis :
 * 
 * 1. Vérifications initiales :
 *    - S'assure qu'il y a au moins un argument à trier
 *    - Initialise les structures à zéro pour sécurité
 * 
 * 2. Traitement des arguments :
 *    - Parse et valide les arguments numériques
 *    - Vérifie l'absence d'erreurs de format ou de doublons
 * 
 * 3. Initialisation des structures :
 *    - Configure les piles A et B
 *    - Prépare les tableaux auxiliaires nécessaires
 * 
 * 4. Vérification de l'état initial :
 *    - Si la pile est déjà triée, termine proprement
 *    - Évite des opérations inutiles
 * 
 * 5. Exécution du tri :
 *    - Sélectionne et exécute l'algorithme approprié
 *    - Termine proprement après le tri
 * 
 * Gestion des erreurs :
 * - Utilise error_exit pour les erreurs fatales
 * - Assure la libération des ressources dans tous les cas
 * - Maintient des codes de retour appropriés
 * 
 * @note Le programme est conçu pour être robuste et efficace,
 *       avec une gestion complète des cas d'erreur et une
 *       utilisation optimale des ressources.
 */
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*nums;
	int		error;

	error = 0;
	a = (t_stack){0};
	b = (t_stack){0};
	if (argc < 2)
		return (0);
	nums = parse_args(argc, argv, &error);
	if (error)
		error_exit(&a, &b, nums);
	init_stacks(&a, &b, nums, argc);
	if (is_sorted(&a))
		clean_exit(&a, &b);
	handle_sorting(&a, &b);
	clean_exit(&a, &b);
	return (0);
}
