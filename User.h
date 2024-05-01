#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class User {
    std::string _name;
    std::string _login;
    std::string _pass;

public:
    User(std::string name, std::string login, std::string pass) :_name(name), _login(login), _pass(pass) {}
    friend std::fstream& operator >>(std::fstream& is, User& obj);
    friend std::ostream& operator <<(std::ostream& os, const User& obj);
    friend void save_users(const std::vector<User>& users, const std::string& file_name);
    friend std::vector<User> load_users(const std::string& file_name);
};
