#include "gameStats.h"

gameStats::gameStats()
{
    this->_keystrokes = 0;
    this->_validkeystrokes = 0;
    this->Precision =0.0f;
    this->Wpm = 0.0f;
    this->Raw = 0.0f;
    time(&start);
}

/*
void gameStats::set_game(Game game)
{
    this->game = game;
}
*/

void gameStats::Addkeystrokes()
{
    _keystrokes++;
}

void gameStats::Addvalidkey()
{
    _validkeystrokes++;
}

void gameStats::Computewpm(int v_word)
{
    time_t now;
    time(&now);
    float diff_time = (float) difftime(now,this->start);
    this->Wpm =(diff_time>0)? v_word / diff_time:0;
}

void gameStats::Computeprecision()
{
    this->Precision = (this->_validkeystrokes / this->_keystrokes)*100;
}

void gameStats::Computeraw(int current)
{
    time_t now;
    time(&now);
    float diff_time = (float) difftime(now,this->start);
    this->Raw =(diff_time>0)? current / diff_time:0;
}

void gameStats::ComputegameStats(int v_word, int current)
{
    //If does not work use thread
    this->Computewpm(v_word);
    this->Computeprecision();
    this->Computeraw(current);
}

void gameStats::Print()
{
    cout<<GREEN<<"Game statistics:\n";
    cout<<GREEN<<"---------------------";
    cout<<GREEN<<"| WPM: "<<this->Wpm<<endl;
    cout<<GREEN<<"| Precision: "<<this->Precision<<endl;
    cout<<GREEN<<"| Raw: "<<this->Raw<<endl;
}

