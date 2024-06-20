#include "menu.h"
#include <time.h>

#include "util.h"

#define TAB_MENU_SIZE 4

extern int numJoeur;

extern MENU menuSelect;
extern MODE_JOUEUR mdJoueur;
extern MODE modeJeuxSYsteme;

extern int peuxGenerer;
bool timeToWait(clock_t debut)
{
    clock_t fin = clock();
    // printf("La fin est : %lf\n",(((double)(fin - debut)) / CLOCKS_PER_SEC));

    if( (((double)(fin - debut)) / CLOCKS_PER_SEC) >= (double) 1.0 ){
        //dactylo->debuter = false;
        // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        return true;
        
    }
    return false;
}

void initTableauMenu(Dactylo *dactylo)
{
    dactylo->m_pMenu = malloc(TAB_MENU_SIZE * sizeof(SDL_Texture*));
    if(dactylo->m_pMenu == NULL) {return; /*false;*/}

    dactylo->menuRectSrc = malloc(TAB_MENU_SIZE * sizeof(SDL_Rect));
    if(dactylo->menuRectSrc == NULL) {return; /*false;*/}

    dactylo->menuRectDest = malloc(TAB_MENU_SIZE * sizeof(SDL_Rect));
    if(dactylo->menuRectDest == NULL) {return; /*false;*/}

    for(int i=0; i< TAB_MENU_SIZE; ++i)
    {
        *(dactylo->m_pMenu+i) = NULL;
    }
// ++++++++++++++++++++++++++++++ ON COMMENCE AVEC L'ELEMENT DE LA POSITION [0] DU MENU QUI EST LE LOGO +++++++++++++++++++++++++++++++++++++

    SDL_Surface *tempS = NULL;
    tempS = SDL_LoadBMP("images/icone.bmp");
    *(dactylo->m_pMenu+0) = SDL_CreateTextureFromSurface(dactylo->m_pRender, tempS);
    SDL_FreeSurface(tempS);

    SDL_QueryTexture(*(dactylo->m_pMenu+0), NULL, NULL,  &dactylo->menuRectSrc[0].w, &dactylo->menuRectSrc[0].h);

    dactylo->menuRectSrc[0].x = 0;
    dactylo->menuRectDest[0].x = 280;
    dactylo->menuRectSrc[0].y = 10;
    dactylo->menuRectDest[0].y = 140;
    dactylo->menuRectDest[0].w = dactylo->menuRectSrc[0].w;
    dactylo->menuRectDest[0].h = dactylo->menuRectSrc[0].h;

    printf("Le width est : %d et le height est %d\n", dactylo->menuRectSrc[0].w, dactylo->menuRectSrc[0].h);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FINI AVEC LE LOGO ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++ PUIS VIENT LE TEXTE A LA POSITION [1]+++++++++++++++++++++++++++++++++++++++++++

    

}

void testTTF(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {0, 0, 0};

    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);

    dactylo->testFont = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);

    TTF_CloseFont(font);
}
void btnJouer(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {0, 0, 0};

    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);

    dactylo->btnJouer = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);

    TTF_CloseFont(font);
}
void btnAide(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {0, 0, 0};

    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);

    dactylo->btnAide = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);

    TTF_CloseFont(font);
}

void btnQuitter(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {0, 0, 0};

    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);

    dactylo->btnQuitter = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);

    TTF_CloseFont(font);
}

void InsertLabel(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {255, 255, 255};
    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);
    dactylo->Labelquestion = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);
    TTF_CloseFont(font);
}

void InsertZoneSaisi(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {255, 255, 0};
    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);
    dactylo->zone_saisi = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);
    TTF_CloseFont(font);
}
void InsertZoneSaisi2(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {255, 255, 0};
    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);
    dactylo->zone_saisi2 = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);
    TTF_CloseFont(font);
}
void InsertZoneSaisi3(Dactylo *dactylo, const char *texte, const char *Font, int sizee)
{
    TTF_Font *font = TTF_OpenFont(Font, sizee);
    SDL_Color color = {255, 255, 0};
    SDL_Surface *srf = TTF_RenderText_Solid(font, texte, color);
    dactylo->zone_saisi3 = SDL_CreateTextureFromSurface(dactylo->m_pRender, srf);
    TTF_CloseFont(font);
}
void animateBegin(Dactylo *dactylo, clock_t debut)
{

    clock_t fin = clock();

    int testW=0; int testH=0;
    SDL_QueryTexture(dactylo->testFont, NULL, NULL, &testW, &testH);
    SDL_Rect dtest = {190, 250, testW, testH};

    SDL_RenderCopy(dactylo->m_pRender, dactylo->m_pMenu[0], &dactylo->menuRectSrc[0], &dactylo->menuRectDest[0]);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->testFont, NULL, &dtest);
    fin = clock();
    // printf("La fin est : %lf\n",(((double)(fin - debut)) / CLOCKS_PER_SEC));

    if( (((double)(fin - debut)) / CLOCKS_PER_SEC) >= (double) 1.0 ){
        dactylo->debuter = false;
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        
    }
    
}

