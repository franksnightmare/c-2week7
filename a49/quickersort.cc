#include "main.ih"

void quickerSort(SafeRangeQueue &nextRange)
{
	Range range = nextRange.pop();
	int* beg = range.beg;
	int* end = range.end;
	
    if (end - beg <= 1)
        return;

    int lhs = *beg;
    int *mid = partition(beg + 1, end,
        [&](int arg)
        {
            return arg < lhs;
        }
    );

    swap(*beg, *(mid - 1));
	
	Range newRange1(beg, mid);
	Range newRange2(mid, end);
	
    nextRange.push(newRange1);
    nextRange.push(newRange2);
}
