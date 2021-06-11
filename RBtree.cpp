// RBNode 
#include<iostream>
using namespace std;
struct RBNode {
	int data;
	RBNode* parent;
	RBNode* left;
	RBNode* right;
	int color; // 1 -> Red, 0 -> Black
};



class RBTree {

	RBNode* root;
	RBNode* TNULL;

public:
	//constructor
	RBTree() {
		TNULL = new RBNode;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}


	// insert the key to the tree in its appropriate position
	// and fix the tree
	void add(int key) {
		// Ordinary Binary Search Insertion
		RBNode* node = new RBNode;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1; // new node must be red

		RBNode* y = nullptr;
		RBNode* x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}

		// y is parent of x

		node->parent = y;
		if (y == nullptr) {
			root = node;
		}

		else if (node->data < y->data) {
			y->left = node;
		}

		else {
			y->right = node;
		}


		if (node->parent == nullptr) {
			node->color = 0;
			return;
		}


		if (node->parent->parent == nullptr) {
			return;
		}


		fixInsert(node);
	}
	// fix the red-black tree
	void fixInsert(RBNode* k) {
		RBNode* u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) /* iS LEFT UNCLE OR NOT*/
			{
				u = k->parent->parent->left; // uncle
				if (u->color == 1) {
					// case 3.1
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {

						k = k->parent;
						rightRotate(k);
					}

					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right; // uncle

				if (u->color == 1) {

					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {

						k = k->parent;
						leftRotate(k);
					}

					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}
	// rotate left at node x
	void leftRotate(RBNode* x) {
		RBNode* y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		}
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	RBNode* search(int key) {
		RBNode* node = getRoot();
		int found = 0;
		while (node != NULL && found == 0)
		{
			if (key == node->data) {
				found = 1;
				return node;
			}
			if (found == 0)
			{
				if (key < node->data) {
					node = node->left;
				}
				else
				{
					node = node->right;
				}
			}

		}
		return NULL;
	}

	// rotate right at node x
	void rightRotate(RBNode* x) {
		RBNode* y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		}
		else if (x == x->parent->right) {
			x->parent->right = y;
		}
		else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}
	/*Three traversals */
	void preOrder(RBNode* node) {
		if (node != TNULL) {
			cout << node->data << " ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void inOrder(RBNode* node) {
		if (node != TNULL) {
			inOrder(node->left);
			cout << node->data << " ";
			inOrder(node->right);
		}
	}

	void postOrder(RBNode* node) {
		if (node != TNULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << " ";
		}
	}

	RBNode* getRoot() {
		return this->root;
	}

	void remove(int key) {
		// find the node containing key
		RBNode* node = getRoot();
		RBNode* z = TNULL;
		RBNode* x, * y;
		while (node != TNULL) {
			if (node->data == key) {
				z = node;
			}

			if (node->data <= key) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}

		if (z == TNULL) {
			cout << "Couldn't find key in the tree" << endl;
			return;
		}
		RBNode* temp = z;
		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL) {
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL) {
			x = z->left;
			rbTransplant(z, z->left);
		}
		else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			}
			else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0) {
			fixDelete(x);
		}
	}
	void rbTransplant(RBNode* u, RBNode* v) {
		if (u->parent == nullptr) {
			root = v;
		}
		else if (u == u->parent->left) {
			u->parent->left = v;
		}
		else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}
	void fixDelete(RBNode* x) {
		RBNode* s;
		while (x != root && x->color == 0) {
			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {
					// case 3.1
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0) {
					// case 3.2
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->right->color == 0) {
						// case 3.3
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					// case 3.4
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else {
				s = x->parent->left;
				if (s->color == 1) {
					// case 3.1
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) {
					// case 3.2
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->left->color == 0) {
						// case 3.3
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					// case 3.4
					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}
	// find the node with the minimum key
	RBNode* minimum(RBNode* node) {
		while (node->left != TNULL) {
			node = node->left;
		}
		return node;
	}
};