# Push_swap

## Language Selection | Sélection de la langue
- [English](#english)
- [Français](#français)

# English

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. The goal is to create a program in C called push_swap which calculates and displays the smallest program, made of Push_swap language instructions, that sorts the integers received as arguments.

## Table of Contents
- [Overview](#overview)
- [Data Structures](#data-structures)
- [Operations](#operations)
- [Algorithms](#algorithms)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Overview

Push_swap is a program that sorts a stack of integers using two stacks (stack A and stack B) and a limited set of operations. The goal is to sort the numbers in stack A in ascending order using the most efficient combination of operations possible.

## Data Structures

The project uses a custom stack structure defined as follows:

```c
typedef struct s_stack
{
    int *data;      // Array storing the stack values
    int *sorted;    // Array for storing sorted values
    int *index_map; // Array for mapping values to indices
    int size;       // Current size of the stack
    int capacity;   // Maximum capacity of the stack
} t_stack;
```

## Operations

The following operations are available to manipulate the stacks:

### Swap Operations
- `sa`: Swap the first two elements of stack A
- `sb`: Swap the first two elements of stack B
- `ss`: Perform sa and sb simultaneously

### Push Operations
- `pa`: Push the first element of stack B onto stack A
- `pb`: Push the first element of stack A onto stack B

### Rotate Operations
- `ra`: Rotate stack A upward (first element becomes last)
- `rb`: Rotate stack B upward (first element becomes last)
- `rr`: Perform ra and rb simultaneously

### Reverse Rotate Operations
- `rra`: Rotate stack A downward (last element becomes first)
- `rrb`: Rotate stack B downward (last element becomes first)
- `rrr`: Perform rra and rrb simultaneously

## Algorithms

The project implements multiple sorting algorithms depending on the input size:

1. **Small Sort (2-5 elements)**
   - Specialized algorithms for sorting 2, 3, 4, or 5 numbers
   - Uses optimized move sequences for each case

2. **Radix Sort**
   - Used for larger sets of numbers
   - Implements binary radix sort using the two stacks
   - Sorts numbers by processing their binary representation

3. **Quicksort**
   - Used internally for creating the index mapping
   - Helps in optimizing the radix sort implementation

## Installation

```bash
# Clone the repository
git clone <repository-url>

# Navigate to the project directory
cd push_swap

# Compile the project
make
```

## Usage

```bash
# Basic usage
./push_swap 2 1 3 6 5 8

# Using with a checker (if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Input Rules
- Numbers must be integers
- No duplicates are allowed
- Numbers must be within INT_MAX and INT_MIN range
- Arguments can be provided as separate numbers or as a string with quotes

## Examples

```bash
# Example with 3 numbers
$> ./push_swap 3 1 2
sa
ra

# Example with 5 numbers
$> ./push_swap 4 2 1 5 3
ra
pb
sa
pa
rra
```

## Error Handling

The program handles various error cases:
- Non-numeric input
- Numbers outside INT range
- Duplicate numbers
- Invalid operation sequences

In case of error, it displays "Error" on the standard error.

---

# Français

Ce projet consiste à trier des données sur une pile, avec un ensemble limité d'instructions, en utilisant le moins de mouvements possible. L'objectif est de créer un programme en C appelé push_swap qui calcule et affiche le plus petit programme, composé d'instructions du langage Push_swap, qui trie les entiers reçus en arguments.

## Table des matières
- [Aperçu](#aperçu)
- [Structures de données](#structures-de-données)
- [Opérations](#opérations)
- [Algorithmes](#algorithmes)
- [Installation](#installation-1)
- [Utilisation](#utilisation)
- [Exemples](#exemples-1)

## Aperçu

Push_swap est un programme qui trie une pile d'entiers en utilisant deux piles (pile A et pile B) et un ensemble limité d'opérations. L'objectif est de trier les nombres dans la pile A par ordre croissant en utilisant la combinaison d'opérations la plus efficace possible.

## Structures de données

Le projet utilise une structure de pile personnalisée définie comme suit :

```c
typedef struct s_stack
{
    int *data;      // Tableau stockant les valeurs de la pile
    int *sorted;    // Tableau pour stocker les valeurs triées
    int *index_map; // Tableau pour mapper les valeurs aux indices
    int size;       // Taille actuelle de la pile
    int capacity;   // Capacité maximale de la pile
} t_stack;
```

## Opérations

Les opérations suivantes sont disponibles pour manipuler les piles :

### Opérations de swap (échange)
- `sa` : Échange les deux premiers éléments de la pile A
- `sb` : Échange les deux premiers éléments de la pile B
- `ss` : Effectue sa et sb simultanément

### Opérations de push (pousser)
- `pa` : Pousse le premier élément de la pile B sur la pile A
- `pb` : Pousse le premier élément de la pile A sur la pile B

### Opérations de rotate (rotation)
- `ra` : Rotation vers le haut de la pile A (le premier élément devient le dernier)
- `rb` : Rotation vers le haut de la pile B (le premier élément devient le dernier)
- `rr` : Effectue ra et rb simultanément

### Opérations de reverse rotate (rotation inverse)
- `rra` : Rotation vers le bas de la pile A (le dernier élément devient le premier)
- `rrb` : Rotation vers le bas de la pile B (le dernier élément devient le premier)
- `rrr` : Effectue rra et rrb simultanément

## Algorithmes

Le projet implémente plusieurs algorithmes de tri selon la taille de l'entrée :

1. **Tri petit (2-5 éléments)**
   - Algorithmes spécialisés pour trier 2, 3, 4 ou 5 nombres
   - Utilise des séquences de mouvements optimisées pour chaque cas

2. **Tri Radix**
   - Utilisé pour les grands ensembles de nombres
   - Implémente le tri radix binaire en utilisant les deux piles
   - Trie les nombres en traitant leur représentation binaire

3. **Quicksort**
   - Utilisé en interne pour créer la cartographie des indices
   - Aide à optimiser l'implémentation du tri radix

## Installation

```bash
# Cloner le dépôt
git clone <repository-url>

# Naviguer vers le répertoire du projet
cd push_swap

# Compiler le projet
make
```

## Utilisation

```bash
# Utilisation basique
./push_swap 2 1 3 6 5 8

# Utilisation avec le checker (si disponible)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Règles d'entrée
- Les nombres doivent être des entiers
- Aucun doublon n'est autorisé
- Les nombres doivent être compris entre INT_MAX et INT_MIN
- Les arguments peuvent être fournis comme des nombres séparés ou comme une chaîne entre guillemets

## Exemples

```bash
# Exemple avec 3 nombres
$> ./push_swap 3 1 2
sa
ra

# Exemple avec 5 nombres
$> ./push_swap 4 2 1 5 3
ra
pb
sa
pa
rra
```

## Gestion des erreurs

Le programme gère différents cas d'erreur :
- Entrée non numérique
- Nombres hors de la plage INT
- Nombres en double
- Séquences d'opérations invalides

En cas d'erreur, il affiche "Error" sur la sortie d'erreur standard.
