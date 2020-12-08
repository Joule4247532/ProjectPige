#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Main.h"
#include "Sauvegarde.h"

/*
 * Nom de la fonction :
 *    AjouterItem
 *
 * Description de la fonction :
 *    Ajoute un Item � listeItems avec allocation de memoire dynamique
 *
 * Param�tre(s) d'entr�e :
 *   1 : Pointeur vers listeItems
 *   2 : Pointeur d'entier pr�cisant le nombre d'items contenue dans la liste
 *   3 : Chaine de charact�res contenant le nom de l'item
 *   4 : Chaine de charact�res contenant la description du l'item
 *   5 : Entier contenant la quantit� disponible de l'item
 *
 * Valeur de retour :
 *   0  : Aucune erreur
 *   -1 : Une erreur est survenue
 *
 * Note(s) :
 *
 * Historique :
 *    2020-12-01 Olivier David Laplante Version 1 D�finie
 *    2020-12-06 Olivier David Laplante Version 1 Finie
 */

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
      fprintf(fiFichier, "%i;%s;%s;%i\n",
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
