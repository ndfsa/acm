#include <iostream>
#include <cmath>

void solve(int64_t *res, uint64_t *input);

bool test(int64_t *res, uint64_t *array);

double delta = 1e4;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int TEST_CASES;
    std::cin >> TEST_CASES;
    uint64_t array[1500];
    int64_t res[7];
    for (int i = 0; i < TEST_CASES; ++i) {
        for (int j = 0; j < 1500; ++j) {
            std::cin >> array[j];
        }
        solve(res, array);
        if (test(res, array)) {
            for (int j = 0; j < 6; ++j) {
                std::cout << res[j] << " ";
            }
            std::cout << res[6] << std::endl;
        }else{
            std::cout << "This is a smart sequence!" << std::endl;
        }
    }
    return 0;
}

bool test(int64_t *res, uint64_t *array) {
    double F_VALUE = 0;
    for (int i = 0; i < 7; ++i) {
        if (*(res + i) < 0 || *(res + i) > 1000) {
            return false;
        }
    }
    for (int i = 1; i <= 1500; ++i) {
        for (int j = 0; j < 7; ++j) {
            F_VALUE += *(res + j) * pow(i, j);
        }
        if (fabs(F_VALUE - ((double) *(array + i - 1))) > delta) {
            return false;
        } else {
            F_VALUE = 0;
        }
    }
    return true;
}

void solve(int64_t *res, uint64_t *input) {
    *(res) = 7 * input[0] - 21 * input[1] + 35 * input[2] - 35 * input[3] + 21 * input[4] -
             7 * input[5] + input[6];
    *(res + 1) = (-669 * input[0] + 2637 * input[1] - 4745 * input[2] + 4920 * input[3] -
                  3015 * input[4] + 1019 * input[5] - 147 * input[6]) / 60;
    *(res + 2) = (2552 * input[0] - 11787 * input[1] + 23340 * input[2] - 25450 * input[3] +
                  16080 * input[4] - 5547 * input[5] + 812 * input[6]) / 360;
    *(res + 3) = (-111 * input[0] + 568 * input[1] - 1219 * input[2] + 1408 * input[3] -
                  925 * input[4] + 328 * input[5] - 49 * input[6]) / 48;
    *(res + 4) = (59 * input[0] - 324 * input[1] + 741 * input[2] - 904 * input[3] +
                  621 * input[4] - 228 * input[5] + 35 * input[6]) / 144;
    *(res + 5) = (-9 * input[0] + 52 * input[1] - 125 * input[2] + 160 * input[3] -
                  115 * input[4] + 44 * input[5] - 7 * input[6]) / 240;
    *(res + 6) = (input[0] - 6 * input[1] + 15 * input[2] - 20 * input[3] + 15 * input[4] -
                  6 * input[5] + input[6]) / 720;
}
