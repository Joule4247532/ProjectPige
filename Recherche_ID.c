/*************************************** Fichiers d'inclusion *************************************/
#include "Main.h"
#include "Recherche_ID.h"

/*
 * Nom de la fonction : RechercherID
 *
 * Description de la fonction : Rechercher un item dans la liste.
 *
 * Paramètre(s) d'entrée : 1 : Pointeur vers listeItems.
 *                         2 : Entier précisant le numéro d'identification de l'item.
 *                         3 : Chaine de charactères contenant le nom de l'item.
 *                         4 : Chaine de charactères contenant la description du l'item.
 * Valeur de retour : 0 : Aucune erreur
 *                   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique : 2020-12-07 / Dany Champagne / Entrée initial du code
 */

int RechercherID(item_t*** listeItems) {
    int iID = 0;
    printf("Entrez le numero d'identification de la piece recherchee:\n");
    scanf("%d", &iID);
    for (int iNbItems = 0; iNbItems < 10; iNbItems++) {
        if ((*listeItems)[iNbItems]->iID == iID) {
        return iID;
        }
        else {
            printf("Le numéro d'identification entre est invalide\n");
        }
    }
}
