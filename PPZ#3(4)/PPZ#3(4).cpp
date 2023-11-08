
#include <iostream>

using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

void add(Node*& head, int N, int j)
{
	if (N > j)
	{
		int n;
		n = rand() % 10001;
		Node* cur = new Node(n);
		head->next = cur;
		j++;
		add(cur, N, j);
	}

}
void show(Node* head)
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
}
void deleteList(Node* head)
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void reorderList(Node* head) {
	if (!head || !head->next || !head->next->next) {
		return; // Немає потреби перевпорядковувати списки з менше ніж трьома елементами
	}

	// Знаходимо середину списку
	Node* slow = head;
	Node* fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// Розділяємо список на дві частини
	Node* secondHalf = slow->next;
	slow->next = nullptr;

	// Перевертаємо другу половину списку
	Node* prev = nullptr;
	Node* current = secondHalf;
	Node* next = nullptr;
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	// Об'єднуємо дві половини у потрібному порядку
	Node* firstHalf = head;
	while (prev) {
		Node* firstNext = firstHalf->next;
		Node* secondNext = prev->next;
		firstHalf->next = prev;
		prev->next = firstNext;
		firstHalf = firstNext;
		prev = secondNext;
	}
}
int main()
{
	int N = -1;
	Node* head = new Node(1);
	srand(time(NULL));
	do {
		cout << "Count of elements (0<N<10001): ";
		cin >> N;
	} while (N > 10000 || N < 1);
	add(head, N, 0);
	show(head);
	reorderList(head);
	cout << "\n";
	show(head);
	deleteList(head);
	return 0;
}