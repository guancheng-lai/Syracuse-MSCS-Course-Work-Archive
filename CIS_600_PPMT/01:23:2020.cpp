#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
#include <functional>
using namespace std;

template <typename T>
bool myComp1(T a, T b) {return a < b;}

struct myComp2 {
	template<typename T>
	bool operator()(const T &a, const T &b) {return a < b;}	
} cp2;

template<typename T>
T product(const T &a, const T &b) {
	cout << a << " " << b << endl;
	return a * b;
}

template<typename T, typename F>
T foo(const T &a, const T &b, function<F(T, T)> myFunc) {
//	return F(a, b) ? a : b;
	cout << a << " " << b << endl;
	T result = myFunc(a, b);
	cout << "result = " << result << endl;
	return result;
}

int main(int argc, char *argv[]) {
	list<int> l1 {4,7,2,5,1};
	l1.sort(myComp1<int>);
	for (auto i : l1) cout << i << " ";
	cout << endl;
	
	vector<int> l2 {4,7,2,5,1};
	std::sort(l2.begin(), l2.end(), myComp1<int>);
//	l2.sort(myComp1<int>);
//	l2.sort(myComp2());
	for (auto i : l2) cout << i << " ";
	cout << endl;
	
//	cout << foo<int>(200, 100, myComp1<int>);
	cout << foo<int, int>(10, 10, product<int>);
}