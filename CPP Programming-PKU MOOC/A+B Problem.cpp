#include <iostream>
using namespace std;

/**
 * A+B Problem
 *
 * Description:
 * Calculate a+b
 *
 * Input:
 * Two integer a,b(0<=a,b<=10)
 *
 * Output:
 * Output a+b
 */

class cal{
private:
    int a,b;
public:
    void GetNum(){
        cin >> a >> b;
    }
    int Plus(){
        return a + b;
    }
};

int main() {
    cal foo;
    foo.GetNum();
    cout << foo.Plus() << endl;
    return 0;
}
