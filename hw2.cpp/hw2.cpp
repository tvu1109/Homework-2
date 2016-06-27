
/** Name: Trang Vu
 Date: October 9, 2015
 @File: hw2.cpp
 @Brief: This program codes for class Polynomial.  Member functions are created to use the polynomial class in the int main.  Definitions are provided after int main
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; // this line lets you to write cout without std:: in front
using std::endl; // this line lets you to write endl without std:: in front

/** @class Polynomial
 @brief functions for the Polynomial Class
 
 This function defines the polynomial a0 + a1x + a2x^2 ... where a is the inputted coefficients
 
 */
class Polynomial {
    //This is a comparison operator
    friend bool operator==(const Polynomial&, const Polynomial&);
public:
    
    //Constructors
    Polynomial();
    Polynomial(const std::vector<int>& coeffs);
    
    // Accessors
    int Degree() const;
    int Coefficient(size_t k) const;
    void print() const;
    
    // Mutators
    void constantMultiply(int x);
    void Transform();
    
    // performs poly = poly + poly2.  Called as poly.AddBy(poly2)
    void AddBy(const Polynomial& poly2);
    
    // poly = poly - poly2
    void SubtractBy(const Polynomial& poly2);
    
    // poly = poly * poly2
    void MultiplyBy(const Polynomial& poly2);
    
    //Arithmetic operations, these will perform the usual polynomial arithmetic as the AddBy, SubtractBy, MultiplyBy functions
    Polynomial& operator+=(const Polynomial& poly2);
    Polynomial& operator-=(const Polynomial& poly2);
    Polynomial& operator*=(const Polynomial& poly2);
    
    //Increment operators
    //Prefix operator
    Polynomial& operator ++();
    //Postfix operator
    Polynomial operator ++(int);
    //Prefix operator
    Polynomial& operator --();
    //Postfix operator
    Polynomial operator --(int);

private:
    std::vector<int> coefficient;
};

//Ask for the input of coefficient for the polynomial
void initializeValueFromTerminal(Polynomial& function);

//Arithmetic operations
Polynomial operator+(Polynomial lhs, const Polynomial& rhs);
Polynomial operator-(Polynomial lhs, const Polynomial& rhs);
Polynomial operator*(Polynomial lhs, const Polynomial& rhs);

//Comparison operator
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

