/************************************** Fichiers d'inclusion ****************************************/
#include "Main.h"
#include "Sauvegarde.h"

/*
 * Nom de la fonction :
 *    SauvegarderDonnees
 *
 * Description de la fonction : Sauvegarde les items dans le fichier.
 *
 * Paramètre(s) d'entrée :
 *   1 : Pointeur vers listeItems.
 *   2 : Entier précisant le nombre d'items contenue dans la liste.
 *   3 : Pointeur vers le nom du fichier.
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-07 Olivier David Laplante Version 1 Définie
 */

int SauvegarderDonnees(item_t*** listeItems, int iNbItems, char* sNomFichier){
  int iCodeErreur = 0;

  // Ouvcerture du fichier pour écrire en overwrite
  FILE *fiFichier = fopen(sNomFichier, "w");

  // Continuer seulement si le fichier existe
  if (fiFichier != NULL) {
    // Mettre l'en-tête de la database
    fprintf(fiFichier, "ID;Nom;Description;Quantite");

    // Lire les items et mettre les élements dans la database
    for (int i = 0; i < iNbItems; i++) {
      fprintf(fiFichier, "%i;%s;%s;%i\r",
              (*listeItems)[i]->iID,
              (*listeItems)[i]->sNom,
              (*listeItems)[i]->sDescription,
              (*listeItems)[i]->iQuantite);
    }

    // Fermer le fichier
    fclose(fiFichier);
  } else {
    // Retourner le code d'erreur
    iCodeErreur = -1;
  }

  // Retourner le code d'erreur s'il y a lieu
  return iCodeErreur;
}
