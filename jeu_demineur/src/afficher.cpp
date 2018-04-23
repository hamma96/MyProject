#include "afficher.h"

afficher::afficher()
{
    //ctor
}

afficher::~afficher()
{
    //dtor
}

void afficher::Regles()
    {
        cout << "        ******************************************************************" <<endl;
        cout << "        *                             REGLES                             *" <<endl;
        cout << "        *                                                                *" <<endl;
        cout << "        * Le but du jeu est de trouver avec moins de coups toutes les    *" <<endl;
        cout << "        * cases du plateau contenant des mines sans les toucher.         *" <<endl;
        cout << "        * Avant de lancer le jeu, le joueur peut configurer les          *" <<endl;
        cout << "        * dimensions du plateau (de la matrice de cases) et le nombre    *" <<endl;
        cout << "        * initial de mines.                                              *" <<endl;
        cout << "        * Pour jouer une partie de démineur, le joueur commence par      *" <<endl;
        cout << "        * découvrir une case de son choix en précisant les cordonnées    *" <<endl;
        cout << "        * (n° ligne et n° colonne). Le joueur va passer son temps à      *" <<endl;
        cout << "        * découvrir ou marquer des cases visant à gagner la partie et    *" <<endl;
        cout << "        * entrer dans les meilleurs scores.                              *" <<endl;
        cout << "        * Le jeu est terminé et le joueur a perdu, si le contenu de la   *" <<endl;
        cout << "        * case est une mine (M).Si le joueur trouve toutes les cases du  *" <<endl;
        cout << "        * plateau contenant des mines sans les toucher,il gagne la partie*" <<endl;
        cout << "        ******************************************************************" <<endl;

    }
void afficher::menu()
    {
        cout << "        ****************************************************************\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                        1. Nouvelle partie                    *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                         2. Regles du jeu                     *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                          3. Scores                           *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        *                                                              *\n"
             "        ****************************************************************\n" <<endl<<endl;

    }
