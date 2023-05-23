#include <iostream>

#define GREEN   "\033[32m"      /* Green */

class gameStats
{
    private:
        int _keystrokes;
        int _validkeystrokes;
        Game game;
    public: 
        float Precision;
        float Wpm;
        float Raw;
        time_t start;
        gameStats();
        void  set_game(Game game);
        void Addkeystrokes();
        void Addvalidkey();
        void Computewpm();
        void Computeprecision();
        void Computeraw();
        void ComputegameStats();
        void Print();
};
gameStats::gameStats()
{
    this->_keystrokes = 0;
    this->_validkeystrokes = 0;
    this->Precision =0.0f;
    this->Wpm = 0.0f;
    this->Raw = 0.0f;
    time(&start);
}
void gameStats::set_game(Game game)
{
    this->game = game;
}

void gameStats::Addkeystrokes()
{
    _keystrokes++;
}

void gameStats::Addvalidkey()
{
    _validkeystrokes++;
}

void gameStats::Computewpm()
{
    time_t now;
    time(&now);
    float diff_time = (float) difftime(now,this->start);
    this->Wpm =(diff_time>0)? this->game->Validword / diff_time:0;
}

void gameStats::Computeprecision()
{
    this->Precision = (this->_validkeystrokes / this->_keystrokes)*100;
}

void gameStats::Computeraw()
{
    time_t now;
    time(&now);
    float diff_time = (float) difftime(now,this->start);
    this->Raw =(diff_time>0)? this->game->Current / diff_time:0;
}

void gameStats::ComputegameStats()
{
    //If does not work use thread
    this->Computewpm();
    this->Computeprecision();
    this->Computeraw();
}

void gameStats::Print()
{
    cout<<GREEN<<"Game statistics:\n";
    cout<<GREEN<<"---------------------";
    cout<<GREEN<<"| WPM: "<<this->Wpm<<endl;
    cout<<GREEN<<"| Precision: "<<this->Precision<<endl;
    cout<<GREEN<<"| Raw: "<<this->Raw<<endl;
}

