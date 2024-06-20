#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Dactytologiciel/Dactylo.h"
#include "Dactytologiciel/typestrc.h"
#include "Dactytologiciel/menuDactylo/menu.h"
#include "Dactytologiciel/menuDactylo/runningMenu.h"
#include "Dactytologiciel/menuDactylo/util.h"

clock_t debutJoueur1;
clock_t debutJoueur2;
size_t pos;

int numJoeur;
int ctrlPos;
int peuxGenerer;

SDL_Event event;
MODE_JOUEUR mdJoueur;
MENU menuSelect;
MODE modeJeuxSYsteme;

Dactylo myDactylo;
bool Gameur1;

int main(int argc, char *argv[])
{
    myDactylo.m_pRunning = init(&myDactylo, "Dactylo-LOGICIEL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480);

    while(myDactylo.m_pRunning)
    {
        handleEvent(&myDactylo);
        update(&myDactylo);
        render(&myDactylo);

    }

    clean(&myDactylo);
    return 0;
}