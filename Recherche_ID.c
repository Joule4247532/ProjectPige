/******************************************** Fichiers d'inclusion ******************************************/
#include "Main.h"
#include "Recherche_ID.h"

/*
 * Nom de la fonction : RechercherID
 *
 * Description de la fonction : Rechercher un item dans la liste.
 *
 * Param�tre(s) d'entr�e : 1 : Pointeur vers listeItems.
 *                         2 : Entier pr�cisant le num�ro d'identification de l'item.
 *                         3 : Chaine de charact�res contenant le nom de l'item.
 *                         4 : Chaine de charact�res contenant la description du l'item.
 * Valeur de retour : 0 : Aucune erreur
 *                   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique : 2020-12-07 / Dany Champagne / Entr�e initial du code
 */

int RechercherID(item_t*** listeItems) {
    int iCodeErreur = 0;
    int iID = 0;
    printf("Entrez le numero d'identification de la piece recherchee:\n");
    scanf("%d", &iID);
    return iID-1;

}
