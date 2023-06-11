#include "game.h"

using namespace std;

int main()
{
    int n_word = display();
    word* w =(word*) malloc(sizeof(word)*n_word);
    game g;
    g.word_text(w,n_word);
    g.set_bank(w,n_word);
    g.Play();
    return 0;
}
