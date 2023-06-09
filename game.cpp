#include "game.h"

game::game()
{
    this->Current = 0;
    this->Validwords = 0;
}
void game::set_bank(word* b, int n)
{
    this->bank = b;
    this->nbr_w = n;
}
void game::Printbank()
{
    //we want to have only 10 words on each line
    
    for(int i =0; i<this->nbr_w-1;i++)
    {
        (*(this->bank+i)).Print_word();
        cout<<(((i+1)%10==0)?'\n':' ');
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
        while(stop!=1)
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
                                this->Validwords--;
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
                            this->bank[this->Current].Delete();
                            i_word--;
                        }
                        break;
                    // space char
                    case 32:
                        this->Validwords+=this->bank[this->Current].Checkword();
                        this->Current++;
                        i_word = 0;
                        break;
                    // enter 
                    case 13:
                        stop = 1;
                        break;
                    // letter
                    default:
                        this->bank[this->Current].Add(ch);
                        this->g_stats.Addkeystrokes();
                        if(this->bank[this->Current].Validkey(i_word))
                            this->g_stats.Addvalidkey();
                        i_word++;
                        if(this->Current == this->nbr_w-1 &&
                            this->bank[this->Current].Ref_size() == i_word)
                            stop = 1;
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

void game::word_text(word*& w, int size)
{
    string path = "word.txt";
    string s;
    int r;
    for(int i =0;i<size;i++)
    {
        r = rand()%10000;
        s = get_line(path,r);
        w[i].set_ref(s);
    }
}

void game::Play()
{
    thread t(bind(&game::Getinput,this));
    t.join();
    //this->Getinput();
    this->Printbank();
    this->g_stats.Print();
}

int main()
{
    cout<<"Welcome to typeright game !\n";
    int n_word;
    cout<<"How many word do you want to type ? ";
    cin>>n_word;
    cout<<"Alright let's go for "<<n_word<<" words\n";
    cout<<"Here are the rule: \n";
    cout<<"No break line it will exit the program\n";
    cout<<"Tap as fast as you can\n";
    cout<<"When you are ready hit Enter to go\n";
    char a = getchar();
    a = getchar();
    word* w =(word*) malloc(sizeof(word)*n_word);
    game g;
    g.word_text(w,n_word);
    g.set_bank(w,n_word);
    g.Play();
    return 0;
}
