#ifndef __CLASS__
#define __CLASS__
#include "word.h"
#include "gameStats.h"
#endif
#include <thread>

using namespace std;

class game
{
    public:
    word* bank;
    int nbr_w;
    int Current;
    int Validwords;
    gameStats g_stats;
    game();
    void set_bank(word* bank,int n);
    void Printbank();
    void Getinput();
    void Play();
};
