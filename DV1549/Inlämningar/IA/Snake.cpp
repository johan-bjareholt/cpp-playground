#include "Snake.h"

#include <algorithm>

// Inner class (Snake::Node)

Snake::Node::Node(int x, int y, Direction direction)
{
	this->entity = new SnakeHead(x, y, direction);
	this->prev = this->next = NULL;
}

Snake::Node::Node(int x, int y, Node* prev, Node* next)
{
	this->entity = new SnakeEntity(x, y);
	this->prev = prev;
	this->next = next;
}

Snake::Node::~Node()
{
	delete this->entity;
}

// Snake class

Snake::Snake(int headX, int headY, Direction direction, int length)
{
	this->head = new Node(headX, headY, direction);
	this->length = max(length, 2);
	
	Node* walker = this->head;
	int deltaX = -DELTA_X_FOR_DIR[direction];
	int deltaY = -DELTA_Y_FOR_DIR[direction];
	for (int i = 1; i < this->length; i++)
	{
		int nextX = walker->entity->getX() + deltaX;
		int nextY = walker->entity->getY() + deltaY;
		walker->next = new Node(nextX, nextY, walker);
		walker = walker->next;
	}
	this->tail = walker;
}

Snake::~Snake()
{
	// Must free up dynamically allocated memory for every single node.
	Node* walker = head;
	for (int i = 0; i < length; i++){
		Node* toDelete = walker;
		walker = walker->next;
		delete toDelete;
	}
}

SnakeHead Snake::getHead() const
{
	// Returns a copy of the SnakeHead object contained in the head node.
	// Don't be afraid to use typecasting and the dereference operator!
	// Also, note that this function returns a COPY of the head. 
	// In other words, don't rely on this function if you intend to make changes to the
	// original SnakeHead object.
	return *dynamic_cast<SnakeHead*>(this->head->entity);
}

vector<SnakeEntity> Snake::getBody() const
{
	// Creates and returns a vector that contains all of the snake's body segments (not the head).
	vector<SnakeEntity> body;
	Node* walker = head->next;
	for (int i = 1; i < this->length; i++){
		body.push_back(*walker->entity);
		walker = walker->next;
	}
	return body;
}

SnakeEntity Snake::getTail() const
{
	// Returns the SnakeEntity object from the last node (the "tail").
	return *this->tail->entity;
}

int Snake::getLength() const
{
	// Returns the current length of the snake.
	return this->length;
}

void Snake::setDirection(Direction direction)
{
	// Changes the direction of the snake's head.
	SnakeHead* head = dynamic_cast<SnakeHead*>(this->head->entity);
	head->setDirection(direction);
}

void Snake::moveHead()
{
	// Moves the snake's head. Nothing else should be done in this function.
	SnakeHead* head = dynamic_cast<SnakeHead*>(this->head->entity);
	head->move();
}

void Snake::insertNodeAfterHead()
{
	// Creates a new SnakeEntity node and inserts it immediately after the first node (head).
	// This new SnakeEntity should have the same X and Y position as the head node.
	// Make sure that every pointer is updated accordingly.
	// Also, since you're adding a new node, do not forget to change the value of "length".

	int x = head->entity->getX();
	int y = head->entity->getY();
	Node* newBodyPart = new Node(x, y, head, head->next);
	head->next->prev = newBodyPart;
	head->next = newBodyPart;
	length++;
}

void Snake::removeTail()
{
	// Frees up the dynamically allocated memory for the last node and removes it.
	// Don't forget to update your "tail" pointer and, since you're removing a node,
	// to change the value of "length".
	
	tail = tail->prev;
	delete tail->next;
	length--;
}

bool Snake::collidedWithSelf() const
{
	// This function returns true if the head has collided with any of the other body
	// segments, false otherwise. Don't forget that there is a handy function called
	// "collidedWith" in the SnakeEntity class!
	bool collision = false;
	Node* walker = head;
	for (int i = 1; i < this->length; i++){
		walker = walker->next;
		if (walker->entity->collidedWith(*head->entity))
			collision = true;
	}
	return collision;
}