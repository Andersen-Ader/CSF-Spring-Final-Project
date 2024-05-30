Doubly Linked List inputting from a file storing every M4 Sherman variant in War Thunder.

It stores the tanks Identifier, Name, Main Armament, Nation of Usage, and "Birthday".

Has a REP loop allowing for parsing of basic user commands to find and print parts of the database.

## Example Of Txt File Output

```
---

Identifier-"USA_M4"
Name-"M4"
Armament-"75mm M3"
Nation-"USA"
Birthday-"7/42"

---

Identifier-"USA_M4A1"
Name-"M4A1"
Armament-"75mm M3"
Nation-"USA"
Birthday-"2/42"

---

Identifier-"USA_T34"
Name-"M4 T34 Calliope"
Armament-"M8 Rocket"
Nation-"USA"
Birthday-"2/45"

---

```

## Commands
New - Create a new entry in the database
Query {search term} - Searches the database for entries containing {search term}
Print {identifier} - Prints the stored information about the specified entry
Remove {identifier} - Removes specified entry
Save - Prints currently saved list to output file
Reload - Loads current version of the file into the linked list 
Quit - Saves and ends the program
