class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0 ? true : false;
        unsigned int ux = x < 0 ? -(unsigned int)x : (unsigned int)x;
        unsigned int res = 0;
        while (ux != 0) {
            unsigned int shang = ux/ 10;
            unsigned int yu = ux%10;
            unsigned int temp = res * 10 + yu;
            if (temp < res || res != (temp -yu)/10) return 0;
            else res = temp;
            cout << res << ", ";
            ux = shang;
        }
        if ((res > ((1U<<31) - 1) && !neg) || (res > (1U<<31) && neg)) return 0; 
        return neg ? -1 * res : res; 
    }
};