#ifndef MENU_DACTYLO_H
#define MENU_DACTYLO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../typestrc.h"


bool timeToWait(clock_t debut);
void initTableauMenu(Dactylo *dactylo);
void testTTF(Dactylo *dactylo, const char *texte, const char *font, int sizee);
void btnJouer(Dactylo *dactylo, const char *texte, const char *Font, int sizee);
void btnAide(Dactylo *dactylo, const char *texte, const char *Font, int sizee);
void btnQuitter(Dactylo *dactylo, const char *texte, const char *Font, int sizee);

void InsertLabel(Dactylo *dactylo, const char *texte, const char *Font, int sizee);
void InsertZoneSaisi(Dactylo *dactylo, const char *texte, const char *Font, int sizee);
void InsertZoneSaisi2(Dactylo *dactylo, const char *texte, const char *Font, int sizee);
void InsertZoneSaisi3(Dactylo *dactylo, const char *texte, const char *Font, int sizee);

void animateBegin(Dactylo *dactylo, clock_t debut);


void menu(Dactylo *dactylo);
void renduJeux(Dactylo *dactylo);
void renduAide(Dactylo *dactylo);

#endif // MENU_DACTYLO_H