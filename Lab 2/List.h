#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>

enum Error_code {
	success,
	fail,
	rangeerror,
	overflow,
	not_present,
	dupplicated,
	found
};

template<class Node_entry> 
struct Node {
	Node_entry entry;
	Node<Node_entry> *next;
	Node();
	Node(Node_entry item, Node<Node_entry> * link = NULL);
};

template <class List_entry>
class List {
public:
	List(); // Khởi tạo danh sách rỗng
	~List(); // Hủy danh sách, giải phóng bộ nhớ

	void clear(); // Xóa toàn bộ danh sách
	bool empty(); // Kiểm tra danh sách có rỗng hay không
	int size(); // Trả về số lượng phần tử trong danh sách
	Error_code insert(int position, List_entry x); // Chèn phần tử x vào vị trí position
	Error_code remove(int position, List_entry &x); // Xóa phần tử tại vị trí position và lưu giá trị vào x
	Error_code retrieve(int position, List_entry &x); // Lấy giá trị phần tử tại vị trí position
	void printAll(); // In toàn bộ danh sách

	// 3.6 - 3.9
	Error_code remove_by_value(List_entry x); // Xóa phần tử x nếu chỉ xuất hiện đúng 1 lần
	Error_code remove_last(List_entry x); // Xóa lần xuất hiện cuối cùng của phần tử x
	void remove_prime_positions(); // Xóa các phần tử tại vị trí nguyên tố
	void remove_all(List_entry x); // Xóa toàn bộ các phần tử có giá trị x

private:
	int count; // Số lượng phần tử trong danh sách
	Node<List_entry> *head; // Con trỏ đầu danh sách
	Node<List_entry> *set_position(int position); // Trả về con trỏ tới vị trí position
};

#endif // __LIST__H__
