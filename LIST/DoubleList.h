#include "OneList.h"
class DoubleLIst
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:
	int GetCount() const
	{
		return count;
	}

	void Clear()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}

	bool IsEmpty() const
	{
		return count == 0;
	}

	void AddToHead(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = head;
		if (IsEmpty())
		{
			tail = temp;
		}
		else
		{
			head->prev = temp;
		}
		head = temp;
		count++;
	}

	void AddToTail(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->prev = tail;
		if (IsEmpty())
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
		count++;
	}

private:
	Node* GetNode(int position)
	{
		if (position < 0 || position >= count) {
			return nullptr;
		}
		if (position == 0)
		{
			return head;
		}
		if (position == count - 1)
		{
			return tail;
		}

		Node* temp;
		int i = position;
		if (position <= count / 2)
		{
			temp = head->next;
			while (--i != 0)
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = tail->prev;
			while (++i != count - 1)
			{
				temp = temp->prev;
			}
		}
		return temp;
	}

public:
	void Insert(int data, int position)
	{
		if (position <= 0)
		{
			AddToHead(data);
			return;
		}
		if (position >= count)
		{
			AddToTail(data);
			return;
		}

		Node* elem = GetNode(position);
		Node* temp = new Node();
		temp->data = data;
		temp->next = elem;
		temp->prev = elem->prev;
		temp->prev->next = temp;
		temp->next->prev = temp;
		count++;
	}

	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		count--;
	}

	void DeleteFromTail()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		if (tail == nullptr)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		count--;
	}

	void DeleteByIndex(int position)
	{
		if (position == 0)
		{
			DeleteFromHead();
			return;
		}
		if (position == count - 1)
		{
			DeleteFromTail();
			return;
		}
		Node* sacrifice = GetNode(position);
		sacrifice->prev->next = sacrifice->next;
		sacrifice->next->prev = sacrifice->prev;
		delete sacrifice;
		count--;
	}

	friend ostream& operator << (ostream& os, const DoubleLIst& dll)
	{
		if (dll.count == 0)
		{
			os << "list is empty!";
		}
		else
		{
			DoubleLIst::Node* temp = dll.head;
			while (temp != nullptr)
			{
				os << temp->data << " ";
				temp = temp->next;
			}
			return os;
		}
	}
};


