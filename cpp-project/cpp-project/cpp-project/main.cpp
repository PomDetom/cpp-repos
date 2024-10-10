#include "pch.h"

//Test1.函数
int Multiply(int a, int b)
{
	return a * b;
}

void MultiplyAndlog(int a, int b)
{
	std::cout << Multiply(a, b) << std::endl;
}

void Test1()
{
	int TestRet1 = Multiply(5, 6);
	std::cout << TestRet1 << std::endl;
	MultiplyAndlog(5, 6);
}
//
// 
//Test2.string类
void Test2()
{
	std::string ExpStr1 = "Hello ";
	std::string ExpStr2 = "World!";
	std::string Result = ExpStr1 + ExpStr2;
	//相加
	std::cout << "ExpStr1 + ExpStr2 = " << Result << std::endl;
	//长度
	std::cout << "Result长度为：" << Result.size() << std::endl;
	//查找
	std::cout << "查找World：" << Result.find("World") << std::endl;
	//替换
	std::string::size_type pos = Result.find("World");
	if (pos != std::string::npos)
	{
		Result.replace(pos, 5, "cpp");
	}
	std::cout << "替换World为cpp：" << Result << std::endl;
}
//
// 
//Test3.Vector容器
void Test3()
{
	std::vector<int> myVector1(4);//(4)优化
	std::vector<int> myVector2 = { 1, 2, 3, 4 };

	myVector1.push_back(1);
	myVector1.push_back(2);
	myVector1.push_back(3);
	myVector1.push_back(4);
	std::cout << "myVector1：";
	for (int element : myVector1)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << "myVector1元素数量：" << myVector1.size() << std::endl;
	
	myVector2.erase(myVector2.begin() + 1);
	std::cout << "myVector2删除第二个元素：";
	for (int element : myVector2)
	{
		std::cout << element << " ";
	}

	myVector1.clear();//清空
}
//
// 
//Test4.类
class Vehicle
{
public:
	std::string brand;
	std::string type;
	int price = 0;
public:
	virtual void charge() = 0;
public:
	void setBrand(std::string brand)
	{
		this->brand = brand;
	}
	void setPrice(int price)
	{
		this->price = price;
	}
};

class OilVehicle : public Vehicle
{
public:
	//构造函数
	OilVehicle()
	{
		brand = "NULL";
		type = "Oil";
	}
	OilVehicle(const std::string brand, int price)
	{
		type = "Oil";
		this->brand = brand;
		this->price = price;
	}

public:
	void charge()
	{
		std::cout << "加油" << std::endl;
	}
};

class MotorVehicle : public Vehicle
{
public:
	//构造函数
	MotorVehicle()
	{
		brand = "NULL";
		type = "Motor";
	}
	MotorVehicle(const std::string brand, int price)
	{
		type = "Motor";
		this->brand = brand;
		this->price = price;
	}

public:
	void charge()
	{
		std::cout << "充电" << std::endl;
	}
};

void Test4()
{
	OilVehicle Dazhong;
	std::cout << Dazhong.price << std::endl;
	Dazhong.setPrice(1000000);
	std::cout << "品牌：" << Dazhong.brand << " 价格：" << Dazhong.price << std::endl;
	Dazhong.charge();

	MotorVehicle Xiaomi("Xiaomi Su7", 299999);
	std::cout << "品牌：" << Xiaomi.brand << " 价格：" << Xiaomi.price << " 种类：" << Xiaomi.type << std::endl;
	Xiaomi.charge();
}
//
//
//Test5.关键词
//const, mutable, new, this, explicit,auto
class expClass
{
public:
	int a = 0;
private:
	std::string expchar1;
	mutable std::string expchar2;
	char* expchar3 = new char[10];
public:
	const char* expFunc(const char (&a)[10], const char* b)const
	{
		//expchar1 = a;
		expchar2 = a;
		return b;
	}

	explicit expClass(int a)
	{
		this->a = a;
		std::cout << "Created expClass!" << std::endl;
	}

	expClass(char* expchar, std::string expchar1)
		:expchar3(expchar) {}

	~expClass()
	{ 
		std::cout << "Destoryed expClass!" << std::endl;
		delete expchar3;
	}
};

void PringClass(const expClass& expClass)
{
	std::cout << expClass.a << std::endl;
}

