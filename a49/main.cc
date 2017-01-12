#include "main.ih"
#include <thread>

int main(int argc, char **argv)
{
	Semaphore nextRange;
	
	int ia[] = {2,4,6,2,3,7,9,1,12};
    size_t iaSize = 9;
	
	nextRange.push(Range(ia, ia + iaSize));
	
	thread sorter1(quickerSorter, std::ref(nextRange.subscribeThread()));
	thread sorter2(quickerSorter, std::ref(nextRange.subscribeThread()));
	thread sorter3(quickerSorter, std::ref(nextRange.subscribeThread()));
	
	sorter1.join();
	sorter2.join();
	sorter3.join();
	
	for (size_t i = 0; i != iaSize; ++i)
        cout << ia[i] << ' ';
    cout << '\n';
}
