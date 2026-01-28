#include "logger.h"

int main() {
    LOG(ERROR, "Critical error occurred!");
    LOG(WARN, "This is a warning.");
    LOG(INFO, "Application started successfully.");
    LOG(DEBUG, "Debugging variable x = 42.");
    return 0;
}
