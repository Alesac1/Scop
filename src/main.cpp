#include "App.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./scop <model.obj>" << std::endl;
        return 1;
    }

    App app(argv[1]);

    if (!app.init())
        return 1;

    app.run();

    return 0;
}