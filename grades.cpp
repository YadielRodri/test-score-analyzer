/*
Test Score File Analyzer
Reads test scores from a file, validates each entry, and creates a summary report.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const int minScore = 0;
    const int maxScore = 100;
    const int aBoundary = 90;
    const int bBoundary = 80;
    const int cBoundary = 70;
    const int dBoundary = 60;

    string fileName;
    ifstream inputFile;

    // Keep asking until the input file opens successfully.
    cout << "Enter the input filename: ";
    getline(cin, fileName);
    inputFile.open(fileName.c_str());

    while (!inputFile)
    {
        cout << "Could not open the file. Enter another filename: ";
        getline(cin, fileName);
        inputFile.close();
        inputFile.open(fileName.c_str());
    }

    ofstream outputFile;
    outputFile.open("score_report.txt");

    if (!outputFile)
    {
        cout << "Could not create score_report.txt." << endl;
        inputFile.close();
        return 0;
    }

    int validScoreCount = 0;
    int outOfRangeCount = 0;
    int nonNumericCount = 0;
    int sumOfScores = 0;
    int highestScore = 0;
    int lowestScore = 0;
    int highestTieCount = 0;
    int lowestTieCount = 0;
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;
    string line;

    // Read every line because the number of scores is not known in advance.
    while (getline(inputFile, line))
    {
        // Skip the required comment line and any other comment lines.
        if (line.length() > 0 && line[0] == '#')
        {
            continue;
        }

        // A completely blank line is ignored silently.
        if (line == "")
            continue;

        bool isNumeric = true;
        bool digitFound = false;
        int startingPosition = 0;
        int score = 0;

        // A minus sign is allowed so that negative scores can be reported
        // as out of range instead of being reported as non-numeric.
        if (line[0] == '-')
        {
            startingPosition = 1;
        }

        // Check every character and build the whole-number score.
        for (int position = startingPosition;
             position < static_cast<int>(line.length());
             position++)
        {
            char currentCharacter = line[position];

            if (currentCharacter >= '0' && currentCharacter <= '9')
            {
                digitFound = true;
                score = score * 10 + (currentCharacter - '0');
            }
            else
            {
                isNumeric = false;
            }
        }

        if (!digitFound)
            isNumeric = false;

        if (line[0] == '-')
            score = -score;

        if (!isNumeric)
        {
            cout << "Non-numeric entry ignored: " << line << endl;
            outputFile << "Non-numeric entry ignored: " << line << endl;
            nonNumericCount++;
        }
        else if (score < minScore || score > maxScore)
        {
            cout << "Invalid score ignored: " << score << endl;
            outputFile << "Invalid score ignored: " << score << endl;
            outOfRangeCount++;
        }
        else
        {
            validScoreCount++;
            sumOfScores += score;

            if (validScoreCount == 1)
            {
                highestScore = score;
                lowestScore = score;
                highestTieCount = 1;
                lowestTieCount = 1;
            }
            else
            {
                if (score > highestScore)
                {
                    highestScore = score;
                    highestTieCount = 1;
                }
                else if (score == highestScore)
                {
                    highestTieCount++;
                }

                if (score < lowestScore)
                {
                    lowestScore = score;
                    lowestTieCount = 1;
                }
                else if (score == lowestScore)
                {
                    lowestTieCount++;
                }
            }

            if (score >= aBoundary)
                aCount++;
            else if (score >= bBoundary)
                bCount++;
            else if (score >= cBoundary)
                cCount++;
            else if (score >= dBoundary)
                dCount++;
            else
                fCount++;
        }
    }

    inputFile.close();

    // The report is written to both the screen and the output file.
    cout << "\n===== Exam Score Summary =====" << endl;
    cout << "Valid scores processed: " << validScoreCount << endl;
    cout << "Out of range scores ignored: " << outOfRangeCount << endl;
    cout << "Non-numeric entries ignored: " << nonNumericCount << endl;
    outputFile << "\n===== Exam Score Summary =====" << endl;
    outputFile << "Valid scores processed: " << validScoreCount << endl;
    outputFile << "Out of range scores ignored: " << outOfRangeCount << endl;
    outputFile << "Non-numeric entries ignored: " << nonNumericCount << endl;

    if (validScoreCount == 0)
    {
        cout << "No valid scores found. Average cannot be calculated." << endl;
        outputFile << "No valid scores found. Average cannot be calculated." << endl;
    }
    else
    {
        double averageScore = static_cast<double>(sumOfScores) / validScoreCount;

        cout << "Sum of scores: " << sumOfScores << endl;
        cout << fixed << setprecision(2);
        cout << "Average score: " << averageScore << endl;
        cout << "Highest score: " << highestScore
             << " (tied by " << highestTieCount
             << (highestTieCount == 1 ? " score)" : " scores)") << endl;
        cout << "Lowest score: " << lowestScore
             << " (tied by " << lowestTieCount
             << (lowestTieCount == 1 ? " score)" : " scores)") << endl;
        cout << "\nGrade Distribution" << endl;
        cout << "A: " << aCount << endl;
        cout << "B: " << bCount << endl;
        cout << "C: " << cCount << endl;
        cout << "D: " << dCount << endl;
        cout << "F: " << fCount << endl;

        outputFile << "Sum of scores: " << sumOfScores << endl;
        outputFile << fixed << setprecision(2);
        outputFile << "Average score: " << averageScore << endl;
        outputFile << "Highest score: " << highestScore
                   << " (tied by " << highestTieCount
             << (highestTieCount == 1 ? " score)" : " scores)") << endl;
        outputFile << "Lowest score: " << lowestScore
                   << " (tied by " << lowestTieCount
             << (lowestTieCount == 1 ? " score)" : " scores)") << endl;
        outputFile << "\nGrade Distribution" << endl;
        outputFile << "A: " << aCount << endl;
        outputFile << "B: " << bCount << endl;
        outputFile << "C: " << cCount << endl;
        outputFile << "D: " << dCount << endl;
        outputFile << "F: " << fCount << endl;
    }

    outputFile.close();
    cout << "\nReport written to score_report.txt" << endl;
    return 0;
}