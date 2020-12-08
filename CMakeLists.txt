cmake_minimum_required(VERSION 3.17)
project(ProjectPige C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjectPige main.c Main.h Interface_Liste.c Interface_Liste.h Menu.c Menu.h Sauvegarde.c Sauvegarde.h Recherche_ID.c Recherche_ID.h ChargerDonnees.c ChargerDonnees.h)