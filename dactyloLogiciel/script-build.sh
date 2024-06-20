#! /usr/bin/bash

#compiler les fichiers du programme
echo "Compilation du programme"
gcc main.c Dactytologiciel/Dactylo.c Dactytologiciel/menuDactylo/menu.c Dactytologiciel/menuDactylo/util.c Dactytologiciel/menuDactylo/deroulement.c -o bin/debug/Dactylo -lSDL2 -lSDL2_image -lSDL2_ttf
