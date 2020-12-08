 /********************************** Fichiers d'inclusion ****************************************/
#include "Main.h"
#include "Menu.h"

/*
 * Nom de la fonction : AfficherMenu
 *
 * Description de la fonction : Faire afficher le menu principal au démarrage du programme et afficher
 * les différentes options d'utilisation du programme.
 *
 * Paramètre d'entrée : Aucun
 *
 * Valeur de retour : Le choix de l'utilisateur.
 *
 * Note(s) :
 *
 * Historique : 2020-12-07 / Dany Champagne / Entrée du code
 */

int AfficherMenu() {
    int iChoix = 0;
    while (iChoix < 1 || iChoix > 7) {
        printf("=====Menu principal=====\n\n");
        printf("Charger la base de donnees: Appuyer sur 1.\n\n");
        printf("Afficher les donnees chargees: Appuyex sur 2.\n\n");
        printf("Effectuer un retrait: Appuyer sur 3\n\n");
        printf("Ajouter une quantite d'un item: Appuyex sur 4\n\n");
        printf("Creer un nouvel item: Appuyex sur 5.\n\n");
        printf("Modifier les details d'un item: Appuyey sur 6.\n\n");
        printf("Sauvegarder: Appuyer sur 7.\n\n");
        printf("Votre choix?\n");
        scanf("%d", &iChoix);
    }
    return iChoix;
}
