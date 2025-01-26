#!/bin/bash

INT_MIN=-2147483648
INT_MAX=2147483647

# ==============================================================================
# Fonctions de test
# ==============================================================================
run_test() {
    local test_name="$1"
    local args="$2"
    
    echo "✨ ---------------------------------------------"
    echo "🧪 Test: $test_name"
    echo "📥 Arguments: $args"
    
    # Exécution de push_swap
    echo -e "\n🚀 Exécution de push_swap :"
    start_time=$(date +%s%N)
    output=$(./push_swap $args 2>&1)
    ret=$?
    end_time=$(date +%s%N)
    execution_time=$(( (end_time - start_time) / 1000000 ))
    
    echo "⏱️  Temps d'exécution : ${execution_time} millisecondes"
    if [ $ret -ne 0 ]; then
        echo "❌ Erreur détectée (code: $ret)"
        echo "📝 Sortie: $output"
    else
        echo "✅ Test réussi"
        if [ ! -z "$output" ]; then
            echo "📝 Sortie: $output"
        fi
    fi

    # Test de fuites mémoire avec valgrind
    echo -e "\n🔍 Vérification des fuites mémoire :"
    echo -e "\n=== Test: $test_name ===" >> valgrind.log
    echo "Arguments: $args" >> valgrind.log
    echo "----------------------------------------" >> valgrind.log
    valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind.log.tmp ./push_swap $args >/dev/null 2>&1
    cat valgrind.log.tmp >> valgrind.log
    echo -e "\n\n" >> valgrind.log
    rm -f valgrind.log.tmp
    echo "📝 Rapport de valgrind ajouté à valgrind.log"
    
    echo "✨ ---------------------------------------------"
    echo ""
}

run_all_tests() {
    echo "🎯 Lancement des tests de validation..."
    echo ""
    
    # Initialisation du fichier de log valgrind
    echo "=== Rapport de tests valgrind $(date) ===" > valgrind.log
    echo "=========================================" >> valgrind.log
    echo "" >> valgrind.log
    
    # Test 1: Liste déjà triée
    run_test "Liste triée" "1 2 3 4 5"
    
    # Test 2: Argument invalide
    run_test "Argument invalide" "1 2 3 abc 5"
    
    # Test 3: Nombres en double
    run_test "Nombres en double" "1 2 2 3 4"
    
    # Test 4: Nombre au-dessus de INT_MAX
    run_test "Au-dessus de INT_MAX" "1 2 2147483648 4"
    
    # Test 5: Nombre en-dessous de INT_MIN
    run_test "En-dessous de INT_MIN" "1 -2147483649 3"
    
    echo "✅ Tests terminés"
}

# ==============================================================================
# Vérification des arguments
# ==============================================================================
if [ -z "$1" ]; then
    echo "Usage: $0 [nombre de nombres à générer | test]"
    echo "  - nombre: Génère N nombres aléatoires"
    echo "  - test: Lance la suite de tests"
    exit 1
fi

if [ "$1" = "test" ]; then
    run_all_tests
    exit 0
fi

NUMBERS_COUNT=$1
MAX_UNIQUE=$((INT_MAX - INT_MIN + 1))

if [ "$NUMBERS_COUNT" -gt "$MAX_UNIQUE" ]; then
  echo "Erreur : Impossible de générer $NUMBERS_COUNT nombres uniques entre $INT_MIN et $INT_MAX"
  exit 1
fi

# ==============================================================================
# Génération de nombres uniques avec /dev/urandom
# ==============================================================================
declare -A unique_numbers
selected_numbers=()
ARG=""

echo -n "🎲 Génération de $NUMBERS_COUNT nombres valides "
# Animation de chargement
for i in {1..3}; do
    echo -n "."
    sleep 0.4
done
echo ""
while [ ${#selected_numbers[@]} -lt "$NUMBERS_COUNT" ]; do
  # Génération d'un nombre signé 32-bit via /dev/urandom
  random_number=$(od -An -N4 -t d4 /dev/urandom | tr -d ' ')
  
  # Validation stricte des limites
  if ((random_number >= INT_MIN && random_number <= INT_MAX)); then
    if [[ -z "${unique_numbers[$random_number]}" ]]; then
      unique_numbers[$random_number]=1
      selected_numbers+=("$random_number")
    fi
  fi
done

# Construction de l'argument
ARG=$(printf "%s " "${selected_numbers[@]}")
ARG=${ARG% }

# ==============================================================================
# Exécution du test
# ==============================================================================
echo "✨ ---------------------------------------------"
echo "📊 Nombres générés ($NUMBERS_COUNT éléments) :"
echo "$ARG"
echo "✨ ---------------------------------------------"

# Exécution de push_swap
echo -e "\n🚀 [1/3] Exécution de push_swap :"
start_time=$(date +%s%N)
./push_swap $ARG > operations.txt
end_time=$(date +%s%N)
execution_time=$(( (end_time - start_time) / 1000000 ))

echo "⏱️  Temps d'exécution : ${execution_time} millisecondes"
echo "🔢 Nombre d'opérations : $(wc -l < operations.txt)"

# Test de fuites mémoire avec valgrind
echo -e "\n🔍 [2/3] Vérification des fuites mémoire :"
echo -e "\n=== Test avec nombres aléatoires ===" >> valgrind.log
echo "Nombre d'éléments: $NUMBERS_COUNT" >> valgrind.log
echo "Arguments: $ARG" >> valgrind.log
echo "----------------------------------------" >> valgrind.log
valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind.log.tmp ./push_swap $ARG >/dev/null
cat valgrind.log.tmp >> valgrind.log
rm -f valgrind.log.tmp
echo "📝 Rapport de valgrind enregistré dans valgrind.log"

# Vérification avec checker
echo -e "\n✅ [3/3] Vérification avec checker :"
./checker_linux $ARG < operations.txt

# Nettoyage des fichiers temporaires
rm -f operations.txt
# Note: valgrind.log est conservé pour analyse
echo "✨ ---------------------------------------------"
