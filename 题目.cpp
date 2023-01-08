#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<string>
#include<random>

using namespace std;

long long int mu = 0, shi = 0, ming = 0, qu = 0, k = 10, kuang = 0, gongzi = 0, lidu = 1, mign = 0, fa = 0, gongzhi = 0, liduu = 1;
double qian = 50000, shui = 50, li = 0, min = 0;
/*
mu=木材总数 shi=石料总数 ming=居民总数 qu=几块居民区 k=一块居民区可容纳的人
qian=钱总数  li=盈利  shui=居民税收  kuang=矿工  gongzi=矿工总工资  lidu=矿工开采力度
mign=没有职业的居民 fa=伐木工人总数 gongzhi=伐木工人工资  liduu=伐木工力度
*/
int times = 2000, n, a = 0, b = 0, c = 0, d = 0, kuangong = 0, qew, famugong = 0;//a=树林 b=水面积 c=石头 d=可建设用地 
string name;

string sj()
{
	string a = "0000000000000";

	for (int i = 1; i <= 13; i++)
	{
		int min = 1, max = 4;
		random_device seed;//硬件生成随机数种子
		mt19937_64 engine(seed());//利用种子生成随机数引擎,算法mt19937_64
		uniform_int_distribution<> distrib(min, max);//设置随机数范围，并为均匀分布
		a[i - 1] = (char)(distrib(engine) + '0');
	}

	return a;
}

int f(string a, char b)
{
	int sum = 0;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b)
		{
			sum++;
		}
	}

	return sum;
}

void printf_red(const char* s)
{
	printf("\033[0m\033[1;31m%s\033[0m", s);
}

