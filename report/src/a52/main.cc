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

void innerProduct(std::promise<double> &ref, int row, int col)
{
    double sum = 0;
    for (int idx = 0; idx != 5; ++idx)
			sum += lhs[row][idx] * rhsT[col][idx];

    ref.set_value(sum);
}

int main()
{
    std::promise<double> result[4][6];

    for (int row = 0; row != 4; ++row)
    {
			for (int col = 0; col != 6; ++col)
	    		std::thread(innerProduct,
						ref(result[row][col]),
						row, col).detach();
    }

    for (int row = 0; row != 4; ++row)
    {
			for (int col = 0; col != 6; ++col)
	    		std::cout
						<< result[row][col].get_future().get()
						<< std::setw(6);
			std::cout << '\n';
    }
}
