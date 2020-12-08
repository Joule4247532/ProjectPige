#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include "Recherche_ID.h"

/*
 * Nom de la fonction :
 *    RechercherID
 *
 * Description de la fonction :
 *    Rechercher un item dans la liste
 *
 * Paramètre(s) d'entrée :
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-07 / Dany Champagne / Entrée initial d
 u code
 */
int RechercherID(item_t*** listeItems, short iNbItems) {
    int iCodeErreur = 0;
    int index = 0;
    for (int i = 0; i < iNbItems; i++){
        int *tete = {0, 1, 3};
        int *tete = {0, 1, 3};
        (*listeItems)[index]->iID
        (*listeItems)[index]->iQuantite
        (*listeItems)[index]->sDescription
    }
    return iCodeErreur;
}
