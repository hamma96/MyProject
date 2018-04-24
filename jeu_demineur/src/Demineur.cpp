#include "Demineur.h"
#include"Case.h"
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BOLDBLUE    "\033[1m\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
Demineur::Demineur(){}
Demineur::~Demineur(){}
void Demineur::menu()
    {   cout<<endl<<endl;
        cout <<CYAN<< "        ****************************************************************\n"
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
             "        ****************************************************************\n"<<RESET<<endl<<endl;

    }
void Demineur::AfficheJeu()
    {
        cout<<endl;
        cout <<CYAN<< "        ****************************************************************" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *         "<<RESET;
        for(int i=0; i<n; i++)
        {   if (i<9)
                cout<<"   "<<i+1;
            else cout<<"  "<<i+1; }
        cout <<CYAN<< "            *"<< RESET<<endl;

        for (int i=0 ; i<m ; i++)
        {
            if (i<9)
            {
                cout <<CYAN<< "        *         " <<RESET<< i+1 << " ";
            }
            else
            {
                cout <<CYAN<< "        *        " <<RESET<< i+1 << " ";
            }

            for (int j(0) ; j<n ; ++j)
            {
                if(JEU[i][j]!=getcacher() && JEU[i][j]!=getVide() && JEU[i][j]!=getDrapeau())
                    cout<<RED<<" "<<JEU[i][j]<<"  "<<RESET;
                else if (JEU[i][j]==getDrapeau())
                    cout<<BOLDBLUE<<" "<<JEU[i][j]<<"  "<<RESET;
                else cout<<" "<<JEU[i][j]<<"  ";

            }
            cout <<CYAN<< "           *" <<endl;
        }
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        ****************************************************************" <<RESET<<endl;

    }
void Demineur::tbool(bool V[1000][1000], int m, int n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                V[i][j]=false;
            }
        }
    }
void Demineur::decouvrirX(int m, int n, int i, int j)
    {
        if(V[i][j]==false)
        {

            JEU[i][j]=MINES[i][j];
            V[i][j]=true;
            if(MINES[i][j]==getVide())
            {

                if(i>0)
                {
                    decouvrirX(m, n, i-1, j);
                }
                if(i>0 && j>0)
                {
                    decouvrirX(m, n, i-1, j-1);
                }
                if(j>0)
                {
                    decouvrirX(m, n, i, j-1);
                }
                if(j>0 && i<m-1)
                {
                    decouvrirX(m, n, i+1, j-1);
                }
                if(i<m-1 && j<n-1)
                {
                    decouvrirX(m, n, i+1, j+1);
                }
                if(i>0 && j<n-1)
                {
                    decouvrirX(m, n, i-1, j+1);   //oui
                }
                if(i<m-1)
                {
                    decouvrirX(m, n, i+1, j);
                }
                if(j<n-1)
                {
                    decouvrirX(m, n, i, j+1);
                }
            }

        }
    }


int Demineur::saisir_nb_mines(int m, int n)
    {
        int nb;

        do
        {
            cout<<MAGENTA<<"\n\tVeuillez saisir le nombre de mines que vous voulez placez: "<<RESET;
            cin>>nb;
        }
        while(nb<=0 || nb>m*n);
        return nb;
    }
void Demineur::Regles()
    {
        cout<<endl;
        cout <<CYAN "        ******************************************************************" <<endl;
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
        cout << "        ******************************************************************" <<RESET<<endl;

    }

