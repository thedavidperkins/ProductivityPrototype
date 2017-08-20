/*
*	Simple linked list
*/

#include "ItemList.h"
#include<iostream>

ItemList::ItemList() : 
	first(nullptr),
	last(nullptr),
	size(0) {}

ItemList::ListNode* ItemList::itemAtPos(size_t pos) const {
	if (pos >= size || pos < 0) {
		throw std::runtime_error("Attempted to access out-of-bounds element");
	}
	ListNode* l = first;
	for (size_t i = 0; i < pos; ++i) {
		l = l->nextItem;
	}
	return l;
}

void ItemList::setPriorities() {
	ListNode* l = first;
	for (size_t i = 1; i <= size; ++i) {
		l->myItem->setPriority(i);
		l = l->nextItem;
	}
}

void ItemList::addItem(Item* item) {
	item->setList(this);
	ListNode* l = new ListNode(item);
	if (isEmpty()) {
		first = l;
		last = l;
		l->prevItem = nullptr;
		l->nextItem = nullptr;
	}
	else {
		last->nextItem = l;
		l->prevItem = last;
		last = l;
	}
	++size;
	setPriorities();
}

void ItemList::removeItem(size_t pos) {
	if (pos >= size || pos < 0) {
		throw std::runtime_error("Attempted to access out-of-bounds element");
	}
	ListNode* l = itemAtPos(pos);
	if (size == 1) {
		delete l;
		first = nullptr;
		last = nullptr;
	}
	else if (first == l) {
		first = l->nextItem;
		delete l;
	}
	else if (last == l) {
		last = l->prevItem;
		delete l;
	}
	else {
		ListNode* temp = l->nextItem;
		l->nextItem->prevItem = l->prevItem;
		l->prevItem->nextItem = temp;
		delete l;
	}
	size--;
	setPriorities();
}

void ItemList::promoteToTop(size_t pos)
{
	moveTo(pos, 0);
}

void ItemList::demoteToBottom(size_t pos)
{
	moveTo(pos, size - 1);
}

void ItemList::moveTo(size_t oldPos, size_t newPos) {
	if (newPos >= size || newPos < 0) {
		throw std::runtime_error("Attempted to access out-of-bounds element");
	}
	if (oldPos == newPos) {
		return;
	}
	ListNode* old = itemAtPos(oldPos);
	ListNode* newAbove = oldPos > newPos ? itemAtPos(newPos)->prevItem : itemAtPos(newPos);
	ListNode* newBelow = oldPos > newPos ? itemAtPos(newPos) : itemAtPos(newPos)->nextItem;
	ListNode* oldAbove = old->prevItem;
	ListNode* oldBelow = old->nextItem;
	if (oldAbove != nullptr) {
		oldAbove->nextItem = oldBelow;
	}
	else {
		first = oldBelow;
	}
	if (oldBelow != nullptr) {
		oldBelow->prevItem = oldAbove;
	}
	else {
		last = oldAbove;
	}
	old->nextItem = newBelow;
	old->prevItem = newAbove;
	if (newBelow != nullptr) {
		newBelow->prevItem = old;
	}
	else {
		last = old;
	}
	if (newAbove != nullptr) {
		newAbove->nextItem = old;
	}
	else {
		first = old;
	}
	setPriorities();
}

void ItemList::printList() {
	std::cout << "======================================" << std::endl;
	ListNode* l = first;
	for (size_t i = 0; i < size; i++) {
		l->myItem->print();
		l = l->nextItem;
	}
	std::cout << "======================================" << std::endl;
}