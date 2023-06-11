#include "gameStats.h"

gameStats::gameStats()
{
    this->_keystrokes = 0.0f;
    this->_validkeystrokes = 0.0f;
    this->Precision =0.0f;
    this->Wpm = 0.0f;
    this->Raw = 0.0f;
    time(&start);
}

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
    this->Wpm =(diff_time>0)? (v_word / diff_time)*120.0f:0;
}

void gameStats::Computeprecision()
{
    this->Precision = (this->_keystrokes>0)?(float)(this->_validkeystrokes / this->_keystrokes)*100.0f:0;
}

void gameStats::Computeraw(int current)
{
    time_t now;
    time(&now);
    float diff_time = (float) difftime(now,this->start);
    this->Raw =(diff_time>0)? current / diff_time*120.0f:0;
}

void gameStats::ComputegameStats(int v_word, int current)
{
    this->Computewpm(v_word);
    this->Computeprecision();
    this->Computeraw(current);
}

void gameStats::Print()
{
    cout<<endl;
    cout<<GREEN<<"Game statistics:\n";
    cout<<GREEN<<"---------------------\n";
    cout<<GREEN<<"| WPM: "<<this->Wpm<<endl;
    cout<<GREEN<<"| Precision: "<<this->Precision<<endl;
    cout<<GREEN<<"| Raw: "<<this->Raw<<endl;
}

