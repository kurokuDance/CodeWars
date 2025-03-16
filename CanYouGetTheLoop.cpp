#include <iostream>
#include <set>


struct Node {
    Node* next;
    Node() : next(nullptr) {};
    void setNext(Node *nextNode)
    {
        next = nextNode;
    }

    Node* getNext() { return next; }
     

};

int getLoopSize(Node* startNode)
{
    std::set<Node*> visitedNodes;
    Node* currentNode = startNode;

    while (currentNode != nullptr)
    {
        if (visitedNodes.find(currentNode) != visitedNodes.end())
        {
            Node* startNode = currentNode;
            int length = 1;
            currentNode = currentNode->getNext();
            while (currentNode != startNode)
            {
                length++;
                currentNode = currentNode->getNext();
            }
            return length;
        }
        visitedNodes.insert(currentNode);
        currentNode = currentNode->getNext();
    }

    return -1;
}

int main()
{
    Node n1, n2, n3, n4;

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n4);

    std::cout << getLoopSize(&n1);
}

