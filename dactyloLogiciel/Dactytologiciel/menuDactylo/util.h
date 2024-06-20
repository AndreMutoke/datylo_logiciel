#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

enum Mode
{
    MODE_MENU,
    MODE_JOUER,
    MODE_AIDE, 
    MODE_QUITTER
};
typedef enum Mode MODE;

enum ModeMenu
{
    JOUER,
    AIDE,
    QUITTER
};
typedef enum ModeMenu MENU;

enum MODE_JOUEUR
{
    INSERT_J1,
    INSERT_J2,
    DEVINE_MOT,
    SHOW_RESULT, 
    QUESTION_TO_RESTART
};
typedef enum MODE_JOUEUR MODE_JOUEUR;

extern MODE_JOUEUR mdJoueur;
extern SDL_Event event;

extern MENU menuSelect;

extern MODE modeJeuxSYsteme;



#endif // UTIL_H