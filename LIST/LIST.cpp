
#include "OneList.h"
#include "DoubleList.h"

int main()
{
	OneList sll;

	sll.AddToTail(10);
	sll.AddToTail(20);
	sll.AddToTail(30);
	sll.AddToTail(40);
	sll.Print();

	
	sll.AddToHead(50);
	sll.AddToHead(60);
	sll.AddToHead(70);
	sll.AddToHead(80);
	sll.Print();

	
	cout << "count: " << sll.GetCount() << "\n";
	cout << "index of 70: " << sll.IndexOf(70) << ", index of 90: " << sll.IndexOf(90) << "\n";


	sll.InsertInto(-1, -1);
	sll.Print();
	sll.InsertInto(2, 2);
	sll.Print();
	sll.InsertInto(22, 22);
	sll.Print();


	sll.DeleteFromHead();
	sll.Print();


	sll.DeleteFromTail();
	sll.Print();

	sll.DeleteByIndex(0);
	sll.Print();



	DoubleLIst dll;
	cout << dll << "\n";

	dll.AddToTail(10);
	dll.AddToTail(20);
	dll.AddToTail(30);
	dll.AddToTail(40);
	cout << dll << "\n";

	dll.AddToHead(50);
	dll.AddToHead(60);
	dll.AddToHead(70);
	dll.AddToHead(80);
	cout << dll << "\n";

	dll.Insert(0, 7);
	dll.Insert(0, 5);
	dll.Insert(0, 3);
	dll.Insert(0, 1);
	cout << dll << "\n";

	dll.DeleteByIndex(1);
	cout << dll << "\n";
}


