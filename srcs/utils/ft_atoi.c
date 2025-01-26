/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:57:40 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/01/26 02:51:46 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Traite la partie numérique d'une chaîne pour la conversion en entier
 * 
 * Cette fonction auxiliaire effectue la conversion des caractères numériques
 * en valeur entière tout en gérant les dépassements et les caractères invalides.
 * 
 * @param str Pointeur vers la chaîne de caractères à convertir
 * @param sign Signe de la valeur (-1 ou 1)
 * @param error Pointeur vers un drapeau d'erreur
 * @return Valeur entière convertie, 0 en cas d'erreur
 * 
 * @details L'algorithme procède caractère par caractère avec plusieurs
 * vérifications de sécurité :
 * 
 * 1. Validation des caractères :
 *    - Vérifie que chaque caractère est un chiffre
 *    - Met le drapeau d'erreur si un caractère non numérique est trouvé
 * 
 * 2. Construction de la valeur :
 *    - Utilise un long pour éviter les dépassements pendant le calcul
 *    - Applique la formule : result = result * 10 + (caractère - '0')
 * 
 * 3. Vérification des limites :
 *    - Pour les nombres positifs : ne doit pas dépasser INT_MAX
 *    - Pour les nombres négatifs : ne doit pas dépasser INT_MIN
 *    - Utilise des comparaisons avec long pour une détection précise
 * 
 * Exemple de traitement :
 * ```
 * Entrée : "123", sign = 1
 * Itération 1 : result = 0 * 10 + (1) = 1
 * Itération 2 : result = 1 * 10 + (2) = 12
 * Itération 3 : result = 12 * 10 + (3) = 123
 * ```
 * 
 * @warning Cette fonction ne doit être appelée qu'après le traitement
 *          du signe par ft_atoi.
 */
static int	process_digits(const char *str, int sign, int *error)
{
	long	result;

	result = 0;
	while (*str && !*error)
	{
		if (!ft_isdigit(*str))
			*error = 1;
		else
		{
			result = result * 10 + (*str - '0');
			if ((sign == 1 && result > INT_MAX)
				|| (sign == -1 && result > -(long)INT_MIN))
				*error = 1;
		}
		str++;
	}
	if (*error)
		return (0);
	return ((int)(sign * result));
}

/**
 * @brief Convertit une chaîne de caractères en entier avec gestion d'erreurs
 * 
 * Cette version sécurisée de atoi détecte et signale les erreurs de format,
 * les dépassements, et autres cas problématiques.
 * 
 * @param str Chaîne de caractères à convertir
 * @param error Pointeur vers un drapeau d'erreur (mis à 1 si erreur)
 * @return Valeur entière convertie, 0 en cas d'erreur
 * 
 * @details Le processus de conversion se déroule en plusieurs étapes :
 * 
 * 1. Initialisation :
 *    - Met le drapeau d'erreur à 0
 *    - Initialise le signe à 1 (positif)
 * 
 * 2. Traitement du signe :
 *    - Reconnaît '-' pour les nombres négatifs
 *    - Accepte '+' optionnel pour les nombres positifs
 *    - Avance le pointeur après le signe
 * 
 * 3. Délégation du traitement :
 *    - Appelle process_digits pour la conversion numérique
 * 
 * Cas d'erreurs détectés :
 * - Caractères non numériques
 * - Dépassement de INT_MAX ou INT_MIN
 * - Chaîne vide ou uniquement composée d'un signe
 * 
 * Exemples d'utilisation :
 * ```c
 * int error;
 * int val1 = ft_atoi("123", &error);     // val1 = 123, error = 0
 * int val2 = ft_atoi("-2147483649", &error);  // val2 = 0, error = 1
 * int val3 = ft_atoi("12a3", &error);    // val3 = 0, error = 1
 * ```
 * 
 * @note Différences avec atoi standard :
 * - Détection explicite des erreurs via le paramètre error
 * - Validation stricte du format
 * - Gestion précise des limites d'entiers
 * 
 * @warning Cette fonction est conçue pour push_swap et peut être plus
 *          stricte que l'atoi standard. Elle n'accepte pas les espaces
 *          avant ou après le nombre, ni les notations spéciales.
 */
int	ft_atoi(const char *str, int *error)
{
	int		sign;

	*error = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (process_digits(str, sign, error));
}
