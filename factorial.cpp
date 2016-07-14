#include <iostream>
#include <functional>

using std::function;
using std::cin;
using std::cout;

#define FACT_TO_CALCULATE 20

typedef unsigned long long ull;

/** Method 1: Using TMP and function template **/
template <int N>
constexpr ull factorial_function_template()
{
    return N * factorial_function_template<N-1>();
}

template <>
constexpr ull factorial_function_template<1>()
{
    return 1;
}


/** Method 2: Using TMP and classes **/
template <ull N>
struct factorial_class
{
    static const ull val = factorial_class<N-1>::val * N;
};

template <>
struct factorial_class<1>
{
    static const ull val = 1;
};



int main()
{

    /** Method 3: Using Lambda and std::function **/
    function<ull(int)> factorial_lambda_std_func;
    factorial_lambda_std_func = [&factorial_lambda_std_func](int n) -> ull
    {
        return (n < 2 ? 1 : n * factorial_lambda_std_func(n-1));

    };

    /** Method 4: Using stateless lambda and function pointer **/
    static ull (*factorial_lambda_func_ptr)(int) = [](int n) ->ull
    {
        return (n < 2 ? 1 : n * factorial_lambda_func_ptr(n-1));

    };


    /** The following two versions are determined during compile time **/
    constexpr ull fact_func_temp = factorial_function_template<FACT_TO_CALCULATE>();
    constexpr ull fact_classes = factorial_class<FACT_TO_CALCULATE>::val;

    ull fact_lambda_std_func = factorial_lambda_std_func(FACT_TO_CALCULATE);
    ull fact_lambda_func_ptr = factorial_lambda_func_ptr(FACT_TO_CALCULATE);

    cout << "\n Factorial of "<<FACT_TO_CALCULATE<<" using function templates:"<<fact_func_temp;
    cout << "\n Factorial of "<<FACT_TO_CALCULATE<<" using classes:"<<fact_classes;
    cout << "\n Factorial of "<<FACT_TO_CALCULATE<<" using lambda and std::function:"<<fact_lambda_std_func;
    cout << "\n Factorial of "<<FACT_TO_CALCULATE<<" using stateless lambda and function pointer:"<<fact_lambda_func_ptr;

    return 0;
}
