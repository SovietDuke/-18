#include "User.h"

std::fstream& operator >>(std::fstream& is, User& obj)
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj)
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}

void save_users(const std::vector<User>& users, const std::string& file_name) {
    fs::perms file_permissions{ fs::perms::owner_all };
    std::fstream ofs(file_name, std::ios::binary | std::ios::out);
    if (ofs.good()) {
        for (const auto& user : users) {
            ofs << user << std::endl;
        }
        ofs.close();
        fs::permissions(file_name, file_permissions, fs::perm_options::replace);
    }
}