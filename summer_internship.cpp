// summer_internship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RBtree.cpp" // C:\Users\Adil\source\repos\summer_internship\RBtree.cpp
#include <vector>
#include "Graph.cpp"
#include <map>

using namespace std;

int RBtreeMain()
{
    std::cout << "2020212035 - SummerInternship";
	RBTree bst;
	bst.add(8);
	bst.add(18);
	bst.add(5);
	bst.add(15);
	bst.add(17);
	bst.add(25);
	bst.add(40);
	bst.add(80);
	bst.inOrder(bst.getRoot());
	bst.remove(25);
	cout << endl;
	bst.inOrder(bst.getRoot());
	cout << endl;
	bst.preOrder(bst.getRoot());
	cout << endl;
	bst.postOrder(bst.getRoot());
	cout << endl;

	auto v = bst.search(155);
	if (v!=NULL)
	{
		
		cout << v->data;
	}
	else
	{
		cout << "NOT FOUND\n";
	}
	
	auto x = bst.search(107);
	if (x!=NULL)
	{
		cout << x->data;
	}
	else
	{
		
		cout << "NOT FOUND\n";
	}
	return 0;
}

int main()
{
	//RBtreeMain();
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 0);
	g.print();
	cout << "\n\n\n------------------\n";
	Graph<string> ga;
	ga.addEdge("A", "B");
	ga.addEdge("A", "D");
	ga.addEdge("A", "E");
	ga.addEdge("B", "A");
	ga.addEdge("B", "C");
	ga.addEdge("D", "C");
	ga.addEdge("B", "F");
	ga.addEdge("D", "A");
	ga.print();
	
	
	ga.DFS("A");
	ga.DFS("C");
	return 0;
}