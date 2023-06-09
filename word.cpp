#include "word.h"

word::word()
{
    this->Wordcurr = "";
    this->Lastkey = 0;
}

void word::set_ref(string ref)
{
    this->Wordref = ref;
    this->Wordstatus =(int*) calloc(ref.size(),sizeof(int));
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
            case 0: 
                cout<<WHITE<<Wordref[i];
                continue;
            default:
                cout<<RED<<Wordcurr[i];
                continue;
        }
    }
    cout<<RESET;
    for(int i = l_curr; i < l_ref;i++)
    {
        cout<<WHITE<<Wordref[i];
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
    else
    {
        this->Wordcurr = "";
        this->Wordstatus[0] = 0;
    }
    this->Lastkey = 0;
}

void word::Add(char c)
{
    int l_curr = this->Wordcurr.size()+1;

    if(l_curr<= this->Wordref.size())
    {
        this->Wordcurr+=c;
        this->Wordstatus[l_curr-1] = 
            (this->Wordcurr[l_curr-1] == this->Wordref[l_curr-1])?1:-1;
        this->Lastkey = this->Wordstatus[l_curr-1];
    }
    else if (l_curr<= this->Wordref.size()+10)
    {
        this->Wordcurr+=c;
        cout<<l_curr+1<<endl;
        this->Wordstatus =(int*) realloc(this->Wordstatus, l_curr+1);
        this->Wordstatus[l_curr] = -1;
        this->Lastkey = this->Wordstatus[l_curr];
    }
}

int word::Curr_size()
{
    return this->Wordcurr.size();
}
int word::Ref_size()
{
    return this->Wordref.size();
}

int word::Validkey(int i)
{
    return (i<this->Wordref.size() && this->Wordref[i] == this->Wordcurr[i])?1:0;
}
int word::Checkword()
{
    int l_ref = this->Wordref.size();
    int l_curr = this->Wordcurr.size();
    if(l_curr != l_ref)
        return 0;
    int i =0;
    while(i<l_curr && *(this->Wordstatus+i) == 1)
        i++;
    return i == l_curr;
}
