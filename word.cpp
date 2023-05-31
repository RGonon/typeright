#include "word.h"

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

int word::Curr_size()
{
    return this->Wordcurr.size();
}

int word::Validkey(int i)
{
    return (i<this->Wordref.size() && this->Wordref[i] == this->Wordcurr[i])?1:0;
}
