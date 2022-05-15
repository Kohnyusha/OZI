#include <iostream>
using namespace std;

int power(int a, int b, int n) { // a^b mod n
    int tmp = a;
    int sum = tmp;
    for (int i = 1; i < b; i++) {
        for (int j = 1; j < a; j++) {
            sum += tmp;
            if (sum >= n) {
                sum -= n;
            }
        }
        tmp = sum;
    }
    return tmp;
}

void rsa()
{
    int p = 17, q = 5, eiler, e = 3, n, h1 = 10, h2, c, d, s;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    n = p * q;
    eiler = (p - 1) * (q - 1);

    cout << "Произведение:" << n << endl;
    cout << "Функция Эйлера: " << eiler << endl;
    cout << "Открытая экспонента: " << e << endl;

    /* d = power(e, -1, eiler); */ d = 43;
    cout << "Секретная экспонента: " << d << endl;
    cout << "Открытый ключ: {" << e << ", " << n << "}" << endl;
    cout << "Закрытый ключ: {" << d << ", " << n << "}" << endl << endl;

    cout << "Число для зашифровки: " << h1 << endl;
    c = power(h1, e, n);//шифртекст

    cout << "Шифротекст: " << c << endl;
    cout << "Расшифровка: " << power(c, d, n) << endl; // c^d mod n

    s = power(h1, d, n); // h1^d mod n

    h2 = power(s, e, n); // s^e mod n, вычисление хеш-образа из цп
    if (h1 == h2)
    {
        cout << "Подпись правильная!" << endl;
    }
    else
    {
        cout << "Подпись некорректная" << endl;
    }
}

int main()
{
    int pulse;
    setlocale(LC_CTYPE, "Rus");
    rsa();
}