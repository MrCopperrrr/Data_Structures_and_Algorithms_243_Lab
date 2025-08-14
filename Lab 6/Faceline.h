#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "User.h"

class Faceline {
public:
    std::unordered_map<std::string, User> users;
    void join(const std::string& name);
    void post(const std::string& name);
    void makefriend(const std::string& name1, const std::string& name2);
    void follow(const std::string& follower, const std::string& followee);
    bool send(const std::string& from, const std::string& to, const std::string& content, const std::string& date);
    std::vector<std::string> find_contact(const std::string& B, const std::string& C);
    bool has_connection(const std::string& A, const std::string& B);
    std::vector<std::string> get_accessible_messages(const std::string& viewer, const std::string& sender);
};
