#include "main.ih"

int main(int argc, char **argv)
{
    int ia[] = {2,4,6,2,3,7,9,1,12};
    size_t iaSize = 9;
    auto fut = async(launch::async, quickersort, ia, ia + iaSize);
    fut.get();

    for (size_t i = 0; i != iaSize; ++i)
        cout << ia[i] << ' ';
    cout << '\n';
}
