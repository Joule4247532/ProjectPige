#include "TeamHeader.h"

int main() {
  int iCodeErreur = 0;
  item_t** items = NULL;
  short iNbItems = 0;
  
  return iCodeErreur;
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
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int AjouterItem(item_t*** listeItems, short* piNbItems, char* sNom, char* sDescription, int iQuantite){
  int iCodeErreur = 0;

  // Allocation de l'espace d'un item
  item_t *p = malloc(sizeof(*p));
  if (p) {
    // Assignation des élems de l'item

    // ID
    p->iID = *piNbItems;

    // Nom
    p->sNom = strcpy((char *) malloc(sizeof(char) * (strlen(sNom) + 1)), sNom);

    // Description
    p->sDescription = strcpy((char *) malloc(sizeof(char) * (strlen(sDescription) + 1)), sDescription);

    // Quantité
    p->iQuantite = iQuantite;

    // Allocation de la mémoire nécécaire à la liste temporairement
    item_t **tempList = realloc(*listeItems, (*piNbItems + 1) * sizeof(*tempList));
    if (tempList){
      // Mettre les pointeurs dans leurs cases mémoires
      *listeItems = tempList;
      (*listeItems)[*piNbItems] = p;
      // Incrémentation du nombre d'item dans la liste
      *piNbItems += 1;
    } else {
      // Si le realloc n'a pas pu alloquer la mémoire
      iCodeErreur = -1;
    }
  } else {
    // Si le malloc de l'item dans p n'a pas réussi
    iCodeErreur = -1;
  }

  return iCodeErreur; // Retourner le code d'erreur s'il y a lieu
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
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int AjouterQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iAjout){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Si la quantité est positive
    if (iAjout >= 0) {
      // Ajouter l'ajout à la quantité
      (*listeItems)[iItemID]->iQuantite += iAjout;
    } else {
      // Si l'ajout est négatif le rendre positif et appeler la fonction pour retirer la quantité ;)
      iAjout = -iAjout;
      iCodeErreur = RetirerQuantiteItem(listeItems, piNbItems, iItemID, iAjout);
    }
  } else {
    // Si le ID est invalide, retourner un code d'erreur
    iCodeErreur = -1;
  }

  return iCodeErreur; // Retourner le code d'erreur s'il y a lieu
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
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int RetirerQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iRetrait){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Si la quantité est positive
    if (iRetrait >= 0) {
      // Retirer le retrait à la quantité
      (*listeItems)[iItemID]->iQuantite -= iRetrait;
    } else {
      // Si le retrait est négatif le rendre positif et appeler la fonction pour ajouter la quantité ;)
      iRetrait = -iRetrait;
      iCodeErreur = AjouterQuantiteItem(listeItems, piNbItems, iItemID, iRetrait);
    }
  } else {
    // Si le ID est invalide, retourner un code d'erreur
    iCodeErreur = -1;
  }

  return iCodeErreur; // Retourner le code d'erreur s'il y a lieu
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
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int ModifierNomItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouveauNom){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Liberer la mémoire occupé par l'ancien nom
    free((*listeItems)[iItemID]->sNom);
    // Alloquer l'espace mémoire du nouveau nom et mettre son addresse dans l'item
    (*listeItems)[iItemID]->sNom = strcpy((char *) malloc(sizeof(char) * (strlen(sNouveauNom) + 1)), sNouveauNom);
  } else {
    // Si le ID est invalide, retourner un code d'erreur
    iCodeErreur = -1;
  }

  return iCodeErreur; // Retourner le code d'erreur s'il y a lieu
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
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int ModifierDescriptionItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouvelleDescription){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Liberer la mémoire occupé par l'ancienne description
    free((*listeItems)[iItemID]->sDescription);
    // Alloquer l'espace mémoire de la nouvelle description et mettre son addresse dans l'item
    (*listeItems)[iItemID]->sDescription = strcpy((char *) malloc(sizeof(char) * (strlen(sNouvelleDescription) + 1)),
                                          sNouvelleDescription);
  } else {
    // Si le ID est invalide, retourner un code d'erreur
    iCodeErreur = -1;
  }

  return iCodeErreur;
}