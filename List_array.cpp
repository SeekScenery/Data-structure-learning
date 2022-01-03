#include <iostream>
using namespace std;

class List;

class List
{
    /*
    顺序存储：通过 array 实现
    功能：
        push 元素
        pop 元素
    */
public:
    List(int a)
        : max_size(a)
    {
        array_pt = new int[max_size];
        cout << " the List is created success" << endl;
    }
    ~List()
    {
        delete[] array_pt;
        cout << " the array_pt is deleted" << endl;
    }
    bool push(const int elem)
    {
        if (size+2 < max_size)
        {
            array_pt[size] = elem;
            size += 1;
            return true;
        }
        else
        {
            cout << "The size is over the max_size" << endl;
            return false;
        }
    }
    int get_element(int index)
    {
        // 如果用非顺序存储， 因该如何 get element
        if ((0 <= index-1) && (index -1 <= size))
        {
            return array_pt[index-1];
        }
        else
        {
            cout << "index beyond the size" << endl;
            return 0;
        }
    }
    int pop()
    {
        if (size > 0)
        {
            size -= 1;
            return array_pt[size];
        }
        else
        {
            cout << "the size is 0" << endl;
            return 0;
        }
    }
    bool insert_elem(const int index, const int elem)
    {
        /* 
        vscode 块注释 快捷键 alt + shift + Q 
        insert element attention:
        1. size+1 不能大于 max size
        2. index  需属于 （0，size+1）
         */
        if(size+1 <= max_size)
        {
            if ((index >= 0) && (index <= size+1))
            {
                if(index == size+1)
                    array_pt[index-1] = elem;
                else
                {
                    for (int inter = size; inter >= index; inter--)
                    {
                        array_pt[inter] = array_pt[inter-1];
                    }
                    array_pt[index-1] = elem;
                }
                size += 1;
                return true;
            }
            else
            {
                cout << index << "over the range of index" << endl;
                return false;
            }
        }
        else
        {
            cout << "beyond the capacity" << endl; 
            return false;
        }

    }
    void print_element()
    {

        cout <<"element: ";
        
        for(int i=0; i < size; i++ )
        {
            cout << get_element(i+1) << "\t";
        }
        cout << endl;
    }
    int delete_elem(int index)
    {

        return 0;
    }
    int get_size()
    {
        return size;
    }

private:
    int max_size;
    int size = 0;
    int *array_pt;
};

int main()
{

    // 测试 List fuction
    // creat
    List list_test(5);
    // push element
    list_test.push(5);
    list_test.push(4);
    list_test.push(3);
    list_test.print_element();
    list_test.insert_elem(2, 34);
    list_test.print_element();
    cout << list_test.get_element(0) << endl;

    return 0;
}