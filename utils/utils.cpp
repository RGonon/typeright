#include "utils.h"

using namespace std;

string get_line(string path, int line)
{
    fstream s;
    s.open(path);
    string l;
    for(int i = 1; i<line;i++)
    {
        getline(s,l,'\n');
    }
    getline(s,l,'\n');
    s.close();
    return l;
}   

int display()
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
    return n_word;
}
