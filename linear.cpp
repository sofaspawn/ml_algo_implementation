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
            this->weight = rand() % 11;
            //this->weight = 2.0f;
            this->bias = rand() % 11;
            //this->bias = 1.0f;
            this->alpha = 0.001;
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
            int max_iterations = 10000000;

            while (i < max_iterations) {
                update_fn(xs, ys);
                cost_fn(xs, ys);

                // Debugging prints to check the progress
                cout << "Iteration " << i << endl;
                cout << "Weight: " << this->weight << ", Bias: " << this->bias << endl;
                cout << "Cost: " << this->cost << endl;

                // Check if the cost is converging
                if (abs(this->cost - last_los) < 1e-6) {
                    cout << "------------------" << endl;
                    cout << "Converged after " << i << " iterations." << endl;
                    break;
                }

                last_los = this->cost;
                i += 1;
            }

            cout << "------------------" << endl;
            cout << "Final model: y = " << this->weight << " * x + " << this->bias << endl;
            cout << "Final cost: " << this->cost << endl;
            cout << "------------------" << endl;
        }

        vector<float> predict(vector<float> x_test){
            vector<float> y_preds(x_test.size());
            for(int i=0; i<x_test.size(); i++){
                y_preds[i] = this->weight * x_test[i] + this->bias;
            }
            return y_preds;
        }
};

float mean_abs_error(vector<float> y_test, vector<float>y_preds){
    float sum{};
    for(int i=0; i<y_test.size(); i++){
        sum+=abs(y_test[i] - y_preds[i]);
    }
    return sum/y_test.size();
}

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

    int train_size = 0.6 * data_size;
    
    vector<float> x_train(train_size);
    vector<float> y_train(train_size);
    vector<float> x_test(data_size - train_size);
    vector<float> y_test(data_size - train_size);

    // Copy data to training set
    for(int i = 0; i < train_size; i++) {
        x_train[i] = xs[i];
        y_train[i] = ys[i];
    }

    // Copy data to testing set
    for(int i = train_size; i < data_size; i++) {
        x_test[i - train_size] = xs[i];
        y_test[i - train_size] = ys[i];
    }
    LinearRegression model = LinearRegression();
    model.fit(x_train, y_train);
    vector<float> y_preds = model.predict(x_test);
    cout << "Running tests..." << endl;
    cout << "Mean absolute error: " << mean_abs_error(y_test, y_preds) << endl;
    //cout << "Linear regression starts here." << endl;
}
