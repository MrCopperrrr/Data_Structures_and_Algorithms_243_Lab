#include <iostream>
#include "Faceline.h"

int main() {
    Faceline network;
    network.join("A");
    network.join("B");
    network.join("C");
    network.join("D");
    network.join("E");

    network.post("A");
    network.post("A");
    network.post("B");
    network.post("C");

    network.makefriend("A", "B");
    network.makefriend("B", "D");
    network.makefriend("C", "E");
    network.follow("A", "C");
    network.follow("D", "E");

    network.send("A", "B", "Hello B!", "250814");
    network.send("B", "A", "Hi A!", "250814");
    network.send("A", "C", "Hi C, I follow you!", "250814");

    // Truy cập tin nhắn của A bởi B (có kết nối)
    std::cout << "\nMessages from A accessible by B:" << std::endl;
    for (const auto& file : network.get_accessible_messages("B", "A")) {
        std::cout << file << std::endl;
    }

    // Truy cập tin nhắn của A bởi E (không có kết nối)
    std::cout << "\nMessages from A accessible by E:" << std::endl;
    for (const auto& file : network.get_accessible_messages("E", "A")) {
        std::cout << file << std::endl;
    }

    std::vector<std::string> contacts = network.find_contact("B", "C");
    std::cout << "Suitable contacts for B to reach C: ";
    for (const auto& name : contacts) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    // Ví dụ 1: Kiểm tra kết nối trực tiếp
    std::cout << "A has connection to B: " << (network.has_connection("A", "B") ? "Yes" : "No") << std::endl;

    // Ví dụ 2: Kiểm tra kết nối qua nhiều bước
    std::cout << "A has connection to D: " << (network.has_connection("A", "D") ? "Yes" : "No") << std::endl;

    // Ví dụ 3: Kiểm tra kết nối không tồn tại
    std::cout << "B has connection to E: " << (network.has_connection("B", "E") ? "Yes" : "No") << std::endl;

    return 0;
}
