#include <bits/stdc++.h> 

struct node{
    int data;
    int val,cnt;

    node* next,*prev;

    node(int k,int v)
    {
        data =k;
        val =v;
        prev =next =NULL;
        cnt=1;
    }
    
};

struct List{

    node *head,*tail;
    int size;

    List()
    {
        head = new node(0,0);
        tail =new node(0,0);
        head->next = tail;
        tail->prev=head;
        size=0;
    }

    void insert_beg(node*  nod)
    {
        nod->next = head->next;
        head->next = nod;
        nod->next->prev = nod;
        nod->prev =head;

        size++;
    }

    void removeNode(node* nod)
    {
        node* p = nod->prev;
        node* n= nod->next;

        p->next =n;
        n->prev= p;
        size--;
    }

};


class LFUCache
{
   map<int,List*> freq;
   map<int,node*> mp;

    int maxi,min_fre,cur_size;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxi =capacity;
        min_fre=0;
        cur_size=0;
    }

    void Updatefreqlist(node* temp)
    {
        mp.erase(temp->data);

        freq[temp->cnt]->removeNode(temp);

        if(temp->cnt==min_fre && freq[temp->cnt]->size==0)
            min_fre++;
        
        List* nextfreq = new List();

        if(freq.count(temp->cnt+1)!=0)
        {
            nextfreq = freq[temp->cnt+1];
        }
        temp->cnt++;
        nextfreq->insert_beg(temp);
        freq[temp->cnt] = nextfreq;
        mp[temp->data] = temp;

    }

    int get(int key)
    {
        // Write your code here.
        if(mp.count(key)!=0)
        {
            node* temp =mp[key];

            int val = temp->val;

            Updatefreqlist(temp);

            return val;
        }
        return -1; 
    }

    void put(int key, int value)
    {
        // Write your code here.

        if(maxi == 0) return;

        if(mp.count(key)!=0)
        {
            node* temp = mp[key];
            temp->val =value;
            Updatefreqlist(temp);       
        }
        else{
             if(cur_size==maxi)
             {
                 List* list = freq[min_fre];
                 mp.erase(list->tail->prev->data);
                 freq[min_fre]->removeNode(list->tail->prev);
                 cur_size--;
             }

             cur_size++;
             min_fre =1;

             List *list = new List();
             if(freq.count(min_fre)!=0)
                list = freq[min_fre];

            node * temp = new node(key,value);
            list->insert_beg(temp);
            mp[key] = temp;
            freq[min_fre] = list;

        }

    }
};
