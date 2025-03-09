int height = 10;
class Weird 
{
    short height; 
    Weird() 
    { 
        height = 5; 
        ::height = 5;   // this accesses the global variable (using :: scope operator)
    }
};
