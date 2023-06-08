#ifndef __CLASS__
#define __CLASS__
#include "word.h"
#include "gameStats.h"
#include "utils/utils.h"
#include <thread>
#include <functional>
#include <cstdlib>
#include <fstream> 
#endif

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
    void word_text(word*& w, int size);
    void Play();
};
