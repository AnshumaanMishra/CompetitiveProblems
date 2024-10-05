#include <bits/stdc++.h>
using namespace std;

class BigInt{
    private:
        vector<int> _mainNumber;
        int _length = 0;

    public:
        BigInt(long long int inputNum, int length){
            if((inputNum == 0) && (length != 0)){
                _length = length;
                vector<int> temp(length, 0);
                _mainNumber = temp;
            }
            else if(length == 0){
                _mainNumber = vector(0, 0);
            }
            else if(inputNum == 0){
                _mainNumber.push_back(0);
            }
            while(inputNum > 0){
                _mainNumber.push_back(inputNum % 10);
                _length++;
                inputNum /= 10;
            }
        }

        int getLength(){
            // return _mainNumber.size();
            return _mainNumber.size();
        }

        void setLength(int value){
            _length = value;
        }

        int operator[](int index){
            if(index >= getLength()){
                return 0;
            }
            return _mainNumber[index];
        }

        BigInt operator+(BigInt _num2){
            int len1 = getLength();
            int len2 = _num2.getLength();
            if(len2 > len1){
                return (_num2 + *this);
            }
            // int maxLen = (len1 > len2) ? len1 : len2;
            BigInt answer = BigInt(0, 0);
            int carry = 0;
            int i;
            for(i = 0; i < len1; i++){
                // if(i >= len1 && i <= len2){
                //     answer.set(i, (_num2[i] + carry) % 10);
                //     carry = (_num2[i] + carry) / 10;    
                //     continue;
                // }
                if(i >= len2){
                    answer.push((_mainNumber[i] + carry) % 10);
                    carry = (_mainNumber[i] + carry) / 10;
                }
                else{
                    answer.push((_mainNumber[i] + _num2[i] + carry) % 10);
                    carry = (_mainNumber[i] + _num2[i] + carry) / 10;
                }
            }
            
            while(carry > 0){
                answer.push(carry % 10);
                carry /= 10;
                i++;
            }
            // answer.clean();
            return answer;
        }

        void push(int value){
            _mainNumber.push_back(value);
            _length++;
        }

        void pop(){
            _mainNumber.pop_back();
        }

        bool operator>(BigInt num2){
            if(getLength() < num2.getLength()){
                return false;
            }
            else if(getLength() > num2.getLength()){
                return true;
            }
            for(int i = getLength() - 1; i >= 0; i--){
                if(_mainNumber[i] > num2[i]){
                    return true;
                }
                else if(_mainNumber[i] < num2[i]){
                    return false;
                }
            }
            return false;
        }

        bool operator<(BigInt num2){
            // int minlen = (getLength() > num2.getLength()) ? getLength() : num2.getLength();
            if(getLength() > num2.getLength()){
                return false;
            }
            else if(getLength() < num2.getLength()){
                return true;
            }
            for(int i = getLength() - 1; i >= 0; i--){
                if(_mainNumber[i] < num2[i]){
                    return true;
                }
                else if(_mainNumber[i] > num2[i]){
                    return false;
                }
            }
            return false;
        }

        bool operator==(BigInt num2){
            for(int i = getLength() - 1; i >= 0; i--){
                if(_mainNumber[i] != num2[i]){
                    return false;
                }
            }
            return true;
        }

        bool operator>=(BigInt num2){
            if(getLength() < num2.getLength()){
                return false;
            }
            else if(getLength() > num2.getLength()){
                return true;
            }
            for(int i = getLength() - 1; i >= 0; i--){
                if(_mainNumber[i] > num2[i]){
                    return true;
                }
                else if(_mainNumber[i] < num2[i]){
                    return false;
                }
            }
            return true;
        }

        bool operator<=(BigInt num2){
            if(getLength() > num2.getLength()){
                return false;
            }
            else if(getLength() < num2.getLength()){
                return true;
            }
            for(int i = getLength() - 1; i >= 0; i--){
                if(_mainNumber[i] < num2[i]){
                    return true;
                }
                else if(_mainNumber[i] > num2[i]){
                    return false;
                }
            }
            return true;
        }

        bool operator!=(BigInt num2){
            if(getLength() != num2.getLength()){
                return true;
            }
            for(int i = getLength() - 1; i >= 0; i--){
                if(_mainNumber[i] != num2[i]){
                    return true;
                }
            }
            return false;
        }

        int* subtract(int digit1, int digit2, int borrow){
            int* result = new int[2 * sizeof(int)];
            *(result + 1) = 0;
            digit1 -= borrow;
            if(digit1 < 0){
                digit1 = 9;
                *(result + 1) = 1;
            }
            // else{
            //     digit1 -= borrow;
            // }
            if(digit1 >= digit2){
                *result = (digit1) - digit2;
            }
            else{
                *result = 10 + digit1 - digit2;
                *(result + 1) = 1;
            }
            return result;
        }

