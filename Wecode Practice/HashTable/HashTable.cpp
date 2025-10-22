#include <iostream>
#include <string>
using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct node
{
    int flag;       //Trạng thái ô (EMPTY (0), OCCUPIED (1), DELETED (-1))
    int key;        //Giá trị được lưu
};

struct hashtable
{
    int m;          //Kích thước Hashtable (số ô)
    int n;          //Số phần tử hiện có
    node* table;    //Mảng các Node
};

int HF(hashtable ht, int key)  //Chia lấy dư để xác định ví trí ban đầu trong bảng
{
    return key % ht.m;
}

int HF_LinearProbing(hashtable ht, int key, int i)   //Dò tuyến tính
{
    int h = HF(ht, key);
    return (h + i) % ht.m;
}

bool Insert(hashtable &ht, int key)
{
    if(((double)(ht.n + 1) / ht.m) > LOAD) return false;

    for(int i = 0; i < ht.m; i++)
    {
        int index = HF_LinearProbing(ht, key, i);

        if(ht.table[index].flag == EMPTY) break;

        if(ht.table[index].flag == OCCUPIED && ht.table[index].key == key) return false;
    }

    for(int i = 0; i < ht.m; i++)
    {
        int index = HF_LinearProbing(ht, key, i);

        if((ht.table[index].flag == EMPTY) || ht.table[index].flag == DELETED)
        {
            ht.table[index].key = key;
            ht.table[index].flag = OCCUPIED;
            ht.n++;
            return true;
        }
    }

    return false;
}

bool Delete(hashtable &ht, int key)
{
    for(int i = 0; i < ht.m; i++)
    {
        int index = HF_LinearProbing(ht, key, i);

        if(ht.table[index].flag == EMPTY) return false;

        if((ht.table[index].flag == OCCUPIED) && (ht.table[index].key == key))
        {
            ht.table[index].flag == DELETED;
            ht.n--;
            return true;
        }
    }
    
    return false;
}

void CreateHashTable(hashtable &ht)
{
    cin >> ht.m;
    ht.n = 0;
    ht.table = new node[ht.m];

    for(int i = 0; i < ht.m; i++)
    {
        ht.table[i].flag = EMPTY;
    }

    int num;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        int op, val;
        cin >> op >> val;
        if(op == 1) Insert(ht, val);

        else if(op == 0) Delete(ht, val);
    }
}

void Traverse(hashtable ht)
{
    for(int i = 0; i < ht.m; i++)
    {
        cout << i << "-->";

        if(ht.table[i].flag == OCCUPIED) cout << ht.table[i].key;

        else if(ht.table[i].flag == DELETED) cout << "DELETED";

        else cout << "EMPTY";

        cout << endl;
    }
}

void DeleteHashTable(hashtable &ht)
{
    delete [] ht.table;
    ht.table = nullptr;
    ht.m = 0;
}

int main()
{
    hashtable ht;
    CreateHashTable(ht);
    Traverse(ht);
    DeleteHashTable(ht);
    return 0;
}