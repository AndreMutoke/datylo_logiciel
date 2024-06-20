#include <time.h>

#include "deroulement.h"

char *mots[] = {"langage", "niveau", "logiciel", "clavier", "programmation", "piratage", "reseau", "design", "informatique"};

extern clock_t debutJoueur1;
extern clock_t debutJoueur2;

extern int numJoeur;
extern int ctrlPos;
extern int peuxGenerer;
int genererMots(char *mots[], int nombre)
{
   
    srand(time(NULL)); // initialisation de l'index qui genere le mots
    int t = rand() % (nombre + 1);
    
    return t;
}

void jouerJeu(Dactylo *dactylo, size_t *pos)
{
    static int nbTour = 0;
   
    clock_t fin;
    
    static char motdesir[25];
    if(peuxGenerer == 0)
    {
        memset(motdesir, '\0', 25 * sizeof(char));
        strcpy(motdesir, mots[genererMots(mots, 9)]);
        peuxGenerer = 1;
    }
    
    // printf("la position  est : %lu\n", *pos); 
    printf("le mot genere est : %s\n", motdesir);
    memset(dactylo->motSaisiJoueur, '\0', 50 * sizeof(char));
    strcpy(dactylo->motSaisiJoueur, motdesir);

    // debut du temps de saisi
    
        if(strcmp(dactylo->motJoueur1, motdesir) != 0)
        {
            
        }
        else
        {
           
            fin = clock();
            // strcpy(dactylo->motJoueur2, dactylo->motJoueur1);
            memset(dactylo->motJoueur1, '\0', 50 * sizeof(char));
            *pos = 0;
            peuxGenerer = 0;
            nbTour++;

            if(numJoeur == 1){
                
                if(nbTour >= 7)
                {
                    dactylo->tempsJoueur1 = ((double)(fin - debutJoueur1)) / CLOCKS_PER_SEC;
                    strcpy(dactylo->motJoueur2, dactylo->motJoueur1);
                    memset(dactylo->motJoueur1, '\0', 50 * sizeof(char));
                    // memset(dactylo->motSaisiJoueur, '\0', 50 * sizeof(char));
                    numJoeur = 2;
                    nbTour = 0;
                }
                }
            else if(numJoeur == 2){
                if(nbTour >=7)
                {
                    dactylo->tempsJoueur2 = ((double)(fin - debutJoueur1)) / CLOCKS_PER_SEC;
                    numJoeur = 3;
                    nbTour = 0;
                }
                
            }
        
        }

}
