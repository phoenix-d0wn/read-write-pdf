// Include C library
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {
    string pdfPath = "bruh.pdf";
    string outputFilePath = "bruh.txt";

    string command = "pdftotext " + pdfPath + " " + outputFilePath;
    int status = system(command.c_str());

    if (status == 0) {
        cout << "Text extraction successful." << endl;
    } else {
        cout << "Text extraction failed." << endl;
        return 1;
    }

    ifstream outputFile(outputFilePath);
    if (outputFile.is_open()) {
        string textContent;
        string line;
        while (getline(outputFile, line)) {
            textContent += line + "\n";
        }
        outputFile.close();

        cout << "Text content extracted from PDF document:" << endl;
        cout << textContent << endl;
    } else {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    return 0;
}
