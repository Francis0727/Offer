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
Node<T>* FindKthToTail(Node<T>* pHead,unsigned int k){
    Node<T>* pListHead = pHead;
    Node<T>* pListBehind = pHead;
    if (pListHead == NULL || k == 0){
        return NULL;
    }
    
    for (int cnt = 0; cnt < k - 1; ++cnt){
        pListHead = pListHead->next;
        if (pListHead == NULL){
            return NULL;
        }
    }
    
    while (pListHead->next != NULL){
        pListHead = pListHead->next;
        pListBehind = pListBehind->next;
    }
    return pListBehind;
}

int main(){
    Node<int>* pHead = CreateLists({1,2,3,4,5});
    print(pHead);
    Node<int>* node = FindKthToTail(pHead,5);
    std::cout << "data: " << node->data << std::endl; 

    return 0;
}