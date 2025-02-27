#include <iostream>
#include <cmath>
#include <cstdlib>

#include <vector>






//
//
//
//
// In Progress
//
//
//
//
//
//
//







using namespace std;

// the line is:
// h(x) = w0 + w1*x

// cost function:
// J = (1/2m)*sum((h(x_i) - y(i))**2)

class LogisticRegression{
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
    LogisticRegression model = LogisticRegression();
    model.fit(x_train, y_train);
    vector<float> y_preds = model.predict(x_test);
    cout << "Running tests..." << endl;
    cout << "Mean absolute error: " << mean_abs_error(y_test, y_preds) << endl;
    //cout << "Linear regression starts here." << endl;
}
