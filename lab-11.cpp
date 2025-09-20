// COMSC-210 | Lab 11 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

// Brainstorming idea:
/* Could just be an array with like music artists I like, then inside there could be an array for like
   favorite songs, could be different the ammount of songs I like depending on the artist, then maybe just pure stats like monthly listenenrs
   and maybe one more stat like... style of music? I guess, that coyuld change depending lets see, full of strings but its fine i guess*/

// Create a struct to hold the artists
struct Artists {
    string name;
    int monthlyListenners;
    string * favSongs;

    // Create destructor for the favSongs array
    ~Artists() {
        if (favSongs){
            delete[] favSongs;
        }
        favSongs = nullptr;
    }
};

// inputArtist() collects data for the artist
// arguments: pointer
// return: nothing
void inputArtist(Artists *);

// displayArtist() displays data for the artist
// arguments: pointer
// return: nothing
void displayArtist(Artists *);