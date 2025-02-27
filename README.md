# Implementing ML algorithms from scratch
- in pursuit of gaining a fundamental understanding.

## 1. Linear Regression:
- find the best fit for y = wx + b; w = weight, b = bias
- assuming that there is only one input variable i.e. x
- once implemented, can be extended to multiple dimensions i.e. y = w1x1 + w2x2 + ... + wnxn + b
### Gradient Descent:
- this is the cost function we're optimizing for
![](linear_png/linear_cost_function.png)
- this is the gradient descent update rule we're using:
![](linear_png/gradient_descent.png)
---
- ![](linear_png/convergence.png)
## 2. Logistic Regression:
- use a sigmoid function (f(x) = 1/(1 + e^(-x))) to approximate the probablity of a certain event happening
![](logistic_png/sigmoid_function.png)
- the actual function we're going to use:
![](logistic_png/logistic.png)
