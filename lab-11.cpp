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
// arguments: pointer, array size
// return: nothing
void inputArtist(Artists *);

// displayArtist() displays data for the artist
// arguments: pointer, array size
// return: nothing
void displayArtist(Artists *);

int main(){
    // Collect the number of artists you would like to input
    int numOfA;
    cout << "Enter # of Artists: ";
    cin >> numOfA;

    // Create dynamic array of artists
    Artists *list = new Artists[numOfA];

    // Create for loop to collect Artist data
    for(int i = 0; i < numOfA; i++){
        inputArtist(&list[i]);
    }

    // Create for loop to display data
    for(int i = 0; i < numOfA; i++){
        displayArtist(&list[i]);
    }
}

void inputArtist(Artists * aptr){
    static int nrA = 1;
    int numSongs;
    cout << "Input data for artist #" << nrA << ": " << endl;
    cout << "Name: ";
    getline(cin, aptr->name);
    cout << "Monthly Listenners: ";
    cin >> aptr->monthlyListenners;
    cout << "Enter # of songs of theirs you enjoy: ";
    cin >> numSongs;
    for(int i = 0; i < numSongs; i++){
        cout << "Favorite Song #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, aptr->favSongs[i]);
    }
    cin.ignore();
    cout << endl;
    nrA++;
}