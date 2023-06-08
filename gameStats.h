#include <iostream>

#define GREEN   "\033[32m"      /* Green */
using namespace std;

class gameStats
{
    private:
        float _keystrokes;
        float _validkeystrokes;
//        Game game;
    public: 
        float Precision;
        float Wpm;
        float Raw;
        time_t start;
        gameStats();
//        void  set_game(Game game);
        void Addkeystrokes();
        void Addvalidkey();
        void Computewpm(int v_word);
        void Computeprecision();
        void Computeraw(int current);
        void ComputegameStats(int v_word, int current);
        void Print();
};

