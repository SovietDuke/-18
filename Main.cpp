#include "Message.h"
#include "User.h"

std::vector<User> load_users(const std::string& file_name) {
    std::vector<User> users;
    std::fstream ifs(file_name, std::ios::binary | std::ios::in);
    if (ifs.good()) {
        User user("", "", "");
        while (ifs >> user) {
            users.push_back(user);
        }
        ifs.close();
    }
    return users;
}

std::vector<Message> load_messages(const std::string& file_name) {
    std::vector<Message> messages;
    std::fstream ifs(file_name, std::ios::binary | std::ios::in);
    if (ifs.good()) {
        Message message("", "", "");
        while (ifs >> message) {
            messages.push_back(message);
        }
        ifs.close();
    }
    return messages;
}

int main()
{
    const std::string user_file = "users.dat";
    const std::string message_file = "messages.dat";

    std::vector<User> users = load_users(user_file);
    std::vector<Message> messages = load_messages(message_file);

    users.push_back(User("test_name", "test_login", "test_pass"));
    messages.push_back(Message("Test text1", "Test text2", "Test text3"));

    save_users(users, user_file);
    save_messages(messages, message_file);

    return 0;
}