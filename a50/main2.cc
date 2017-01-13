#include <thread>
#include <iostream>
#include <future>
#include <utility>
#include <iomanip>

double lhs[4][5] = {{1, 2, 3, 4, 5},
		    {1, 2, 3, 4, 5},
		    {1, 2, 3, 4, 5},
		    {1, 2, 3, 4, 5}};

double rhsT[6][5] = {{1, 2, 3, 4, 5},
		     {1, 2, 3, 4, 5},
		     {1, 2, 3, 4, 5},
		     {1, 2, 3, 4, 5},
		     {1, 2, 3, 4, 5},
		     {1, 2, 3, 4, 5}};

double innerProduct(int row, int col)
{
    double sum = 0;
    
    for (int idx = 0; idx != 5; ++idx)
	sum +=  lhs[row][idx] * rhsT[col][idx];

    return sum;
}

int main()
{
   
    std::future<double> fut[4][6];
    
    for (int row = 0; row != 4; ++row)
    {
	for (int col = 0; col != 6; ++col)
	{
	    std::packaged_task<double(int,int)> Task (innerProduct);
	    fut[row][col] = Task.get_future();
	    std::thread(std::move(Task), row, col).detach();
	}
    }
    
    for (int row = 0; row != 4; ++row)
    {
	for (int col = 0; col != 6; ++col)
	{
	    std::cout << fut[row][col].get() << std::setw(6);
	}
	std::cout << '\n';
    }
}
