#include <future>
#include <algorithm>
#include <iostream>

using namespace std;


int* quickersort(int *beg, int *end)
{
    if (end - beg <= 1)
        return beg;

    int lhs = *beg;
    int *mid = partition(beg + 1, end,
        [&](int arg)
        {
            return arg < lhs;
        }
    );

    swap(*beg, *(mid - 1));

    auto leftPart = async(launch::async, quickersort, beg, mid);
    auto rightPart = async(launch::async, quickersort, mid, end);

    rightPart.get();

    return leftPart.get();
}

int main()
{
    int* ia = new int[9]{2,4,6,2,3,7,9,1,12};
    int iaSize = 9;
    auto fut = async(launch::async, quickersort, ia, ia + iaSize);
    fut.get();

    for (size_t i = 0; i < 9; i++)
    {
        cout << ia[i] << ' ';
    }
    cout << '\n';
    delete ia;
}
