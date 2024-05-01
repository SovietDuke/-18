#include "Message.h"

std::fstream& operator >>(std::fstream& is, Message& obj)
{
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;
    return is;
}

std::ostream& operator <<(std::ostream& os, const Message& obj)
{
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    return os;
}

void save_messages(const std::vector<Message>& messages, const std::string& file_name) {
    fs::perms file_permissions{ fs::perms::owner_all };
    std::fstream ofs(file_name, std::ios::binary | std::ios::out);
    if (ofs.good()) {
        for (const auto& message : messages) {
            ofs << message << std::endl;
        }
        ofs.close();
        fs::permissions(file_name, file_permissions, fs::perm_options::replace);
    }
}