#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Array
{
public:

    typedef double
        value_type;
    typedef double*
        iterator;
    typedef const double*
        const_iterator;
    typedef double&
        reference;
    typedef const double&
        const_reference;
    typedef size_t
        size_type;

    Array(const size_type n);
    Array(const Array& arr);

    Array(int mnInd, int mxInd, string name)
    {
        maxid = mxInd;
        minid = mnInd;
        Name = name;
        Size = maxid - minid * 2;
        elems = new value_type[Size];
        Count = 0;
    }

    ~Array()
    {
        delete[]elems;
    }

    Array& operator=(const Array&);

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems + Count; }
    const_iterator end() const { return elems + Count; }

    size_type size() const
    {
        return Count;
    }

    size_type capacity() const
    {
        return Size;
    }

    bool empty() const
    {
        if (Count == 0)
            return true;
        else
            return false;
    }

    void resize(size_type newsize);

    void clear() { Count = 0; }

    void swap(Array& other);

    void assign(const value_type& v);

    reference operator[](int index);
    const_reference operator[](int index) const;
    reference front() { return elems[0]; }
    const_reference front() const { return elems[0]; }

    reference back() {
        return elems[size() - 1];
    }

    void push_back(const value_type& v);

    void pop_back()
    {
        elems[Count - 1] = 0;
        Count--;
    }

    int getMinInd() const
    {
        return minid;
    }

    string getName() const
    {
        return Name;
    }

    void swap(int one, int two)
    {
        value_type t;

        t = elems[one];
        elems[one] = elems[two];
        elems[two] = t;
    }

    void show() const
    {
        if (Name != "")
            cout << Name << "= ";

        for (int i = 0; i < Count; i++)
            cout << elems[i] << " ";
        cout << '\n';
    }

    void fsort()
    {
        int j = 0;

        for (int i = 1; i < Count; i++)
        {
            j = i - 1; // int j = j-1;

            while (j >= 0 && elems[j] > elems[j + 1])
            {
                swap(j, j + 1);

                j--;
            }
        }
    }

    void secsort()
    {
        int j = 0;

        for (int i = 1; i < Count; i++)
        {
            j = i - 1; // int j = j-1;

            while (j >= 0 && elems[j] < elems[j + 1])
            {
                swap(j, j + 1);

                j--;
            }
        }
    }

private:
    string Name;

    int minid;
    int maxid;

    static const size_type min = 10;

    size_type Size;
    size_type Count;

    value_type* elems;
};

class indexhelp
{
    string obj;
    string fault = "wrong index";

public:

    indexhelp(string name)
    {
        obj = name;
    }

    void show() const
    {
        cout << obj << " " << fault;
    }
};

double minfinder(const Array& arr)
{
    int i = 0;
    double min = arr.begin()[i];

    for (int n = 0; n < arr.size(); i++, n++)
    {
        if (arr.begin()[i] < min)
            min = arr.begin()[i];
    }

    return min;
}

double maxfinder(const Array& arr)
{
    int i = 0;
    double max = arr.begin()[i];

    for (int n = 0; n < arr.size(); n++, i++)
    {
        if (arr.begin()[i] > max)
            max = arr.begin()[i];
    }

    return max;
}

double summary(const Array& arr)
{
    double sum = 0;

    for (int i = 0; i < arr.size(); i++)
        sum += arr.begin()[i];

    return sum;
}

double diff(const Array& arr)
{
    double raz = 0;

    for (int i = 0; i < arr.size(); i++)
        raz += arr.begin()[i];

    return raz;
}

double average(const Array& arr)
{
    double sr = summary(arr) / arr.size();

    return sr;
}

void arrsummary(const Array& arr, const double num)
{

    int size = arr.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
        newarr.push_back(arr.begin()[i] + num);

    cout << arr.getName() << "+const= ";

    newarr.show();
}

void arrdiff(const Array& arr, const double num)
{
    int size = arr.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
        newarr.push_back(arr.begin()[i] - num);

    cout << arr.getName() << "-const= ";

    newarr.show();

}

void arrmulti(const Array& arr, const double num)
{
    int size = arr.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
    {
        newarr.push_back(arr.begin()[i] * num);
        if (newarr[i] == -0)
            newarr[i] = 0;
    }

    cout << arr.getName() << "*const= ";

    newarr.show();

}


void up(const Array& arr)
{
    Array newarr(arr);

    newarr.fsort();

    cout << "sort up " << arr.getName() << "= ";

    newarr.show();
}


void down(const Array& arr)
{
    Array newarr(arr);

    newarr.secsort();

    cout << "sort down " << arr.getName() << "= ";

    newarr.show();
}

