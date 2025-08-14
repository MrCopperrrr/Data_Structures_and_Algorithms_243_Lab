#include "Message.h"

Message::Message(const std::string& sender, const std::string& receiver, const std::string& content, const std::string& date, int msgNumber)
    : sender(sender), receiver(receiver), content(content), date(date), msgNumber(msgNumber) {}

std::string Message::getFileName() const {
    return sender + "_" + date + "_" + std::to_string(msgNumber) + ".txt";
}
