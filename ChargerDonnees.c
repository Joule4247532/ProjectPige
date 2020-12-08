/************************************** Fichiers d'inclusion ****************************************/
#include "Main.h"
#include "ChargerDonnees.h"

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
int ChargerDonnees(item_t*** items, int* iNbItems, char* sNomFichier){
    int iErr = -1;
    FILE* pBaseDeDonnees = NULL;
    char* sGetString = "\0";
    char* psGetString;
    int iQuantite;
    char* sNom;
    char* sDescription;
    int iIndex = 0;
    char cItem = '\0';




    pBaseDeDonnees = fopen(sNomFichier, "r");
    if (pBaseDeDonnees != NULL) {
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

                    iErr = AjouterItem(&items, &iNbItems, sNom, sDescription, &iQuantite);
                }
            }

            free(sGetString);
            iIndex = iIndex + 1;
        } while (cItem != EOF);
    }
    fclose(pBaseDeDonnees);


    return iErr;
}
