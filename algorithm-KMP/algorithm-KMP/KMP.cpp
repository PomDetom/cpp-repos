#include <iostream>
#include <string>
#include <chrono>

//计时器
class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
public:
	Timer()
	{
		start_time = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto end_time = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << duration << " μs (" << ms << " ms )\n";
	}
};

//暴力匹配法
int TraverseMatch(const std::string& main_string, const std::string& pattern_string)
{
	int main_string_size = (int)main_string.size();
	int pattern_string_size = (int)pattern_string.size();
	int front = 0;
	int i = 0;
	int j = 0;

	while (i < main_string_size && j < pattern_string_size)
	{
		if (main_string[i] == pattern_string[j])
		{
			++i;
			++j;
		}
		else
		{
			++front;
			i = front;
			j = 0;
		}
	}

	if (j == pattern_string_size)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}

//KMP
void InitNext(const std::string& pattern_string, int* next)
{
	next[0] = -1;
	int i = 0;
	int j = -1;
	int patter_string_size = (int)pattern_string.size();

	while (i < patter_string_size)
	{
		if (j == -1 || pattern_string[i] == pattern_string[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(const std::string& main_string, const std::string& pattern_string)
{
	int main_string_size = (int)main_string.size();
	int pattern_string_size = (int)pattern_string.size();
	int* next = new int[pattern_string_size + 1];
	InitNext(pattern_string, next);
	int i = 0;
	int j = -1;

	while (i < main_string_size && j < pattern_string_size)
	{
		if (j == -1 || main_string[i] == pattern_string[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == pattern_string_size)
		return i - j;
	else
		return -1;
}

//判断
void JudgeMatch(int judge)
{
	if (judge > 0)
		std::cout << "匹配成功，在主串的第" << judge << "位\n";
	else
		std::cout << "未在主串找到子串\n";
}

int main()
{
	std::string main_string = "ABACABABC";
	std::string pattern_string = "ABABC";

	std::cout << "主串为：";
	for (char value : main_string)
		std::cout << value;
	std::cout << "\n子串为：";
	for (char value : pattern_string)
		std::cout << value;
	std::cout << "\n";

	std::cout << "暴力算法：\n";
	{
		Timer time1;
		int ret = TraverseMatch(main_string, pattern_string) + 1;
		JudgeMatch(ret);
	}
	std::cout << "-----------------\n";
	std::cout << "KMP算法：\n";
	{
		Timer time2;
		int ret = KMP(main_string, pattern_string) + 1;
		JudgeMatch(ret);
	}

	return 0;
}