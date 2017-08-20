#include "Item.h"
#include "ItemList.h"

#include<iostream>

int main() {
	Item* a = new Item("Go to bed");
	Item* b = new Item("Wake up");
	Item* c = new Item("Brush your teeth");
	Item* d = new Item("Read a book");
	Item* e = new Item("Go outside");
	Item* f = new Item("Ride a bike");
	ItemList list;
	list.addItem(a);
	list.addItem(b);
	list.addItem(c);
	list.addItem(d);
	list.addItem(e);
	list.addItem(f);

	std::cout << "Printing original list: " << std::endl;
	list.printList();

	list.promoteToTop(2);
	std::cout << "Third item promoted to top: " << std::endl;
	list.printList();

	list.demoteToBottom(1);
	std::cout << "Second item demoted to bottom: " << std::endl;
	list.printList();

	list.removeItem(3);
	std::cout << "Fourth item removed: " << std::endl;
	list.printList();

	list.moveTo(0, 3);
	std::cout << "First item moved to fourth position: " << std::endl;
	list.printList();

	list.moveTo(1, 2);
	std::cout << "Second item moved to third position: " << std::endl;
	list.printList();

	list.moveTo(4, 4);
	std::cout << "Last item moved to last position: " << std::endl;
	list.printList();

	list.moveTo(3, 1);
	std::cout << "Fourth item moved to second position: " << std::endl;
	list.printList();
}