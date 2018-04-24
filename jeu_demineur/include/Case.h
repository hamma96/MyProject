#ifndef CASE_H
#define CASE_H


class Case
{
    public:
        Case();
        virtual ~Case();
        char getMine();
        char getVide();
        char getcacher();
        char getDrapeau();
    protected:
        char Mine='M';
        char Vide='X';
        char cacher='#';
        char Drapeau='D';

    private:
};

#endif // CASE_H
