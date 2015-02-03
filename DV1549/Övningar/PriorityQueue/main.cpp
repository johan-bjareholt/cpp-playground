#include <iostream>

#include "PriorityQueue.h"

int main(){
	PriorityQueue<int> pq;
	std::cout << pq.size() << std::endl;
	pq.enqueue(1);
	pq.present();
	pq.enqueue(5);
	pq.present();
	pq.enqueue(9);
	pq.present();
	std::cout << pq.size() << " - " << pq.peek() << std::endl;

	pq.enqueue(7);
	pq.present();
	pq.enqueue(3);
	pq.present();
	pq.enqueue(0);
	pq.enqueue(10);
	pq.present();
	std::cout << pq.size() << " - " << pq.peek() << std::endl;

	pq.dequeue();
	pq.present();
	pq.dequeue();
	pq.present();
	std::cout << pq.size() << " - " << pq.peek() << std::endl;

	return 0;
}