#include "Dactylo.h"
#include "menuDactylo/menu.h"
#include "menuDactylo/util.h"
#include "menuDactylo/deroulement.h"

#include <time.h>
#include <string.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>


static clock_t debut ;
extern size_t pos;
extern int numJoeur;
extern int ctrlPos;
extern int peuxGenerer;

extern clock_t debutJoueur1;
extern clock_t debutJoueur2;
extern MENU menuSelect;

extern MODE modeJeuxSYsteme;
extern SDL_Event event;

extern bool Gameur1;

bool init(Dactylo *dactylo, 
          const char *titre, 
          int xpos, 
          int ypos, 
          int width, 
          int height)
{
    ctrlPos = 1;
    pos = 0; numJoeur = 1; 
    peuxGenerer = 0;
    dactylo->debuter = true;
    
    Gameur1 = true;

    memset(dactylo->joueur1, '\0', 20*sizeof(char));
    memset(dactylo->joueur2, '\0', 20*sizeof(char));

    memset(dactylo->motSaisiJoueur, '\0', 50 * sizeof(char));

    memset(dactylo->motJoueur1, '\0', 50 * sizeof(char));
    memset(dactylo->motJoueur2, '\0', 50 * sizeof(char));

    menuSelect = JOUER;
    modeJeuxSYsteme = MODE_MENU;

    dactylo->m_pRender = 0;
    dactylo->m_pWindow = 0;
    dactylo->m_pRunning = false;
    if(SDL_Init(SDL_INIT_EVERYTHING) >=0)
    {
        TTF_Init();
        // printf("Creation de la fenetre\n");
        dactylo->m_pWindow = SDL_CreateWindow(titre, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        if(dactylo->m_pWindow == 0) {
            // printf("Probleme de creation de la fenetre\n");
            return false;
        }
        else{
            // printf("La fenetre a ete creee\n");
            
            // printf("Preparation du rendu\n");
            dactylo->m_pRender = SDL_CreateRenderer(dactylo->m_pWindow, -1, 0);
            if(dactylo->m_pRender == 0)
            {
                // printf("Probleme de prepation du rendu\n");
                SDL_DestroyWindow(dactylo->m_pWindow);
                return false;
            }
            else
            {
                // printf("Le rendu est pret\n");
                debut = clock();
                // testTTF(dactylo);
                testTTF(dactylo, "Dactylo-LOGICIEL", "snacker-comic/SnackerComic_PerosnalUseOnly.ttf",50);
                btnJouer(dactylo, "Jouer", "snacker-comic/SnackerComic_PerosnalUseOnly.ttf", 50);
                btnAide(dactylo, "Aide", "snacker-comic/SnackerComic_PerosnalUseOnly.ttf", 50);
                btnQuitter(dactylo, "Quitter", "snacker-comic/SnackerComic_PerosnalUseOnly.ttf", 50);

                // +++++++++++++++++++++++++++++++++ POUR LA PARTIE EN MODE JEU +++++++++++++++++++++++++++++++++++++++


                
                SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
                SDL_Surface *icone;
                icone = SDL_LoadBMP("images/icone.bmp");
                SDL_SetWindowIcon(dactylo->m_pWindow, icone);
                SDL_FreeSurface(icone);
            }
        }
    }
    else {return false;}

    // printf("Initialisation avec success\nInitialisation des images...\n");
    initTableauMenu(dactylo);

    
    // printf("La fonction clavier : %d \n", SDL_GetWindowGrab(dactylo->m_pWindow));
    // dactylo->m_pRunning = true;
    return true;
}

void update(Dactylo *dactylo)
{
    if(modeJeuxSYsteme == MODE_JOUER)
    {
        if(mdJoueur == DEVINE_MOT){ 
            if(numJoeur== 1 || numJoeur == 2){
                jouerJeu(dactylo, &pos);
            }
            
        }
        //jouerJeu();
    }
}

void controlClavier(Dactylo *dactylo, SDL_Event *event, size_t *pos)
{
     
    if(*pos == 0){dactylo->joueur2[*pos] = '\0';}
    // printf("la valeur de pos %lu\n", *pos);
    switch (event->key.keysym.sym)
    {
                    
    case SDLK_0 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '0'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '0'; *pos = (*pos) + 1;}

        if((mdJoueur == DEVINE_MOT)) 
        {
                dactylo->motJoueur1[*pos] = '0'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_1 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '1'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '1'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
           dactylo->motJoueur1[*pos] = '1'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_2 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '2'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '2'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '2'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_3 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '3'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '3'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '3'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_4 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '4'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '4'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '4'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_5 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '5'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '5'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '5'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_6 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '6'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '6'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '6'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_7 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '7'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '7'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '7'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_8 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '8'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '8'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)){
            dactylo->motJoueur1[*pos] = '8'; *pos = (*pos) + 1;
        }
        break;
    case SDLK_9 :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = '9'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = '9'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = '9'; *pos = (*pos) + 1;
        }
        break;
    case SDLK_a :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'a'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'a'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'a'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_b :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'b'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'b'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'b'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_c :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'c'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'c'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'c'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_d :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'd'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'd'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'd'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_e :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'e'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'e'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'e'; *pos = (*pos) + 1;
        }
        break;
    case SDLK_f :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'f'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'f'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'f'; *pos = (*pos) + 1;
        }
        break;
    case SDLK_g :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'g'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'g'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'g'; *pos = (*pos) + 1;            
        }
        break;
    case SDLK_h :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'h'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'h'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'h'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_i :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'i'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'i'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'i'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_j :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'j'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'j'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'j'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_k :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'k'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'k'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'k'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_l :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'l'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'l'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'l'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_m :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'm'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'm'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'm'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_n :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'n'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'n'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'n'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_o :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'o'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'o'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'o'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_p :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'p'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'p'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'p'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_q :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'q'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'q'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'q'; *pos = (*pos) + 1;            
        }
        break;
    case SDLK_r :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'r'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'r'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'r'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_s :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 's'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 's'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 's'; *pos = (*pos) + 1;
        }
        break;
    case SDLK_t :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 't'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 't'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 't'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_u :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'u'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'u'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'u'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_v :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'v'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'v'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'v'; *pos = (*pos) + 1;            
        }
        break;
    case SDLK_w :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'w'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'w'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'w'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_x :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'x'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'x'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'x'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_y :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'y'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'y'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'y'; *pos = (*pos) + 1;
            
        }
        break;
    case SDLK_z :
        if((mdJoueur == INSERT_J2)) {dactylo->joueur2[*pos] = 'z'; *pos = (*pos) + 1;}
        if((mdJoueur == INSERT_J1)) {dactylo->joueur1[*pos] = 'z'; *pos = (*pos) + 1;}
        if((mdJoueur == DEVINE_MOT)) 
        {
            dactylo->motJoueur1[*pos] = 'z'; *pos = (*pos) + 1;
        }
        break;
    case SDLK_SPACE:
        if((mdJoueur == INSERT_J2) && (modeJeuxSYsteme == MODE_JOUER))
        {
            dactylo->joueur2[*pos] = '\n';
            *pos = 0;
            SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            debutJoueur1 = clock();
            mdJoueur = DEVINE_MOT;
        }
        else if((mdJoueur == INSERT_J1) && (modeJeuxSYsteme == MODE_JOUER))
        {
            dactylo->joueur1[*pos] = '\n';
            *pos = 0;
            // printf("la valeur de pos %lu\nla valeur des chars : %s\n", *pos, dactylo->motJoueur1);
            SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            mdJoueur = INSERT_J2;
        }
        if((mdJoueur == DEVINE_MOT) && (modeJeuxSYsteme == MODE_JOUER))
        {
            
                dactylo->motJoueur1[*pos] = '\n';
                // printf("Le motJoueur : %s",dactylo->motJoueur1);
                *pos = 0;
                // if(numJoeur == 2)
                // {
                //     debutJoueur1
                // }
                SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
                // Gameur1 = false;
                ctrlPos = 2;
                if(numJoeur == 3)
                {
                    modeJeuxSYsteme = MODE_MENU;
                    menuSelect = JOUER;
                    mdJoueur = INSERT_J1;
                    memset(dactylo->joueur1, '\0', 20 * sizeof(char));
                    memset(dactylo->joueur2, '\0', 20 * sizeof(char));
                    memset(dactylo->motJoueur1, '\0', 50 * sizeof(char));
                    memset(dactylo->motJoueur2, '\0', 50 * sizeof(char));
                    memset(dactylo->motSaisiJoueur, '\0', 50 * sizeof(char));

                    dactylo->tempsJoueur1 = 0.0;
                    dactylo->tempsJoueur2 = 0.0;
                    ctrlPos = 1;
                    numJoeur = 1;
                    peuxGenerer = 0;
                }

                // mdJoueur = DEVINE_MOT;
            
        } 
        if(modeJeuxSYsteme == MODE_AIDE)
        {
            modeJeuxSYsteme = MODE_MENU;
        }                       
                        
        break;
    // case SDLK_ESCAPE :
    //     // modeJeuxSYsteme = MODE_MENU;
    //     // menuSelect = JOUER;
    //     // mdJoueur = INSERT_J1;
    //     // memset(dactylo->joueur1, '\0', 20 * sizeof(char));
    //     // memset(dactylo->joueur2, '\0', 20 * sizeof(char));
    //     // memset(dactylo->motJoueur1, '\0', 50 * sizeof(char));
    //     // memset(dactylo->motJoueur2, '\0', 50 * sizeof(char));
    //     // memset(dactylo->motSaisiJoueur, '\0', 50 * sizeof(char));

    //     // dactylo->tempsJoueur1 = 0.0;
    //     // dactylo->tempsJoueur2 = 0.0;
    //     // ctrlPos = 1;
    //     // numJoeur = 1;
    //     // peuxGenerer = 0;
    //     break;
    default:
                        
        break;
    }
}

