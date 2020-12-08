#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NETTOYAGE "\t\n\r;"

/*
 * D�finition du type item_t
 */
typedef struct {
  short iID;
  char* sNom;
  char* sDescription;
  int iQuantite;
} item_t;


