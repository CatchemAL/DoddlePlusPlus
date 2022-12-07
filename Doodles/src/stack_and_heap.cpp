#include <iostream>
#include <memory>

class Bucket
{
	int start_;

public:
	int end;

	Bucket(int start=0, int end = 0)
		:start_(start), end(end)
	{
		std::cout << "Created Bucket(start=" << start << ", end=" << end << ")" << std::endl;
	}

	void SayHello()
	{
		std::cout << "Hello there!" << std::endl;
	}

	~Bucket()
	{
		std::cout << "Destroyed Bucket(start=" << start_ << ", end=" << end << ")" << std::endl;
	}
};


class ScopedPtr
{
private:
	const Bucket* ptr_;

public:
	ScopedPtr(const Bucket* ptr)
		:ptr_(ptr)
	{
	}

	~ScopedPtr()
	{
		std::cout << "Scoped Pointer dropping out of scope here" << std::endl;
		std::cout << "Clearing resources..." << std::endl;
		delete ptr_;
		std::cout << "Housekeeping done!" << std::endl;
	}

	const Bucket* operator->() const
	{
		return this->ptr_;
	}
};

void FunWithStacks()
{
	{
		Bucket stackBucket;
		auto heapBucket = new Bucket(123, 456); // leaked!!
	}

	{
		ScopedPtr ptr = new Bucket(3, 8); // implicit constructor call!
		const int end = ptr->end; // overload the arrow operator to forward the call
		std::cout << "End is " << end << std::endl;
	}

	{
		// std::unique_ptr<Bucket> ptr = new Bucket(); // won't work because the constructor is explicit

		// Works but not the best...
		Bucket* bucket_ptr = new Bucket(2, 5);
		std::unique_ptr<Bucket> ptr(bucket_ptr); // won't work because the constructor is explicit

		// Preferred way is to use make_unique to avoid dangling references if exceptions are
		// thrown in constructors
		const std::unique_ptr<Bucket> correctWay = std::make_unique<Bucket>(4, 71);
		correctWay->SayHello();
	}

	{
		std::shared_ptr<Bucket> shared0;

		{
			const std::shared_ptr<Bucket> shared1 = std::make_shared<Bucket>(1, 1);
			shared0 = shared1;
		}
	}

}