// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Austin Yono
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{ 
  string newName;
  int newInt;
  int keyNumber;
  htable newTable;
  int userInput = 0;
  char userInput2 = 'Y';

  cout << "Input the amount of names:\n";
  cin >> userInput;

  for (int i = 0; i < userInput; i++) {
    cout << "Input ID number:\n";
    cin >> newInt;
    cout << "Input name:\n";
    cin >> newName;
    el_t newPerson(newInt, newName);
    newTable.add(newPerson);
  }
  newTable.displayTable();

  do {
    cout << "Input a key number:\n";
    cin >> keyNumber;
    el_t found = newTable.find(keyNumber);
    el_t notFound;
    
    if (found == notFound) { 
      cout << keyNumber << " not found.\n";
    } else {
      cout << "Found " << found << endl;
    }
    cout << "Continue: (Y / N)?\n";
    cin >> userInput2;
  } while (toupper(userInput2) != 'N');

}
// Loop:  
//   Interactively add about 20 keys and names to the table,
//     making sure some of them  collide. (function add)
//     You can create el_t containing a key and name using a constructor.
// DisplayTable.
// Loop:
//  Interactively look up names using keys. (function find)
//    Cout the key + name if found else (blank element was returned)
//    an error message. 
// }
