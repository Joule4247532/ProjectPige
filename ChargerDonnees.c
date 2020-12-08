/******************************************** Fichiers d'inclusion *********************************************/
#include "Main.h"
#include "Interface_Liste.h"
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
    int iErr = 0;
    char* psGetString = NULL;
    int iQuantite = 0;
    char* sNom = NULL;
    char* sDescription = NULL;
    char * buffer = 0;
    long length;
    FILE * f = fopen (sNomFichier, "rb");

    if (f != NULL) {
        printf("Fichier ouvert\n");
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer) {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    }
    else {
        printf("Echec\n");
    }

    if (buffer) {
        psGetString = strtok(buffer, "\t\n\r;");
      psGetString = strtok(NULL, "\t\n\r;");
      psGetString = strtok(NULL, "\t\n\r;");
      psGetString = strtok(NULL, "\t\n\r;");
      psGetString = strtok(NULL, "\t\n\r;");

        while(psGetString != NULL && iErr != -1) {
            psGetString = strtok(NULL, "\t\n\r;");
          if (psGetString != NULL)
            sNom = psGetString;
          if (psGetString != NULL)
            psGetString = strtok(NULL, "\t\n\r;");
          if (psGetString != NULL)
            sDescription = psGetString;
          if (psGetString != NULL)
            psGetString = strtok(NULL, "\t\n\r;");
          if (psGetString != NULL)
            iQuantite = atoi(psGetString);
          if (psGetString != NULL)
            iErr = AjouterItem(items, iNbItems, sNom, sDescription, iQuantite);
          if (psGetString != NULL)
            printf("%s\n", (*items)[*iNbItems - 1]->sNom);
          if (psGetString != NULL)
            psGetString = strtok(NULL, "\t\n\r;");
        }
    }
    return iErr;
}
