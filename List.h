#pragma once

#include <iostream>

template<typename T>
struct ListNode{
    T data;
    ListNode* next = nullptr;

    ListNode(){}
    ListNode(T data) : data(data) {}
    ListNode(T data, ListNode* next) : data(data), next(next) {}
};

template <typename T>
class List{
private:
    ListNode<T>* m_Head;
    size_t m_Size;
public:
    List(){
        m_Head = nullptr;
        m_Size = 0;
    }
    List(T data[]){}

    //add an element to the begining of the list
    void Add(const T& data){
        ListNode<T>* node = new ListNode<T>(data, m_Head);
        m_Head = node;
        m_Size++;
    }

    //insert an element to a specific index
    //zero-based indexing
    void Insert(const T& data, const size_t& index){
        if(index > m_Size || index < 0){
            std::cout << "Out of bounds exception!\n";
            return;
        }
        ListNode<T>* node = new ListNode<T>(data);
        m_Size++;
        if(index == 0){
            node->next = m_Head;
            m_Head = node;
            return;
        }

        ListNode<T>* prev = m_Head;

        for(int i = 0; i < index - 1; i++){
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }

    void PopFront(){
        if(m_Size > 0){
            ListNode<T>* _to_be_deleted = m_Head;
            m_Head = m_Head->next;
            m_Size--;
            std::cout << "First element removed!\n";

            delete _to_be_deleted;
        }
    }

    //remove a node by element
    void Remove(const T& element){
        ListNode<T>* current = m_Head;
        ListNode<T>* prev = m_Head;

        while(current != nullptr){
            if(current->data == element){
                if(current == m_Head){
                    m_Head = m_Head->next;
                }
                else{
                    prev->next = current->next;
                }
                delete current;
                m_Size--;
                std::cout << "Element Removed!\n";
                return;
            }
            prev = current;
            current = current->next;
        }
        std::cout << "Element Not Found!\n";
    }

    //print all the elements in the list
    void Print() const {
        ListNode<T>* temp = m_Head;

        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";

    }

    //return the number of elements there are in the list
    size_t Size() const {
        return m_Size;
    }
    
    void Clear(){
        while(m_Head != nullptr){
            ListNode<T>* temp = m_Head->next;
            delete m_Head;
            m_Head = temp;
        }
        m_Size = 0;
        std::cout << "List Cleared!\n";
    }
};
