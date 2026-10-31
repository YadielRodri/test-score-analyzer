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

## Example output

Using the included `scores.txt` sample data:

```text
Enter the input filename: scores.txt
Invalid score ignored: 125
Non-numeric entry ignored: absent

===== Exam Score Summary =====
Valid scores processed: 7
Out of range scores ignored: 1
Non-numeric entries ignored: 1
Sum of scores: 340
Average score: 48.57
Highest score: 100 (tied by 2 scores)
Lowest score: 0 (tied by 1 score)

Grade Distribution
A: 2
B: 0
C: 0
D: 0
F: 5

Report written to score_report.txt
```

## What I practiced

C++ loops, conditionals, strings, file input/output (`ifstream` and `ofstream`), input validation, and formatted output.
