#include <iostream>

//void print(int x)
//{
//    std::cout << "print(int)\n";
//}
//
//void print(int x, int y = 10)
//{
//    std::cout << "print(int, int)\n" << y;
//}
//
//int main()
//{
//    static_cast<void(*)(int)>(print)(1);
//
//    static_cast<void(*)(int, int)>(print)(1,0);
//
//    return 0;
//}

#include <iostream>
#include <limits>
#include <functional>

class Data
{
private:
	double m_x{ 1.0 };
	double m_y{ 1.0 };
	char m_z{ '*' };
public:
	double getFirstNum() { return m_x; }
	void setFirstNum(double x) { m_x = x; }

	double getSecondNum() { return m_y; }
	void setSecondNum(double y) { m_y = y; }

	char getOperation() { return m_z; }
	void setOperation(char z) { m_z = z; }
};

using ValidateFunction = std::function<double(Data&)>;

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			std::exit(0);
		}

		std::cin.clear();
		return true;
	}

	return false;
}

bool hasUnextractedInput()
{
	return ((!std::cin.eof()) && (std::cin.peek() != '\n'));
}

void getUserInputs(Data& x)
{
	double temp{};
	char holder{};
	while (true)
	{
		std::cout << "Enter your first integer: ";
		std::cin >> temp;
		if (clearFailedExtraction() || hasUnextractedInput())
		{
			ignoreLine();
			std::cout << "Invalid inputs!!! Please Retry!!!\n";
			continue;
		}
		x.setFirstNum(temp);
		break;
	}

	while (true)
	{
		std::cout << "Enter your second integer: ";
		std::cin >> temp;
		if (clearFailedExtraction() || hasUnextractedInput())
		{
			ignoreLine();
			std::cout << "Invalid inputs!!! Please Retry!!!\n";
			continue;
		}
		x.setSecondNum(temp);
		break;
	}

	while (true)
	{
		std::cout << "Enter your mathetical operation (+, -, *, /): ";
		std::cin >> holder;
		if (clearFailedExtraction() || hasUnextractedInput() || (holder != '*' && holder != '-' && holder != '/' && holder != '+'))
		{
			ignoreLine();
			std::cout << "Invalid inputs!!! Please Retry!!!\n";
			continue;
		}
		x.setOperation(holder);
		break;
	}
}

using ValidateFunction = std::function<double(Data&)>;

double add(Data& x)
{
	return x.getFirstNum() + x.getSecondNum();
}

double sub(Data& x)
{
	return x.getFirstNum() - x.getSecondNum();
}

double mult(Data& x)
{
	return x.getFirstNum() * x.getSecondNum();
}

double divi(Data& x)
{
	return x.getFirstNum() / x.getSecondNum();
}

ValidateFunction getArithmeticFunction(Data& x)
{
	switch (x.getOperation())
	{
	case '+':
		return &add;
	case '-':
		return &sub;
	case '*':
		return &mult;
	case '/':
		return &divi;
	default:
		return nullptr;
	}
}

int main()
{
	Data x{};
	getUserInputs(x);
	ValidateFunction y{ getArithmeticFunction(x) };
	std::cout << x.getFirstNum() << ' ' << x.getOperation() << ' ' << x.getSecondNum() << " = " << y(x) << '\n';
	return 0;
}