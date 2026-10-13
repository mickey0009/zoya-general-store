#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player
{
public:
    string name;
    int health;
    int coins;
    bool hasKey;
    bool hasSword;

    Player()
    {
        health = 100;
        coins = 0;
        hasKey = false;
        hasSword = false;
    }

    void showStatus()
    {
        cout << "\n========== PLAYER STATUS ==========\n";
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Coins  : " << coins << endl;
        cout << "Key    : " << (hasKey ? "Yes" : "No") << endl;
        cout << "Sword  : " << (hasSword ? "Yes" : "No") << endl;
        cout << "===================================\n";
    }
};

void introduction(Player &player)
{
    cout << "========================================\n";
    cout << "       THE LOST TREASURE ADVENTURE\n";
    cout << "========================================\n";

    cout << "\nEnter your name: ";
    getline(cin, player.name);

    cout << "\nWelcome, " << player.name << "!\n";

    cout << "\nYou are an adventurer searching for a\n";
    cout << "legendary treasure hidden deep inside\n";
    cout << "the Dark Forest.\n";

    cout << "\nYour adventure begins now...\n";
}

void forest(Player &player)
{
    int choice;

    cout << "\n========================================\n";
    cout << "              DARK FOREST\n";
    cout << "========================================\n";

    cout << "\nYou enter a dark and mysterious forest.";
    cout << "\nYou see two paths.\n";

    cout << "\n1. Take the left path";
    cout << "\n2. Take the right path";
    cout << "\n3. Check your status";
    cout << "\n4. Quit game";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nYou follow the left path...\n";

        cout << "\nYou discover an old wooden chest!\n";
        cout << "You open it and find a golden key.\n";

        player.hasKey = true;
        player.coins += 10;

        cout << "\nYou received:";
        cout << "\n+ Golden Key";
        cout << "\n+ 10 coins\n";
    }
    else if (choice == 2)
    {
        cout << "\nYou follow the right path...\n";

        cout << "\nSuddenly, a wild wolf attacks you!\n";

        if (player.hasSword)
        {
            cout << "\nYou use your sword and defeat the wolf!\n";
            player.coins += 20;

            cout << "You found 20 coins!\n";
        }
        else
        {
            cout << "\nYou have no weapon!\n";
            cout << "The wolf injures you.\n";

            player.health -= 30;

            cout << "Health -30\n";
        }
    }
    else if (choice == 3)
    {
        player.showStatus();
    }
    else if (choice == 4)
    {
        cout << "\nThanks for playing!\n";
        exit(0);
    }
    else
    {
        cout << "\nInvalid choice!\n";
    }
}

void village(Player &player)
{
    int choice;

    cout << "\n========================================\n";
    cout << "             MYSTERIOUS VILLAGE\n";
    cout << "========================================\n";

    cout << "\nYou discover a small village.";
    cout << "\nThere is a blacksmith and a mysterious shopkeeper.\n";

    cout << "\n1. Visit the blacksmith";
    cout << "\n2. Talk to the shopkeeper";
    cout << "\n3. Leave the village";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nThe blacksmith says:";
        cout << "\n\"I can sell you a sword for 15 coins.\"\n";

        if (player.coins >= 15)
        {
            int buy;

            cout << "\nDo you want to buy the sword?";
            cout << "\n1. Yes";
            cout << "\n2. No";

            cout << "\n\nChoice: ";
            cin >> buy;

            if (buy == 1)
            {
                player.coins -= 15;
                player.hasSword = true;

                cout << "\nYou bought a sword!\n";
            }
        }
        else
        {
            cout << "\nYou don't have enough coins.\n";
        }
    }
    else if (choice == 2)
    {
        cout << "\nShopkeeper:";
        cout << "\n\"The treasure is hidden inside the ancient castle.\"\n";
        cout << "\"You will need a golden key to enter.\"\n";
    }
    else if (choice == 3)
    {
        cout << "\nYou leave the village.\n";
    }
    else
    {
        cout << "\nInvalid choice!\n";
    }
}

void castle(Player &player)
{
    int choice;

    cout << "\n========================================\n";
    cout << "             ANCIENT CASTLE\n";
    cout << "========================================\n";

    cout << "\nYou arrive at an ancient castle.";
    cout << "\nA giant locked door stands before you.\n";

    if (!player.hasKey)
    {
        cout << "\nThe door is locked.";
        cout << "\nYou need a golden key.\n";
        return;
    }

    cout << "\nYou use the golden key.";
    cout << "\nThe door opens slowly...\n";

    cout << "\nInside, you see a giant dragon!\n";

    cout << "\n1. Fight the dragon";
    cout << "\n2. Run away";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (player.hasSword)
        {
            cout << "\nYou attack the dragon with your sword!\n";
            cout << "After a difficult battle, you defeat it!\n";

            cout << "\nYou discover the legendary treasure!\n";

            cout << "\n****************************************\n";
            cout << "          YOU FOUND THE TREASURE!\n";
            cout << "              YOU WIN!\n";
            cout << "****************************************\n";

            player.coins += 100;
        }
        else
        {
            cout << "\nYou try to fight the dragon with your bare hands.\n";
            cout << "The dragon defeats you.\n";

            player.health = 0;

            cout << "\nGAME OVER!\n";
        }
    }
    else if (choice == 2)
    {
        cout << "\nYou run away from the castle.\n";
        cout << "The treasure remains hidden...\n";
    }
    else
    {
        cout << "\nInvalid choice!\n";
    }
}

int main()
{
    srand(time(0));

    char playAgain;

    do
    {
        Player player;

        cin.ignore();

        introduction(player);

        int choice;

        while (player.health > 0)
        {
            cout << "\n\n========================================\n";
            cout << "                MAIN MENU\n";
            cout << "========================================\n";

            cout << "\n1. Explore the Dark Forest";
            cout << "\n2. Visit the Village";
            cout << "\n3. Enter the Ancient Castle";
            cout << "\n4. Check Player Status";
            cout << "\n5. Quit Game";

            cout << "\n\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    forest(player);
                    break;

                case 2:
                    village(player);
                    break;

                case 3:
                    castle(player);
                    break;

                case 4:
                    player.showStatus();
                    break;

                case 5:
                    cout << "\nThank you for playing, "
                         << player.name << "!\n";
                    return 0;

                default:
                    cout << "\nInvalid choice! Please try again.\n";
            }

            if (player.health <= 0)
            {
                cout << "\nYour health has reached zero.\n";
                cout << "GAME OVER!\n";
                break;
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n========================================\n";
    cout << "       THANK YOU FOR PLAYING!\n";
    cout << "========================================\n";

    return 0;
}
