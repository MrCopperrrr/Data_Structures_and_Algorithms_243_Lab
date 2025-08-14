#pragma once
#include <string>

class Message {
public:
    std::string sender;
    std::string receiver;
    std::string content;
    std::string date; // Định dạng: yymmdd
    int msgNumber;
    Message(const std::string& sender, const std::string& receiver, const std::string& content, const std::string& date, int msgNumber);
    std::string getFileName() const;
};
