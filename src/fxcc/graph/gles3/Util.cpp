#include "fxcc/graph/Util.h"

std::string Ogl::Gut::Util::getExtension(const std::string &filename)
{
    size_t dotPos = filename.find_last_of(".");
    if (dotPos == std::string::npos)
    {
        return "";
    }
    return filename.substr(dotPos);
}

std::string Ogl::Gut::Util::readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::ostringstream oss;
    oss << file.rdbuf();
    file.close();

    return oss.str();
}

void Ogl::Gut::Util::Write(const std::string &path, const std::string &code)

{
    fs::path _p(path);
    if (_p.has_parent_path())
    {
        fs::create_directories(_p.parent_path());
    }
    std::ofstream ofs(path);

    ofs << code;
    ofs.flush();
    ofs.close();
}