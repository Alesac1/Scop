#ifndef SHADER_PROGRAM_HPP
# define SHADER_PROGRAM_HPP

# include <string>

class ShaderProgram
{
    public:
        ShaderProgram();
        ~ShaderProgram();

        bool load(
            const std::string& vertexPath,
            const std::string& fragmentPath
        );

        void use() const;

    private:
        unsigned int _id;

        std::string readFile(const std::string& path) const;

        bool compileShader(
            unsigned int shader,
            const std::string& source,
            const std::string& label
        ) const;

        bool linkProgram(unsigned int program) const;
};

#endif