#include "Main.h"
#include "Interface_Liste.h"

/*
 * Nom de la fonction :
 *    AjouterItem
 *
 * Description de la fonction :
 *    Ajoute un Item � listeItems avec allocation de memoire dynamique
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
int AjouterItem(item_t*** listeItems, short* piNbItems, char* sNom, char* sDescription, int iQuantite){
  int iCodeErreur = 0;

  // Allocation de l'espace d'un item
  item_t *p = malloc(sizeof(*p));
  if (p) {
    // Assignation des �lems de l'item

    // ID
    p->iID = *piNbItems +1;

    // Nom
    p->sNom = strcpy((char *) malloc(sizeof(char) * (strlen(sNom) + 1)), sNom);

    // Description
    p->sDescription = strcpy((char *) malloc(sizeof(char) * (strlen(sDescription) + 1)), sDescription);

    // Quantit�
    p->iQuantite = iQuantite;

    // Allocation de la m�moire n�c�caire � la liste temporairement
    item_t **tempList = realloc(*listeItems, (*piNbItems + 1) * sizeof(*tempList));
    if (tempList){
      // Mettre les pointeurs dans leurs cases m�moires
      *listeItems = tempList;
      (*listeItems)[*piNbItems] = p;
      // Incr�mentation du nombre d'item dans la liste
      *piNbItems += 1;
    } else {
      // Si le realloc n'a pas pu alloquer la m�moire
      iCodeErreur = -1;
    }
  } else {
    // Si le malloc de l'item dans p n'a pas r�ussi
    iCodeErreur = -1;
  }

  return iCodeErreur; // Retourner le code d'erreur s'il y a lieu
}

/*
 * Nom de la fonction :
 *    AjouterQuantiteItem
 *
 * Description de la fonction :
 *    Ajoute une certaine quantit� � un item dans la liste d'items
 *
 * Param�tre(s) d'entr�e :
 *   1 : Pointeur vers la liste � �crire
 *   2 : Entier pr�cisant le nombre de donn�es contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item � modifier
 *   4 : Entier contenant la quantit� � ajouter
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
int AjouterQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iAjout){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Si la quantit� est positive
    if (iAjout >= 0) {
      // Ajouter l'ajout � la quantit�
      (*listeItems)[iItemID]->iQuantite += iAjout;
    } else {
      // Si l'ajout est n�gatif le rendre positif et appeler la fonction pour retirer la quantit� ;)
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
 *    Retire une certaine quantit� � un item dans la liste d'items
 *
 * Param�tre(s) d'entr�e :
 *   1 : Pointeur vers la liste � �crire
 *   2 : Entier pr�cisant le nombre de donn�es contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item � modifier
 *   4 : Entier contenant la quantit� � retirer
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-11-17 Olivier David Laplante Version 1 D�finie
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int RetirerQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iRetrait){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Si la quantit� est positive
    if (iRetrait >= 0) {
      // Retirer le retrait � la quantit�
      (*listeItems)[iItemID]->iQuantite -= iRetrait;
    } else {
      // Si le retrait est n�gatif le rendre positif et appeler la fonction pour ajouter la quantit� ;)
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
 * Param�tre(s) d'entr�e :
 *   1 : Pointeur vers la liste � �crire
 *   2 : Entier pr�cisant le nombre de donn�es contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item � modifier
 *   4 : Chaine de charact�res contenant le nouveau nom de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-11-17 Olivier David Laplante Version 1 D�finie
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int ModifierNomItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouveauNom){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Liberer la m�moire occup� par l'ancien nom
    free((*listeItems)[iItemID]->sNom);
    // Alloquer l'espace m�moire du nouveau nom et mettre son addresse dans l'item
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
 * Param�tre(s) d'entr�e :
 *   1 : Pointeur vers la liste � �crire
 *   2 : Entier pr�cisant le nombre de donn�es contenue dans la liste
 *   3 : Entier contenant le No identificateur de l'item � modifier
 *   4 : Chaine de charact�res contenant la nouvelle description de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-11-17 Olivier David Laplante Version 1 D�finie
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */
int ModifierDescriptionItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouvelleDescription){
  int iCodeErreur = 0;

  // Si le ID est valide
  if (iItemID > 0 && iItemID < piNbItems){
    // Liberer la m�moire occup� par l'ancienne description
    free((*listeItems)[iItemID]->sDescription);
    // Alloquer l'espace m�moire de la nouvelle description et mettre son addresse dans l'item
    (*listeItems)[iItemID]->sDescription = strcpy((char *) malloc(sizeof(char) * (strlen(sNouvelleDescription) + 1)),
                                          sNouvelleDescription);
  } else {
    // Si le ID est invalide, retourner un code d'erreur
    iCodeErreur = -1;
  }

  return iCodeErreur;
}
