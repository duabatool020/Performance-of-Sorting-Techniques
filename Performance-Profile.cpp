#include<iostream>
#include<windows.h>
#include <chrono>
#include <fstream>
#include <string>
#include<ctime>
    using namespace std;
    using namespace std::chrono;
    template <class itemtype>
    class node {
    public:
        itemtype data;
        node* next;
    };
    node<int>* head;
    template <class itemtype>
    class Slist {
    public:
        Slist() {
            head = NULL;
        }
        void insertBeg(itemtype value) {
            node<itemtype>* temp;
            if (head == NULL)
            {
                temp = new node<itemtype>;
                temp->data = value;
                temp->next = NULL;
                head = temp;
            }
            else
            {
                temp = new node<itemtype>;
                temp->data = value;
                temp->next = head;
                head = temp;
            }
        }
        void insertEnd(itemtype val) {
            node<itemtype>* temp = head;
            node<itemtype>* p;
            if (head == NULL)
            {
                temp = new node<itemtype>;
                temp->data = val;
                temp->next = NULL;
                head = temp;
            }
            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                p = new node<itemtype>;
                p->data = val;
                p->next = NULL;
                temp->next = p;
            }
        }
        void insertMid(itemtype oldval, itemtype val)
        {
            node<itemtype>* temp;
            node<itemtype>* p;
            if (head == NULL)
            {
                temp = new node<itemtype>;
                temp->data = val;
                temp->next = NULL;
                head = temp;
            }
            else
            {
                temp = head;
                while (temp->data != oldval)
                {
                    temp = temp->next;
                }
                p = new node<itemtype>;
                p->data = val;
                p->next = temp->next;
                temp->next = p;
            }
        }
        
    };
    class sorting
    {
    private:
        int N;           //sotres aray size
        long int* arr;        //stores aray values
    public:
        node<int>* sortedval;
        void insertSort(node<int>* curr)
        {
            sortedval = NULL;
            while (curr != NULL)
            {
                node<int>* next = curr->next;
                sortedInsert(curr);
                curr = next;
            }
            head = sortedval;
        }
        void sortedInsert(node<int>* newnode)
        {
            if (sortedval == NULL ||
                sortedval->data >= newnode->data)
            {
                newnode->next = sortedval;
                sortedval = newnode;
            }
            else
            {
                node<int>* curr = sortedval;
                while (curr->next != NULL &&
                    curr->next->data < newnode->data)
                {
                    curr = curr->next;
                }
                newnode->next = curr->next;
                curr->next = newnode;
            }
        }
        void printsortlist(node<int>* head)
        {
            while (head != NULL)
            {
                cout << head->data << " ";
                head = head->next;
            }
        }

        void ComputeMergeSOrtTime()
        {
          
            auto start = high_resolution_clock::now();
            MergeSort(&head);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Merge Sort function: "
                << duration.count() << " microseconds" << endl;
        }
        void ComputeHeapSortTime()
        {
            auto start = high_resolution_clock::now();
            Heapsort();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Heap sort function: "
                << duration.count() << " microseconds" << endl;
        }
        void ComputeInsertionSortTime()
        {
            auto start = high_resolution_clock::now();
            insertSort(head);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Insertion sort function: "
                << duration.count() << " microseconds" << endl;

        }
        void ComputeQuickSortTime()
        {
            auto start = high_resolution_clock::now();
            QUICK_sort();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by Quick sort function: "
                << duration.count() << " microseconds" << endl;

        }
        //void sorttec()
        //{

        //    int num;
        //    cout << "Enter array size: "; cin >> num;
        //    long int* aray = new long int[num];
        //    for (int i = 0; i < num; i++)
        //    {
        //        aray[i] = rand();
        //    }
        //    setAray(num, aray);
        //    /DisplayArray();/
        //    Slist<int> l; char ch;
        //    for (int i = 0; i < N - 1; i++)
        //    {
        //        l.insertEnd(aray[i]);
        //    }
        //    /*cout << " List before sorting" << endl;
        //    printsortlist(head);*/
        //    cout << endl << "Enter the sort function you want run "; cin >> ch;
        //    if (ch == 'M') {
        //        auto start = high_resolution_clock::now();
        //        MergeSort(&head);
        //        auto stop = high_resolution_clock::now();
        //        auto duration = duration_cast<microseconds>(stop - start);
        //        cout << "Time taken by function: "
        //            << duration.count() << " microseconds" << endl;
        //        cout << "List After sorting" << endl;
        //        printsortlist(head);
        //    }
        //    else if (ch == 'I') {
        //        auto start = high_resolution_clock::now();
        //        insertSort(head);
        //        auto stop = high_resolution_clock::now();
        //        auto duration = duration_cast<microseconds>(stop - start);
        //        cout << "Time taken by function: "
        //            << duration.count() << " microseconds" << endl;
        //        cout << "List After sorting" << endl;
        //        printsortlist(head);
        //    }
        //    else if (ch == 'H') {
        //        auto start = high_resolution_clock::now();
        //        Heapsort();
        //        auto stop = high_resolution_clock::now();
        //        auto duration = duration_cast<microseconds>(stop - start);
        //        cout << "Time taken by function: "
        //            << duration.count() << " microseconds" << endl;
        //        DisplayArray();
        //    }
        //    else if (ch == 'Q') {
        //        auto start = high_resolution_clock::now();
        //        QUICK_sort();
        //        auto stop = high_resolution_clock::now();
        //        auto duration = duration_cast<microseconds>(stop - start);
        //        cout << "Time taken by function: "
        //            << duration.count() << " microseconds" << endl;
        //        DisplayArray();
        //    }

        //}

        node<int>* Merge(node<int>* h1, node<int>* h2)
        {
            node<int>* t1 = new node<int>;
            node<int>* t2 = new node<int>;
            node<int>* temp = new node<int>;
            if (h1 == NULL)
                return h2;
            if (h2 == NULL)
                return h1;

            t1 = h1;
            while (h2 != NULL)
            {
                t2 = h2;
                h2 = h2->next;
                t2->next = NULL;
                if (h1->data > t2->data)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
                bool flag = true;
                do {
                    if (t1->next == NULL)
                    {
                        t1->next = t2;
                        t1 = t1->next;
                        flag = true;
                    }
                    else if ((t1->next)->data <= t2->data)
                    {
                        t1 = t1->next;
                        flag = false;
                    }
                    else
                    {
                        temp = t1->next;
                        t1->next = t2;
                        t2->next = temp;
                        flag = true;
                    }
                } while (flag == false);


            }
            return h1;
        }
        void MergeSort(node<int>** head)
        {
            node<int>* first = new node<int>;
            node<int>* second = new node<int>;
            node<int>* temp = new node<int>;
            first = *head;
            temp = *head;
            if (first != NULL && first->next != NULL)
            {
                while (first->next != NULL)
                {
                    first = first->next;
                    if (first->next != NULL)
                    {
                        temp = temp->next;
                        first = first->next;
                    }
                }
                second = temp->next;
                temp->next = NULL;
                first = *head;

            }
            else
            {
                return;
            }

            MergeSort(&first);
            MergeSort(&second);

            // Merge the two part of the list into a sorted one.      
            *head = Merge(first, second);
        }
        sorting()   //default constructor
        {
            N = 2;
            arr = new long int[N];
        }
        sorting(int size, long int* aray) //Paramterized constrcutor
        {
            N = size;
            arr = aray;

        }
        void setAray(int size, long int* aray)
        {
            N = size;
            arr = aray;

        }
        void SetList(int size, long int* aray)
        {
            N = size;
            Slist<int> l;

            for (int i = 0; i < N - 1; i++)
            {
                l.insertEnd(aray[i]);
            }
        }

        void DisplayArray()
        {
            cout << "{ ";
            for (int i = 0; i < N; i++)
            {
                cout << arr[i] << ", ";
            }
            cout << "}" << endl;
        }

        void swap(long int index1, long int index2)
        {
            long int temp;
            temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }


        //*QUICK SORT**//

        int partition(int left, int right)//for sorting pivot element
        {
            int pivot = arr[right];
            int index = left - 1;
            for (int i = left; i <= right - 1; i++)
            {
                if (arr[i] <= pivot)
                {
                    index++;
                    swap(index, i);
                }
            }
            swap(index + 1, right);
            return index + 1;
        }
        void QuickSort(int left, int right)
        {
            if (left < right)
            {
                int SortedIndex = partition(left, right);
                QuickSort(left, SortedIndex - 1);
                QuickSort(SortedIndex + 1, right);
            }
        }

        void QUICK_sort()
        {
            QuickSort(0, N - 1);

        }


        //*HEAP SORT*//


        void heapify(int i)//fucntion which again build a heap when heap lose its heap property 
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;  //parent(max heap)
            if (left < N && arr[left] > arr[largest])//checking if left child is greater than parent
            {
                largest = left;//assigning parent left child value if left child is greater
            }
            if (right < N && arr[right] > arr[largest])//checking if right child is greater than parent
            {
                largest = right;//assigning parent right child value if left child is greater
            }
            if (largest != i) //checking if largest element is not root
            {
                swap(i, largest);
                heapify(largest);
            }
        }
        void buildMaxHeap()//transform an array in heap
        {
            for (int i = N / 2 - 1; i >= 0; i--)
            {
                heapify(i);
            }
        }


        void Heapsort()
        {
            buildMaxHeap();
            for (int i = N - 1; i >= 0; i--)
            {
                swap(0, i);
                N--;
                heapify(0); //Considering 0 index as well
            }
        }
        ~sorting()
        {
            delete[]arr;
        }
    };
    //global function
    void UserInterface()
    {
        sorting a, b,c,d;  
        Slist<int> l1, l2; 

        int num;
        cout << "Enter array size: "; cin >> num;
        long int* aray = new long int[num];
        for (int i = 0; i < num; i++)
        {
            aray[i] = rand();
        }
        //storing same values in all objects for time comparison
        a.setAray(num, aray);
        b.setAray(num, aray);
        c.SetList(num, aray);
        d.SetList(num, aray);
        
        a.ComputeQuickSortTime();
        b.ComputeHeapSortTime();
        c.ComputeMergeSOrtTime();
        d.ComputeInsertionSortTime();
        

    }
    int main()
    {
        
        UserInterface();


        return 0;
    }
