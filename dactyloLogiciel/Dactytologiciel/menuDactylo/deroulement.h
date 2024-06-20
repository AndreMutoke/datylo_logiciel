#ifndef DEROULEMENT_H
#define DEROULEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../typestrc.h"


int genererMots(char *mots[], int nombre);
void jouerJeu(Dactylo *dactylo, size_t *pos);

#endif // DEROULEMENT_H