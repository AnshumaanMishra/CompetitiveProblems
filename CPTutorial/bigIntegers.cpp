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
            while(inputNum > 0){
                _mainNumber.push_back(inputNum % 10);
                _length++;
                inputNum /= 10;
            }
        }

        void set(int index, int value){
            _mainNumber[index] = value;
        }

        int getLength(){
            // return _mainNumber.size();
            return _length;
        }

        void setLength(int value){
            _length = value;
        }

        int operator[](int index){
            return _mainNumber[index];
        }

        BigInt operator+(BigInt _num2){
            int len1 = getLength();
            int len2 = _num2.getLength();
            if(len2 > len1){
                return (_num2 + *this);
            }
            // int maxLen = (len1 > len2) ? len1 : len2;
            BigInt answer = BigInt(0, len1 + 1);
            int carry = 0;
            int i;
            for(i = 0; i < len1; i++){
                // if(i >= len1 && i <= len2){
                //     answer.set(i, (_num2[i] + carry) % 10);
                //     carry = (_num2[i] + carry) / 10;    
                //     continue;
                // }
                if(i >= len2){
                    answer.set(i, (_mainNumber[i] + carry) % 10);
                    carry = (_mainNumber[i] + carry) / 10;
                }
                else{
                    answer.set(i, (_mainNumber[i] + _num2[i] + carry) % 10);
                    carry = (_mainNumber[i] + _num2[i] + carry) / 10;
                }
            }
            
            while(carry > 0){
                answer.set(i, carry % 10);
                carry /= 10;
                i++;
            }
            // answer.clean();
            return answer;
        }

        int* subtract(int digit1, int digit2, int borrow){
            int* result = new int[2 * sizeof(int)];
            *(result + 1) = 0;
            digit1 -= borrow;
            if(digit1 < 0){
                digit1 = 9;
                *(result + 1) = 1;
            }
            if(digit1 >= digit2 + borrow){
                *result = (digit1 - borrow) - digit2;
            }
            else{
                *result = 10 + digit1 - digit2;
                *(result + 1) = 1;
            }
            return result;
        }

        void push(int value){
            _mainNumber.push_back(value);
            _length++;
        }

        bool operator>(BigInt num2){
            if(getLength() < num2.getLength()){
                return false;
            }
            else if(getLength() > num2.getLength()){
                return true;
            }
            for(int i = 0; i < getLength(); i++){
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
            if(getLength() > num2.getLength()){
                return false;
            }
            else if(getLength() < num2.getLength()){
                return true;
            }
            for(int i = 0; i < getLength(); i++){
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
            if(getLength() != num2.getLength()){
                return false;
            }
            for(int i = 0; i < getLength(); i++){
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
            for(int i = 0; i < getLength(); i++){
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
            for(int i = 0; i < getLength(); i++){
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
            for(int i = 0; i < getLength(); i++){
                if(_mainNumber[i] != num2[i]){
                    return true;
                }
            }
            return false;
        }

        BigInt operator-(BigInt _num2){
            if(*this < _num2){
                BigInt temp = _num2 - *this;
                temp.push(-1);
                return temp;
            }
            int len1 = getLength();
            int len2 = _num2.getLength();
            int maxLen = (len1 > len2) ? len1 : len2;
            BigInt answer = BigInt(0, maxLen + 1);
            int borrow = 0;
            // cout << len1 << " " << len2 << " " << (len2 - len1) << endl;
            if(len2 < len1){
                for(int i = 0; i < (len1 - len2); i++){
                    _num2.push(0);
                }
            }
            _num2.push(0);
            // _num2.printNum();
            // cout << endl;
            for(int i = 0; i < maxLen; i++){
                // cout << i << ", " << _mainNumber[i] << ", " << _num2[i] << ", " << borrow << endl;
                int* result = subtract(_mainNumber[i],  _num2[i], borrow);
                // cout << "Result = " << *result << " Borrow = " << *(result + 1) << endl;
                answer.set(i, *result);
                borrow = *(result + 1);
            }
            // answer.clean();
            return answer;
        }

        BigInt operator*(int powerOf10){
            BigInt answer = BigInt(0, getLength() + powerOf10);
            for(int i = 0; i < getLength() + powerOf10; i++){
                if(i < powerOf10){
                    answer.set(i, 0);
                    continue;
                }
                answer.set(i, _mainNumber[i - powerOf10]);
            }
            answer.setLength(getLength() + powerOf10);
            // cout << "Multiplication" << endl;
            // answer.printNum();
            // answer.clean();
            return answer;
        }

        BigInt operator*(BigInt _num2){
            int len1 = getLength();
            int len2 = _num2.getLength();
            int maxLen = (len1 > len2) ? len1 : len2;
            BigInt answer = BigInt(0, len1 + len2);
            int carry = 0;
            int i, j;
            for(i = 0; i < len1; i++){
                int currentDigit = _mainNumber[i];
                BigInt currentRow = BigInt(0, len1 + 1);
                for(j = 0; j < len2; j++){
                    int currentInnerDigit = _num2[j];
                    // cout << currentDigit << " " << currentInnerDigit << " " << (currentInnerDigit * currentDigit + carry) % 10 << endl;
                    currentRow.set(j, (currentInnerDigit * currentDigit + carry) % 10);
                    carry = (currentInnerDigit * currentDigit + carry) / 10;
                }
                while(carry > 0){
                    currentRow.set(j, carry % 10);
                    carry /= 10;
                    j++;
                }
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
            for(int i = getLength()-1; i >= 0; i--){
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

        void clean(){
            int i = getLength() - 1;
            bool negative = _mainNumber[i] == -1;
            if(negative){
                _mainNumber.pop_back();
                i--;
            }
            while(_mainNumber[i] <= 0){
                _mainNumber.pop_back();
                i--;
            }
            if(negative){
                push(-1);
            }
        }

        friend ostream& operator<<(ostream& os, const BigInt& int1);
};

ostream& operator<<(ostream& os, BigInt& int1){
    int1.printNum();
    return os;
}

/*
BigInt bigFactorial(BigInt n){
    cout << n << endl;
    if(n == BigInt(1, 0)){
        return BigInt(1, 0);
    }
    BigInt smallFact = bigFactorial(n - BigInt(1, 0));
    // smallFact.clean();
    return n * smallFact;
}
*/

int main(){
    BigInt int1 = BigInt(999999999999, 0);
    BigInt int2 = BigInt(9999, 0);
    BigInt sum = int1 + int1;
    BigInt difference = int2 - int1;
    BigInt prodcut = int1 * int2;
    // cout << "Int1 = " << int1 << endl << "Int2 = " << int2 << endl;
    sum.printNum();
    difference.printNum();
    prodcut.printNum();
    // cout << "Sum = " << sum << endl << "Difference = " << difference << endl << "Product = " << prodcut << endl;
    // BigInt factorial = bigFactorial(int2);
    // cout << "exit" << endl;
    // cout << factorial << endl;
    // factorial.printNum();
    // cout << endl;

}