int main() {
	cout<<"很高兴能在此认识您(回车继续)";
	getchar();
	cout << "请问您贵姓：";
	cin >> name;
	cout << "因您德高望重，才华出众，中央决定将您任命为市长";
	getchar();
	cout << "恭喜您啊" << name << "市长";
	getchar();
	string d1 = sj(), d2 = sj(), d3 = sj(), d4 = sj();
	cout << endl << "请选择您想去的地形建城市" << endl;
	cout << "1:树林 2:石头 3:水 4:草地" << endl;
	cout << "第一种:" << d1 << endl;
	cout << "第二种:" << d2 << endl;
	cout << "第三种:" << d3 << endl;
	cout << "第四种:" << d4 << endl;
	cout << "请输入1234此序号代表你选择的地形：";
	while (true)
	{
		cin >> n;
		if (!cin)
		{
			cout << "您输的数据不合法，请输入数字：";
			cin.clear();
			cin.ignore();
		}
		if (n >= 1 && n <= 4)
		{
			cout << endl;
			break;
		}
	}
	a = f(d1, '1');
	b = f(d2, '2');
	c = f(d3, '3');
	d = f(d4, '4');

	n = 999;

	cout << "钱初始值为50000 如果钱小于-20000视为破产游戏自动失败";
	getchar();
	cout << "一个居民每回合税收为5元(税收一开始初始值为50%)";
	getchar();
	cout << "可以将您的居民职业调为矿工  矿工可以增加石料 但是要扣除相应的工资";
	getchar();
	cout << "输入666结束游戏";
	getchar();
	cout << "不管哪个功能只要是输入0就跳出那个功能";
	getchar();
	cout << "好的让我们正式开始吧!";
	getchar();
	printf_red("\n接下来屏幕会闪烁两次（2-3秒），请在灯光明亮处观看，或闭上眼睛，防止出现光敏性癫痫，准备好后请敲击回车");
	getchar();

	for (int j = 1; j <= 2; j++)
	{
		system("color fe");//白色
		_sleep(500);
		system("color 7");//黑色
		_sleep(500);
	}

	while (true)
	{
		cout << endl;
		li = ming * (shui / 10) - gongzi - gongzhi;//利润 
		qian += li;
		cout << "木材=" << mu + a * 5 << "(每回合效率为" << fa * liduu * 100 - qu * 100 - kuang * 200 << ")" << "     ";
		cout << "石料=" << shi + c * 5 << "(每回合效率为" << kuang * lidu * 100 - qu * 50 - fa * 300 << ")" << endl;
		cout << "钱=" << qian << "(每回合盈利为" << li << ")" << endl;
		cout << "选择您本回合要做的事务:" << endl;
		cout << "输入0下一个回合" << endl;
		cout << "1:居民  2:采石场  3:伐木场  4:水资源  5:交易市场  6:银行" << endl;
		gongzi = kuang * 50 * lidu / 10; //矿工工资 
		gongzhi = fa * 50 * liduu / 10;//伐木工工资 
		mu -= kuang * 200;//矿工每回合消耗的木材 
		shi -= fa * 300;//伐木工每回合消耗的石料 
		mu -= qu * 100;//居民区维护费 
		shi -= qu * 50;//居民区维护费  
		mu += fa * liduu * 100;//伐木工砍树总量 
		shi += kuang * lidu * 100;//矿工采矿总量 
		mign = ming - kuang - fa;//没职业的居民 
		cin >> n;
		if (n == 1)
		{
			cout << "您拥有" << ming << "居民" << endl;
			cout << "您拥有" << d << "块可建设用地" << endl;
			cout << "您拥有" << qu << "块居民区    " << "您的居民区一块可容纳" << k << "个人" << endl;
			cout << "一块居民区每回合维护费为木材100 石料50" << endl;
			while (true)
			{
				cout << "1:增加居民区 2:升级居民区 3:调整税收" << endl;
				int j, kl = 0;
				string yuanyi;
				cin >> j;
				if (j == 0)
				{
					break;
				}
				if (j == 1)
				{
					cout << "您需要增加几个居民区 一个居民区100元 需要石料200 木材500" << endl;
					cin >> kl;
					qian -= kl * 100;
					shi -= kl * 200;
					mu -= kl * 500;
					qu += kl;
					d -= qu;
					cout << "您的居民区已增加完成" << endl;
				}
				if (j == 2)
				{
					cout << "升级一次居民区需要扣除 您拥有的居民区*120元 石料*1000 木材*1500" << endl;
					cout << "您是否愿意(输入是或否)" << endl;
					cin >> yuanyi;
					if (yuanyi == "是") {
						qian -= qu * 120;
						shi -= qu * 1000;
						mu -= qu * 1500;
						k += 10;
						cout << "您已升级居民区";
					}
				}
				if (j == 3)
				{
					int y = 0;
					cout << "当前税收为" << shui << "%" << endl;
					cout << "您要把税调到多少 只能调至10%到200%" << endl;
					cin >> shui;
					if (shui < 10 || shui>200)
					{
						cout << "此次调税无效 税收调为50%" << endl;
						shui = 50;
					}
					else cout << "调税成功" << endl;
				}
			}
			if (ming < qu * k)
			{
				ming += 10;
			}
		}
		if (n == 666)
		{
			break;
		}
		if (n == 2)
		{
			cout << "您现拥有石料" << shi << "   " << "效率为" << kuang * lidu * 100 - qu * 50 - fa * 300 << endl;
			cout << "您现拥有矿工" << kuang << "   ";
			cout << "您的矿工总工资为" << gongzi << endl;
			cout << "一个矿工每回合消耗200个木材" << endl;
			while (true)
			{
				cout << "1:增减矿工 2:开采力度";
				cin >> qew;
				string yuan;
				if (qew == 1)
				{
					cout << "您需要增加还是减少矿工(是=增加  否=减少)(矿工工资一人:每回合50元)" << endl;
					cin >> yuan;
					if (yuan == "是")
					{
						cout << "您需要增加几个矿工(0<=增加矿工数<=还没有职业的居民)" << endl;
						cin >> kuangong;
						if (kuangong >= 0 && kuangong <= mign)
						{
							kuang += kuangong;
							cout << "增加成功" << endl;
						}
						else
						{
							cout << "增加失败" << endl;
						}
					}
					if (yuan == "否")
					{
						cout << "您需要减少几个矿工(0<=减少矿工数<=矿工总数)" << endl;
						cin >> kuangong;
						if (kuangong >= 0 && kuangong <= kuang)
						{
							kuang -= kuangong;
							cout << "减少成功" << endl;
						}
						else
						{
							cout << "减少失败" << endl;
						}
					}
				}
				if (qew == 2)
				{
					cout << "您当前开采力度为" << lidu << endl;
					cout << "您调整开采的力度为(1到5)初始值为1" << endl;
					cout << "力度越高工资越高";
					cin >> lidu;
					if (lidu >= 1 && lidu <= 5)
					{
						cout << "调整成功" << endl;
					}
					else
					{
						lidu = 1;
						cout << "调整失败" << endl;
					}
				}
				if (qew == 0)
				{
					break;
				}
			}
		}
		if (n == 3)
		{
			cout << "您现拥有木材" << mu << "   " << "效率为" << fa * liduu * 100 - qu * 100 - kuang * 200 << endl;
			cout << "您现拥有伐木工" << fa << "   ";
			cout << "您的伐木工总工资为" << gongzhi << endl;
			cout << "一个矿工每回合消耗300个石料" << endl;
			while (true)
			{
				cout << "1:增减伐木工 2:开采力度";
				cin >> qew;
				string yuan;
				if (qew == 1)
				{
					cout << "您需要增加还是减少伐木工(是=增加  否=减少)(伐木工工资一人:每回合50元)" << endl;
					cin >> yuan;
					if (yuan == "是")
					{
						cout << "您需要增加几个伐木工(0<=增加矿工数<=还没有职业的居民)" << endl;
						cin >> famugong;
						if (famugong >= 0 && famugong <= mign)
						{
							fa += famugong;
							cout << "增加成功" << endl;
						}
						else
						{
							cout << "增加失败" << endl;
						}
					}
					if (yuan == "否")
					{
						cout << "您需要减少几个伐木工(0<=减少矿工数<=矿工总数)" << endl;
						cin >> famugong;
						if (famugong >= 0 && famugong <= fa)
						{
							fa -= famugong;
							cout << "减少成功" << endl;
						}
						else
						{
							cout << "减少失败" << endl;
						}
					}
				}
				if (qew == 2)
				{
					cout << "您当前开采力度为" << liduu << endl;
					cout << "您调整开采的力度为(1到5)初始值为1" << endl;
					cout << "力度越高工资越高";
					cin >> liduu;
					if (liduu >= 1 && liduu <= 5)
					{
						cout << "调整成功" << endl;
					}
					else
					{
						liduu = 1;
						cout << "调整失败" << endl;
					}
				}
				if (qew == 0)
				{
					break;
				}
			}
		}
		if (qian <= -20000)
		{
			printf_red("您的资金小于-20000，已视为您破产，程序将于五秒后自动关闭!");
			_sleep(5000);
			exit(1);
		}
	}
}
