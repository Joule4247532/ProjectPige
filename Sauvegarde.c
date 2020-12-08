#include "Main.h"
#include "Sauvegarde.h"

int sauvegarderDonnees(item_t*** listeItems, short iNbItems, char* sNomFichier){
  int iCodeErreur = 0;

  // Ouvcerture du fichier pour écrire en overwrite
  FILE *fiFichier = fopen(sNomFichier, "w");

  // Continuer seulement si le fichier existe
  if (fiFichier) {
    // Mettre l'en-tête de la database
    fprintf(fiFichier, "ID;Nom;Description;Quantite");

    // Lire les items et mettre les élems dans la database
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