int main() {
    
    Polynomial p;                       // Default constructor , p = initially
    initializeValueFromTerminal(p) ;    // Prompt user for coefficients ,
    // stops when input is −12345
    // For example , input of 1 , −2, 0 , 4 , −12345 creates polynomial
    // p(x) = 1−2x+4xˆ3
    
    cout<<"Your first polynomial is "; p.print(); cout<<endl;
    
    Polynomial q ;
    initializeValueFromTerminal (q) ;
    // For example, input of 0, −1, 5, 0, 0, 0, −3, −12345 creates ← polynomial
    // q(x) = −x+5xˆ2−3xˆ6
    
    cout<<"Your second polynomial is "; q.print(); cout<<endl;
    
    Polynomial r = p+q;
    cout<<"r(x) := p(x)+q(x) = "; r.print(); cout<<endl;
    // r (x) = p(x)+q(x) = 1−3x+5xˆ2+4xˆ3−3xˆ6
    
    r += p;
    cout<<"r(x)+p(x) = "; r.print(); cout<<endl;
    // r(x) = 2−5x+5xˆ2+8xˆ3−3xˆ6
    
    r *= q;
    cout<<"(r(x)+p(x))*q(x) = "; r.print() ; cout<<endl;
    // r(x) = −2x+15xˆ2−30xˆ3+17xˆ4+40xˆ5−6xˆ6+18xˆ7−30xˆ8−24xˆ9+9xˆ12
    
    Polynomial s = ++r;
    cout<<"s(x) := (r(x)+p(x))*q(x)+1 = "; s.print() ; cout<<endl;
    // s(x) = 1−2x+15xˆ2−30xˆ3+17xˆ4+40xˆ5−6xˆ6+18xˆ7−30xˆ8−24xˆ9+9xˆ12
    
    Polynomial t = s ;
    cout<<"t(x) := s(x)"; cout<<endl;
    // t(x) = 1−2x+15xˆ2−30xˆ3+17xˆ4+40xˆ5−6xˆ6+18xˆ7−30xˆ8−24xˆ9+9xˆ12
    
    cout << "t(x) == s(x)? ";
    if ( t==s ) cout<<"yes!\n";
    else cout<<"no!\n";
    // In this case, yes, since we just assigned s to be the same value as t
    
    s++;
    cout<<"s(x) <−− s(x)+1 = "; s.print() ; cout<<endl;
    //s(x) = 2−2x+15xˆ2−30xˆ3+17xˆ4+40xˆ5−6xˆ6+18xˆ7−30xˆ8−24xˆ9+9xˆ12
    
    cout << "t(x) != s(x)? ";
    if (t!= s) cout<<"yes!\n";
    else cout<<"no!\n";
    // In this case, yes, since we just incremented s , they are no longer ← the same.
    
    Polynomial a = p*q ;
    cout<<"a(x) := p(x)*q(x) = "; a.print(); cout<<endl;
    // a(x) = −x+7xˆ2−10xˆ3−4xˆ4+20xˆ5−3xˆ6+6xˆ7−12xˆ9
    
    Polynomial b = p-q ;
    cout<<"b(x) := p(x)−q(x) = "; b.print(); cout<<endl;
    // b(x) = 1−x−5xˆ2+4xˆ3+3xˆ6
    
    b -= a ;
    cout<<"p(x)−q(x)−p(x)*q(x) = "; b.print() ; cout<<endl;
    // b(x) = 1−12xˆ2+14xˆ3+4xˆ4−20xˆ5+6xˆ6−6xˆ7+12xˆ9
    
    b--;
    cout<<"p(x)−q(x)−p(x)*q(x)−1 = "; b.print() ; cout<<endl;
    // b(x) = −12xˆ2+14xˆ3+4xˆ4−20xˆ5+6xˆ6−6xˆ7+12xˆ9
    
    --b;
    cout<<"p(x)−q(x)−p(x)*q(x)−2 = "; b.print() ; cout<<endl;
    // b(x) = −1−12xˆ2+14xˆ3+4xˆ4−20xˆ5+6xˆ6−6xˆ7+12xˆ9
    
    return 0;
}

/** This is the default constructor, which initializes the Polynomial to 0
 */
Polynomial::Polynomial() : coefficient(1,0){
}

/** Allow polynomial to save coefficients into a vector.
 The polynomial is initialized to 0 if there are no input for the vector
 */
Polynomial::Polynomial(const std::vector<int>& coeffs){
    coefficient = coeffs;
    //polynomial is initialized to 0 if there are no input for the vector
    if (coefficient.size () == 0){
        coefficient = std::vector<int> (1,0);
    }
}

/** Give the highest degree of the polynomial
 */
int Polynomial::Degree() const{
    return coefficient.size() - 1;
}

/** Returns the coefficient of the requested degree of x.
 @param k is the degree of x
 */
int Polynomial::Coefficient(size_t k) const {
    //if the size is less than the requested degree then return 0
    if ((coefficient.size()-1) < k) {
        return 0;
    }
    //else return the coefficient of the degree
    else {
        return coefficient[k];
    }
}

/** Prints the polynomial in the form of "a0 + a1x + a2x^2 ..."
 If the inputed coefficient is 0, then it is not printed out in the polynomial
 If the inputed coefficient is either 1 or -1, then only x or -x is printed
 */
void Polynomial::print() const {
    //If the vector has a size of 0 then output 0
    if (coefficient.size() == 0){
        std::cout << "0";
    }
    //If the vector only have one input then it is stored in [0]
    else if (coefficient.size() == 1) {
        std::cout << coefficient [0];
    }
    //This statement is used to replace 1 and -1 with x and -x, respectively
    else {
        //if [0] is not equal to 0 then cout [0]
        if (coefficient[0] != 0){
            std::cout << coefficient[0];
        }
        //if [1] equal 1 then cout x
        if (coefficient[1] == 1) {
            std::cout << "x";
        }
        //if [1] equal -1 then cout -x
        else if (coefficient[1] == -1) {
            std::cout << "-x";
        }
        //if [1] does not equal 0 then cout [1]x
        else if (coefficient[1] != 0) {
            std::cout << "+" << coefficient[1] << "x";
        }
    }
    //This loop goes through all of the coefficient in the vector and add a "+" sign in front of it and add its degree
    for (int a = 2; a < coefficient.size(); a++){
        //if any element in the vector equals -1 then cout +-x (prospective degree)
        if (coefficient[a] == -1){
            std::cout << "+" << "-x^" << a;
        }
        //if any element in the vector equals 1 then cout +x^ (prospective degree)
        else if (coefficient[a] == 1) {
            std::cout << "+" << "x^" << a;
        }
        //if none of the element equals 0 then cout the value of the element ^ (prospective degree)
        else if (coefficient[a] != 0) {
            std::cout << "+" << coefficient[a] << "x^" << a;
        }
    }
}

