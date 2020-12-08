/* Nom du fichier: Main.c
 *
 * Description: Ce programme est un gestionnaire d'inventaire du magasin de pièces électroniques du collège.
 *              Le programme permet à l'utilisateur de modifier l'inventaire du magasin en soustraiyant ou en rajoutant
 *              des quantités de pièces. Il peut modifier les noms et description ainsi que rajouter
 *              des composants nnouveaux.
 *
 *  Historique: 2020-12-07 / D. Champagne / Entrée initiale du code.
*/

/********************************** Fichier d'inclusion ***********************************/
#include "Main.h"
#include "Interface_Liste.h"
#include "Menu.h"
#include "Recherche_ID.h"
#include "Sauvegarde.h"
#include "ChargerDonnees.h"

int main() {
    char sNouveauNom[100];
    char sNouvelleDescription[2000];
    char sNouvelleQuantite[16];
    int iCodeErreur = 0;
    item_t** items = NULL;
    int iNbItems = 0;
    int iID = 0;
    int iNouvelleQuantite = 0;
    int iRetire = 0;
    int iContinuerProgramme = 1;

    // Titre
    GESTION_INVENTAIRE()
    // L'heure et la date du fichier.
    HEURE_DATE()

    do {
        switch (AfficherMenu()) {
            case 1:
                printf("Vous avez choisi: Charger la base de donnees.\n\n");

                // Appel de la fonction de chargement de données.
                ChargerDonnees(&items, &iNbItems, FICHIER_BdD);
                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            case 2:
                printf("Vous avez choisi: Afficher les donnees chargees.\n\n");

                // Appel de la fonction d'affichage.
                for (int i = 0; i < iNbItems; i++) {
                    printf("%i;%s;%s;%i\n",
                        items[i]->iID,
                        items[i]->sNom,
                        items[i]->sDescription,
                        items[i]->iQuantite);
                }
                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            case 3:
                printf("Vous avez choisi: Effectuer un retrait.\n\n");


                // Appel de la fonction de recherche.
                iID = RechercherID(&items);
                fflush(stdin);
                printf("Entrez la quantite a retirer\n");
                scanf("%d", &iRetire);
                // Appel de la fonction de retrait.
                RetirerQuantiteItem(&items, iNbItems, iID, iRetire);

                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            case 4:
                printf("Vous avez choisi: Ajouter une quantite d'un item.\n\n");

                // Appel de la fonction de recherche.
                iID = RechercherID(&items);
                fflush(stdin);
                printf("Entrez la quantite a ajouter:\n");
                scanf("%d", &iNouvelleQuantite);
                // Appel de la fonction d'ajout.
                AjouterQuantiteItem(&items, iNbItems, iID, iNouvelleQuantite);
                // Appel de la fonction d'affichage.

                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            case 5:
                printf("Vous avez choisi: Creer un nouvel item.\n\n");

                fflush(stdin);
                printf("Entrez le nom de l'item:\n");
                fgets(sNouveauNom, sizeof(sNouveauNom), stdin);
                fflush(stdin);
                printf("Entrez la description de l'item:\n");
                fgets(sNouvelleDescription, sizeof(sNouvelleDescription), stdin);
                fflush(stdin);
                printf("Entrez la quantite du nouvel item ajoute a l'inventaire:\n");
                iNouvelleQuantite = strtol(fgets(sNouvelleQuantite, sizeof(sNouvelleQuantite), stdin), NULL, 10);
                fflush(stdin);

                sNouveauNom[strlen(sNouveauNom)-1] = '\0';
                sNouvelleDescription[strlen(sNouvelleDescription)-1] = '\0';

                // Appel de la fonction de creation d'item.
                AjouterItem(&items, &iNbItems, sNouveauNom, sNouvelleDescription, iNouvelleQuantite);
                memset(sNouveauNom, '\0', (strlen(sNouveauNom)+1)*sizeof(char));
                memset(sNouvelleDescription, '\0', (strlen(sNouvelleDescription)+1)*sizeof(char));
                memset(sNouvelleQuantite, '\0', (strlen(sNouvelleQuantite)+1)*sizeof(char));

                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            case 6:
                printf("Vous avez choisi: Modifier les details d'un item.\n\n");

                // Appel de la fonction de recherche.
                iID = RechercherID(&items);
                fflush(stdin);
                printf("Entrez le nouveau nom de l'item:\n");
                fgets(sNouveauNom, sizeof(sNouveauNom), stdin);
                fflush(stdin);
                sNouveauNom[strlen(sNouveauNom)-1] = '\0';
                // Appel de la fonction de modification du nom de l'item.
                ModifierNomItem(&items, iNbItems, iID, sNouveauNom);
                fflush(stdin);
                printf("Entrez la description de l'item:\n");
                fgets(sNouvelleDescription, sizeof(sNouvelleDescription), stdin);
                fflush(stdin);
                sNouvelleDescription[strlen(sNouvelleDescription)-1] = '\0';
                // Appel de la fonction de modification de description de l'item.
                ModifierDescriptionItem(&items, iNbItems, iID, sNouvelleDescription);

                memset(sNouveauNom, '\0', (strlen(sNouveauNom)+1)*sizeof(char));
                memset(sNouvelleDescription, '\0', (strlen(sNouvelleDescription)+1)*sizeof(char));
                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            case 7:
                printf("Sauvegarde en cours...\n\n");
                SauvegarderDonnees(&items, iNbItems, FICHIER_BdD);
                printf("Fini\n");
                printf("Entrez 1 pour continuer, entrez 0 pour quitter.\n");
                scanf("%d", &iContinuerProgramme);
                break;
            default:
                while (iContinuerProgramme != 0) {
                    printf("Il faut impérativement entrer un des 6 choix du menu.\n");
                    break;
                }
        }
    } while (iContinuerProgramme != 0);
    for (int i = 0; i < iNbItems; i++){
        free(items[i]->sNom);
        free(items[i]->sDescription);
        free(items[i]);
    }
    free(items);

    return iCodeErreur;
}
