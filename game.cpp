#include "game.h"

game::game()
{
    this->Current = 0;
    this->Validwords = 0;
//    this->g_stats.set_game(this);
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
        (*(this->bank+i)).Print_word();
        cout<<" ";
    }
    (*(this->bank+nbr_w-1)).Print_word();
    cout<<endl;
}

void game::Getinput()
{
    char ch;
    //index var used for the actual word
    int i_word =0;
    int stop = 0;
    while(this->Current < this->nbr_w && stop != 1)
    {
        this->Printbank();
        this->g_stats.ComputegameStats(this->Validwords, this->Current);
        this->g_stats.Print();
        system("stty raw");
        while(1)
        {
            ch = getchar();
            if(ch != '\0')
            {
                switch(ch)
                {
                    // backspace
                    case 127:
                        if(i_word ==0)
                        {
                            if(this->Current>0)
                            {
                                this->Current--;
                                this->bank[this->Current].Delete();
                                i_word = this->bank[this->Current].Curr_size();
                            }
                            else 
                            {
                                this->bank[this->Current].Delete();    
                                i_word = -1;
                            }
                        }
                        else if(i_word >0)
                        {
                            cout<<"COUCOU";
                            this->bank[this->Current].Delete();
                            i_word--;
                        }
                        break;
                    // space char
                    case 32:
                        this->Current++;
                        i_word = 0;
                        break;
                    case 13:
                        stop = 1;
                        break;
                    // letter case 
                    default:
                        this->bank[this->Current].Add(ch);
                        this->g_stats.Addkeystrokes();
                        if(this->bank[this->Current].Validkey(i_word))
                            this->g_stats.Addkeystrokes();
                        i_word++;
                        break;
                }
                break;
            }
        }
        system("stty cooked");
        system("clear");
        ch = 0;
    }
}

void game::Play()
{
    //gamestat start
//    thread t(this->Getinput());
  //  t.join();
    this->Getinput();
    this->Printbank();
    this->g_stats.Print();
}

int main()
{
    word w[2];
    for(int i =0; i<2;i++)
    {
        w[i].set_ref("coucou");
    }
    game g;
    g.set_bank(w,2);
    g.Play();

    return 0;
}
