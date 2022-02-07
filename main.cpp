//
// By: Angelina Guzman and Mashrul Shifat
//
#include "Playlist.h"
#include <iostream>
using namespace std;
void PrintMenu(string title);

int main()
{
    string plTitle;

    cout << "Enter playlist's title:" << endl;
    getline(cin, plTitle);
    cout << "\n";
    PrintMenu(plTitle);

    return 0;
}

void PrintMenu(string title)
{
    Playlist list;
    string id;
    string sname;
    string aname;
    int length;
    int oldPos;
    int newPos;
    char choice;
    while (true)
    {
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit\n" << endl;

        cout << "Choose an option:" << endl;
        cin >> choice;
        if (choice == 'q')
        {
            exit(1);
        }
        else if (choice == 'a')
        {
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            cin.ignore();//ignore newline
            cout << "Enter song's name:" << endl;
            getline(cin, sname);
            cout << "Enter artist's name:" << endl;
            getline(cin, aname);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;
            cout << "\n";
            list.AddSong(id, sname, aname, length);
        }
        else if (choice == 'd')
        {
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            list.RemoveSong(id);
        }
        else if (choice == 'c')
        {
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> oldPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            list.ChangePosition(oldPos, newPos);
        }
        else if (choice == 's')
        {
            string newname;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin, newname);
            list.SongsByArtist(newname);
        }
        else if (choice == 't')
        {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << list.TotalTime() << " seconds\n" << endl;
        }
        else if (choice == 'o')
        {
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            list.PrintList();
        }
        else
        {
            cout << "Invalid menu choice! Please try again." << endl;
        }
    }
} // end?