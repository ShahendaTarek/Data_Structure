#include <iostream>
using namespace std;
////////////////////////Vector//////////////////////////////////
template<typename T> class Vector
{
    T* arr;
    int maxSize;
    int index;
public:
    Vector(int sz = 1)
    {
        if (sz < 0)
        {
            cout << "Size must be greater than 0" << endl;
        }
        maxSize = sz;
        index = 0;
        arr = new T[maxSize];
    }
    bool isempty()///O(1)
    {
        return index == 0;
    }
    bool isfull()///O(1)
    {
        return index == maxSize;
    }
    int size()///O(1)
    {
        return index;
    }
    void display()///O(n)
    {
        for (int i = 0;i < index;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insert(T element)
    {
        if (index == maxSize)///O(n)
        {
            T* tmp;
            tmp = new T[maxSize * 2];
            for (int i = 0;i < index;i++)
            {
                tmp[i] = arr[i];
            }
            delete[]arr;
            maxSize *= 2;
            arr = tmp;
        }

        arr[index] = element;
        index++;

    }
    void updateValue(int pos, T element)
    {
        if (pos<0 || pos >index)
        {
            cout << "Out of range" << endl;
        }
        else
        {
            arr[pos] = element;
        }
    }
    T returnvlaue(int pos)
    {
        if (pos<0 || pos>index)
        {
            return -1;
        }
        return arr[pos];
    }
    void insertpos(int pos, T element)///O(n)
    {
        if (isfull())
        {
            T* tmp;
            tmp = new T[maxSize * 2];
            for (int i = 0;i < index;i++)
            {
                tmp[i] = arr[i];
            }
            delete[]arr;
            maxSize *= 2;
            arr = tmp;
        }
        if (pos == index)
        {
            insert(element);
        }
        else if (pos < 0)
        {
            cout << "Error" << endl;
        }
        else
        {
            for (int i = pos + 1;i <= index;i++)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            index++;

        }
    }
    void erase()///o(1)
    {
        index--;
    }
    void erasepos(int pos)///O(n)
    {
        if (pos<0 || pos>index)
        {
            cout << "this position isn't found" << endl;
        }
        else
        {
            for (int i = pos;i < index - 1;i++)
            {
                arr[i] = arr[i + 1];
            }
            index--;
        }
    }
    int search(T element)
    {
        for (int i = 0;i < index;i++)
        {
            if (arr[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    ~Vector()
    {
        delete[] arr;
    }

};
/////////////////////////////stack with dynamic array////////////////////////////
template<typename T> class Stack{

    int top;
    enum{mx=100};
    T arr[];
public:
    Stack()
    {
        top=-1;
        arr[mx];
    }
    void push(T element)
    {
        if(top==mx-1)
        {
            cout<<"Stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=element;
    }
    void pop()
    {
        if(top<0)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        top--;
    }
    T Top()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            return -1;
        }

    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
//////////////////////linked list stack////////////////////////////////////////////////////
template<typename T> class LS_Stack{

    struct node
    {
        T item;
        node*next;
    };
    node* top;
public:
    LS_Stack()
    {
        top=NULL;
    }
    void push(T element)
    {
        node*newnode=new node();
        newnode->item=element;
        newnode->next=top;
        top=newnode;

    }
    bool isEmtpy()
    {
        return top==NULL;
    }
    void pop()
    {
        if(isEmtpy())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        node *cur=top;
        top=top->next;
        cur->next=NULL;
        delete cur;


    }
    T popvalue()
    {
        T element;
        if(isEmtpy())
        {
            cout<<"Stack is empty"<<endl;
            return-1;
        }
        else
        {
            node*cur=top;
            element=cur->item;
            top=top->next;
            cur->next=NULL;
            delete cur;
            return element;
        }
    }
    T Top()
    {
        if(!isEmtpy())
            return top->item;
        else
            cout<<"Stack is Emtpy"<<endl;
    }
    void display()
    {
        node*cur=top;
        while(cur!=NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->next;
        }
        cout<<endl;

    }



};
////////////////////////////Queue with dynamic array/////////////////////////
template<typename T>class Queue
{
    int back;
    int front;
    int length;
    int mx;
    T *arr;
public:
    Queue(int size)
    {
        mx=size;
        back=mx-1;
        front=0;
        length=0;
        arr=new T[mx];
    }
    bool isEmpty()
    {
        return length==0;
    }
    bool isFull()
    {
        return length==mx;
    }
    void push(T element)
    {
        if(isFull())
        {
            cout<<"queue is full"<<endl;
        }
        else
        {
            back=(back+1)%mx;
            length++;
            arr[back]=element;
            //  cout<<"back = "<<back<<" ";
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"queue is empty "<<endl;
        }
        else
        {
            front++;
            front=front%mx;
            length--;

        }
    }
    T Front()
    {
        if(!isEmpty())
            return arr[front];
    }
    T Back()
    {
        if(!isEmpty())
            return arr[back];
    }
    void display()
    {
        for(int i=front;i!=back;i=(i+1)%mx)
        {
            cout<<arr[i]<<" ";
        }
        cout<<arr[back]<<endl;
    }



};
//////////////////////linked list queue/////////////////////////
template<typename T> class queuelinkedlist
{
    struct node
    {
        T item;
        node*next;

    };
    node* front;
    node*back;
    int length;
public:
    queuelinkedlist()
    {
        front=back=NULL;
        length=0;

    }
    void push(T element)
    {
        node *newnode= new node;
        newnode->item=element;
        if(length==0)
        {
            front=back=newnode;
            newnode->next=NULL;
            length++;
        }
        else
        {
            back->next=newnode;
            newnode->next=NULL;
            back=newnode;
            length++;

        }

    }
    void pop()
    {
        if(length==0)
        {
            cout<<"Queue is empty"<<endl;
        }
        else if(length==1)
        {
            delete front;
            back=NULL;

        }
        else
        {
            node*cur=front;
            front=front->next;
            cur->next=NULL;
            delete cur;
        }
        length--;
    }
    bool isEmpty()
    {
        return length==0;
    }
    T Front()
    {
        if(!isEmpty())
            return front->item;
    }
    T Back()
    {
        if(!isEmpty())
            return back->item;
    }
    void clear()
    {
        node*cur;
        while(front!=NULL)
        {
            cur=front;
            front=front->next;
            delete cur;
        }
        length=0;
    }
    void display()
    {
        if(!isEmpty())
        {
            node*cur=front;
            while(cur!=NULL)
            {
                cout<<cur->item<<" ";
                cur=cur->next;
            }
            cout<<endl;
        }
        else
        {
            cout<<"Queue is Emtpy"<<endl;
        }

    }
    int size()
    {
        return length;
    }

};
//////////////////////Linked List/////////////////////
template<typename T>class LinkedList
{
    struct node{
        T item;
        node *next;

    };
    node *head;
    node *tail;
    int length;
public:
    LinkedList()
    {
        head=tail=NULL;
        length=0;
    }
    bool isEmpty()///O(1)
    {
        return length==0;
    }
    void insertfront(T value)///O(1)
    {
        node *newnode=new node();
        newnode->item=value;
        if(length==0)
        {
            head=newnode;
            tail=newnode;
            newnode->next=NULL;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
        length++;
    }
    void insertBack(T value)///O(1)
    {
        node *newnode=new node();
        newnode->item=value;
        if(length==0)
        {
            tail=newnode;
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            tail->next=newnode;
            newnode->next=NULL;
            tail=newnode;
        }
        length++;


    }
    void insertAtPos(int pos,T value)///O(N)
    {
        node*newnode=new node;
        newnode->item=value;
        if(pos>length)
        {
            tail->next=newnode;
            newnode->next=NULL;
            tail=newnode;
            length++;

        }
        else if(pos<0)
        {
            cout << "Error" << endl;
        }
        else if(pos==0)
        {
            insertfront(value);
        }
        else if(pos==length)
        {
            insertBack(value);
        }
        else
        {
            node*cur=head;
            for(int i=1;i<pos;i++)
            {
                cur=cur->next;
            }
            newnode->next=cur->next;
            cur->next=newnode;
            length++;
        }
    }
    void popFront() ///O(1)
    {
        node*cur=head;
        if (length == 0)
        {
            cout<<"linked list is empty"<<endl;
        }
        else if(length==1)
        {
            head=tail=NULL;
            delete cur;
            length--;
        }
        else
        {
            head=head->next;
            delete cur;
            length--;
        }
    }
    void popBack()///O(N)
    {
        if(length==0)
        {
            cout<<"Linked List is empty"<<endl;
        }
        else if(length==1)
        {
            head=tail=NULL;
            delete head;
            length--;
        }
        else
        {
            node*cur=head->next;
            node*prv=head;
            while(cur!=tail)
            {
                prv=cur;
                cur=cur->next;
            }
            delete cur;
            prv->next=NULL;
            tail=prv;
            length--;
        }
    }
    void eraseByitem(T element)///O(N)
    {
        if(length==0)
        {
            return;
        }
        else
        {
            node*cur;
            node*prv;
            if(head->item==element)
            {
                cur=head;
                head=head->next;
                delete cur;
                length--;
                if(length==0)
                {
                    tail=NULL;
                }
            }
            else
            {
                cur=head->next;
                prv=head;
                while(cur!=NULL)
                {
                    if(cur->item==element)
                    {
                        break;
                    }
                    prv=cur;
                    cur=cur->next;
                }
                if(cur==NULL)
                {
                    cout<<"element not found"<<endl;
                    return;
                }
                else
                {
                    prv->next=cur->next;
                    if(tail==cur)
                    {
                        tail=prv;
                    }
                }
                delete cur;
                length--;
            }

        }
    }
    void eraseAtPos(int pos)///o(N)
    {
        if(length==0)
        {
            cout<<"Linked List is  Empty"<<endl;
            return;
        }
        else if(length<=pos)
        {
            cout<<"Error"<<endl;
            return;
        }
        else
        {
            node*cur;
            node*prv;
            cur=head->next;
            prv=head;
            if(pos==0)
            {
                cur=head;
                head=head->next;
                delete cur;
                length--;
                if(length==0)
                {
                    tail=NULL;
                }
            }
            else
            {
                for (int i = 1; i < pos; i++)
                {
                    prv=cur;
                    cur=cur->next;
                }
                if(cur==NULL)
                {
                    cout<<"position not found"<<endl;
                }
                else
                {
                    if(cur==tail)
                    {
                        tail=prv;
                    }
                    prv->next=cur->next;
                    delete cur;
                    length--;
                }
            }

        }
    }
    void reverse()
    {
        node* cur;
        node* prev;
        node* next;
        prev=NULL;
        cur=head;
        next=cur->next;
        while(next!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;

    }
    int search(T element)
    {
        int pos=0;
        for(node*i=head;i!=NULL;i=i->next)
        {
            if(i->item==element)
            {
                return pos;
            }
            pos++;
        }
        return -1;
    }
    int size()
    {
        return length;
    }
    void clear()
    {
        node*next=NULL;
        node *cur=head;
        while(cur!=NULL)
        {
            next=cur->next;
            delete cur;
            cur=next;
        }

        head=NULL;
        length=0;

    }
    int returnPos(T element)
    {
        int cnt=0;
        node*cur=head;
        while(cur!=NULL)
        {
            if(cur->item==element)
            {
                return cnt;
            }
            cur=cur->next;
            cnt++;
        }
        return -1;
    }
    int returnPosBack(int index)
    {
        int cnt=length-index;
        if(cnt<0)
        {
            return -1;
        }
        node *cur=head;
        int i=0;
        while(cur!=NULL)
        {
            if(i==cnt)
            {
                return cur->item;
            }
            i++;
            cur=cur->next;

        }
        return -1;
    }
    void display()///O(N)
    {
        for(node *i=head;i!=NULL;i=i->next)
        {
            cout<<i->item<<" ";
        }
        cout<<endl;
    }


};
//////////////////////////doubly linked list////////////////////
template<typename T>class DoubleyList
{
    struct node
    {
        T item;
        node*prev;
        node*next;
    };
    int length;
    node*head;
    node*tail;
public:
    DoubleyList()
    {
        length=0;
        head=NULL;
        tail=NULL;
    }
    void pushFront(T element)
    {
        node*newnode=new node();
        newnode->item=element;
        if(length==0)
        {
            head=tail=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
        }
        else
        {
            newnode->next=head;
            newnode->prev=NULL;
            head->prev=newnode;
            head=newnode;
        }
        length++;
    }
    void pushBack(T element)
    {
        node*newnode=new node();
        newnode->item=element;
        if(length==0)
        {
            head=tail=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
        }
        else
        {
            newnode->next=NULL;
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
        length++;

    }
    void insertPos(int pos,T element)
    {
        node*newnode=new node();
        newnode->item=element;
        if(pos==0)
        {
            pushFront(element);
        }
        else if(pos>=length)
        {
            pushBack(element);
        }
        else
        {
            node*cur=head;
            for(int i=1;i<pos;i++)
            {
                cur=cur->next;///cur=pos-1;
            }
            newnode->next=cur->next;
            newnode->prev=cur;
            cur->next=newnode;
            cur->next->prev=newnode;
            length++;
        }


    }
    void popFront()
    {
        if(length==0)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        if(length==1)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            node*cur=head;
            head=head->next;
            head->prev=NULL;
            delete cur;
        }
        length--;
    }
    void popBack()
    {
        if (length == 0)
            cout << "Empty List" << endl;
        else if (length == 1)
        {
            delete head;
            //		delete last;
            tail = head = NULL;
            length--;
        }
        else
        {
            node *current = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete current;
            length--;
        }

    }
    void erase(T element)
    {
        if(head->item==element)
        {
            popFront();
        }
        else
        {
            node*current=head->next;
            while (current != NULL)//current->item!=element
            {
                if (current->item == element)
                    break;
                current = current->next;
            }

            if (current == NULL) {
                cout << "The item is not there\n";
                return;
            }
            else if (current->next == NULL) {
                popBack();
                return;
            }

            else
            {
                current->prev->next = current->next;
                //if (current->next != NULL)
                current->next->prev = current->prev;
                delete current;
                length--;
            }
        }


    }
    void display()
    {
        node*cur=head;
        while(cur!=NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    void reversedisplay()
    {
        node*cur=tail;
        while(cur!=NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->prev;
        }
        cout<<endl;
    }



};
//////////////////////////Binary Search Tree//////////////////////////
template<typename T> class BST{
    struct node
    {
        T item;
        node*left;
        node*right;
    };
    node *root;
    ////////////////////////private functions/////////////////
    void preorder(node*cur)
    {
        if(cur != NULL)
        {
            cout<<cur->item<<" ";
            preorder(cur->left);
            preorder(cur->right);
        }

    }
    void inorder(node*cur)
    {
        if(cur!=NULL)
        {
            inorder(cur->left);
            cout<<cur->item<<" ";
            inorder(cur->right);
        }
    }
    void postorder(node*cur)
    {
        if(cur!=NULL)
        {
            postorder(cur->left);
            postorder(cur->right);
            cout<<cur->item<<" ";
        }

    }

public:
    BST()
    {
        root=NULL;
    }
    bool isEmpty()
    {
        return root==NULL;
    }
    void insert(T element)
    {
        node*newnode=new node();
        newnode->item=element;
        newnode->left=NULL;
        newnode->right=NULL;
        node*cur=root;
        node*parent;

        if(isEmpty())
        {
            root=newnode;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            while (cur!=NULL)
            {
                parent=cur;
                if(element<=cur->item)
                {
                    cur=cur->left;
                }
                else
                {
                    cur=cur->right;
                }
            }
            if(element>parent->item)
            {
                parent->right=newnode;
            }
            else
            {
                parent->left=newnode;
            }

        }

    }
    bool search(int element)
    {
        node*cur=root;
        while(cur!=NULL)
        {
            if(cur->item==element)
            {
                return true;
            }
            else if(cur->item>element)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }
        return false;
    }
    void deletenode(node*&p)
    {
        node*cur;
        node*parent;
        if(p->left==NULL and p->right==NULL)///leaf
        {
            delete p;
            p=NULL;
        }
        else if(p->left==NULL)///one child at right
        {
            node*tmp=p;
            p=p->right;
            delete tmp;

        }
        else if(p->right==NULL)///one child at left;
        {
            node*tmp=p;
            p=p->left;
            delete tmp;
        }
        else
        {
            cur = p->right;
            parent = NULL;
            while (cur->left != NULL) {
                parent = cur;
                cur = cur->left;
            }
            p->item = cur->item;
            if (parent == NULL)
            {
                p->right = cur->left;
            } else {
                parent->left = cur->right;
            }
        }
    }
    void remove(T element)
    {
        if(isEmpty())
        {
            cout<<"tree is empty"<<endl;
            return;
        }
        if(root->item==element)
        {
            deletenode(root);
        }
        else
        {
            node*cur;
            node*parent;
            if(root->item>=element)
            {
                cur=root->left;
            }
            else
            {
                cur=root->right;
            }
            while(cur!=NULL)
            {
                if(cur->item==element)
                {
                    break;
                }
                else
                {
                    parent=cur;
                    if(cur->item>element)
                    {
                        cur=cur->left;
                    }
                    else
                    {
                        cur=cur->right;
                    }
                }
            }
            if(cur==NULL)
            {
                cout<<"element is not found"<<endl;
            }
            else
            {
                if(parent->item>element)
                {
                    deletenode(parent->left);
                }
                else
                {
                    deletenode(parent->right);
                }
            }

        }

    }
    void preorder()
    {
        preorder(root);
    }
    void inorder()
    {
        inorder(root);
    }
    void postorder()
    {
        postorder(root);
    }




};
//////////////////////////////Heap Sorting /////////////////////////
template<typename T> class MaxHeab {
    T *arr;
    int length;
    int mx;
public:
    MaxHeab(int sz =1)
    {
        mx = sz;
        length = 0;
        arr = new T[mx];
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void heapify(int i,int n)///O(nlog(n))
    {
        int left=2*i+1;
        int right=2*i+2;
        int max=i;
        if(left<n && arr[left]>arr[max])
        {
            max=left;
        }
        if(right<n and arr[right]>arr[max])
        {
            max=right;
        }
        if(max!=i)
        {
            swap(arr[i],arr[max]);
            heapify(max,n);
        }


    }
    void buildheap()
    {
        for (int i = (length / 2) - 1; i >= 0; i--)
        {
            heapify(i, length);
        }
    }
    void insert(T element)
    {
        if (length == mx) {
            mx *= 2;
            T* tmp = new T[mx];
            for (int i = 0; i < length; i++) {
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
        arr[length] = element;
        length++;
        buildheap();

    }
    void erase(int i)
    {
        sort();
        if(i<0 or i>=length)
        {
            cout<<"out of range"<<endl;
            return;
        }
        // cout<<i<<" "<<arr[i]<<" "<<length<<endl;
        arr[i]=arr[length-1];
        length--;
        //buildheap();
        heapify(i,length);

    }
    void sort()
    {
        buildheap();
        for (int i = length - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(0, i);  // heapify the reduced heap
        }
    }

    void display()
    {
        for(int i=0;i<length;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }



};
/////////////////////main//////////////////
int main()
{
    ////////////////////vector///////////////////////////
    Vector<int>v;
    cout << v.size() << endl;
    v.insert(5);
    v.display();
    v.insert(33);
    v.display();
    v.insertpos(1, 4);
    v.display();
    v.updateValue(2, 3);
    v.display();
    cout << v.returnvlaue(0) << endl;
    v.erasepos(0);
    v.display();
    v.erase();
    v.display();
    v.insert(3);
    cout << v.search(3) << endl;
    cout << v.isempty() << endl;
    cout << v.isfull() << endl;
    /////////////////Stack with array///////////
    Stack<char>st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.pop();
    cout<<st.Top()<<endl;
    st.display();
    /////////////stack_linked list/////////////////////
    LS_Stack<int>ST;
    ST.push(1);
    ST.push(2);
    ST.push(3);
    ST.push(4);
    ST.pop();
    cout<<ST.Top()<<endl;
    cout<<ST.popvalue()<<endl;
    ST.display();
    ///////////////queue with array////////////////////////
    Queue<int>q(10);
    q.push(1);///0
    q.push(2);///1
    q.push(3);///2
    q.push(4);///3
    q.push(5);///4
    q.pop();///front=1
    q.push(3);
    q.pop();///
    q.pop();
    q.push(6);
    cout<<q.Front()<<endl;
    cout<<q.Back()<<endl;
    q.display();
    //////////////////linked list queue////////////////
    queuelinkedlist<int>Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.pop();
    cout<<Q.Front()<<endl;
    cout<<Q.Back()<<endl;
    cout<<Q.size()<<endl;
    Q.display();
    //////////////////////////Linked List/////////////
    LinkedList<int>list;
    list.insertfront(5);
    list.insertBack(4);
    list.insertBack(3);
    list.insertAtPos(1,2);
    list.insertAtPos(6,1);
    list.popBack();
    list.popFront();
    list.reverse();
    cout<<list.size()<<endl;
    cout<<list.returnPos(5)<<endl;
    cout<<list.returnPosBack(3)<<endl;
    list.display();
    ////////////////////////doubly linked list//////////////
    DoubleyList<int>dlist;
    dlist.pushBack(2);
    dlist.pushFront(1);
    dlist.pushBack(3);
    dlist.pushBack(4);
    dlist.insertPos(2,2);
    dlist.erase(4);
    dlist.erase(1);
    dlist.popBack();
    dlist.display();
    dlist.reversedisplay();
    ////////////////////Binary Search Tree/////////////////
    BST<int>tree;
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);
    tree.remove(300);
    tree.preorder();
    cout<<endl;
    tree.inorder();
    cout<<endl;
    tree.postorder();
    cout<<endl;
    cout<<tree.search(10)<<endl;
    //////////////Heap Sorting///////////////
    MaxHeab <int>h(15);
    h.insert(3);
    h.insert(10);
    h.insert(12);
    h.insert(8);
    h.insert(2);
    h.insert(14);
    h.sort();
    h.erase(5);
    h.sort();
    h.display();

}

