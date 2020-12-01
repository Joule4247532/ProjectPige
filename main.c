#include "TeamHeader.h"

int main() {
  item_t* items;
  short iNbItems;
  
  return 0;
}

/*
 * Nom de la fonction :
 *    AjouterItem
 *
 * Description de la fonction :
 *    Ajoute un Item à listeItems avec allocation de memoire dynamique
 *
 * Paramètre(s) d'entrée :
 *   1 : Pointeur vers listeItems
 *   2 : Pointeur d'entier précisant le nombre d'items contenue dans la liste
 *   3 : Chaine de charactères contenant le nom de l'item
 *   4 : Chaine de charactères contenant la description du l'item
 *   5 : Entier contenant la quantité disponible de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-01 Olivier David Laplante Version 1 Définie
 */
int AjouterItem(item_t* listeItems, short* piNbItems, char* sNom, char* sDescription, int iQuantite){
  int iCodeErreur = 0;
  // Ici

  return iCodeErreur;
}

/*
 * Nom de la fonction :
 *    AjouterQuantiteItem
 *
 * Description de la fonction :
 *    Ajoute une certaine quantité à un item dans la liste d'items
 *
 * Paramètre(s) d'entrée :
 *   1 : Pointeur vers la liste à écrire
 *   2 : Entier précisant le nombre de données contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item à modifier
 *   4 : Entier contenant la quantité à ajouter
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-01 Olivier David Laplante Version 1 Définie
 */
int AjouterQuantiteItem(item_t* listeItems, short piNbItems, short iItemID, short iAjout){
  int iCodeErreur = 0;

  return iCodeErreur;
}

/*
 * Nom de la fonction :
 *    RetirerQuantiteItem
 *
 * Description de la fonction :
 *    Retire une certaine quantité à un item dans la liste d'items
 *
 * Paramètre(s) d'entrée :
 *   1 : Pointeur vers la liste à écrire
 *   2 : Entier précisant le nombre de données contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item à modifier
 *   4 : Entier contenant la quantité à retirer
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-11-17 Olivier David Laplante Version 1 Définie
 */
int RetirerQuantiteItem(item_t* listeItems, short piNbItems, short iItemID, short iRetrait){
  int iCodeErreur = 0;

  return iCodeErreur;
}

/*
 * Nom de la fonction :
 *    ModifierNomItem
 *
 * Description de la fonction :
 *    Change le nom de l'item dans la liste d'items
 *
 * Paramètre(s) d'entrée :
 *   1 : Pointeur vers la liste à écrire
 *   2 : Entier précisant le nombre de données contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item à modifier
 *   4 : Chaine de charactères contenant le nouveau nom de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-11-17 Olivier David Laplante Version 1 Définie
 */
int ModifierNomItem(item_t* listeItems, short piNbItems, short iItemID, char* sNouveauNom){
  int iCodeErreur = 0;

  return iCodeErreur;
}

/*
 * Nom de la fonction :
 *    ModifierDescriptionItem
 *
 * Description de la fonction :
 *    Change la description de l'item dans la liste d'items
 *
 * Paramètre(s) d'entrée :
 *   1 : Pointeur vers la liste à écrire
 *   2 : Entier précisant le nombre de données contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item à modifier
 *   4 : Chaine de charactères contenant la nouvelle description de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-11-17 Olivier David Laplante Version 1 Définie
 */
int ModifierDescriptionItem(item_t* listeItems, short piNbItems, short iItemID, char* sNouvelleDescription){
  int iCodeErreur = 0;

  return iCodeErreur;
}