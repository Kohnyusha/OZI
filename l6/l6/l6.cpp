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

int mul(int a, int b, int n) { // a*b mod n
    int sum = 0;

    for (int i = 0; i < b; i++) {
        sum += a;

        if (sum >= n) {
            sum -= n;
        }
    }

    return sum;
}

void rsa()
{
    int p, q, eiler, e, n, m, c;
    double d;
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите простое число q: ";
    cin >> q;
    cout << "Введите открытую экспоненту е: ";
    cin >> e;
    n = p * q;
    eiler = (p - 1) * (q - 1);
    cout << "Произведение: " << n << endl;
    cout << "Функция Эйлера: " << eiler << endl;
    d = power(e, -1, eiler);
    cout << "Секретная экспонента: " << d << endl;
    cout << "Открытый ключ: {" << e << ", " << n << "}" << endl;
    cout << "Закрытый ключ: {" << d << ", " << n << "}" << endl << endl;

    cout << "Введите число для зашифровки: ";
    cin >> m;
    c = power(m, e, n);
    cout << "Шифротекст: " << c << endl << endl;

    cout << "Расшифровка: " << power(c, d, n);
}

void diffie()
{
    int p, g, a = 6, b = 15;
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите простое число g, которое меньше " << p << "): ";
    cin >> g;
    cout << "Секретный ключ Алисы: " << a << endl;
    cout << "Секретный ключ Боба: " << b << endl;
    cout << "Открытый ключ Алисы: " << power(g, a, p) << endl;
    cout << "Открытый ключ Боба: " << power(g, b, p) << endl;
    cout << "Общий секретный ключ (по Алисе): " << power(power(g, b, p), a, p) << endl;
    cout << "Общий секретный ключ (по Бобу): " << power(power(g, a, p), b, p) << endl;
}

void elgamal()
{
    int M, M1, p, g, x, y, k, a, b;
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите случайный примитивный элемент g: ";
    cin >> g;
    cout << "Введите случайное целое число х (1 < x < " << p - 1 << "): ";
    cin >> x;
    y = power(g, x, p);
    cout << "Открытый ключ: тройка (" << p << ", " << g << ", " << y << ")" << endl;
    cout << "Закрытый ключ: " << x << endl;

    cout << "Введите число для шифрования: ";
    cin >> M;
    cout << "Введите сессионный ключ (1 < k < " << p - 1 << "): ";
    cin >> k;
    a = power(g, k, p);
    b = mul(power(y, k, p), M, p);
    cout << "Шифротекст: пара (а, b) = (" << a << ", " << b << ")" << endl << endl;
    M1 = mul(b, power(a, p - 1 - x, p), p);
    cout << "Расшифровка: " << M1;
}


int main()
{
    int pulse;
    setlocale(LC_CTYPE, "Rus");
    do
    {
        cout << endl << "Выберите тип шифровки:" << endl;
        cout << "1) RSA" << endl;
        cout << "2) Диффи-Хеллман" << endl;
        cout << "3) Эль-Гамаль" << endl;
        cout << "4) Выход" << endl;
        cout << "-------------------------------" << endl;
        cin >> pulse;
        switch (pulse)
        {
        case 1: rsa(); break;
        case 2: diffie(); break;
        case 3: elgamal();  break;
        case 4: break;
        }
    } while (pulse != 4);
}