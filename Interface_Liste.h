#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

int AjouterItem(item_t*** listeItems, int* piNbItems, char* sNom, char* sDescription, int* iQuantite);
int AjouterQuantiteItem(item_t*** listeItems, int piNbItems, int iItemID, int iAjout);
int RetirerQuantiteItem(item_t*** listeItems, int piNbItems, int iItemID, int iRetrait);
int ModifierNomItem(item_t*** listeItems, int piNbItems, int iItemID, char* sNouveauNom);
int ModifierDescriptionItem(item_t*** listeItems, int piNbItems, int iItemID, char* sNouvelleDescription);

#endif // INTERFACE_H_INCLUDED