/** Multiplies the polynomial by a constant
 @param x is the constant that the polynomial is multiplied to
 */
void Polynomial::constantMultiply(int x) {
    //Goes through each element and multiply the value of each element by the constant
    for (int a = 0; a < coefficient.size(); a++) {
        coefficient[a] = coefficient[a] * x;
    }
}

/** Transforms the polynomial to its derivative using the power rule
 */
void Polynomial::Transform() {
    //If there was only one input then set the value of the element 0 equal to 0
    if (coefficient.size() == 1) {
        coefficient [0] = 0;
    }
    //Takes the derivative of each element, then delete one element for the new vector
    else {
        for (int a = 0; a < (coefficient.size()-1); a++){
            coefficient[a] = coefficient[a+1] * (a+1);
        }
        coefficient.pop_back();
    }
}

/**  Adds the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial

void Polynomial::AddBy(const Polynomial& poly2){
    std::vector<int> sum;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    for (int a = 0; a<loop_length; a++)
    {
        if (a > this->Degree())
            sum.push_back(poly2.coefficient[a]);
        else if (a > poly2.Degree())
            sum.push_back(this->coefficient[a]);
        else
            sum.push_back(this->coefficient[a]+poly2.coefficient[a]);
    }
    while ((sum.back() == 0) && (sum.size() > 1)){
        sum.pop_back();
    }
    coefficient = sum;
}

 Subtracts the second polynomial from the first polynomial
 @param poly2 is the vector of coeffcients for the second polynomial

void Polynomial::SubtractBy(const Polynomial& poly2){
    std::vector<int> diff;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    for (int a = 0; a<loop_length; a++)
    {
        if (a > this->Degree())
            diff.push_back(-poly2.coefficient[a]);
        else if (a > poly2.Degree())
            diff.push_back(this->coefficient[a]);
        else
            diff.push_back(this->coefficient[a]-poly2.coefficient[a]);
    }
    while ((diff.back() == 0) && (diff.size() > 1)){
        diff.pop_back();
    }
    coefficient = diff;
    
}

 Multiplies the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 
void Polynomial::MultiplyBy(const Polynomial& poly2){
    int degree_prod = this->Degree() + poly2.Degree() + 1;
    std::vector<int> prod(degree_prod,0);
    for (size_t a=0; a<(this->Degree() +1);a++){
        for (size_t b=0; b < (poly2.Degree() +1); b++){
            prod[a+b] += this->Coefficient(a)*poly2.Coefficient(b);
        }
    }
    coefficient = prod;
}
 */

/**Ask for the input of coefficient for the polynomial
 @param function is the inputted polynomial
 */
void initializeValueFromTerminal(Polynomial& function){
    std::cout << "Please input the coefficients of the polynomial." << std::endl << "When you are finished, enter -12345." << std::endl;
    //Vector stores inputted coeffcients of polynomial 1
    std::vector<int>p;
    int coeff = 0;
    std::cin >> coeff;
    // -12345 ends the loop
    while (coeff != -12345){
        p.push_back(coeff);
        std::cin >> coeff;
    }
    function = p;
    
}

/**  Adds the two polynomials together
    @param poly2 is the vector of coeffcients for the second polynomial
    @return *this refers to the object pointint to the function
*/
Polynomial& Polynomial::operator+=(const Polynomial& poly2){
    std::vector<int> sum;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    //This loop goes through each element from each vector, and add the first element of the first vector and the first element of the second vector and so on
    for (int a = 0; a<loop_length; a++)
    {
        //add an element if a is greater than degree
        if (a > this->Degree())
            sum.push_back(poly2.coefficient[a]);
        //add an element if a is greater than the degree of polynomial 2
        else if (a > poly2.Degree())
            sum.push_back(this->coefficient[a]);
        //add an element
        else
            sum.push_back(this->coefficient[a]+poly2.coefficient[a]);
    }
    //delete an element from the vector sum
    while ((sum.back() == 0) && (sum.size() > 1)){
        sum.pop_back();
    }
    coefficient = sum;
    return *this;
}

