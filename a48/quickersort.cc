#include "main.ih"

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
