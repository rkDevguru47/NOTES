#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char sourceFile[100], destinationFile[100];
    ifstream fin;
    ofstream fout;
    char buffer[1024];
    size_t bytesRead;

    cout << "Enter the source file name: ";
    cin >> sourceFile;

    cout << "Enter the destination file name: ";
    cin >> destinationFile;

    fin.open(sourceFile, ios::binary);
    if (!fin) {
        cout << "Error opening source file." << endl;
        return 1;
    }

    fout.open(destinationFile, ios::binary | ios::trunc);
    if (!fout) {
        cout << "Error opening destination file." << endl;
        fin.close();
        return 1;
    }

    while (true) {
        fin.read(buffer, sizeof(buffer));
        bytesRead = fin.gcount();
        if (bytesRead == 0) {
            break;
        }
        fout.write(buffer, bytesRead);
    }

    fin.close();
    fout.close();

    cout << "File copied successfully." << endl;

    return 0;
}