void arrnewsum(const Array& arr1, const Array& arr2)
{
    int size = arr1.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
        newarr.push_back(arr1.begin()[i] + arr2.begin()[i]);

    cout << "summa= ";

    newarr.show();
}

void arrnewdif(const Array& arr1, const Array& arr2)
{
    int size = arr1.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
        newarr.push_back(arr1.begin()[i] - arr2.begin()[i]);

    cout << "raznost= ";

    newarr.show();
}

void arrnewmulti(const Array& arr1, const Array& arr2)
{
    int size = arr1.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
        newarr.push_back(arr1.begin()[i] * arr2.begin()[i]);

    cout << "proizv= ";

    newarr.show();
}

void arrnewdiv(const Array& arr1, const Array& arr2)
{
    int size = arr1.size();

    Array newarr(size);

    for (int i = 0; i < size; i++)
    {
        if (arr2.begin()[i] != 0)
        {
            newarr.push_back(trunc(arr1.begin()[i] / arr2.begin()[i]));
            if (newarr[i] == -0)
                newarr[i] = 0;
        }
        else
            throw "delenie na 0";
    }

    cout << "delenie= ";

    newarr.show();
}


void helper(const Array& arr, double num)
{
    arrsummary(arr, num);

    arrdiff(arr, num);

    arrmulti(arr, num);

    up(arr);

    down(arr);
}

void toohelper(const Array& arr1, const Array& arr2)
{
    arrnewsum(arr1, arr2);

    arrnewdif(arr1, arr2);

    arrnewmulti(arr1, arr2);

    try
    {
        arrnewdiv(arr1, arr2);
    }
    catch (const char* err)
    {
        cout << err << '\n';
    }
}

double& Array::operator[](int index)
{
    size_type defid = minid;
    size_type id = 0;

    if (index <= maxid && index >= minid)
    {
        while (defid != index)
        {
            defid++;
            id++;
        }
        return elems[id];
    }
    else
        throw indexhelp(Name);
}

const double& Array::operator[](int index) const
{
    size_type defid = minid;
    size_type id = 0;

    if (index <= maxid && index >= minid)
    {
        while (defid != index)
        {
            defid++;
            id++;
        }
        return elems[id];
    }
    else
        throw indexhelp(Name);
}

void Array::push_back(const value_type& v)
{
    if (Count == Size)
        resize(Size * 2);

    elems[Count++] = v;
}

void Array::resize(size_type newsize)
{
    try
    {
        value_type* data = new value_type[newsize];

        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];

        delete[] elems;

        elems = data;
        Size = newsize;
    }
    catch (bad_alloc& ba)
    {
        cout << ba.what() << '\n';
    }
}

Array::Array(const Array& arr)
{
    try
    {
        Size = arr.size();

        minid = arr.getMinInd();

        maxid = minid + Size - 1;

        elems = new value_type[Size];

        for (int i = 0; i < Size; ++i)
            elems[i] = arr.begin()[i];

        Count = Size;
    }
    catch (bad_alloc& ba)
    {
        cout << ba.what() << '\n';
    }
}

Array::Array(const size_type n)
{
    try
    {
        Size = n;
        minid = 0;
        maxid = n - 1;

        elems = new value_type[n];

        for (int i = 0; i < Size; i++)
            elems[i] = 0;

        Count = 0;
        Name = "";
    }

    catch (bad_alloc& ba)
    {
        cout << ba.what() << '\n';
    }
}

int main()
{
    int minid, maxid, s = 1;

    double a, num;

    cin >> minid >> maxid;

    Array arr1(minid, maxid, "Array1");
    Array arr2(minid, maxid, "Array2");

    for (int i = minid; i < maxid + 1; i++)
    {
        cin >> a;

        arr1.push_back(a);
    }

    for (int i = minid; i < maxid + 1; i++)
    {
        cin >> a;

        arr2.push_back(a);
    }

    cin >> num;

    arr1.show();
    helper(arr1, num);

    arr2.show();
    helper(arr2, num);

    toohelper(arr1, arr2);

    while (true)
    {
        cin >> s;

        if (s == 0)
        {
            break;
        }
        else
        {
            switch (s)
            {
            case 1:
                cin >> a;

                try
                {
                    cout << arr1.getName() << "[" << a << "]= " << arr1[a] << '\n';
                }
                catch (const indexhelp exp)
                {
                    exp.show();

                    cout << " " << a << '\n';
                }

                break;
            case 2:
                cin >> a;

                try
                {
                    cout << arr2.getName() << "[" << a << "]= " << arr2[a] << '\n';
                }
                catch (const indexhelp exp)
                {
                    exp.show();

                    cout << " " << a << '\n';
                }
                break;
            }
        }
    }
    return 0;
}