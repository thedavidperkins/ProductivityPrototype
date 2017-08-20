/*
*	Basic to-do item
*/

#include "Item.h"
#include<iostream>

Item::Item(std::string name) :
	m_name(name),
	m_priority(0) {}

Item::Item(const Item& rhs) :
	m_name(rhs.getName()),
	m_priority(0) {}

Item& Item::operator=(const Item& rhs) {
	Item temp(rhs);
	m_name = rhs.getName();
	m_priority = rhs.getPriority();
	return *this;
}

void Item::print() {
	std::cout << "Task: " << m_name << ", Priority: " << m_priority << std::endl;
}
