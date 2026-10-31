# Test Score File Analyzer (C++)

A C++ console program that reads test scores from a text file, checks each entry, and writes a score summary report.

## Features

- Reads scores from a file chosen by the user.
- Ignores blank lines and lines beginning with `#`.
- Reports non-numeric entries and scores outside the 0 to 100 range.
- Calculates the count, total, average, highest and lowest scores, including ties.
- Counts letter grades from A to F.
- Prints a summary to the console and saves it to `score_report.txt`.

## How to run

Compile with a C++ compiler such as g++:

```bash
g++ grades.cpp -o grades
```

Run the program (macOS/Linux):

```bash
./grades
```

On Windows, run `grades.exe` from your terminal instead.

When prompted for the filename, type `scores.txt` to use the included example data. The program creates `score_report.txt` in the current directory.

## What I practiced

C++ loops, conditionals, strings, file input/output (`ifstream` and `ofstream`), input validation, and formatted output.