void menu(Dactylo *dactylo)
{
    int testW=0; int testH=0;
    

    switch (menuSelect)
    {
    case JOUER:
        dactylo->Rectselect.x = 95;
        dactylo->Rectselect.y = 15;
        SDL_QueryTexture(dactylo->btnJouer, NULL, NULL, &dactylo->Rectselect.w, &dactylo->Rectselect.h);
        dactylo->Rectselect.w += 10;
        dactylo->Rectselect.h += 10;
        SDL_SetRenderDrawColor(dactylo->m_pRender, 0, 200, 0, 10);
        SDL_RenderFillRect(dactylo->m_pRender, &dactylo->Rectselect);
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        
        break;
    case AIDE:
        dactylo->Rectselect.x = 95;
        dactylo->Rectselect.y = dactylo->Rectselect.h + 35;
        SDL_QueryTexture(dactylo->btnAide, NULL, NULL, &dactylo->Rectselect.w, &dactylo->Rectselect.h);
        dactylo->Rectselect.w += 10;
        dactylo->Rectselect.h += 10;
        SDL_SetRenderDrawColor(dactylo->m_pRender, 0, 200, 0, 10);
        SDL_RenderFillRect(dactylo->m_pRender, &dactylo->Rectselect);
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        break;
    case QUITTER:
        dactylo->Rectselect.x = 95;
        dactylo->Rectselect.y =2 * (dactylo->Rectselect.h + 35);
        SDL_QueryTexture(dactylo->btnQuitter, NULL, NULL, &dactylo->Rectselect.w, &dactylo->Rectselect.h);
        dactylo->Rectselect.w += 10;
        dactylo->Rectselect.h += 10;
        SDL_SetRenderDrawColor(dactylo->m_pRender, 0, 200, 0, 10);
        SDL_RenderFillRect(dactylo->m_pRender, &dactylo->Rectselect);
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        break;
    default:
        break;
    }

    SDL_QueryTexture(dactylo->btnJouer, NULL, NULL, &testW, &testH);
    SDL_Rect dtest = {100, 20, testW, testH};
    SDL_RenderCopy(dactylo->m_pRender, dactylo->btnJouer, NULL, &dtest);
    

    SDL_QueryTexture(dactylo->btnAide, NULL, NULL, &testW, &testH);
    dtest.y = dtest.h + 50;
    dtest.w = testW;
    dtest.h = testH;
    SDL_RenderCopy(dactylo->m_pRender, dactylo->btnAide, NULL, &dtest);

    SDL_QueryTexture(dactylo->btnQuitter, NULL, NULL, &testW, &testH);
    dtest.y = 2 * (dtest.h + 50);
    dtest.w = testW;
    dtest.h = testH;
    SDL_RenderCopy(dactylo->m_pRender, dactylo->btnQuitter, NULL, &dtest);

    int test2W=0; int test2H=0;
    SDL_QueryTexture(dactylo->m_pMenu[0], NULL, NULL, &test2W, &test2H);
    SDL_Rect d2test = {480, 280, test2W, test2H};
    SDL_RenderCopy(dactylo->m_pRender, dactylo->m_pMenu[0], &dactylo->menuRectSrc[0], &d2test);
}

