// ********************************************* //
// This is not a compilable file DO NOT compile  //
// ********************************************* //

int a = {1} ,b = {1} ,c = {1};

// NOT OK!
auto lambda_1 = [a,b,c](void)->void
{
    a++;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
};

// OK! (but will NOT affect a,b,c outside lambda and outside change will NOT be re-captured)
auto lambda_2 = [a,b,c](void) mutable->void
{
    a++;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
};

// OK! (changes made to variable will affect outter scope)
auto lambda_3 = [&a,&b,&c](void) ->void
{
    a++;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
};