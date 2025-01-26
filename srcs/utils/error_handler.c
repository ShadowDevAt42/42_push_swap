/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:56:44 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:50:55 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gère la sortie du programme en cas d'erreur avec
 * nettoyage des ressources
 * 
 * Cette fonction assure une terminaison propre du programme en cas d'erreur en
 * libérant toutes les ressources allouées dynamiquement et en affichant un
 * message d'erreur standardisé.
 * 
 * @param a Pointeur vers la pile A
 * @param b Pointeur vers la pile B
 * @param nums Pointeur vers le tableau d'entiers temporaire utilisé pendant
 *             l'initialisation
 * 
 * @details La fonction effectue un nettoyage méthodique en plusieurs phases :
 * 
 * 1. Nettoyage de la pile A :
 *    - Vérifie si la pile existe
 *    - Libère le tableau de données (data)
 *    - Libère le tableau trié (sorted)
 *    - Libère le tableau de mapping des index (index_map)
 * 
 * 2. Nettoyage de la pile B :
 *    - Même processus que pour la pile A
 *    - Chaque composant est vérifié avant libération
 * 
 * 3. Nettoyage du tableau temporaire :
 *    - Libère le tableau nums s'il existe
 * 
 * 4. Notification et terminaison :
 *    - Écrit "Error\n" sur la sortie d'erreur (fd 2)
 *    - Termine le programme avec le code d'erreur 1
 * 
 * Exemple d'utilisation :
 * ```c
 * if (condition_erreur)
 *     error_exit(stack_a, stack_b, numbers);
 * ```
 * 
 * @note La fonction utilise write() plutôt que printf() pour l'affichage
 *       du message d'erreur, conformément aux bonnes pratiques de gestion
 *       d'erreurs système.
 * 
 * Sécurité et robustesse :
 * - Vérifie chaque pointeur avant de tenter de libérer la mémoire
 * - Peut gérer des structures partiellement initialisées
 * - Gère les cas où certains pointeurs sont NULL
 * 
 * @warning Cette fonction ne retourne jamais - elle termine toujours
 *          le programme via exit(1). Elle doit donc être appelée uniquement
 *          dans les cas où la récupération n'est pas possible ou souhaitée.
 * 
 * Considérations de conception :
 * 1. Message d'erreur minimal :
 *    - "Error\n" est suffisamment explicite pour l'utilisateur
 *    - Conforme aux spécifications du projet
 * 
 * 2. Ordre de nettoyage :
 *    - Du plus spécifique au plus général
 *    - Assure qu'aucune ressource n'est oubliée
 * 
 * 3. Robustesse :
 *    - Peut être appelée à n'importe quel stade de l'exécution
 *    - Gère correctement les structures partiellement initialisées
 */
void	error_exit(t_stack *a, t_stack *b, int *nums)
{
	if (a)
	{
		if (a->data)
			free(a->data);
		if (a->sorted)
			free(a->sorted);
		if (a->index_map)
			free(a->index_map);
	}
	if (b)
	{
		if (b->data)
			free(b->data);
		if (b->sorted)
			free(b->sorted);
		if (b->index_map)
			free(b->index_map);
	}
	if (nums)
		free(nums);
	write(2, "Error\n", 6);
	exit(1);
}
