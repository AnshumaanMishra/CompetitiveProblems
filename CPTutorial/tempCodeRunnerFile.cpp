hile(carry > 0){
                answer.set(j, carry % 10);
                carry /= 10;
                i++;
            }