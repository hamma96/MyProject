#include "Demineur.h"
#include<bits/stdc++.h>
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
Demineur::Demineur(){}
Demineur::~Demineur(){}
void Demineur::menu()
    {
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

        cout <<CYAN<< "        ****************************************************************" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *                                                              *" <<endl;
        cout << "        *         "<<RESET;
        for(int i=0; i<n; i++)
            cout<<"   "<<i+1;
          //printf("  %2d",i+1);
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
               cout<<" "<<JEU[i][j]<<"  ";
               //printf(" %2.c ",JEU[i][j]);
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
            if(MINES[i][j]=='X')
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
                if(MINES[i][j+1]=='M')
                    N++;
                if(MINES[i+1][j]=='M')
                    N++;
                if(MINES[i+1][j+1]=='M')
                    N++;
            }
            else
            {
                if(j==n)
                {
                    if(MINES[i][j-1]=='M')
                        N++;
                    if(MINES[i+1][j-1]=='M')
                        N++;
                    if(MINES[i+1][j]='M')
                        N++;
                }
                else
                {

                    if(MINES[i][j-1]=='M')
                        N++;
                    if(MINES[i][j+1]=='M')
                        N++;
                    if(MINES[i+1][j-1]=='M')
                        N++;
                    if(MINES[i+1][j]=='M')
                        N++;
                    if(MINES[i+1][j+1]=='M')
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
                    if(MINES[i-1][j]=='M')
                        N++;
                    if(MINES[i-1][j+1]=='M')
                        N++;
                    if(MINES[i][j+1]=='M')
                        N++;
                }
                else
                {
                    if(j==n)
                    {
                        if(MINES[i-1][j-1]=='M')
                            N++;
                        if(MINES[i-1][j]=='M')
                            N++;
                        if(MINES[i][j-1]=='M')
                            N++;
                    }
                    else
                    {
                        if(MINES[i-1][j-1]=='M')
                            N++;
                        if(MINES[i-1][j]=='M')
                            N++;
                        if(MINES[i-1][j+1]=='M')
                            N++;
                        if(MINES[i][j-1]=='M')
                            N++;
                        if(MINES[i][j+1]=='M')
                            N++;
                    }
                }
            }
            else
            {
                if(MINES[i-1][j-1]=='M')
                    N++;
                if(MINES[i-1][j]=='M')
                    N++;
                if(MINES[i-1][j+1]=='M')
                    N++;
                if(MINES[i][j-1]=='M')
                    N++;
                if(MINES[i][j+1]=='M')
                    N++;
                if(MINES[i+1][j-1]=='M')
                    N++;
                if(MINES[i+1][j]=='M')
                    N++;
                if(MINES[i+1][j+1]=='M')
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
                if(JEU[i][j]=='#' || JEU[i][j]=='D')
                {
                    vis=vis+1;
                }
            }
        }
        return(vis);
    }
void Demineur::INFO(int nb, int vis, int coup)
    {

        cout<<"\t__________________________________________________"<<endl;
        cout<<"\tNombres de Mines en jeu : "<<nb<<endl<<endl;
        cout<<"\tCases visibles : "<<vis<<endl<<endl;
        cout<<"\tNombre de coup joue : "<<coup<<endl;
        cout<<"\t__________________________________________________"<<endl<<endl<<endl;
    }

void Demineur::nouveauJeu()
    {
        int choix;
        cout<<MAGENTA<<"\n\tdonner le nombre de ligne: ";
        cin>>m;
        cout<<"\n\tdonner le nombre de colonne: "<<RESET;
        cin>>n;

        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                JEU[i][j]='#';//' 'implique case cachée
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
                MINES[i][j]='M';
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
                        MINES[i][j]='X';
                }
            }
        system("clear");
        // Démarrage de la partie
        cout<<RED<<"\n\n\tVoici votre grille : A vous de jouer !"<<RESET<<"\n\n";
        AfficheJeu();
        INFO(Nb,nbvisible(m,n),coup);
        do
        {

            cout<<"\n\nVeuillez entrer la case choisie (numero de ligne [espace] numero de colonne):\t";
            cin>>i>>j;
            cout<<"Vous avez choisi la case ("<<i<<","<<j<<").\ Que voulez-vous faire ?\n";
            i=i-1;
            j=j-1;
            cout<<endl;

            cout<<"\t1. Decouvrir une case"<<endl;
            cout<<"\t2. Placer un drapeau"<<endl;
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
                if (MINES[i][j]=='M')
                {
                    for(int k=0; k<m; k++)
                        for(int l=0; l<n; l++)
                            JEU[k][l]=MINES[k][l];
                    AfficheJeu();
                    cout<<"Vous avez perdu !!!\n\n";
                    Quitter();
                }

                else if((MINES[i][j]!='X'))
                {
                    coup+=100;
                    JEU[i][j]=MINES[i][j];
                    INFO(Nb,nbvisible(m,n),coup);
                    AfficheJeu();
                }
                else
                {
                    coup+=100;
                    decouvrirX(m,n,i,j);
                    //decouvrirX2(v,MINES,JEU,m,n,i,j);
                    INFO(Nb,nbvisible(m,n),coup);
                    AfficheJeu();
                }

                break;
            case 2 :
                if(JEU[i][j]=='#')
                    if(Nb!=0)
                    {
                        JEU[i][j]='D';
                        V[i][j]=true;
                        coup+=100;
                        Nb--;
                    }
                    else cout<<"c'est impossible de placer un Drapeau"<<endl;
                else if(JEU[i][j]=='D')
                {
                    JEU[i][j]='#';
                    V[i][j]=true;
                    coup+=100;
                    Nb++;
                }
                else cout<<"cette case et visible"<<endl;
                INFO(Nb,nbvisible(m,n),coup);
                AfficheJeu();
                break;
            }

        }
        while(nbvisible(m,n)!=Nb2 );
        AfficheJeu();
        cout<<"\n\n\t\tBravo vous avez gagné !"<<endl;
        cout<<"dooner votre nom pour sauvegarder le score !"<<endl;
        string ch1;
        cin>>ch1;
        fstream f("score.txt", ios::in | ios::out | ios::app);
        if(f.is_open())
        {
            f<<ch1<<" "<<coup;
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
            string g;
            fstream f("score.txt", ios::in | ios::out);
            cout<<endl<<endl;
            cout<<"\t___________________"<<endl;
            if(f.is_open())
            {
                while(f>>g>>h)
                {
                    cout<<"\t"<<g<<" "<<h<<endl;;
                }
                f.close();
            }
             cout<<"\t___________________"<<endl;
             cout<<endl<<endl;
            BEGIN();
            break;
        }
    }
void Demineur::Quitter()
    {
                    char qu;
                    cout<<"Voulez-vous recommencer\? O/N ";
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
