#include <iostream>
#include <initializer_list>
#include <iterator>
#include <list>

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
auto CreateLists(std::initializer_list<T> list1)->Node<T>*{
    Node<T>* listHead = NULL;
    Node<T>* curNode = NULL ;
    Node<T>* newNode = NULL;
    for (auto ite = std::rbegin(list1);ite != std::rend(list1);++ite){
        // 构造出来的新的Node节点
        newNode = new Node<T>{*ite,NULL};
        newNode->next = curNode;
        curNode = newNode;
    }
    listHead = curNode;
    return listHead;
}

template<typename T>
void print(Node<T>* pHead){
    struct Node<T>* node = pHead;
    while (node){
        std::cout << node->data << " ";
        node = node->next;
    }std::cout << std::endl;
}

template<typename T>
auto ReverseList(Node<T>* pHead)->Node<T>*{
    Node<T>* prev = NULL;
    Node<T>* pNode = pHead;
    Node<T>* pNext = NULL;
    while (pNode != NULL){
        pNext = pNode->next;
        pNode->next = prev;
        
        if (pNext == NULL){
            break;
        }
        
        prev = pNode;
        pNode = pNext;
    }
    
    return pNode;
}

int main(){
    Node<int>* pHead = CreateLists({1,2,3,4,5});
    print(pHead);
    Node<int>* reverseHead = ReverseList<int>(pHead);
    print(reverseHead);

    return 0;
}