void handleEvent(Dactylo *dactylo)
{
    // printf("Le modeJeuxSysteme vaut : %d\n Le menuSelect vaut : %d\n", modeJeuxSYsteme, menuSelect);
    //pos = 0;
    int unicode;
    
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            dactylo->m_pRunning = false;
            break;
        case SDL_KEYDOWN:
            if(modeJeuxSYsteme ==  MODE_MENU)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    if(menuSelect == JOUER)
                    {
                        menuSelect = QUITTER;
                    }
                    else if(menuSelect == AIDE)
                    {
                        menuSelect = JOUER;
                    }
                    else if(menuSelect == QUITTER)
                    {
                        menuSelect = AIDE;
                    }
                    break;
                case SDLK_DOWN:
                    if(menuSelect == JOUER)
                    {
                        menuSelect = AIDE;
                    }
                    else if(menuSelect == AIDE)
                    {
                        menuSelect = QUITTER;
                    }
                    else if(menuSelect == QUITTER)
                    {
                        menuSelect = JOUER;
                    }
                    
                    break;
                case SDLK_RETURN:
                    if(menuSelect == JOUER)
                    {
                        modeJeuxSYsteme = MODE_JOUER;
                        mdJoueur = INSERT_J1;
                    }
                    else if(menuSelect == AIDE)
                    {
                        // printf("On est ici\n");
                        modeJeuxSYsteme = MODE_AIDE;
                    }
                    else if(menuSelect == QUITTER)
                    {
                        modeJeuxSYsteme = MODE_QUITTER;
                    }
                    
                    break;
                
                default:
                    break;
                }
                

            }
            if(modeJeuxSYsteme == MODE_JOUER)
            {
                if(mdJoueur == INSERT_J1 || mdJoueur == INSERT_J2)
                {

                    controlClavier(dactylo, &event, &pos);
                }

                if(mdJoueur == DEVINE_MOT)
                {
                    // printf("modee Devine\n");
                    controlClavier(dactylo, &event, &pos);
                }
            }
            if(modeJeuxSYsteme ==  MODE_AIDE)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    modeJeuxSYsteme = MODE_MENU;                    
                    break;
                
                default:
                    break;
                }
                

            }

            
            break;
        
        default:
            break;
        }
    }
}

void render(Dactylo *dactylo)
{
   
    
    SDL_RenderClear(dactylo->m_pRender);

    if(dactylo->debuter)
    {
        animateBegin(dactylo, debut);
    }
    else{
        if(modeJeuxSYsteme == MODE_MENU)
        {
            menu(dactylo);
        }
        else if(modeJeuxSYsteme == MODE_JOUER)
        {
            // Rendu du mode jeux ici
            renduJeux(dactylo);
        }
        else if(modeJeuxSYsteme == MODE_AIDE)
        {
            // Rendu du mode AIDE ici
            renduAide(dactylo);
        }
        else if(modeJeuxSYsteme == MODE_QUITTER)
        {
            // mode quitter
            dactylo->m_pRunning = false;
            // SDL_Quit();
        }
        // renderBtn(&dactylo->btnJouer, dactylo->m_pRender);
    }
    

    SDL_RenderPresent(dactylo->m_pRender);
}

void clean(Dactylo *dact)
{
    SDL_DestroyWindow(dact->m_pWindow);
    SDL_DestroyRenderer(dact->m_pRender);

    TTF_Quit();

    SDL_Quit();
    // printf("Fin du programme\n");
}

