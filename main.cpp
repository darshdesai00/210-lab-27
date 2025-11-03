#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;


    // insert elements into the map
    villagers["Audie"]   = make_tuple(5, "Dog", "Fluffly!!");
    villagers["Raymond"] = make_tuple(7, "Cat", "Purr!!");
    villagers["Mitch"] = make_tuple(9, "Fox", "Reese");

    // access the map using a range-based for loop
    cout << "Villager details (range-based for loop):" << endl;
    for (auto pair : villagers) {
        auto [friendship, species, catchphrase] = pair.second;
        cout << pair.first << " [" << friendship << ", "
             << species << ", " << catchphrase << "]" << endl;
    }

    // access the map using iterators
    cout << "\nVillagers details (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
        it != villagers.end(); ++it) {
        int friendship;
        string species, catchphrase;
        tie(friendship, species, catchphrase) = it->second;
        cout << it->first << " [" << friendship << ", "
             << species << ", " << catchphrase << "]" << endl;
    }    

    // delete an element
    villagers.erase("Raymond");

    // search for an element
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {
        auto [f, s, c] = it->second;
        cout << "\nFound " << searchKey << ": [" << f << ", "
             << s << ", " << c << "]" << endl;
    } else {
        cout << "\n" << searchKey << " not found." << endl;
    }

    // report size, clear, report size again
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
