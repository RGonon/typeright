#include <iostream>

using namespace std;

class game
{
    public:
    word* bank;
    int nbr_w;
    int Current;
    int ValidWords;
    gameStats g_stats;
    game();
    void set_bank(word* bank);
    void Printbank();
    void Getinput();
    void Play();
};

game::game()
{
    this->Current = 0;
    this->Validword = 0;
    this->g_stats.set_game(this);
}
void game::set_bank(word* b, int n)
{
    this->bank = b;
    this->nbr_w = n;
}
void game::Printbank()
{
    for(int i =0; i<this->nbr_w-1;i++)
    {
        *(this->bank+i).Print_word();
        cout<<" ";
    }
    *(this->bank+nbr_w-1).Print_word();
    cout<<endl;
}
