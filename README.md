# fancy-recursions
Performing recursions the unusual way to calculate factorial.

## Building
```
g++ factorial.cpp -std=c++11
```

## Sample Output
```
Factorial of 20 using function templates:2432902008176640000
Factorial of 20 using classes:2432902008176640000
Factorial of 20 using lambda and std::function:2432902008176640000
Factorial of 20 using stateless lambda and function pointer:2432902008176640000
```
## Note
- Edit **FACT_TO_CALCULATE** to the number you want to calculate the factorial. The input is taken at compile time rather than run time to see TMP in action.
- Since factorials can get pretty huge and C++ supports only 64bit unsigned integers, it is only possible to calculate factorials upto 20.

## Blog Article
For further explanation please refer to my blog on [Tumblr](https://1337ninja.tumblr.com/post/147400346326/recursions-the-unusual-way)
