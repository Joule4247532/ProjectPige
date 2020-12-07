#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Définition du type item_t
 */
typedef struct {
  short iID;
  char* sNom;
  char* sDescription;
  int iQuantite;
} item_t;

/*
 * Interface pour listeItems
 */
int AjouterItem(item_t*** listeItems, short* piNbItems, char* sNom, char* sDescription, int iQuantite);
int AjouterQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iAjout);
int RetirerQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iRetrait);
int ModifierNomItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouveauNom);
int ModifierDescriptionItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouvelleDescription);