#include <iostream>

using namespace std;

class game
{
    public:
    word* bank;
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
void game::set_bank(word* b)
{
    this->bank = b;
}
void game::Printbank()
{
}
