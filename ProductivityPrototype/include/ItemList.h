#include "Item.h"

#ifndef ITEM_LIST
#define ITEM_LIST

class ItemList {
private:
	struct ListNode {
		ListNode(Item* item) :
			myItem(item),
			prevItem(nullptr),
			nextItem(nullptr) {}
		~ListNode() {
			delete myItem;
		}
		Item* myItem;
		ListNode* prevItem;
		ListNode* nextItem;
	};

	ListNode* first;
	ListNode* last;

	ListNode* itemAtPos(size_t) const;
	
	size_t size;

	void setPriorities();
public:
	ItemList();
	ItemList(const ItemList& rhs) = delete;
	ItemList& operator=(const ItemList& rhs) = delete;

	size_t getSize() { return size; }
	bool isEmpty() const { return first == nullptr; }
	void addItem(Item*);
	void removeItem(size_t pos);
	void promoteToTop(size_t pos);
	void demoteToBottom(size_t pos);
	void moveTo(size_t oldPos, size_t newPos);
	void printList();
};

#endif // !ITEM_LIST

