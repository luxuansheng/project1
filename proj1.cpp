// this is a program to let users continue playing games if he wants
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    char FLAG;
    int array[3]={0};
    int i,a,b,c,gu_a,gu_b,gu_c,correct,wrong_dir,cor_times=0,wrong_times=0,total,times;     /*a,b,cΪ�������a_gu,b_gu,c_guΪ�²�����iΪ�ж�������Ƿ��ظ���ѭ����*/
    cout << "�������Ƿ�Ҫ������Ϸ������Y��ʾ������" << endl;
    cin >> FLAG;
    FLAG = toupper(FLAG);
    while(FLAG ==  'Y')              /* �ж��Ƿ�Ҫ������Ϸ*/
    {
        srand(time(NULL));
        a=rand()%10;
        while(true)                  /*�������ظ������*/
        {
            b=rand()%10;
            c=rand()%10;
            if ((a != b) && (a != c) && (b != c)) break;
        }
        cout << a << b << c;
        times = 1;
        while(times <= 7)
        {

            correct = 0, wrong_dir = 0;
            cout << "���������²���������֣�" << endl;
            cin >> gu_a >> gu_b >> gu_c;                /*������Ҳµ���*/
            array[0] = gu_a;
            array[1] = gu_b;
            array[2] = gu_c;
            for(i=0;i<=2;i++)                           /*�жϴ�λ����Ŀ*/
            {
                if (array[i] == a && i!=0) wrong_dir++;
                if (array[i] == b && i!=1) wrong_dir++;
                if (array[i] == c && i!=2) wrong_dir++;
            }
            if (array[0] == a) correct++;               /*�ж���ȷ��*/
            if (array[1] == b) correct++;
            if (array[2] == c) correct++;

            cout << correct << "A" << wrong_dir << "B" << endl;
            if (correct == 3)
            {
            	cor_times++;
                cout << "���Ѿ��ɹ����Ƿ�Ҫ������Ϸ��" << endl;
                cin >> FLAG;
                FLAG = toupper(FLAG);
                break;
            }
            else
            {
                if (times == 7)
                {
                	wrong_times++;
                    cout << "�Բ�������û�л��ᣬ��ȷ��Ϊ��" << a <<" " << b << " " << c << "\n" << "�Ƿ�Ҫ���¿�ʼ��Ϸ��" << endl;
                    cin >> FLAG;
                    FLAG = toupper(FLAG);
                    break;
                }
                else
                {
                    cout <<"�²�����������ĵ�" << times << "�����룬���������²����֣�" << endl;
                    times++;
                }

            }

        }

    }
    total = cor_times + wrong_times;
    cout << "��һ����Ϸ�ˣ�" << total << "�Σ��ɹ���" << cor_times << "��" << "ʧ����" << wrong_times << "�Ρ�";
    return 0;
}
