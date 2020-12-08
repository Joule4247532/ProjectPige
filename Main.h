#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define FICHIER_BdD "BdD.csv"
#define HEURE_DATE() printf("%s   %s   %s\n\n", __DATE__, __TIME__, __FILE__);
#define GESTION_INVENTAIRE() printf("/*=========================== GESTIONNAIRE D'INVENTAIRE =================================*/ \n\n");

/********************************** Fichier d'inclusion ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Définition du type item_t
 */
typedef struct {
  int iID;
  char* sNom;
  char* sDescription;
  int iQuantite;
} item_t;

#endif // MAIN_H_INCLUDED


