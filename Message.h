#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include "User.h"

namespace fs = std::filesystem;

class Message {
    std::string _text;
    std::string _sender;
    std::string _receiver;

public:
    Message(std::string text, std::string sender, std::string receiver) : _text(text), _sender(sender), _receiver(receiver) {}
    friend std::fstream& operator >>(std::fstream& is, Message& obj);
    friend std::ostream& operator <<(std::ostream& os, const Message& obj);
    friend void save_messages(const std::vector<Message>& messages, const std::string& file_name);
    friend std::vector<Message> load_messages(const std::string& file_name);
};
