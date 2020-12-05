#include <iostream>
#include <cstdlib>
 
using namespace std;
 
class Array{
 
private:
    int* A;
    int size;
    int length;
 
public:
    Array(int size, int length, bool sorted=false){
 
        this->size = size;
        this->length = length;
 
        A = new int [size];
 
        if (sorted){
            cout << "Enter ints in sorted manner" << endl;
            for (int i = 0; i < length; i++){
                cout << "Enter element " << i << " : " << flush;
                cin >> A[i];
            }
        } else {
            for (int i = 0; i < length; i++){
 
                int val;
                val = rand() % 100;  // Random int in range 0 to 100
 
                // Generate random binary int and make value negative
                if (rand() % 2){
                    A[i] = -1 * val;
                } else {
                    A[i] = val;
                }
 
            }
        }
    }
 
    int Get(int index){
        if (index >= 0 && index < length){
            return A[index];
        }
      return 0;
    }
 
    void Set(int index, int x){
        if (index >= 0 && index < length){
            A[index] = x;
        }
    }
 
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }
 
    Array Merge(Array& B){
        Array C(length + B.length, length + B.length);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < length && j < B.length){
            if (A[i] < B.Get(j)){
                C.Set(k++, A[i++]);
            } else {
                C.Set(k++, B.Get(j++));
            }
        }
        for (; i < length; i++){
            C.Set(k++, A[i]);
        }
        for (; j < B.length; j++){
            C.Set(k++, B.Get(j));
        }
        return C;
    }
 
    ~Array(){
        delete[] A;
    }
 
 
};
 
int main() {
 
    Array X(10, 5, true);
    Array Y(10, 4, true);
 
    Array Z = X.Merge(Y);
    Z.display();
 
    return 0;
}
