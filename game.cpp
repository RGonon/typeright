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

void Getinput()
{
    char ch;
    //index var used for the actual word
    int i_word =0;
    while(this->Current < this->nbr_w)
    {
        this.Printbank();
        this->g_stats.ComputegameStats();
        this->g_stats.Print();
        system("stty raw");
        while(1)
        {
            ch = getchar();
            if(ch != 0)
            {
                
                switch(ch)
                {
                    // backspace
                    case 8:
                        if(i_word ==0 && this->Current >0)
                        {
                            this->Current--;
                            this->bank[this->Current].Delete();
                            i_word = this->bank[this->Current].size();
                        }
                        else
                        {
                            this->bank[this->Current].Delete();
                            i_word--;
                        }
                    case 32:
                        this->Current++;
                        indice = 0;

                    default:
                        this->bank[this->Current].Add(ch);
                        this->g_stats.Addkeystrokes();
                        //TODO 
                        // add valid keystrokes
                }
                system("stty cooked");
                system("clear");
                break;
            }
        }
        a+=ch;

        ch = 0;
        n++;
    }