void renduJeux(Dactylo *dactylo)
{
    
    int xpos = 50; int ypos = 50;
    int width = 540; int height = 380;
    dactylo->fenetreInsertion.x = xpos;
    dactylo->fenetreInsertion.y = ypos;
    dactylo->fenetreInsertion.w = width;
    dactylo->fenetreInsertion.h = height;

    SDL_SetRenderDrawColor(dactylo->m_pRender, 0, 0, 0, 255);
    SDL_RenderFillRect(dactylo->m_pRender, &dactylo->fenetreInsertion);
    SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);

    if(mdJoueur == INSERT_J1)
    {
        InsertLabel(dactylo, "Entrez le nom du joueur 1", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
        // int posX = 60; int posY = 60;

        SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &width, &height);

        SDL_Rect posLabel = {60, 60, width, height};
        
        // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

        InsertZoneSaisi(dactylo, dactylo->joueur1, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);

        posLabel.y = height + 72;
        posLabel.x = posLabel.x + 15;
        SDL_QueryTexture(dactylo->zone_saisi, NULL, NULL, &posLabel.w, &posLabel.h);        
        
        SDL_RenderCopy(dactylo->m_pRender, dactylo->zone_saisi, NULL, &posLabel);

        posLabel.y = height + 70;
        posLabel.x = 60 + 5;
        posLabel.w = dactylo->fenetreInsertion.w - 30;
        posLabel.h = height + 5;
        
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        SDL_RenderDrawRect(dactylo->m_pRender, &posLabel);
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
    }
    if(mdJoueur == INSERT_J2)
    {
        InsertLabel(dactylo, "Entrez le nom du joueur 2", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
        // int posX = 60; int posY = 60;

        SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &width, &height);

        SDL_Rect posLabel = {60, 60, width, height};

        dactylo->zone_saisi = NULL;
        
        // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

        InsertZoneSaisi(dactylo, dactylo->joueur2, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);

        posLabel.y = height + 72;
        posLabel.x = posLabel.x + 15;
        
        
        SDL_QueryTexture(dactylo->zone_saisi, NULL, NULL, &posLabel.w, &posLabel.h);        
        
        SDL_RenderCopy(dactylo->m_pRender, dactylo->zone_saisi, NULL, &posLabel);

        posLabel.y = height + 70;
        posLabel.x = 60 + 5;
        posLabel.w = dactylo->fenetreInsertion.w - 30;
        posLabel.h = height + 5;
        
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        SDL_RenderDrawRect(dactylo->m_pRender, &posLabel);
        SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
// +++++++++++++++++++++++++++++++++ partie de devinette +++++++++++++++++++++++++++++++++++++++++


        
    }
    if(mdJoueur == DEVINE_MOT)
    {
        
        if(numJoeur == 1)
        {
            // printf("Rendu devine mot\n");
            char phrase1[250];
            strcpy(phrase1, dactylo->joueur1);
            strcat(phrase1, ", Saisit : "); 
            if(peuxGenerer == 1)
            {
                strcat(phrase1, dactylo->motSaisiJoueur); 
            }
            InsertLabel(dactylo, (const char*)phrase1, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // InsertLabel(dactylo, "Entrez le nom du joueur 2", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // int posX = 60; int posY = 60;

            SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &width, &height);

            SDL_Rect posLabel = {60, 60, width, height};
            
            
            // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);
            dactylo->zone_saisi = NULL;

            InsertZoneSaisi(dactylo, dactylo->motJoueur1, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);

            posLabel.y = height + 72;
            posLabel.x = posLabel.x + 15;
            
            
            SDL_QueryTexture(dactylo->zone_saisi, NULL, NULL, &posLabel.w, &posLabel.h);        
            
            SDL_RenderCopy(dactylo->m_pRender, dactylo->zone_saisi, NULL, &posLabel);

            posLabel.y = height + 70;
            posLabel.x = 60 + 5;
            posLabel.w = dactylo->fenetreInsertion.w - 30;
            posLabel.h = height + 5;
            
            SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            SDL_RenderDrawRect(dactylo->m_pRender, &posLabel);
            SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        }
        else if(numJoeur == 2)
        {
            // printf("Rendu devine mot\n");
            char phrase1[350];
            strcpy(phrase1, dactylo->joueur2);
            strcat(phrase1, ", Saisit : "); 
            if(peuxGenerer == 1)
            {
                strcat(phrase1, dactylo->motSaisiJoueur); 
            }

            InsertLabel(dactylo, (const char*)phrase1, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // InsertLabel(dactylo, "Entrez le nom du joueur 2", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // int posX = 60; int posY = 60;

            SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &width, &height);

            SDL_Rect posLabel = {60, 60, width, height};
            
            
            // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);
            dactylo->zone_saisi = NULL;

            InsertZoneSaisi(dactylo, dactylo->motJoueur1, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);

            posLabel.y = height + 72;
            posLabel.x = posLabel.x + 15;
            
            
            SDL_QueryTexture(dactylo->zone_saisi, NULL, NULL, &posLabel.w, &posLabel.h);        
            
            SDL_RenderCopy(dactylo->m_pRender, dactylo->zone_saisi, NULL, &posLabel);

            posLabel.y = height + 70;
            posLabel.x = 60 + 5;
            posLabel.w = dactylo->fenetreInsertion.w - 30;
            posLabel.h = height + 5;
            
            SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            SDL_RenderDrawRect(dactylo->m_pRender, &posLabel);
            SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
        }
        else if(numJoeur == 3)
        {
            char phrase1[350];
            if(dactylo->tempsJoueur1 > dactylo->tempsJoueur2)
            {
                strcpy(phrase1, dactylo->joueur1);
                strcat(phrase1, ", est plus rapide que "); 
                strcat(phrase1, dactylo->joueur2);
                strcat(phrase1, "joueur 2");
            }
            else if(dactylo->tempsJoueur1 < dactylo->tempsJoueur2)
            {
                strcpy(phrase1, dactylo->joueur2);
                strcat(phrase1, " joueur 2, est plus rapide que "); 
                strcat(phrase1, dactylo->joueur1);
                
            }
            else
            {
                strcpy(phrase1, "les deux joueur ont la meme vitesse au clavier");
            }
            // char phrase1[350];

            InsertLabel(dactylo, (const char*)phrase1, "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // InsertLabel(dactylo, "Entrez le nom du joueur 2", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // int posX = 60; int posY = 60;

            SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &width, &height);

            SDL_Rect posLabel = {60, 60, width, height};
            
            
            // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
            SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);
            
        }
        
    }        

    
}

