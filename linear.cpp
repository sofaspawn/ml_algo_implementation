#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// the line is:
// h(x) = w0 + w1*x

// cost function:
// J = (1/2m)*sum((h(x_i) - y(i))**2)

class LinearRegression{
    private:
        float weight;
        float bias;
        float alpha;

    public:
        float xs[];
        float ys[];

        LinearRegression(){
            this->weight = rand() % 11;
            this->bias = rand() % 11;
            this->alpha = 0.01;
        }

        void cost(){
        }
};

int main(){
    cout << "Linear regression starts here." << endl;
}
