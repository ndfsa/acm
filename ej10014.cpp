#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int lim;
    double n;
    double a0;
    double an1;
    double res = 0;
    std::cin >> lim;
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < lim; ++i) {
        std::cin >> n;
        std::cin >> a0;
        std::cin >> an1;
        double c = 0;
        for (double j = 1; j <= n; ++j) {
            std::cin >> c;
            res += (n - j + 1) * c;
        }
        res = ((n * a0) + an1 - (res * 2)) / (n + 1);
        if (res < 0) {
            res = round(res * 100) / 100;
        }
        std::cout << ((res < 0) ? "-" : "") << ((res < 0) ? -res : res) << ((i != lim - 1) ? "\n" : "") << std::endl;
        res = 0;
    }
    return 0;
}

