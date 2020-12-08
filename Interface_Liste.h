#ifndef GÈRER_ITEM_H_INCLUDED
#define GÈRER_ITEM_H_INCLUDED

int AjouterItem(item_t*** listeItems, short* piNbItems, char* sNom, char* sDescription, int iQuantite);
int AjouterQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iAjout);
int RetirerQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iRetrait);
int ModifierNomItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouveauNom);
int ModifierDescriptionItem(item_t*** listeItems, short piNbItems, short iItemID, char* sNouvelleDescription);

#endif // GÈRER_ITEM_H_INCLUDED
