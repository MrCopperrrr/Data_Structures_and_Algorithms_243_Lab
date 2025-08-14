
#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "Message.h"

class User {
public:
    std::string name;
    int status_count;
    std::unordered_set<std::string> friends;
    std::unordered_set<std::string> followers;
    std::unordered_map<std::string, int> messages_sent; // key: receiver, value: count
    std::vector<class Message> sent_messages;

    User(); // constructor mặc định
    User(const std::string& name);
    void post();
    void add_friend(const std::string& other);
    void add_follower(const std::string& other);
    void send_message(const std::string& to, const std::string& content, const std::string& date);
};
