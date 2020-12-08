#include "Main.h"

/*
 * Nom de la fonction :
 *    AfficherMenu
 *
 * Description de la fonction :
 *    Afficher le menu principal
 *
 * Param�tre(s) d'entr�e :
 *   1 : Pointeur vers listeItems
 *   2 : Pointeur d'entier pr�cisant le nombre d'items contenue dans la liste
 *   3 : Chaine de charact�res contenant le nom de l'item
 *   4 : Chaine de charact�res contenant la description du l'item
 *   5 : Entier contenant la quantit� disponible de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-01 Olivier David Laplante Version 1 D�finie
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */

int AfficherMenu() {
    int choix = 0;
    while (choix < 1 || choix > 6) {
        printf("=====Menu principal=====\n\n");
        printf("Charger la base de donnees: Appuyer sur 1.\n\n");
        printf("Effectuer un retrait: Appuyex sur 2.\n\n");
        printf("Afficher les donnees chargees: Appuyer sur 3\n\n");
        printf("Creer un nouvel item: Appuyex sur 4\n\n");
        printf("Ajouter une quantite d'un item: Appuyex sur 5.\n\n");
        printf("Modifier les details d'un item: Appuyex sur 6.\n\n");
        printf("Votre choix?\n");
        scanf("%d", &choix);
    }
    return choix;
}