/**  Subtracts the first polynomial from the second polynomial
 @param poly2 is the vector of coeffcients for the second polynomial
 @return *this refers to the object pointing to the function
 */
Polynomial& Polynomial::operator-=(const Polynomial& poly2){
    std::vector<int> diff;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    //This loop goes through each element from each vector, and subtract the first element of the first vector and the first element of the second vector and so on
    for (int a = 0; a<loop_length; a++)
    {
        //add an element
        if (a > this->Degree())
            diff.push_back(-poly2.coefficient[a]);
        //add an element
        else if (a > poly2.Degree())
            diff.push_back(this->coefficient[a]);
        //add an element
        else
            diff.push_back(this->coefficient[a]-poly2.coefficient[a]);
    }
    //delete an element
    while ((diff.back() == 0) && (diff.size() > 1)){
        diff.pop_back();
    }
    coefficient = diff;
    return *this;
}

/**  Multiplies the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 @return *this is a copy
 */
Polynomial& Polynomial::operator*=(const Polynomial& poly2){
    int degree_prod = this->Degree() + poly2.Degree() + 1;
    std::vector<int> prod(degree_prod,0);
    // this loop is used to multiply each element from each vector together
    for (size_t a=0; a<(this->Degree() +1);a++){
        for (size_t b=0; b < (poly2.Degree() +1); b++){
            prod[a+b] += this->Coefficient(a)*poly2.Coefficient(b);
        }
    }
    coefficient = prod;
    return *this;
}
/**Add the right polynomial to the left polynomial
 @param lhs is passed by value because we want it to make a copy so we can alter the lhs
 @param rhs is the polynomial on the right hand side
 @return lhs+=rhs
 */
Polynomial operator+(Polynomial lhs, const Polynomial& rhs){
    return lhs+=rhs;
}

/**Subtract the right polynomial from the left polynomial
 @param lhs is passed by value because we want it to make a copy so we can alter the lhs
 @param rhs is the polynomial on the right hand side
 @return lhs+=rhs
 */
Polynomial operator-(Polynomial lhs, const Polynomial& rhs){
    return lhs-=rhs;
}

/**Multiply the right polynomial to the left polynomial
 @param lhs is passed by value because we want it to make a copy so we can alter the lhs
 @param rhs is the polynomial on the right hand side
 @return lhs+=rhs
 */
Polynomial operator*(Polynomial lhs, const Polynomial& rhs){
    return lhs*=rhs;
}

/**Comparison operator that make sure both side of the equal sign is the same
 @param lhs does not need a copy and does not need modification
 @param rhs does not need a copy and does not need modification
 @return lhs.coefficient == rhs.coefficient compares two ints
*/
bool operator == (const Polynomial& lhs, const Polynomial& rhs){
    return (lhs.coefficient == rhs.coefficient);
}

/**Comparison operator
 @param lhs does not need a copy and does not need modification
 @param rhs does not need a copy and does not need modification
 @return !(lhs == rhs) is a nonmember because we don't need to access to private variable
 */
bool operator != (const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs);
}

/**Prefix, increment operator
 @return *this is a copy
 */
Polynomial& Polynomial::operator++(){
    coefficient[0]=coefficient[0]+1;
    return *this;
}

/**Postfix, increment operator
 @param unused is the int created
 @return clone
 */
Polynomial Polynomial::operator++(int unused) {
    Polynomial clone = *this;
    ++(*this);
    return clone;
}

/**Prefix, increment operator
 @return *this is a copy
 */
Polynomial& Polynomial::operator--(){
    coefficient[0]=coefficient[0]-1;
    return *this;
}

/**Postfix, increment operator
 @param unused is the int created
 @return clone
 */
Polynomial Polynomial::operator--(int unused) {
    Polynomial clone = *this;
    --(*this);
    return clone;
}

