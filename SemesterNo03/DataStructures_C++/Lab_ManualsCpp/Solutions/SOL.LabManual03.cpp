#include <iostream>
#include <string>
using namespace std;

// Construction of a Doubly LinkedList (Circular):

class Playlist
{

    class Node
    {
    public:
        string songInfo;
        Node *prev;
        Node *next;

        Node(string songInfo)
        {
            this->songInfo = songInfo;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node *Head = NULL;
    Node *Tail = NULL;

public:
    // ================= Iterator Class =================
    // A small pointer-based iterator that supports both forward

    // and backward traversal over a circular doubly linked list

    // Since the list is circular there is no NULL to stop at, so

    // we mark completion using a "looped" flag instead

    class Iterator
    {
        Node *current;
        Node *anchor; // the node we started from (Head for forward, Tail for backward)
        bool looped;  // becomes true once we have gone all the way around

    public:
        Iterator(Node *current, Node *anchor, bool looped)
        {
            this->current = current;
            this->anchor = anchor;
            this->looped = looped;
        }

        string &operator*()
        {
            return current->songInfo;
        }

        // prefix ++
        Iterator &operator++()
        {
            current = current->next;
            if (current == anchor)
                looped = true;
            return *this;
        }

        // prefix --
        Iterator &operator--()
        {
            current = current->prev;
            if (current == anchor)
                looped = true;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            if (current == other.current && looped == other.looped)
                return false;
            return true;
        }
    };

    Iterator begin()
    {
        return Iterator(Head, Head, false);
    }

    Iterator end()
    {
        return Iterator(Head, Head, true);
    }

    Iterator rbegin()
    {
        return Iterator(Tail, Tail, false);
    }

    Iterator rend()
    {
        return Iterator(Tail, Tail, true);
    }

    // small helper used by a couple of functions below
    int countSongs()
    {
        if (Head == NULL)
            return 0;

        int count = 0;
        Node *temp = Head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != Head);

        return count;
    }

    // Addition of Songs in Doubly LinkedList:
    void addASongAtStart(string song)
    {
        Node *newNode = new Node(song);

        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            newNode->next = Head;
            newNode->prev = Tail;
            Head->prev = newNode;
            Tail->next = newNode;
            Head = newNode;
        }

        cout << "\"" << song << "\" added at the beginning." << endl;
    }

    void addASongAtEnd(string song)
    {
        if (Head == NULL)
        {
            addASongAtStart(song);
            return;
        }

        Node *newNode = new Node(song);

        newNode->next = Head;
        newNode->prev = Tail;
        Tail->next = newNode;
        Head->prev = newNode;
        Tail = newNode;

        cout << "\"" << song << "\" added at the end." << endl;
    }

    void addASongAtSpecificPosition(int target, string song)
    {
        if (target <= 1 || Head == NULL)
        {
            addASongAtStart(song);
            return;
        }

        Node *temp = Head;
        int position = 1;

        // move temp to the node just before the target position
        while (position < target - 1 && temp->next != Head)
        {
            temp = temp->next;
            position++;
        }

        if (temp->next == Head)
        {
            // requested position is beyond the current length, add at end
            addASongAtEnd(song);
            return;
        }

        Node *newNode = new Node(song);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        cout << "\"" << song << "\" added at position " << target << "." << endl;
    }