int Demineur::NbMinesAutour(int i,int j)
    {
        N=0;
        if (i==0)
        {
            if (j==0)
            {
                if(MINES[i][j+1]==getMine())
                    N++;
                if(MINES[i+1][j]==getMine())
                    N++;
                if(MINES[i+1][j+1]==getMine())
                    N++;
            }
            else
            {
                if(j==n)
                {
                    if(MINES[i][j-1]==getMine())
                        N++;
                    if(MINES[i+1][j-1]==getMine())
                        N++;
                    if(MINES[i+1][j]==getMine())
                        N++;
                }
                else
                {

                    if(MINES[i][j-1]==getMine())
                        N++;
                    if(MINES[i][j+1]==getMine())
                        N++;
                    if(MINES[i+1][j-1]==getMine())
                        N++;
                    if(MINES[i+1][j]==getMine())
                        N++;
                    if(MINES[i+1][j+1]==getMine())
                        N++;
                }
            }
        }
        else
        {
            if (i==m)
            {
                if (j==0)
                {
                    if(MINES[i-1][j]==getMine())
                        N++;
                    if(MINES[i-1][j+1]==getMine())
                        N++;
                    if(MINES[i][j+1]==getMine())
                        N++;
                }
                else
                {
                    if(j==n)
                    {
                        if(MINES[i-1][j-1]==getMine())
                            N++;
                        if(MINES[i-1][j]==getMine())
                            N++;
                        if(MINES[i][j-1]==getMine())
                            N++;
                    }
                    else
                    {
                        if(MINES[i-1][j-1]==getMine())
                            N++;
                        if(MINES[i-1][j]==getMine())
                            N++;
                        if(MINES[i-1][j+1]==getMine())
                            N++;
                        if(MINES[i][j-1]==getMine())
                            N++;
                        if(MINES[i][j+1]==getMine())
                            N++;
                    }
                }
            }
            else
            {
                if(MINES[i-1][j-1]==getMine())
                    N++;
                if(MINES[i-1][j]==getMine())
                    N++;
                if(MINES[i-1][j+1]==getMine())
                    N++;
                if(MINES[i][j-1]==getMine())
                    N++;
                if(MINES[i][j+1]==getMine())
                    N++;
                if(MINES[i+1][j-1]==getMine())
                    N++;
                if(MINES[i+1][j]==getMine())
                    N++;
                if(MINES[i+1][j+1]==getMine())
                    N++;
            }
        }
        return(N);
    }
int Demineur::nbvisible(int m, int n)
    {
        int vis=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(JEU[i][j]==getcacher() || JEU[i][j]==getDrapeau())
                {
                    vis=vis+1;
                }
            }
        }
        return(vis);
    }
void Demineur::INFO(int nb, int vis, int coup)
    {

        cout<<CYAN<<"\t__________________________________________________"<<RESET<<endl;
        cout<<"\tNombres de Mines en jeu : "<<nb<<endl<<endl;
        cout<<"\tCases invisibles : "<<vis<<endl<<endl;
        cout<<"\tNombre de coup joue : "<<coup<<endl;
        cout<<CYAN<<"\t__________________________________________________"<<RESET<<endl<<endl<<endl;
    }