void renduAide(Dactylo *dactylo)
{
    int xpos = 50; int ypos = 50;
    int width = 540; int height = 380;
    dactylo->fenetreInsertion.x = xpos;
    dactylo->fenetreInsertion.y = ypos;
    dactylo->fenetreInsertion.w = width;
    dactylo->fenetreInsertion.h = height;

    SDL_SetRenderDrawColor(dactylo->m_pRender, 0, 0, 0, 255);
    SDL_RenderFillRect(dactylo->m_pRender, &dactylo->fenetreInsertion);
    SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);

    InsertLabel(dactylo, "+++++++++ Projet Langage C ++++++++++", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // InsertLabel(dactylo, "Entrez le nom du joueur 2", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
            // int posX = 60; int posY = 60;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &width, &height);
    SDL_Rect posLabel = {60, 60, width, height};     
            // SDL_SetRenderDrawColor(dactylo->m_pRender, 255, 255, 255, 255);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "Presente par : ", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = height + 72;
    posLabel.x = posLabel.x + 15;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);
    InsertLabel(dactylo, "MUKEBO ILUNGA Gift", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    // posLabel.x = posLabel.x + 15;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    // MUKEBO ILUNGA GIFT\nMUSEKA KASUBA GABRIEL\nMUKAZO MAZANGA DON\nMUTWALE ILUNGA ADORA
    InsertLabel(dactylo, "MUSEKA KASUBA Gabriel", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    // posLabel.x = posLabel.x + 15;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "MUKAZO MAZANGA Don", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    // posLabel.x = posLabel.x + 15;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "MUTWALE ILUNGA Adora", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    // posLabel.x = posLabel.x + 15;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    // ++++++++++++++++++++++++++ PRINCIPE DU JEUX +++++++++++++++++++++++++++++++

    InsertLabel(dactylo, "++++++++++++++++++++++++++ PRINCIPE DU JEUX ++++++++++++++++++++++++++++", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +20 ;
    // posLabel.x = posLabel.x + 15;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "Une fois le jeus lance, il faudra inserer les noms des deux joueurs", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "Pour valider, il faut apuyer sur ESPACE", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "Les joueurs devronts deviner le mot que l'ordinateur aura", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "generer, ces mots sont :", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "langage, niveau, logiciel, clavier, programmation, piratage", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "reseau, design, informatique", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "Le vainqueur est celui qui aura mis le moins de temps pour", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);

    InsertLabel(dactylo, "deviner et ecrire le mot genere par l'ordinateur", "JetBrainsMono/fonts/ttf/JetBrainsMono-Light.ttf", 12);
    posLabel.y = posLabel.y +15 ;
    SDL_QueryTexture(dactylo->Labelquestion, NULL, NULL, &posLabel.w, &posLabel.h);
    SDL_RenderCopy(dactylo->m_pRender, dactylo->Labelquestion, NULL, &posLabel);
    
    
}