#include <stdio.h>
#include <stdlib.h>


typedef struct item_t {
  short iID;
  char* sNom;
  char* sDescription;
  int iQuantite;
} item_t;

/*
 * Interface pour listeItems
 */
int AjouterItem(item_t* listeItems, short* piNbItems, struct item_t* item);
int ModifierItem(item_t* listeItems, short iItemID);