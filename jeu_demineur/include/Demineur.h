#ifndef DEMINEUR_H
#define DEMINEUR_H
#include<fstream>
#include <iostream>
using namespace std;
#include <stdlib.h>
class Demineur
{
public:
    Demineur();
    ~Demineur();
    void menu();
    void AfficheJeu();
    void tbool(bool V[1000][1000], int m, int n);
    void decouvrirX(int m, int n, int i, int j);
    int saisir_nb_mines(int m, int n);
    void Regles();
    int NbMinesAutour(int i,int j);
    int nbvisible(int m, int n);
    void INFO(int nb, int vis, int coup);
    void nouveauJeu();
    void BEGIN();
    void Quitter();
protected:
private:
    int coup=0;
    int m,n;
    char JEU[1000][1000];
    bool V[1000][1000];
    int i,j;//i les lignes, j les colonnes
    char MINES[1000][1000];//la grille avec les mines
    int N;//Nombre de mines autour
};

#endif // DEMINEUR_H
