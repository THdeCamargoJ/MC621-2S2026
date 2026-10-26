#include <iostream>
#include <vector>
#define PLUS         1
#define MINUS       -1


using namespace std;


class BigInt {
    private:
        vector<int> digits;
        int sign;

        void digit_shift(int shift) {
            if ((digits.size() == 1) && (digits[0] == 0)) {
                return;
            }

            for (int i = 0; i < shift; i++) {
                digits.insert(digits.cbegin(), 0);
            }
        }

        void zero_justify() {
            while ((digits.size() > 1) && (digits.back() == 0)) {
                digits.pop_back();
            }

            if ((digits.size() == 1) && (digits.back() == 0)) {
                sign = PLUS; // Avoid negative zero
            }
        }
        
    public:
        BigInt(string digitsArray) {
            if (digitsArray.length() == 0) {
                digits.push_back(0);
                sign = PLUS;
                return;
            }

            sign = digitsArray[0] == '-' ? MINUS : PLUS;
            for (int i = digitsArray.length() - 1; i >= (sign < 0 ? 1 : 0); i--) {
                digits.push_back(digitsArray[i] - '0');
            }
            zero_justify();
        }

        BigInt() {
            digits.push_back(0);
            sign = PLUS;
        }

        void print() {
            if (sign < 0) cout << '-';
            for (int i = digits.size() - 1; i >= 0; i--) cout << digits[i];
        }

        /**
         * @param b Some other BigInt 
         * @return 0 if equal, -1 if b is greater and 1 otherwise.
         */
        int compare(BigInt *b) {
            if ((sign == MINUS) && (b->sign == PLUS)) {
                return MINUS; /* b is greater than me */
            }

            if ((sign == PLUS) && (b->sign == MINUS)) {
                return PLUS; /* I am greater than b */
            }

            if (digits.size() > b->digits.size()) {
                /* I am greater than b (if my sign is PLUS) or 
                b is greater than me (if my sign is MINUS) */
                return PLUS * sign;
            }
            
            if (digits.size() < b->digits.size()) {
                /* b is greater than me (if my sign is PLUS) or 
                I am greater than b (if my sign is MINUS) */
                return MINUS * sign;
            }

            for (int i = digits.size() - 1; i >= 0; i--) {
                if (digits[i] > b->digits[i]) {
                    /* I am greater than b (if my sign is PLUS) or 
                    b is greater than a (if my sign is MINUS) */
                    return PLUS * sign;
                }
                if (b->digits[i] > digits[i]) {
                    /* b is greater than a (if my sign is PLUS) or 
                    I am greater than b (if my sign is MINUS) */
                    return MINUS * sign;
                }
            }

            return 0; /* a and b are equal */
        }

        BigInt *sub(BigInt *b) {
            int max_size, value, borrow = 0;

            if ((sign == MINUS) || (b->sign == MINUS)) {
                b->sign *= -1;
                add(b);
                b->sign *= -1;
                return this;
            }
            
            if (compare(b) < 0) {
                digits = (b->sub(this)->digits);
                sign = MINUS;
                return this;
            }

            max_size = max(digits.size(), b->digits.size());
            for (int i = 0; i <= max_size; i++) {
                if (i < digits.size() && i < b->digits.size()) {
                    value = digits[i] - b->digits[i] - borrow;
                } else if (i < digits.size()) {
                    value = digits[i] - borrow;;
                } else if (i < b->digits.size()) {
                    value = 0 - b->digits[i] - borrow;
                } else value = 0 - borrow;
                
                if (value < 0) {
                    value += 10;
                    borrow = 1;
                } else borrow = 0;

                if (i >= digits.size()) digits.push_back(value);
                else digits[i] = value;
            }

            zero_justify();
            return this;
        }

        BigInt *add(BigInt *b) {
            int max_size, value, carry = 0;

            if (sign != b->sign) {
                if (sign == MINUS) {
                    sign = PLUS;
                    digits = b->sub(this)->digits;
                    sign = MINUS;
                } else {
                    b->sign = PLUS;
                    sub(b);
                    b->sign = MINUS;
                }
                return this;
            }

            max_size = max(digits.size(), b->digits.size());
            for (int i = 0; i <= max_size; i++) {
                if (i < digits.size() && i < b->digits.size()) {
                    value = carry + digits[i] + b->digits[i];
                } else if (i < digits.size()) {
                    value = carry + digits[i];
                } else if (i < b->digits.size()) {
                    value = carry + b->digits[i];
                } else value = carry;

                if (i >= digits.size()) digits.push_back(value % 10);
                else digits[i] = value % 10;
                carry = value / 10;
            }

            zero_justify();
            return this;

        }

        BigInt *mul(BigInt *b) {
            BigInt result = BigInt(),
                   shift_row = *this,
                   partial;

            shift_row.sign = PLUS;
            for (int i = 0; i < b->digits.size(); i++) {
                partial = shift_row;
                for (int j = 1; j < b->digits[i]; j++) {
                    partial.add(&shift_row);
                }
                result.add(&partial);
                shift_row.digit_shift(1);
            }

            digits = result.digits;
            sign = sign * b->sign;
            zero_justify();
            return this;
        }

        BigInt *div(BigInt *b) {
            BigInt shift_row = BigInt();
            int origSign = sign,
                origBSign = b->sign;
            
            sign = PLUS;
            b->sign = PLUS;

            for (int i = digits.size() - 1; i >= 0; i--) {
                shift_row.digit_shift(1);
                shift_row.digits[0] = digits[i];
                digits[i] = 0;
                while (shift_row.compare(b) >= 0) {
                    digits[i]++;
                    shift_row.sub(b);
                }
            }
            
            sign = origBSign * origSign;
            b->sign = origBSign;
            zero_justify();
            return this;
        }

        BigInt *mod(BigInt *b) {
            BigInt quotient, product;

            if (compare(b) < 0) return this;

            quotient = *this;
            product = *quotient.div(b);
            sub(product.mul(b));
            return this;
        }
};


int main() {
    // Optimize standard I/O operations for speed (prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nItems, nFriends, bill = 1;
    BigInt bill_cost, item_cost, n;
    string input;

    while (true) {
        cin >> nItems;
        cin >> nFriends;

        if (nItems == nFriends && nItems == 0) return 0;

        bill_cost = BigInt();

        cout << "Bill #" << bill++ << " costs ";

        for (int i = 0; i < nItems; i++) {
            cin >> input;
            item_cost = BigInt(input);
            bill_cost.add(&item_cost);
        }

        bill_cost.print();

        cout << ": each friend should pay ";

        n = BigInt(to_string(nFriends));
        bill_cost.div(&n);

        bill_cost.print();

        cout << "\n\n";
    }

    return 0;
}