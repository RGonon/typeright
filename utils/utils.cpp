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
    return l;
}   