    // Removal of the Song in Doubly LinkedList
    void removeASongAtStart()
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty, nothing to remove." << endl;
            return;
        }

        Node *toDelete = Head;

        if (Head == Tail)
        {
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Head = Head->next;
            Head->prev = Tail;
            Tail->next = Head;
        }

        cout << "\"" << toDelete->songInfo << "\" removed from the beginning." << endl;
        delete toDelete;
    }

    void removeASongAtEnd()
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty, nothing to remove." << endl;
            return;
        }

        Node *toDelete = Tail;

        if (Head == Tail)
        {
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Tail = Tail->prev;
            Tail->next = Head;
            Head->prev = Tail;
        }

        cout << "\"" << toDelete->songInfo << "\" removed from the end." << endl;
        delete toDelete;
    }

    void removeASongAtSpecificPosition(int target)
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty, nothing to remove." << endl;
            return;
        }

        if (target <= 1)
        {
            removeASongAtStart();
            return;
        }

        Node *temp = Head;
        int position = 1;

        while (position < target && temp != Tail)
        {
            temp = temp->next;
            position++;
        }

        if (position != target)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (temp == Tail)
        {
            removeASongAtEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        cout << "\"" << temp->songInfo << "\" removed from position " << target << "." << endl;
        delete temp;
    }

    // Searching Songs from the playlist
    void searchSong(string target)
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *temp = Head;
        int position = 1;

        do
        {
            if (temp->songInfo == target)
            {
                cout << "\"" << target << "\" found at position " << position << "." << endl;
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != Head); // stop after one full revolution

        cout << "\"" << target << "\" not found in the playlist." << endl;
    }

    // Methods to Traverse the Playlist (using the custom Iterator, not raw pointers)
    void traverseForword()
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Forward: ";
        for (Iterator it = begin(); it != end(); ++it)
        {
            cout << *it;
            cout << " -> ";
        }
        cout << "(end)" << endl;
    }

    void traverseBackword()
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Backward: ";
        for (Iterator it = rbegin(); it != rend(); --it)
        {
            cout << *it;
            cout << " -> ";
        }
        cout << "(end)" << endl;
    }

    // Same idea as traverseForword(), only exposed with the exact
    // name asked for in the manual.
    void printPlaylistUsingIterator()
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        for (Iterator it = begin(); it != end(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    // Looping the Songs Mechanism
    void playNSongsOnLoop(int n)
    {
        if (Head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (n <= 0)
        {
            cout << "n must be greater than 0." << endl;
            return;
        }

        Node *temp = Head;

        for (int i = 0; i < n; i++)
        {
            cout << temp->songInfo;
            if (i != n - 1)
                cout << " -> ";
            temp = temp->next; // wraps back to Head automatically since it's circular
        }
        cout << endl;
    }

    // Removal of duplicates Mechanism (keeps the first occurrence of every song)
    void removeDuplicateSongs()
    {
        if (Head == NULL || Head == Tail)
            return;

        Node *outer = Head;

        do
        {
            Node *inner = outer->next;

            while (inner != Head)
            {
                Node *nextInner = inner->next;

                if (inner->songInfo == outer->songInfo)
                {
                    inner->prev->next = inner->next;
                    inner->next->prev = inner->prev;

                    if (inner == Tail)
                        Tail = inner->prev;

                    delete inner;
                }

                inner = nextInner;
            }

            outer = outer->next;

        } while (outer != Head);

        cout << "Duplicate songs removed." << endl;
    }

    // Searching Song from the end
    void findSongNfromEnd(int n)
    {
        int length = countSongs();

        if (length == 0)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (n <= 0 || n > length)
        {
            cout << "Invalid value of n." << endl;
            return;
        }

        int positionFromHead = length - n + 1;
        Node *temp = Head;

        for (int i = 1; i < positionFromHead; i++)
            temp = temp->next;

        cout << "Song " << n << " from the end is: \"" << temp->songInfo << "\"" << endl;
    }

    // Checking the LinkedList Playlist Palindrome
    void checkPlaylistPalindrome()
    {
        int length = countSongs();

        if (length == 0)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *front = Head;
        Node *back = Tail;

        for (int i = 0; i < length / 2; i++)
        {
            if (front->songInfo != back->songInfo)
            {
                cout << "Playlist is NOT a palindrome." << endl;
                return;
            }
            front = front->next;
            back = back->prev;
        }

        cout << "Playlist IS a palindrome." << endl;
    }
};

int main()
{
    Playlist Songs;

    int choice;

    do
    {
        cout << endl;
        cout << " ==== Circular Playlist Manager ==== " << endl;
        cout << " 1. Add Song at Beginning " << endl;
        cout << " 2. Add Song at End " << endl;
        cout << " 3. Add Song at Position " << endl;
        cout << " 4. Remove Song from the Beginning" << endl;
        cout << " 5. Remove Song from End " << endl;
        cout << " 6. Remove Song from position" << endl;
        cout << " 7. Search Song  " << endl;
        cout << " 8. Traverse Forword " << endl;
        cout << " 9. Traverse Backword " << endl;
        cout << " 10. Play N Songs on Loop " << endl;
        cout << " 11. Remove Duplicate Songs " << endl;
        cout << " 12. Find Song N from End " << endl;
        cout << " 13. Check Playlist Palindrome " << endl;
        cout << " 14. Exit " << endl;

        cout << "Enter the Required Choice: ";
        cin >> choice;

        while (true)
        {
            if (cin.fail() || choice < 1 || choice > 14)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid choice, please re-enter (1-14): ";
                cin >> choice;
            }
            else
                break;
        }

        string song;
        int position, n;

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, song);
            Songs.addASongAtStart(song);
            break;

        case 2:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, song);
            Songs.addASongAtEnd(song);
            break;

        case 3:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, song);
            cout << "Enter position: ";
            cin >> position;
            Songs.addASongAtSpecificPosition(position, song);
            break;

        case 4:
            Songs.removeASongAtStart();
            break;

        case 5:
            Songs.removeASongAtEnd();
            break;

        case 6:
            cout << "Enter position to remove: ";
            cin >> position;
            Songs.removeASongAtSpecificPosition(position);
            break;

        case 7:
            cout << "Enter song name to search: ";
            cin.ignore();
            getline(cin, song);
            Songs.searchSong(song);
            break;

        case 8:
            Songs.traverseForword();
            break;

        case 9:
            Songs.traverseBackword();
            break;

        case 10:
            cout << "Enter number of songs to play: ";
            cin >> n;
            Songs.playNSongsOnLoop(n);
            break;

        case 11:
            Songs.removeDuplicateSongs();
            break;

        case 12:
            cout << "Enter N (from end): ";
            cin >> n;
            Songs.findSongNfromEnd(n);
            break;

        case 13:
            Songs.checkPlaylistPalindrome();
            break;

        case 14:
            cout << "Exiting Circular Playlist Manager..." << endl;
            break;
        }

    } while (choice != 14);

    return 0;
}