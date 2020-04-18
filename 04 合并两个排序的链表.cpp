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
Node<T>* Merge(Node<T>* pHead1,Node<T>* pHead2){
    if (pHead1 == NULL){
        return pHead2;
    }
    
    if (pHead2 == NULL){
        return pHead1;
    }
    
    Node<T>* mergeHead = NULL;

    if (pHead1->data < pHead2->data){
        mergeHead = pHead1;
        mergeHead->next = Merge(pHead1->next,pHead2);
    }
    else {
        mergeHead = pHead2;
        mergeHead->next = Merge(pHead1,pHead2->next);
    }

    return mergeHead;
}

int main(){
    Node<int>* list1 = CreateLists({1,3,5,7,9});
    Node<int>* list2 = CreateLists({2,4,6,8,10,12});
    Node<int>* mergeList = Merge(list1,list2);
    print(mergeList);

    return 0;
}