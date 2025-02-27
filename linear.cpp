#include <iostream>
#include <cmath>
#include <cstdlib>

#include <vector>

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
        float cost{};

    public:
        LinearRegression(){
            //this->weight = rand() % 11;
            this->weight = 2.0f;
            //this->bias = rand() % 11;
            this->bias = 1.0f;
            this->alpha = 0.00001;
        }

        void update_fn(vector<float> xs, vector<float> ys){
            float bias_sum{};
            float weight_sum{};
            int size = xs.size();

            for(int i=0; i<size; i++){
                float h_i = this->bias + this->weight * xs[i];

                float bias_error = h_i - ys[i];
                float weight_error = bias_error * xs[i];

                bias_sum += bias_error;
                weight_sum += weight_error;
            }

            this->bias -= (this->alpha/size)*bias_sum; 
            this->weight -= (this->alpha/size)*weight_sum;
        }

        void cost_fn(vector<float> xs, vector<float> ys){
            float sum_error{};
            int size = xs.size();

            for(int i=0; i<size; i++){
                float h_i = this->bias + this->weight * xs[i];

                float error = pow(h_i - ys[i], 2);

                sum_error+=error;
            }

            this->cost = sum_error/(2*size);
        }

        void fit(vector<float> xs, vector<float> ys){
            int i = 0;
            float last_los = 0;
            int max_iterations = 100;

            while (i < max_iterations) {
                update_fn(xs, ys);
                cost_fn(xs, ys);

                // Debugging prints to check the progress
                cout << "Iteration " << i << endl;
                cout << "Weight: " << this->weight << ", Bias: " << this->bias << endl;
                cout << "Cost: " << this->cost << endl;

                // Check if the cost is converging
                if (abs(this->cost - last_los) < 1e-6) {
                    cout << "Converged after " << i << " iterations." << endl;
                    break;
                }

                last_los = this->cost;
                i += 1;
            }

            cout << "------------------" << endl;
            cout << "Steps to convergence: " << i << endl;
            cout << "Final model: y = " << this->weight << " * x + " << this->bias << endl;
            cout << "Final cost: " << this->cost << endl;
            cout << "------------------" << endl;
        }
};

int main(){
    srand(time(0));

    float m = 2.0f;
    float b = 1.0f;
    float noise_level = 0.1f;

    int data_size = 100;

    vector<float> xs(data_size);
    vector<float> ys(data_size);

    for(int i = 0; i < data_size; i++) {
        //xs[i] = (float)(rand() % 100 + 1);
        xs[i] = (float)(i+1);
        float noise = ((rand() % 1000) / 1000.0f - 0.5f) * noise_level;
        ys[i] = m * xs[i] + b + noise;
    }

    /*
    int train_size = 0.6*data_size;
    
    vector<float> x_train(train_size);
    vector<float> y_train(train_size);

    int i=0;

    while (i<train_size){
        x_train[i] = xs[i];
        i+=1;
    }

    i=0;
    while (i<train_size){
        y_train[i] = ys[i];
        i+=1;
    }
    */

    LinearRegression model = LinearRegression();
    model.fit(xs, ys);
    //cout << "Linear regression starts here." << endl;
}
