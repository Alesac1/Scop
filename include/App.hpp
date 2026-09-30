#ifndef APP_HPP
# define APP_HPP

# include <string>
# include "ShaderProgram.hpp"

struct GLFWwindow;

class App {
    public:
        App(const std::string& modelPath);
        ~App();

        bool init();
        void run();
    
    private:
        std::string _modelPath;
        GLFWwindow *_window;
        ShaderProgram _shader;
};

#endif
