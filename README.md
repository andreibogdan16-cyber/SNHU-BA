# Corner Grocer - Item Frequency Tracker

This console program reads grocery items from `CS210_Project_Three_Input_File.txt`,
counts occurrences, writes a backup `frequency.dat`, and provides a menu to:

1. Search for an item’s frequency (case-insensitive)
2. Print frequency of all items
3. Print a text histogram (asterisks)
4. Exit

## Build & Run

### macOS/Linux (Make)

```bash
make run
```

or

```bash
g++ -std=c++17 main.cpp -o grocer
./grocer
```

### Windows (MinGW g++)

Double-click `build_and_run.bat` or run:

```bat
g++ -std=c++17 main.cpp -o grocer.exe
grocer.exe
```

Ensure `CS210_Project_Three_Input_File.txt` is in the same folder as the executable.
The program will generate `frequency.dat` automatically.
