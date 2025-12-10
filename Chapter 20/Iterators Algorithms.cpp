#include <iostream>
#include <vector>
#include <ranges>
//fibonacci one
int main()
{
	std::size_t fibNum{ 0 };
	std::vector<int> results{ 0,1 };

	for (int x{ 2 }; x < 13; ++x)
	{
		fibNum = results[(x - 1)] + results[(x - 2)];
		results.push_back(fibNum);
	}

	for (const auto& a : results)
		std::cout << a << ' ';
	return 0;
}
//binary convert one
int main()
{
	int x{ -15 };
	unsigned int y{ static_cast<unsigned int>(x) };
	std::vector<bool> result{};
	while (y > 1)
	{
		result.push_back(y % 2);
		y /= 2;
	}

	for (auto x : std::ranges::reverse_view(result))
	{
		std::cout << x;
	}

	return 0;
}
//add all nums one
int main()
{
	int x{ 93427 };
	int result{ 0 };
	while (x > 0)
	{
		result += (x % 10);
		x /= 10;
	}

	std::cout << result;
}
//factorial one
int main()
{
	int x{ 5 };
	int result{ 1 };
	for (int i{ 1 }; i < x + 1; ++i)
	{
		result *= i;
	}
	std::cout << result;
}