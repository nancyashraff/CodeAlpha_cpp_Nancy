// Basic File Manager


#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using namespace std;

void displayCurrentPath() {
    cout << "Current Path: " << fs::current_path() << endl;
}

void listFilesInDirectory(const fs::path& dir) {
    cout << "Files in " << dir << ":" << endl;
    for (const auto& entry : fs::directory_iterator(dir)) {
        cout << entry.path().filename() << endl;
    }
}

void createDirectory(const string& dirName) {
    if (fs::create_directory(dirName)) {
        cout << "Directory '" << dirName << "' created." << endl;
    }
    else {
        cout << "Failed to create directory '" << dirName << "'." << endl;
    }
}

void copyFile(const fs::path& source, const fs::path& destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);
    if (src && dest) {
        dest << src.rdbuf();
        cout << "File copied from " << source << " to " << destination << "." << endl;
    }
    else {
        cout << "Error copying file." << endl;
    }
}

void moveFile(const fs::path& source, const fs::path& destination) {
    if (rename(source.c_str(), destination.c_str()) == 0) {
        cout << "File moved from " << source << " to " << destination << "." << endl;
    }
    else {
        cout << "Error moving file." << endl;
    }
}

int main() {
    string command;
    string arg1, arg2;

    while (true) {
        displayCurrentPath();
        cout << "Enter command (ls, mkdir <dir>, cp <src> <dest>, mv <src> <dest>, exit): ";
        getline(cin, command);

        if (command == "exit") {
            break;
        }
        else if (command == "ls") {
            listFilesInDirectory(fs::current_path());
        }
        else if (command.substr(0, 6) == "mkdir ") {
            arg1 = command.substr(6);
            createDirectory(arg1);
        }
        else if (command.substr(0, 3) == "cp ") {
            size_t spacePos = command.find(' ', 3);
            if (spacePos != string::npos) {
                arg1 = command.substr(3, spacePos - 3);
                arg2 = command.substr(spacePos + 1);
                copyFile(arg1, arg2);
            }
        }
        else if (command.substr(0, 3) == "mv ") {
            size_t spacePos = command.find(' ', 3);
            if (spacePos != string::npos) {
                arg1 = command.substr(3, spacePos - 3);
                arg2 = command.substr(spacePos + 1);
                moveFile(arg1, arg2);
            }
        }
        else {
            cout << "Unknown command!" << endl;
        }
    }

    return 0;
}
