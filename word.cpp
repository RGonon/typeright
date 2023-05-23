#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */


using namespace std;

class word
{
    private: 
        string Wordref;
        string Wordcurr;
        // key status are defined as follow:
        // waiting = 0 
        // correct = 1
        // invalid = -1 
        int* Wordstatus;
        int Lastkey;
    public: 
    word(string ref);
    void Print_word();
    void Delete();
    void Add(char c);
};

word::word(string ref)
{
    this->Wordref = ref;
    this->Wordcurr = "";
    this->Wordstatus =(int*) calloc(ref.size(),sizeof(int));
    this->Lastkey = 0;
}

void word::Print_word()
{
    int l_ref = this->Wordref.size();
    int l_curr = this->Wordcurr.size();
    for(int i = 0; i < l_curr; i++)
    {
        switch(this->Wordstatus[i])
        {
            case 1:
                cout<<GREEN<<Wordcurr[i];
                continue;
            case -1: 
                cout<<RED<<Wordcurr[i];
                continue;
            default:
                cout<<WHITE<<Wordcurr[i];
                continue;
        }
    }
    cout<<RESET;
    for(int i = l_curr; i < l_ref;i++)
    {
        cout<<Wordref[i];
    }
    cout<<endl;
}

void word::Delete()
{
    int lenght = this->Wordcurr.size();
    if(lenght > 0)
    {
        string temp = this->Wordcurr.substr(0,lenght-1);
        this->Wordcurr = temp;
        this->Wordstatus[lenght-1] = 0;
    }
    this->Lastkey = (lenght>1)? this->Wordstatus[lenght-2]:0;
}

void word::Add(char c)
{
    this->Wordcurr+=c;
    int l_curr = this->Wordcurr.size();

    if(l_curr<= this->Wordref.size())
    {
        this->Wordstatus[l_curr-1] = 
            (this->Wordcurr[l_curr-1] == this->Wordref[l_curr-1])?1:-1;
        this->Lastkey = this->Wordstatus[l_curr-1];
    }
    else
    {
        this->Wordstatus =(int*) realloc(this->Wordstatus, l_curr+1);
        this->Wordstatus[l_curr] = -1;
        this->Lastkey = this->Wordstatus[l_curr];
    }
}

int main()
{
    word w("coucou");
    w.Print_word();
    w.Add('c');
    w.Add('c');
    w.Print_word();
    w.Delete();
    w.Print_word();
    w.Add('o');
    w.Print_word();
    return 0;
}
