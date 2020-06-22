#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

class Hand
{
protected:
    string cards[52];
    int top = -1;
    int points = 0;
    string name = "Player";

public:
    Hand(string name)
    {
        this->name = name;
    }

    void give(Hand player)
    {
        player.recieve(cards[top]);
        top--;
    }

    void recieve(string card)
    {
        top++;
        cards[top] = card;
        cout << this->name << " recieved " << cards[top] << endl;
        points += stipple(card);
    }

private:
    int stipple(string card)
    {
        char val = card[0];

        switch (val)
        {
        case '1':
            return 10;
            break;
        case 'J':
            return 10;
            break;
        case 'Q':
            return 10;
            break;
        case 'K':
            return 10;
            break;
        case 'A':
            if (points > 10)
                return 1;
            else
                return 11;
            break;
        default:
            return (int)(val - '0');
            break;
        }
    }
};

class Deck : public Hand
{
    string faces[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    string suits[4] = {" of Spades", " of Clubs", " of Diamonds", " of Hearts"};

public:
    Deck()
        : Hand("Deck")
    {
        setup();
        shuffle();
    }

private:
    void setup()
    {
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int index = 4 * i + j;
                cards[index] = faces[i] + suits[j];
            }
        }
    }

    void shuffle()
    {
        srand(time(NULL));

        for (int i = 0; i < 100; i++)
        {
            int index1 = rand() % 53;
            int index2 = rand() % 53;

            string buff = cards[index1];
            cards[index1] = cards[index2];
            cards[index2] = buff;
        }
    }
};

void show_scoreboard();

int run_game()
{
    Deck deck;
    Hand p1("Player 1");
    Hand p2("Player 2");
    Hand croupier("Croupier");
}

int main()
{
    string scoreboard[255];
    scoreboard[0] = "No statistics yet";
    int game = 1;

    int choice = 0;
    while (choice != 3)
    {

        switch (choice)
        {
        case 1:
            run_game();
            break;
        case 2:
            show_scoreboard();
            break;
        default:
            continue;
        }
    }

    return 0;
}