void expAuto()
{
	std::array<int, 5> expArray = { 1, 2, 3, 4, 5 };
	
	for (int i = 0; i < expArray.size(); i++)
	{
		std::cout << expArray[i] << " ";
	}
	std::cout << "\n";
	for (const auto& value : expArray)
	{
		std::cout << value << " ";
	}
}

void Test5()
{
	//PringClass(expClass(100));
	//PringClass(100);
	//expClass a = 2;
	expAuto();
}
//
//
// Test6.智能指针
class Entity
{
public:
	Entity() 
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destoryed Entity!" << std::endl;
	}
};

void Test6()
{
	{
		//std::shared_ptr<Entity>expEntity4;
		std::weak_ptr<Entity>expEntity5;
		{
			//std::unique_ptr<Entity>expEntity1 = new Entity(); explicit
			//std::unique_ptr<Entity>expEntity1(new Entity());// 不好
			//std::unique_ptr<Entity>expEntity2 = std::make_unique<Entity>();

			std::shared_ptr<Entity>expEntity3 = std::make_shared<Entity>();
			//expEntity4 = expEntity3;
			expEntity5 = expEntity3;
		}
		std::cout << "中" << std::endl;
	}
}
//
//
//Test7.复制拷贝构造函数
class Rect
{
public:
	Rect()
	{
		count++;
	}
	~Rect()
	{
		count--;
	}
	Rect(const Rect& a)
	{
		height = a.height;
		width = a.width;
		count++;
	}
	Rect(int height)
	{
		this->height = height;
	}
	static int getCount()
	{
		return count;
	}
private:
	int width{};
	int height{};
	static int count;
};

int Rect::count = 0;

void Test7()
{
	Rect rect1;
	std::cout << "The count of Rect:" << Rect::getCount() << std::endl;
	Rect rect2(rect1);
	std::cout << "The count of Rect:" << Rect::getCount() << std::endl;
}
//
//
//Test8.template
template<typename T>
void PrintT(T values)
{
	std::cout << values << std::endl;
}

void Test8()
{
	int a = 10;
	char b = 'p';
	std::string expString = "abcd";

	PrintT(a);
	PrintT(b);
	PrintT(expString);
}
//
//
//Test9.迭代器iterator
void Test9()
{
	std::vector<std::string> expVector;
	expVector.push_back("one");
	expVector.push_back("two");

	for (std::vector<std::string>::iterator it = expVector.begin();
		it != expVector.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	//auto
	for (auto it = expVector.begin(); it != expVector.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
//
//
//Test10.lambda
void expLambda(const std::vector<std::string> expVector,
				const std::function<void(std::string)>& funcPrint)
{
	for (auto it = expVector.begin(); it != expVector.end(); it++)
	{
		funcPrint(*it);
	}
}

void Test10()
{
	std::string expString("Test10");
	std::vector<std::string> expVector;
	expVector.push_back("one");
	expVector.push_back("two");
	expLambda(expVector, [&](std::string value) { std::cout << expString << value << std::endl; });
}
//
//
//Test11.线程
static bool s_finished = false;

void T1()
{
	std::cout << "请输入密码" << std::endl;
	std::cin.get();
	s_finished = true;
}

void T2()
{
	using namespace std::literals::chrono_literals;

	while (!s_finished)
	{
		std::this_thread::sleep_for(2s);
		std::cout << "请输入\n";
	}
}

void Test11()
{
	std::thread t1(T1);
	T2();
	t1.join();
}
//
//
//Test12.计时
struct chrono
{
	std::chrono::time_point<std::chrono::steady_clock> begin{};
	std::chrono::duration<float> duration{};
	
	chrono()
	{
		begin = std::chrono::high_resolution_clock::now();
	}

	~chrono()
	{
		duration = std::chrono::high_resolution_clock::now() - begin;
		float time = duration.count() * 1000.0f;

		std::cout << "duration: " << time << "ms" << std::endl;
	}
};

void Hello1()
{
	chrono timer1;
	for (int i = 0; i < 100; i++)
		std::cout << "Hello World\n";
}

void Hello2()
{
	chrono timer2;
	for (int i = 0; i < 100; i++)
		std::cout << "Hello World" << std::endl;
}

void Test12()
{
	Hello1();
	//Hello2();
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	//Test11();
	//Test12();

	return 0;
}