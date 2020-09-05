#include <cstddef>
#include <cstdint>

namespace dsalib
{
    template <typename T> class LinkedList;
    template <typename T>
    class LinkedListNode{
        T data;
        LinkedListNode<T> *next, *prev;
        public:
        friend class LinkedList<T>;
        LinkedListNode()                   {        next=NULL; prev=NULL;}
        LinkedListNode(T d)                {data=d; next=NULL; prev=NULL;}
        void operator = (T d)              {data=d;}
        void operator = (LinkedListNode<T> l) {data=l.data;}
    };

    template <typename T>
    class LinkedList{
        LinkedListNode<T> *head, *tail;
        uint64_t size;
        public:
        class Iterator{
            LinkedListNode<T> *ptr;
            public:
            friend class LinkedList<T>;
            Iterator(){
                ptr = NULL;
            }
            Iterator(LinkedListNode<T> *t){
                ptr = t;
            }
            Iterator(const Iterator& i){
                ptr = i.ptr;
            }
            void operator =(const Iterator& i){
                ptr = i.ptr;
            }
            T operator *(){
                return ptr->data;
            }
            Iterator operator ++(){
                ptr = ptr->next;
                Iterator temp(*this);
                return temp;
            }
            Iterator operator ++(T){
                ptr = ptr->next;
                Iterator temp(*this);
                return temp;
            }
            Iterator operator --(){
                ptr = ptr->prev;
                Iterator temp(*this);
                return temp;
            }
            Iterator operator --(T){
                ptr = ptr->prev;
                Iterator temp(*this);
                return temp;
            }
            bool operator ==(Iterator i){
                return ptr==i.ptr;
            }
            bool operator !=(Iterator i){
                return ptr!=i.ptr;
            }
            bool operator ==(void *p){
                return ptr==p;
            }
            bool operator !=(void *p){
                return ptr!=p;
            }
        };
        LinkedList(){head=NULL; tail=NULL; size=0;}
        uint64_t get_size(){
            return size;
        }
        Iterator first(){
            Iterator i;
            i.ptr = head;
            return i;
        }
        Iterator last(){
            Iterator i;
            i.ptr = tail;
            return i;
        }
        Iterator get_iterator(uint64_t index){
            Iterator i;
            LinkedListNode<T> *p=head;
            for(uint64_t i=0; i<index; ++i){
                if(p)
                    p=p->next;
                else
                    break;
            }
            i.ptr=p;
            return i;
        }
        void push_front(T n){
            LinkedListNode<T> *p = new LinkedListNode<T>(n);
            p->next = head; head? head->prev=p : NULL;
            tail ? NULL : tail=p;
            head = p;
            ++size;
        }
        void push_back(T n){
            LinkedListNode<T> *p = new LinkedListNode<T>(n);
            tail? tail->next=p,p->prev=tail : NULL;
            tail = p;
            head ? NULL : head=p;
            ++size;
        }
        void insert(T n, uint64_t pos){
            if(pos==0){
                push_front(n);
            }
            else if(pos==size){
                push_back(n);
            }
            else{
                LinkedListNode<T> *p = new LinkedListNode<T>(n), *q=head;
                for (uint64_t i=0; i<pos-1; ++i){
                    q=q->next;
                }
                p->next = q->next;   p->prev=q;
                p->next->prev = p;   q->next=p;
                ++size;
            }
        }
        void insert(T n, Iterator i){
            if(i==first()){
                push_front(n);
            }
            else if(i==Iterator()){
                push_back(n);
            }
            else{
                LinkedListNode<T> *p = new LinkedListNode<T>(n);
                Iterator q(head);
                while(q!=i){
                    q++;
                }
                p->next = q->next;
            }
        }
        /*void insert(Iterator first, Iterator last, Iterator pos){
            ;
        }*/

    };
}