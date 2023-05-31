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
    word();
    void set_ref(string ref);
    void Print_word();
    void Delete();
    void Add(char c);
    int Curr_size();
    int Validkey(int i);
};