        BigInt operator-(BigInt _num2){
            if(*this < _num2){
                BigInt temp = _num2 - *this;
                temp.push(-1);
                // temp.setLength(temp.getLength() + 1);
                return temp;
            }
            int len1 = getLength();
            int len2 = _num2.getLength();
            BigInt answer = BigInt(0, 0);
            int borrow = 0;
            // cout << len1 << " " << len2 << " " << (len2 - len1) << endl;
            // _num2.push(0);
            // _num2.printNum();
            // cout << endl;
            for(int i = 0; i < len1; i++){
                // cout << i << ", " << _mainNumber[i] << ", " << _num2[i] << ", " << borrow << endl;
                int* result = subtract(_mainNumber[i], _num2[i], borrow);
                // cout << "Result = " << *result << " Borrow = " << *(result + 1) << endl;
                answer.push(*result);
                borrow = *(result + 1);
            }
            // answer.clean();
            return answer;
        }

        BigInt operator*(int powerOf10){
            BigInt answer = BigInt(0, 0);
            for(int i = 0; i < getLength() + powerOf10; i++){
                if(i < powerOf10){
                    answer.push(0);
                    continue;
                }
                answer.push(_mainNumber[i - powerOf10]);
            }
            // answer.setLength(getLength() + powerOf10);
            // cout << "Multiplication" << endl;
            // answer.printNum();
            // answer.clean();
            return answer;
        }

        BigInt operator*(BigInt _num2){
            int len1 = getLength();
            int len2 = _num2.getLength();
            // int maxLen = (len1 > len2) ? len1 : len2;
            BigInt answer = BigInt(0, 0);
            int carry = 0;
            int i, j;
            for(i = 0; i < len1; i++){
                int currentDigit = _mainNumber[i];
                BigInt currentRow = BigInt(0, 0);
                for(j = 0; j < len2; j++){
                    int currentInnerDigit = _num2[j];
                    // cout << currentDigit << " " << currentInnerDigit << " " << (currentInnerDigit * currentDigit + carry) % 10 << endl;
                    currentRow.push((currentInnerDigit * currentDigit + carry) % 10);
                    carry = (currentInnerDigit * currentDigit + carry) / 10;
                }
                // printf("Infinite Loop Here Carry: %d, j = %d\n", carry, j);
                while(carry > 0){
                    // printf("Setting Carry: \n");
                    // currentRow.printWhole();
                    // printf("Carry: %d, j = %d\n", carry, j);
                    currentRow.push(carry % 10);
                    carry /= 10;
                    j++;
                }
                // printf("Current Row: ");
                // currentRow.printNum();
                // cout << endl;
                answer = answer + (currentRow * i);
                
                carry = 0;
            }
            // answer.clean();
            return answer;
        }

        

        void printNum(){
            bool leadingZero = true;
            for(int i = getLength() - 1; i >= 0; i--){
                // if((getLength() - 1 - i) % 3 == 0){
                //     printf(",");
                // }
                if(_mainNumber[i] == -1){
                    printf("-");
                    continue;
                }
                // cout << _mainNumber[i] << " " << (_mainNumber[i] > 0) << endl;
                if(_mainNumber[i] > 0){
                    leadingZero = false;
                }
                // cout << "Leading Zeroes: " << leadingZero << " CurrentDigit: " << _mainNumber[i] << endl;
                if(!leadingZero){
                    printf("%d", _mainNumber[i]);
                }
            }
            printf("\n");
        }

        void printWhole(){
            // cout << _mainNumber.size() << " " << getLength() << endl;
            for(int i = _mainNumber.size() - 1; i >= 0; i--){
                cout << _mainNumber[i];
            }
            cout << endl;
        }

        friend ostream& operator<<(ostream& os, const BigInt& int1);
};

ostream& operator<<(ostream& os, BigInt& int1){
    int1.printNum();
    return os;
}


BigInt bigFactorial(BigInt n){
    // cout << n << endl;
    BigInt one = BigInt(1, 0);
    if(n == one){
        return one;
    }
    return n * bigFactorial(n - BigInt(1, 0));
}

// BigInt bigFactorial(BigInt n){
//     BigInt product = BigInt(1, 0);
//     int i = 1;
//     while(1){
//         if(n == BigInt(1, 0)){
//             break;
//         }
//         product = product * n;
//         n = n - BigInt(1, 0);
//         i++;
//     }
//     return product;
// }


int main(){
    BigInt int1 = BigInt(100, 0);
    BigInt int2 = BigInt(1, 0);
    BigInt fact = bigFactorial(BigInt(300 , 0));
    fact.printNum();

}