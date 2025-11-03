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
            cout << "1. Increase Friendship\n";
            cout << "2. Decrease Friendship\n";
            cout << "3. Search for Villager\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice; 

            if (choice == 1) {
            cout << "Enter villager name to increase friendship: ";
            cin >> name;
            if (villagers.find(name) != villagers.end()) {
                auto &[friendship, species, catchphrase] = villagers[name];
                friendship++;
                cout << name << "'s friendship increased to " << friendship << "!" << endl;
            } else {
                cout << name << " not found." << endl;
            }
            displayVillagers(villagers);
        }
            else if (choice == 2) {
            cout << "Enter villager name to decrease friendship: ";
            cin >> name;
            if (villagers.find(name) != villagers.end()) {
                auto &[friendship, species, catchphrase] = villagers[name];
                if (friendship > 0) friendship--;
                cout << name << "'s friendship decreased to " << friendship << "!" << endl;
            } else {
                cout << name << " not found." << endl;
            }
            displayVillagers(villagers);
        }
            else if (choice == 3) {
            cout << "Enter villager name to search: ";
            cin >> name;
            auto it = villagers.find(name);
            if (it != villagers.end()) {
                auto [f, s, c] = it->second;
                cout << "Found " << name << ": [" << f << ", " << s << ", " << c << "]" << endl;
            } else {
                cout << name << " not found." << endl;
            }
            displayVillagers(villagers);
        }
           else if (choice == 4) {
            cout << "Exiting program." << endl;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}    

    