void Demineur::nouveauJeu()
    {
        int choix;
        cout<<MAGENTA<<"\n\tdonner le nombre de ligne: "<<RESET;
        cin>>m;
        cout<<MAGENTA<<"\n\tdonner le nombre de colonne: "<<RESET;
        cin>>n;

        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                JEU[i][j]=getcacher();//' 'implique case cachée
                MINES[i][j]='0';
            }
        }

        //demander à l'utilisateur de choisir un nombre de mines
        int NbMines=saisir_nb_mines(m, n);
        int Nb=NbMines;
        int Nb2=NbMines;
        tbool(V,m,n);
        // Initialisation des mines

        for (int CMines=0; CMines<NbMines; CMines++)
        {
            i=rand()%m;//on choisit la ligne de manière aléatoire
            j=rand()%n;//on choisit la colonne de manière aléatoire
            if(MINES[i][j]=='0')
            {
                MINES[i][j]=getMine();
                V[i][j]=true;
            }

            else
            {
                NbMines++;//Sinon, il y a déjà un M et il faut faire un tour de plus
            }
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                N=NbMinesAutour(i,j);
                if(MINES[i][j]=='0')
                {
                    if(N>0)
                        MINES[i][j]= '0'+ N;
                    else
                        MINES[i][j]=getVide();
                }
            }
        system("clear");
        // Démarrage de la partie
        cout<<RED<<"\n\n\tVoici votre grille : A vous de jouer !"<<RESET<<"\n\n";
        AfficheJeu();
        INFO(Nb,nbvisible(m,n),coup);
        do
        {

            cout<<"\n\n\tVeuillez entrer la case choisie (numero de ligne [espace] numero de colonne):\t";
            cin>>i>>j;
            cout<<"\n\tVous avez choisi la case ("<<i<<","<<j<<").\ Que voulez-vous faire ?"<<endl;
            i=i-1;
            j=j-1;
            cout<<endl;

            cout<<MAGENTA<<"\t1. Decouvrir une case"<<endl;
            cout<<"\t2. Placer un drapeau"<<RESET<<endl;
            do
            {
                cout<<"\t\t\tVotre choix : ";
                cin>>choix;
            }
            while (choix<0 || choix>2);
            system("clear");
            switch (choix)
            {
            case 1 :
                if (MINES[i][j]==getMine())
                {
                    for(int k=0; k<m; k++)
                        for(int l=0; l<n; l++)
                            JEU[k][l]=MINES[k][l];
                    AfficheJeu();
                    cout<<RED<<"\n\n\tVous avez perdu !!!\n\n"<<RESET;
                    Quitter();
                }

                else if((MINES[i][j]!=getcacher())&&(MINES[i][j]!=getVide())&&(V[i][j]==false))
                {
                    coup+=100;
                    JEU[i][j]=MINES[i][j];
                    INFO(Nb,nbvisible(m,n),coup);
                    AfficheJeu();
                }
                else if (MINES[i][j]==getVide()&& JEU[i][j]!=getVide())
                {
                    coup+=100;
                    decouvrirX(m,n,i,j);
                    INFO(Nb,nbvisible(m,n),coup);
                    AfficheJeu();
                }
                else {INFO(Nb,nbvisible(m,n),coup);AfficheJeu(); cout<<"\n\tdeja decouverte"<<endl; usleep(1000000);}

                break;
            case 2 :
                if(JEU[i][j]==getcacher())
                    {if(Nb!=0)
                    {
                        JEU[i][j]=getDrapeau();
                        V[i][j]=true;
                        coup+=100;
                        Nb--;
                        INFO(Nb,nbvisible(m,n),coup);
                        AfficheJeu();
                    }
                    else{ INFO(Nb,nbvisible(m,n),coup);AfficheJeu();cout<<"\n\tc'est impossible de placer un Drapeau"<<endl;
                        usleep(1000000);
                       }}
                else if(JEU[i][j]==getDrapeau())
                {
                    JEU[i][j]=getcacher();
                    V[i][j]=true;
                    coup+=100;
                    Nb++;
                    INFO(Nb,nbvisible(m,n),coup);
                    AfficheJeu();
                }
                else {INFO(Nb,nbvisible(m,n),coup);
                AfficheJeu();cout<<"\n\tcette case et visible"<<endl;
                usleep(1000000);}
                break;
            }

        }
        while(nbvisible(m,n)!=Nb2 );
        AfficheJeu();
        cout<<"\n\n\t\tBravo vous avez gagné !"<<endl;
        cout<<"\n\n\t\tdooner votre nom pour sauvegarder le score !"<<endl;
        string ch1;
        cin>>ch1;
        fstream f("score.txt", ios::in | ios::out | ios::app);
        if(f.is_open())
        {
            f<<"Player: "<<ch1<<" "<<"Score: "<<coup;
            f.close();
        }
        Quitter();
    }
void Demineur::BEGIN()
    {
        int men;
        menu();
        cout<<"\n\tVeuillez saisir votre choix: ";
        do
        {
            cin>>men;
        }
        while (men<1 || men>4);
        switch(men)
        {
        case 1:
            system("clear");
            nouveauJeu();
            break;
        case 2:
            system("clear");
            Regles();
            BEGIN();
            break;
        case 3:
            system("clear");
            int h;
            string g,k,l;
            fstream f("score.txt", ios::in | ios::out);
            cout<<endl<<endl;
            cout<<CYAN<<"\t_________________________"<<RESET<<endl;
            if(f.is_open())
            {
                while(f>>g>>k>>l>>h)
                {
                    cout<<"\t"<<g<<" "<<k<<" "<<l<<" "<<h<<endl;;
                }
                f.close();
            }
             cout<<CYAN<<"\t_________________________"<<RESET<<endl;
             cout<<endl<<endl;
            BEGIN();
            break;
        }
    }
void Demineur::Quitter()
    {
                    char qu;
                    cout<<"\n\n\t\tVoulez-vous recommencer\? O/N ";
                    do
                    {
                        cin>>qu;
                    }
                    while(qu!='O' && qu!='o' && qu!='N' && qu!='n');
                    cout<<endl;
                    if(qu=='O' || qu=='o')
                    {
                        system("clear");
                        BEGIN();
                    }
                    if(qu=='N' || qu=='n')
                    {
                        exit(0);
                    }
    }
