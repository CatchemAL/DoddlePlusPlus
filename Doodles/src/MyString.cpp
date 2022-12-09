
#include <iostream>
#include <ostream>

class MyString
{
private:
	std::size_t length_;
	char* buffer_;

public:
	MyString(const char* buffer) // USUAL CONSTRUCTOR
	{
		length_ = strlen(buffer);
		buffer_ = new char[length_+1];
		memcpy(buffer_, buffer, length_);
		buffer_[length_] = '\0';
	}

	MyString(const MyString& other) // COPY CONSTRUCTOR
	{
		// As simple as this...
		// memcpy(this, &other, sizeof(MyString));

		length_ = other.length_;
		std::cout << "Copy constructor being called..." << std::endl;
		buffer_ = new char[length_ + 1];
		memcpy(buffer_, other.buffer_, length_ + 1);
	}

	MyString(MyString&& other) // MOVE CONSTRUCTOR
	{
		std::cout << "Move constructor being called..." << std::endl;
		length_ = other.length_;
		buffer_ = other.buffer_;
		other.buffer_ = nullptr;
	}

	MyString& operator=(MyString other) {
		MyString::Swap(*this, other);
		return *this;
	}

	static void Swap(MyString& string, MyString& other) {
		std::swap(string.length_, other.length_);
		std::swap(string.buffer_, other.buffer_);
	}

	~MyString()
	{
		std::cout << "Calling destructor for " << *this << "..." << std::endl;
		delete[] buffer_;
	}

	char& operator[](const int index) const
	{
		return buffer_[index];
	}

	friend std::ostream& operator << (std::ostream& outs, const MyString& p);
};

std::ostream& operator << (std::ostream& outs, const MyString& p)
{
	return outs << "MyString(length_=" << p.length_ << ", buffer_=" << p.buffer_ << ")";
}


void print_bad(const MyString my_string)
{
	std::cout << my_string << std::endl;
}


void print_good(const MyString& my_string)
{
	std::cout << my_string << std::endl;
}


void MakingMyOwnString()
{
	const MyString my_string = "ALEX"; // implicit constructor
	std::cout << my_string << std::endl;


	my_string[2] = 'I'; // surprising inversion...

	std::cout << my_string << std::endl;

	// Playing around with copy
	const MyString my_copied_string = my_string;
	std::cout << my_copied_string << std::endl;
	my_copied_string[0] = 'F';
	std::cout << my_copied_string << std::endl;
	std::cout << my_string << std::endl;

	MyString foo("temp");
	MyString bar("key");
	foo = bar;


	// Print with unintended copy
	print_bad(my_string);
	print_good(my_string);
}