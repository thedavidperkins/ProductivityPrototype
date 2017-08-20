#include<string>

#ifndef ITEM
#define ITEM

typedef uint16_t uint;

class ItemList;

class Item {
private:
	std::string m_name;
	size_t m_priority;
	ItemList* myList;

	Item();
	ItemList* getList() const { return myList; }
public:
	Item(std::string name);
	Item(const Item& rhs);
	Item& operator=(const Item& rhs);

	void setName(std::string n) { m_name = n; }
	std::string getName() const { return m_name; }
	void setPriority(uint p) { m_priority = p; }
	void setList(ItemList* p) { myList = p; }
	uint getPriority() const { return m_priority; }
	void print();
};

#endif // !ITEM
