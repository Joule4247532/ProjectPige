#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choix = 0;
    while (choix < 1 || choix > 6) {
        printf("=====Menu principal=====\n\n");
        printf("Charger la base de donn�es: Appuyer sur 1.\n\n");
        printf("Effectuer un retrait: Appuyex sur 2.\n\n");
        printf("AaAppuyex sur 3\n\n");
        printf("Cr�er un nouvel item: Appuyex sur 4\n\n");
        printf("Ajouter une quantit� d'un item: Appuyex sur 4.\n\n");
        printf("Votre choix?\n");
        scanf("%d", &choix);
    }
    return choix;
}
