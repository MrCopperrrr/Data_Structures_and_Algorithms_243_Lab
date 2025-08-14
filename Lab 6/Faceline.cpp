// ...existing code...
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
#include <fstream>
#include "User.h"
#include "Faceline.h"
#include "Message.h"
// Kiểm tra nếu có đường đi từ A đến B qua các mối quan hệ bạn bè hoặc follower
#include <queue>
bool Faceline::has_connection(const std::string& A, const std::string& B) {
    if (users.find(A) == users.end() || users.find(B) == users.end()) return false;
    std::unordered_set<std::string> visited;
    std::queue<std::string> q;
    q.push(A);
    visited.insert(A);
    while (!q.empty()) {
        std::string current = q.front(); q.pop();
        if (current == B) return true;
        // Duyệt bạn bè
        for (const auto& f : users[current].friends) {
            if (!visited.count(f)) {
                visited.insert(f);
                q.push(f);
            }
        }
        // Duyệt follower
        for (const auto& fo : users[current].followers) {
            if (!visited.count(fo)) {
                visited.insert(fo);
                q.push(fo);
            }
        }
    }
    return false;
}

void Faceline::join(const std::string& name) {
    if (users.find(name) == users.end()) {
        users[name] = User(name);
    }
}

void Faceline::post(const std::string& name) {
    if (users.find(name) != users.end()) {
        users[name].post();
    }
}

void Faceline::makefriend(const std::string& name1, const std::string& name2) {
    if (users.find(name1) != users.end() && users.find(name2) != users.end()) {
        users[name1].add_friend(name2);
        users[name2].add_friend(name1);
    }
}

void Faceline::follow(const std::string& follower, const std::string& followee) {
    if (users.find(follower) != users.end() && users.find(followee) != users.end()) {
        users[followee].add_follower(follower);
    }
}

// Gửi tin nhắn có nội dung và ngày, lưu ra file
bool Faceline::send(const std::string& from, const std::string& to, const std::string& content, const std::string& date) {
    if (users.find(from) != users.end() && users.find(to) != users.end()) {
        if (users[from].friends.count(to) || users[to].followers.count(from)) {
            users[from].send_message(to, content, date);
            return true;
        }
    }
    return false;
}
// Trả về danh sách file tin nhắn mà viewer có thể truy cập từ sender
std::vector<std::string> Faceline::get_accessible_messages(const std::string& viewer, const std::string& sender) {
    std::vector<std::string> files;
    if (users.find(viewer) == users.end() || users.find(sender) == users.end()) return files;
    if (!has_connection(viewer, sender) && viewer != sender) return files;
    for (const auto& msg : users[sender].sent_messages) {
        files.push_back(msg.getFileName());
    }
    return files;
}

std::vector<std::string> Faceline::find_contact(const std::string& B, const std::string& C) {
    std::vector<std::string> result;
    if (users.find(B) == users.end() || users.find(C) == users.end()) return result;
    for (const auto& x : users[B].friends) {
        if (users[C].friends.count(x) || users[C].followers.count(x)) {
            result.push_back(x);
        }
    }
    return result;
}
