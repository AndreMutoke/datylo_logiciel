#ifndef DACTYLOGICIEL_H
#define DACTYLOGICIEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "typestrc.h"



/// @brief init permet d'initialiser une instance Dactylo
/// @param dactylo 
/// @param titre 
/// @param xpos 
/// @param ypos 
/// @param width 
/// @param height 
/// @return une valeur booleen est revoyee
bool init(Dactylo *dactylo, 
          const char *titre, 
          int xpos, 
          int ypos, 
          int width, 
          int height);

void controlClavier(Dactylo *dactylo, SDL_Event *event, size_t *pos);
void handleEvent(Dactylo *dactylo);

void render(Dactylo *dactylo);
void update(Dactylo *dactylo);
void clean(Dactylo *dact);



#endif // DACTYLOGICIEL_H