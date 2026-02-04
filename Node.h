#include <iostream>
#include <cmath>
using namespace std;

class Node
{
    int data, weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int key)
    {
        data = key;
        weight = 1;
        lchild = nullptr;
        rchild = nullptr;
    }

    bool searchI(int k)
    {
        Node *father = this;
        Node *current = this;
        bool check = true;
        do{
            if(current==NULL){
                cout << "Node not found" << endl;
                return false;
                check = false;
            }
            if(current->data==k){
                cout << "Node found" << endl;
                return true;
                check = false;
            }
            if(k<current->data){
                father = current;
                current = current->lchild;
                check = true;
            } else {
                father = current;
                current = current->rchild;
                check = true;
            }
        }while(check);
        return true;
    }

    bool searchR(int num)
    {
        if(this->data==num){
            cout << "Node found" << endl;
            return true;
        }
        if(num<this->data){
            if(this->lchild == nullptr){
                cout << "Node not found" << endl;
                return false;
            }
            return this->lchild->searchR(num);
        } else {
            if(this->rchild == nullptr){
                cout << "Node not found" << endl;
                return false;
            }
            return this->rchild->searchR(num);
        }
    }

    Node* insertI(int num)
    {
        Node *current = this;
        Node *father = this;
        bool check = true;
        do{
            if(current==NULL)
            {
                if(num<father->data)
                {
                    father->lchild = new Node(num);
                    return this;
                    check = false;
                } else {
                    father->rchild = new Node(num);
                    return this;
                    check = false;
                }
            }
            if(current->data==num)
            {
                current->weight++;
                return current;
                check = false;
            }
            if(num<current->data)
            {
                father = current;
                current = current->lchild;
            } else {
                father = current;
                current = current->rchild;
            }
        }while(check);
        return this;
    }

    Node* insertR(int num)
    {
        if(this->data == num)
        {
            this->weight++;
            return this;
        }
        if(num < this->data)
        {
            if(this->lchild == nullptr){
                this->lchild = new Node(num);
            }else{
                this->lchild->insertR(num);
            }
        }else{
            if(this->rchild == nullptr){
                this->rchild = new Node(num);
            }else{
                this->rchild->insertR(num);
            }
        }
        return this;
    }

    void inOrder()
    {
        if(this->lchild != nullptr) this->lchild->inOrder();
        cout << this->data << " ";
        if(this->rchild != nullptr) this->rchild->inOrder();
    }

    void preOrder()
    {
        cout << this->data << " ";
        if(this->lchild != nullptr) this->lchild->preOrder();
        if(this->rchild != nullptr) this->rchild->preOrder();
    }

    void postOrder()
    {
        if(this->lchild != nullptr) this->lchild->postOrder();
        if(this->rchild != nullptr) this->rchild->postOrder();
        cout << this->data << " ";
    }
    
    void kthSmallestUtil(int& k, int& result, int& count)
    {
        if(this->lchild!=nullptr){
            this->lchild->kthSmallestUtil(k, result, count);
        }
        count++;
        if (count==k){
            result=this->data;
        }
        if(this->rchild!=nullptr){
            this->rchild->kthSmallestUtil(k, result, count);
        }
    }

    int kthSmallest(int k)
    {
        int result = -1;
        int count = 0;
        this->kthSmallestUtil(k, result, count);
        return result;
    }
	
	int findDepth(int k)
	{
		Node* current = this;
		int count = 0;
		while (current!=NULL) {
			if (k > current->data) {
				current = current->rchild;
			}else if (k < current->data){
				current = current->lchild;
			}else if (k == current->data){
				return count;
			}
			count++;
		}
		return -1;
	}
};
