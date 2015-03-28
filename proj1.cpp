// this is a program to let users continue playing games if he wants
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    char FLAG;
    int array[3]={0};
    int i,a,b,c,gu_a,gu_b,gu_c,correct,wrong_dir,cor_times=0,wrong_times=0,total,times;     /*a,b,c为随机数，a_gu,b_gu,c_gu为猜测数，i为判定随机数是否重复的循环数*/
    cout << "请问您是否要进行游戏？输入Y表示继续。" << endl;
    cin >> FLAG;
    FLAG = toupper(FLAG);
    while(FLAG ==  'Y')              /* 判断是否要继续游戏*/
    {
        srand(time(NULL));
        a=rand()%10;
        while(true)                  /*生成无重复随机数*/
        {
            b=rand()%10;
            c=rand()%10;
            if ((a != b) && (a != c) && (b != c)) break;
        }
        times = 1;
        while(times <= 7)
        {

            correct = 0, wrong_dir = 0;
            cout << "请输入您猜测的三个数字：" << endl;
            cin >> gu_a >> gu_b >> gu_c;                /*储存玩家猜的数*/
            array[0] = gu_a;
            array[1] = gu_b;
            array[2] = gu_c;
            for(i=0;i<=2;i++)                           /*判断错位数数目*/
            {
                if (array[i] == a && i!=0) wrong_dir++;
                if (array[i] == b && i!=1) wrong_dir++;
                if (array[i] == c && i!=2) wrong_dir++;
            }
            if (array[0] == a) correct++;               /*判断正确数*/
            if (array[1] == b) correct++;
            if (array[2] == c) correct++;

            cout << correct << "A" << wrong_dir << "B" << endl;
            if (correct == 3)
            {
            	cor_times++;
                cout << "您已经成功，是否还要继续游戏？" << endl;
                cin >> FLAG;
                FLAG = toupper(FLAG);
                break;
            }
            else
            {
                if (times == 7)
                {
                	wrong_times++;
                    cout << "对不起，您已没有机会，正确答案为：" << a <<" " << b << " " << c << "\n" << "是否要重新开始游戏？" << endl;
                    cin >> FLAG;
                    FLAG = toupper(FLAG);
                    break;
                }
                else
                {
                    cout <<"猜测错误！这是您的第" << times << "次输入，请您继续猜测数字！" << endl;
                    times++;
                }

            }

        }

    }
    total = cor_times + wrong_times;
    cout << "您一共游戏了：" << total << "次，成功了" << cor_times << "次" << "失败了" << wrong_times << "次。";
    return 0;
}
