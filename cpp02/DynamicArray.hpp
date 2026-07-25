#ifndef DYNAMICARRAY_HPP
# define DYNAMICARRAY_HPP
# include <iostream>
class DynamicArray
{
    public:
    DynamicArray();
    DynamicArray(int size , int fillValue);
    DynamicArray(DynamicArray const& other);
    DynamicArray& operator=(DynamicArray const &other);
    ~DynamicArray();
    explicit DynamicArray(int size);//zero-initalized array  //this make sure that the comp dont auto con to Dynamic array and its taking as int 
    //this mean itexplicit DynamicArray(int size); so this mean DynamicArray obj =10 ; is not working and must  write as()
    int getAt(int index) const ;
    void setAt(int index , int value);
    int getSize() const ; 

    void swapWith(DynamicArray & other);
    void print(std::string const& label) const;
    friend std::ostream& operator<<(std::ostream &os , DynamicArray const& arr);
    private:
    int *_data;
    int _size; 
};
#endif