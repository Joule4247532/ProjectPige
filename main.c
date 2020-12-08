#include "Main.h"
#include "Interface_Liste.h"
#include "Menu.h"

int main() {
    int iCodeErreur = 0;
    item_t** items = NULL;
    short iNbItems = 0;
    int iContinueProgramme = 1;

     do {

/******************************************************Menu principal*********************************************************/

        switch (menu()) {
            case 1:
                printf("Vous avez choisi de charger la base de donn�es.\n\n");

                while (iContinueProgramme == 1) {
                    // Appel de la fonction de chargement de donn�es.

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
                printf("Vous avez choisi d'afficher les donn�es charg�es.\n\n");

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
