//CIS600/CSE691  HW1
//Due: 11:59PM, Friday(1/31)

/*
Implement the two member functions: merge_sort and merge, as defined below for a sequential merge sort.
Note that the merge will be called by merge_sort.

In implementing both functions, you are only allowed to modify "next" and "previous" of nodes, but not "values" of nodes. 
You are not allowed to use any external structures such as array, linked list, etc.
You are not allowed to create any new node.
You are not allowed to create any new function.


After completing the above sequential version,  create a parallel version, by using two additional threads to speed up the merge sort.
You have to use the two functions you have implemented above.  You are not allowed to create new functions. Extra work will be needed in main function.

In your threaded implementation, you are allowed to introduce an extra node and a global pointer to the node.

It is alright if your implementation does not require the extra node or global pointer to node.

*/

#include <iostream>
using namespace std;


class node {
public:
	int value;
	node * next;
	node * previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class doubly_linked_list {
    public:
        int num_nodes;
        node * head;
        node * tail;
        doubly_linked_list() { num_nodes = 0; head = tail = nullptr; }
        void make_random_list(int m, int n);
        void print_forward();
        void print_backward();


	//Recursively merge sort i numbers starting at node pointed by p
	void merge_sort(node * p, int i);//in-place recursive merge sort

	//Merge i1 numbers starting at node pointed by p1 with i2 numbers starting at node pointed by p2
	void merge(node * p1, int i1, node * p2, int i2);

};

void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node * p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail = p1;
		if (head == nullptr) head = p1;
		num_nodes++;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	node * p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
	cout << endl;
}

void doubly_linked_list::print_backward() {
	cout << endl;
	node * p1 = tail;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
	cout << endl;
}

void doubly_linked_list::merge_sort(node *p, int i) {
    if (p == nullptr || i <= 1) return;

    node * slow = p, * fast = p;
    int slowCount = 0, fastCount = 0;

    while (slowCount < i - 1 && fastCount <= i && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        slowCount++;

        fast = fast->next->next;
        fastCount += 2;
    }

    auto getDistance = [&](node * from, node * dest, bool prevDirection) {
        int count(0);
        while (from != dest) {
            if (prevDirection) { from = from->previous; }
            else { from = from->next; }
            count++;
        }
        return count;
    };

    int origin_distance_p_to_head = getDistance(p, head, true);
    int origin_distance_slow_to_tail = getDistance(slow, tail, false);

    cout << "slow = " << slow->value << ", slowCount = " << slowCount << endl;
    merge_sort(p, slowCount);
    merge_sort(slow, fastCount - slowCount);

    while(head->previous != nullptr && head->previous->value < head->value) { head = head->previous; p = p->previous; }
    while(tail->next != nullptr && tail->next->value > tail->value) { tail = tail->next; slow = slow->next; }

    int new_distance_p_to_head = getDistance(p, head, true);
    while (new_distance_p_to_head != origin_distance_p_to_head) {
        if (new_distance_p_to_head > origin_distance_p_to_head) { p = p->previous; new_distance_p_to_head--;}
        else { p = p->next; new_distance_p_to_head++; }
    }

    int new_distance_slow_to_tail = getDistance(slow, tail, false);
    while (new_distance_slow_to_tail != origin_distance_slow_to_tail) {
        if (new_distance_slow_to_tail > origin_distance_slow_to_tail) { slow = slow->next; new_distance_slow_to_tail--; }
        else { slow = slow->previous; new_distance_slow_to_tail++; }
    }


    cout << "Before Merge: p = " << p->value << ", slow = " << slow->value << endl;
    merge(p, slowCount, slow, fastCount - slowCount);
    cout << "After Merge: p = " << p->value << ", slow = " << slow->value << endl;

    while(head->previous != nullptr && head->previous->value < head->value) { head = head->previous; p = p->previous; }
    while(tail->next != nullptr && tail->next->value > tail->value) { tail = tail->next; slow = slow->next; }
}

void doubly_linked_list::merge(node *p1, int i1, node *p2, int i2) {
    if (i1 <= 0 || i2 <= 0) return;
    if (p1 == nullptr || p2 == nullptr) return;
    if (p1->next == p2 && p1->value <= p2->value) return;

    print_forward();
    cout << "merging " << p1->value << ": " << i1 << " " << p2->value << ": " << i2 << endl;

    while ( (p1 != nullptr && i1 > 0) && (p2 != nullptr && i2 > 0) ) {
        if (p1->value > p2->value) {
            i2--;
            node * p2next = p2->next;
            p2->previous->next = p2->next;
            if (p2->next != nullptr) { p2->next->previous = p2->previous; } // p1 -> ... -> p2 -> NULL


            if (p1->previous == nullptr) {  // NULL -> p1 -> ...
                p2->previous = nullptr;
                p2->next = p1;
                p1->previous = p2;
            }
            else {                          // ... -> p1 -> ...
                p2->previous = p1->previous;
                p1->previous->next = p2;
                p2->next = p1;
                p1->previous = p2;
            }

            p2 = p2next;
        }
        else {
            i1--;
            p1 = p1->next;
        }
    }

    print_forward();
}


int main() {
	/*
	Implement the merge_sort and merge_functions defined above to complete a sequential version of 
	merge sort.

    srand(unsigned(time(NULL)));
	doubly_linked_list d1, d2;
	d1.make_random_list(3, 30);
	d1.print_forward();
//	d1.print_backward();

	d1.merge_sort(d1.head, d1.num_nodes);
	d1.print_forward();
//	d1.print_backward();


//	d2.make_random_list(50, 40);
//	d2.print_forward();
//	d2.print_backward();
//
//
//	Create two additional threads to speed up the merge sort.
//	You have to still use the same merge_sort and merge functions implemented above.
//	You will need to do some extra work within main funciton.
//	*/
//	d2.print_forward();
//	d2.print_backward();
//	return 0;

}