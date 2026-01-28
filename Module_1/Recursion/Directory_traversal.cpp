#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

/* Recursive function to traverse directory */
void recursiveDirectoryTraversal(const fs::path& path, int level) {
    for (const auto& entry : fs::directory_iterator(path)) {
        
        // Indentation
        for (int i = 0; i < level; i++)
            cout << " ";

        if (fs::is_directory(entry)) {
            cout << entry.path().filename().string() << ":\n";

            // Recursive call
            recursiveDirectoryTraversal(entry.path(), level + 2);
        } else {
            cout << entry.path().filename().string() << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: program <directory_path>\n";
        return 0;
    }

    cout << "Root:\n";
    recursiveDirectoryTraversal(argv[1], 2);

    return 0;
}
