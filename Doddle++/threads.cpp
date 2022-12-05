
#include <iostream>
#include <thread>

static bool s_Finished = false;

using namespace std::literals::chrono_literals;

void DoWork(const int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Working... (" << n << ")" << std::endl;
		std::this_thread::sleep_for(1s);
	}
}


void FunWithThreads()
{
	std::thread worker1([]() { DoWork(4); });
	std::thread worker2([]() { DoWork(5); });
	worker1.join();
	worker2.join();
}