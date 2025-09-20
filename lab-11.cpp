// COMSC-210 | Lab 11 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <string>
#include <limits>
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
    int favCount;

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
void displayArtist(const Artists *);

int main(){
    // Collect the number of artists you would like to input
    int numOfA;
    cout << "Enter # of Artists: ";
    cin >> numOfA;

    // Getting bugs with the idescriminate cin.ignore had to change
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    

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

    // delete list
    delete[] list;
    return 0;
}

void inputArtist(Artists * aptr){
    // Keep count of which artist we are on
    static int nrA = 1;

    // Collect artist name and monthly listenners
    cout << "Input data for artist #" << nrA << ": " << endl;
    cout << "Name: ";
    getline(cin, aptr->name);
    cout << "Monthly Listenners: ";
    cin >> aptr->monthlyListenners;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Get number of songs for each artist, then make the for loop to fill the array of fav songs
    cout << "Enter # of songs of theirs you enjoy: ";
    cin >> aptr->favCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Create if statement to only collect if they have a favorite song
    if (aptr->favCount < 0){
        aptr->favCount = 0;
    }   

    if(aptr->favCount > 0){
        aptr -> favSongs = new string[aptr->favCount];
        for(int i = 0; i < aptr->favCount; i++){
            cout << "Favorite Song #" << i + 1 << ": ";
            getline(cin, aptr->favSongs[i]);
        }
    }

    cout << endl;
    nrA++;
}

void displayArtist(const Artists * aptr){
    // Display data
    cout << "Artist Overview:" << endl;
    cout << "\tName: " << aptr->name << endl;
    cout << "\tMonthly Listenners: " << aptr->monthlyListenners << endl;

    // Display fav songs array, with the size being determined dependent on the ammount of favsongs per artist
    cout << "\tFav Songs:" << endl;
    for(int i = 0; i < aptr->favCount; i++){
        cout << "\t\tSong #" << i + 1 << ": " << aptr->favSongs[i] << endl;
    }

    cout << endl;
}