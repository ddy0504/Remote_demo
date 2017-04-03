extern "C"{

    int func1()
    {
        return 100;
    }

    int factorial(int n)
    {
        if(n<2)
           return 1;
        return factorial(n-1)*n;
    }
}
