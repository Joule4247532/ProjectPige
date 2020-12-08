#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Définition du type item_t
 */
typedef struct {
  short iID;
  char* sNom;
  char* sDescription;
  int iQuantite;
} item_t;

#endif // MAIN_H_INCLUDED
