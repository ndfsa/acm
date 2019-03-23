#include <iostream>

long f91(long num);

int main(){
    std::ios_base::sync_with_stdio(false);
    long num;
    while(std::cin >> num){
        if (num == 0){
            break;
        }
        std::cout << "f91(" << num << ")" << " = " << f91(num) << std::endl;
    }
    return 0;
}

long f91(long num){
    if (num <= 100){
        return 91;
    }else{
        return num - 10;
    }
}
