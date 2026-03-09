#include <fstream>
#include <iostream>
#include <string>

class FileWrapper {
    std::ofstream file;
public:
    FileWrapper(const std::string& filename) {
        file.open(filename);
        if (!file) throw std::runtime_error("Failed to open file");
        std::cout << "File opened: " << filename << "\n";
    }
    ~FileWrapper() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed automatically.\n";
        }
    }

    std::ofstream& get() { return file; }
};

int main() {
    try {
        FileWrapper fw("example.txt");
        fw.get() << "First line." << std::endl;
        fw.get() << "Second line." << std::endl;
        // Uncomment the following to test exception safety:
        // throw std::runtime_error("Simulated crash!");
        fw.get() << "Third line." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    std::cout << "Back in main, after FileWrapper goes out of scope.\n";
    return 0;
}
