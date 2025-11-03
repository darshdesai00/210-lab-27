// COMSC-210 | Lab 27 | Darsh Desai
// IDE used: VS Code (Mac)
// Description: This program simulates a villager management system using std::map and std::tuple.
// The user will be able to do the following add, delete, search, and modify villagers' friendship levels via a menu-driven interface.
// It also has a bunch of key operations with std::map such as insert, erase, find, and iteration.

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// below is the helper function to print all villagers
void displayVillagers(map<string, tuple<int, string, string>> &villagers) {
    cout << "\nVillager details:" << endl;
    for (auto &pair : villagers) {
    auto [friendship, species, catchphrase] = pair.second;
    cout << pair.first << " [" << friendship << ", "
    << species << ", " << catchphrase << "]" << endl;
    }
}

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    villagers["Audie"]   = make_tuple(5, "Dog", "Fluffly!!");
    villagers["Raymond"] = make_tuple(7, "Cat", "Purr!!");
    villagers["Mitch"] = make_tuple(9, "Fox", "Reese");

    int choice;
    string name;

        do{
            cout << "\nMenu:\n";
            cout << "1. Add Villager\n";
            cout << "2. Delete Villager\n";
            cout << "3. Increase Friendship\n";
            cout << "4. Decrease Friendship\n";
            cout << "5. Search for Villager\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";
            cin >> choice; 

            if (choice == 1) {
            string species, catchphrase;
            int friendship;
            cout << "Villager name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Friendship level (0-10): ";
            cin >> friendship;
            cout << "Species: ";
            cin >> ws;
            getline(cin, species);
            cout << "Catchphrase: ";
            cin >> ws;
            getline(cin, catchphrase);
            
            villagers[name] = make_tuple(friendship, species, catchphrase);
            cout << name << " added." << endl;
            displayVillagers(villagers);
        }

        else if (choice == 2) {
            cout << "Enter villager name to delete: ";
            cin >> ws;
            getline(cin, name);
            if (villagers.erase(name))
                cout << name << " deleted." << endl;
            else
                cout << name << " not found." << endl;
            displayVillagers(villagers);
        }

            if (choice == 3) {
            cout << "Enter villager name to increase friendship: ";
            cin >> ws;
            getline(cin, name);
            if (villagers.find(name) != villagers.end()) {
                auto &[friendship, species, catchphrase] = villagers[name];
                friendship++;
                cout << name << "'s friendship increased to " << friendship << "!" << endl;
            } else {
                cout << name << " not found." << endl;
            }
            displayVillagers(villagers);
        }
            else if (choice == 4) {
            cout << "Enter villager name to decrease friendship: ";
            cin >> ws;
            getline(cin, name);
            if (villagers.find(name) != villagers.end()) {
                auto &[friendship, species, catchphrase] = villagers[name];
                if (friendship > 0) friendship--;
                cout << name << "'s friendship decreased to " << friendship << "!" << endl;
            } else {
                cout << name << " not found." << endl;
            }
            displayVillagers(villagers);
        }
            else if (choice == 5) {
            cout << "Enter villager name to search: ";
            cin >> ws;
            getline(cin, name);
            auto it = villagers.find(name);
            if (it != villagers.end()) {
                auto [f, s, c] = it->second;
                cout << "Found " << name << ": [" << f << ", " << s << ", " << c << "]" << endl;
            } else {
                cout << name << " not found." << endl;
            }
            displayVillagers(villagers);
        }
           else if (choice == 6) {
            cout << "Exiting program." << endl;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}    

    