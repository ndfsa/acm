#include <iostream>
#include <set>

int gcd(int a, int b);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int dir = 0;
    int n = 0;
    int d = 0;
    int g = 0;

    int cont = 0;
    const int lim = 510005;

    int16_t num[lim] = {};
    int16_t den[lim] = {};

    std::pair<int16_t , int16_t > pair;
    std::set<std::pair<int16_t , int16_t >> set;

    for (int i = 1; cont < lim; ++i) {
        dir = (i % 2 == 0) ? -1 : 1;
        for (int j = 0; j < i; ++j) {
            if (cont >= lim)break;
            n += dir;
            if (d != 0) {
                g = gcd((d < 0) ? ~d+1 : d, (n < 0) ? ~n+1 : n);
                if (d > 0) {
                    pair = std::make_pair(n / g, d / g);
                } else {
                    pair = std::make_pair(-n / g, -d / g);
                }
                if (set.find(pair) == set.end()) {
                    set.insert(pair);
                    num[cont] = pair.first;
                    den[cont] = pair.second;
                    cont++;
                }
            }
        }

        for (int j = 0; j < i; ++j) {
            d += dir;
            if (cont >= lim)break;
            if (d != 0) {
                g = gcd((d < 0) ? ~d+1 : d, (n < 0) ? ~n+1 : n);
                if (d > 0) {
                    pair = std::make_pair(n / g, d / g);
                } else {
                    pair = std::make_pair(-n / g, -d / g);
                }
                if (set.find(pair) == set.end()) {
                    set.insert(pair);
                    num[cont] = pair.first;
                    den[cont] = pair.second;
                    cont++;
                }
            }
        }
    }
    int get = 0;
    while (std::cin >> get) {
        std::cout << num[get] << " / " << den[get] << std::endl;
    }

    return 0;
}

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}


