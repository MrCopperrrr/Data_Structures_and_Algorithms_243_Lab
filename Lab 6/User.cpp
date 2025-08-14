#include "User.h"


User::User() : name(""), status_count(0) {}

User::User(const std::string& name) : name(name), status_count(0) {}

void User::post() {
    status_count++;
}

void User::add_friend(const std::string& other) {
    friends.insert(other);
}

void User::add_follower(const std::string& other) {
    followers.insert(other);
}

// Gửi tin nhắn, lưu vào danh sách và file
#include "Message.h"
#include <fstream>
void User::send_message(const std::string& to, const std::string& content, const std::string& date) {
    int msgNum = messages_sent[to] + 1;
    messages_sent[to] = msgNum;
    Message msg(name, to, content, date, msgNum);
    sent_messages.push_back(msg);
    std::ofstream fout("Lab 6/" + msg.getFileName());
    fout << "From: " << name << "\nTo: " << to << "\nDate: " << date << "\nContent: " << content << std::endl;
    fout.close();
}
