#include <iostream>

using namespace std;

float readHeight()
{
    float height;
    cout << "Podaj swoj wzrost: ";
    cin >> height;
    return height;
}

int readMass()
{
    int mass;
    cout << "Podaj swoja wage: ";
    cin >> mass;
    return mass;
}

float BMI(float height, int mass)
{
    return mass / (height*height) * 10000;
}

void BMIprint(float BMI)
{
    cout << "Twoje BMI to: " <<BMI << endl;
}

int main()
{
    BMIprint(BMI(readHeight(), readMass()));
    return 0;
}