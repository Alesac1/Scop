#ifndef APP_HPP
# define APP_HPP

# include <string>

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
};

#endif
