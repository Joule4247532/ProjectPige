#include "Main.h"
#include "Interface_Liste.h"
#include "Menu.h"
#include "Recherche_ID.h"

int main() {
    int iCodeErreur = 0;
    item_t** items = NULL;
    short iNbItems = 0;
    int iContinueProgramme = 1;

    do {

/******************************************************Menu principal*********************************************************/

        switch (menu()) {
            case 1:
                printf("Vous avez choisi de charger la base de donnees.\n\n");

                while (iContinueProgramme == 1) {
                    // Appel de la fonction de chargement de donn�es.
                    RechercherID(&items);

                    // On demande si l'utilisateur veut sortir du proramme.
                    printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                    scanf("%d", &iContinueProgramme);
                }
            case 2:
                printf("Vous avez choisi d'effectuer un retrait.\n\n");

                while (iContinueProgramme == 1){
                    // Appel de la fonction de retrait.
                    int RetirerQuantiteItem(item_t*** listeItems, short piNbItems, short iItemID, int iRetrait);

                    // On demande si l'utilisateur veut sortir du proramme.
                    printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                    scanf("%d", &iContinueProgramme);
                }
            case 3:
                printf("Vous avez choisi d'afficher les donnees chargees.\n\n");

                while (iContinueProgramme == 1) {
                    // Appel de la fonction de chargement de donn�es.

                    // On demande si l'utilisateur veut sortir du proramme.
                    printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                    scanf("%d", &iContinueProgramme);
                }

                // On demande si l'utilisateur veut sortir du proramme.
                printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                scanf("%d", &iContinueProgramme);
            case 4:
                printf("Vous avez choisi de cr�er un nouvel item.\n\n");

                while (iContinueProgramme == 1) {
                    // Appel de la fonction de chargement de donn�es.

                    // On demande si l'utilisateur veut sortir du proramme.
                    printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                    scanf("%d", &iContinueProgramme);
                }
            case 5:
                printf("Vous avez choisi d'ajouter une quantit� d'un item.\n\n");

                while (iContinueProgramme == 1) {
                    // Appel de la fonction de chargement de donn�es.

                    // On demande si l'utilisateur veut sortir du proramme.
                    printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                    scanf("%d", &iContinueProgramme);
                }
            case 6:
                printf("Vous avez choisi de modifier les d�tails d'un item.\n\n");

                while (iContinueProgramme == 1) {
                    // Appel de la fonction de chargement de donn�es.

                    // On demande si l'utilisateur veut sortir du proramme.
                    printf("Entrez 1 pour continuer, sinon entrez 0.\n");
                    scanf("%d", &iContinueProgramme);
                }
            default:
                while (iContinueProgramme == 1) {
                    printf("Il faut entrer un des 6 choix du menu: 1, 2, 3, 4, 5 ou 6.\n");
                    break;
                }
        }
    } while (iContinueProgramme == 1);

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

/*
 * Nom de la fonction :
 *    ChargerDonnees
 *
 * Description de la fonction :
 *    Charge les données de BdD.csv dans la structure.
 *
 * Paramètre(s) d'entrée :
 *   Un pointeur vers la structure item_t
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-07    Paul Richard    Création du code
 */
int ChargerDonnees(item_t*** items, short* iNbItems, char* sNomFichier){
    int iErr = -1;
    FILE* pBaseDeDonnees = NULL;
    char* sGetString = "\0";
    char* psGetString;
    short iID;
    int iQuantite;
    char* sNom;
    char* sDescription;
    int iIndex = 0;
    char cItem = '\0';




    pBaseDeDonnees = fopen(sNomFichier, "r");
    if (pBaseDeDonnees) {
        do {
            sGetString = malloc(sizeof(char));
            iErr = sGetString != NULL ? 0 : -1;
            cItem = '\0';

            for (int i = 0; cItem != '\r' && iErr != -1 && cItem != EOF; i++) {
                cItem = (char) fgetc(pBaseDeDonnees);
                sGetString = (char*) realloc(sGetString, (i+1)*sizeof(char));
                iErr = sGetString == NULL ? -1 : 0;
                if (iErr == 0 && cItem != EOF)
                    sGetString[i] = cItem;
            }

            if (iErr == 0) {
                if (iIndex != 0) {
                    psGetString = strtok(sGetString, NETTOYAGE);
                    psGetString = strtok(NULL, NETTOYAGE);
                    sNom = psGetString;
                    psGetString = strtok(NULL, NETTOYAGE);
                    sDescription = psGetString;
                    psGetString = strtok(NULL, NETTOYAGE);
                    iQuantite = strtol(psGetString, NULL, 10);

                    iErr = AjouterItem(items, iNbItems, sNom, sDescription, iQuantite);
                }
            }

            free(sGetString);
            iIndex = iIndex + 1;
        } while (cItem != EOF);
    }
    fclose(pBaseDeDonnees);


    return iErr;
}