Doubly Linked List inputting from a file storing every M4 Sherman variant in War Thunder.

It stores the tanks Identifier, Name, Main Armament, Nation of Usage, and "Birthday".

Has a REP loop allowing for parsing of basic user commands to find and print parts of the database.

## Example Of Txt File Output

```
USA_M4 M4 75mm_M3 USA 7/42
USA_M4A1 M4A1 75mm_M3 USA 2/42
USA_T34 Calliope M8_Rocket USA 2/45
```

## Commands
New - Create a new entry in the database\
Query {search term} - Searches the database for entries containing {search term}\
Print {identifier} - Prints the stored information about the specified entry\
Remove {identifier} - Removes specified entry\
Save - Prints currently saved list to output file\
Reload - Loads current version of the file into the linked list\
Quit - Saves and ends the program
