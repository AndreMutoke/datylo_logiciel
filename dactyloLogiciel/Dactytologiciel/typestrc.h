#ifndef TYPE_STRUCT_H
#define TYPE_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


/**
 * @brief Dactylo definie le systeme lui meme
 *
*/

struct Dactylo
{

    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRender;

    SDL_Texture **m_pMenu;
    SDL_Rect *menuRectSrc;
    SDL_Rect *menuRectDest;

    SDL_Texture *testFont;

    // ++++++++++++ POUR LES OPTIONS DU MENU +++++++++++++++++++++
    
    SDL_Texture *btnJouer;
    SDL_Texture *btnAide;
    SDL_Texture *btnQuitter;
    // -------------------------- les rectangles contenants les menus -------------
    // +++++++++++++++ FIN OPTION DU MENU ++++++++++++++++++++++++
    SDL_Rect Rectselect;

    // +++++++++++++++++++++++++++++ POUR LE MODE JOUER ++++++++++++++++++++++++

    SDL_Rect fenetreInsertion;
    SDL_Texture *Labelquestion;
    SDL_Texture *zone_saisi;
    SDL_Texture *zone_saisi2;
    SDL_Texture *zone_saisi3;

    char joueur1[20];
    char joueur2[20];

    char motSaisiJoueur[50];

    char motJoueur1[50];
    char motJoueur2[50];

    double tempsJoueur1;
    double tempsJoueur2;

    // +++++++++++++++++++++++++++ FIN DU MODE JOUER ++++++++++++++++++++++++++++

    bool m_pRunning;
    bool debuter;

};
typedef struct Dactylo Dactylo;

#endif // TYPE_STRUCT_H