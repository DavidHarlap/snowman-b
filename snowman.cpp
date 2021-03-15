#include "snowman.hpp"
#include <string>
#include <math.h>
#include <iostream>

#define EMPTY_ROW " (   ) \n"

using namespace std;

namespace location{
    int const nose_location = 3;
    int const right_eye_location = 4;
    int const left_eye_location = 2;
    int const left_arm = 0;
    int const right_arm = 6;



}

namespace hat{
    string const type1 = "       \n _===_ \n";
    string const type2 = "  ___  \n ..... \n";
    string const type3 = "   _   \n  /_\\  \n";
    string const type4 = "  ___  \n (_*_) \n";
}

namespace nose{
    char const type1 = ',';
    char const type2 = '.';
    char const type3 = '_';
    char const type4 = ' ';
}

namespace lEye{
    char const type1 = '.';
    char const type2 = 'o';
    char const type3 = 'O';
    char const type4 = '-';
}

namespace rEye{
    char const type1 = '.';
    char const type2 = 'o';
    char const type3 = 'O';
    char const type4 = '-';
}

namespace lArm{
    char const type1 = '<';
    char const type2 = '\\';
    char const type3 = '/';
    char const type4 = ' ';
}

namespace rArm{
    char const type1 = '>';
    char const type2 = '/';
    char const type3 = '\\';
    char const type4 = ' ';
}

namespace torso{
    string const type1 = " : ";
    string const type2 = "] [";
    string const type3 = "> <";
    string const type4 = "   ";
}

namespace base{
    string const type1 = " ( : ) \n";
    string const type2 = " (\" \") \n";
    string const type3 = " (___) \n";
    string const type4 = " (   ) \n";
}
    


string fill_hat(int* code)
{
    int hat_type;
    string row1and2;
    hat_type= *code/(int)pow(10,7);
    if(hat_type>9)
        throw(stderr, "the code length is to long");
    if(hat_type>4)
        throw(__throw_out_of_range);
    if(hat_type==0)
        throw(stderr, "the code length is to short");
    if(hat_type<0)
        throw(stderr, "not possible to insert negative code");
    if(hat_type== 1)
        row1and2 =hat::type1;
    if(hat_type== 2)
        row1and2 =hat::type2;
    if(hat_type== 3)
        row1and2 =hat::type3;
    if(hat_type== 4)
        row1and2 =hat::type4;
    
    *code%= (int)pow(10,7);
    return row1and2 ;
}

void fill_nose(int *code,string row3){
    switch ((*code/(int)pow(10,6)))
    {
    case 1:
        row3[location::nose_location]=nose::type1;
        break;
    case 2:
        row3[location::nose_location]=nose::type2;
        break;
    case 3:
        row3[location::nose_location]=nose::type3;
        break;
    case 4:
        row3[location::nose_location]=nose::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
    *code%= (int)pow(10,6);
}

void fill_left_eye(int *code,string row3){
    switch ((*code/(int)pow(10,5)))
    {
    case 1:
        row3[location::left_eye_location]=lEye::type1;
        break;
    case 2:
        row3[location::left_eye_location]=lEye::type2;
        break;
    case 3:
        row3[location::left_eye_location]=lEye::type3;
        break;
    case 4:
        row3[location::left_eye_location]=lEye::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
    *code%= (int)pow(10,5);
}

void fill_right_eye(int *code,string row3){
    switch ((*code/(int)pow(10,4)))
    {
    case 1:
        row3[location::right_eye_location]=rEye::type1;
        break;
    case 2:
        row3[location::right_eye_location]=rEye::type2;
        break;
    case 3:
        row3[location::right_eye_location]=rEye::type3;
        break;
    case 4:
        row3[location::right_eye_location]=rEye::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
    std::cout<< row3;
    *code%= (int)pow(10,4);
}

void fill_face(int *code,string row3){
    fill_nose(code,row3);
    fill_left_eye(code,row3);
    fill_right_eye(code, row3);
}

void fill_arms(int* code, string row3, string row4){
    switch ((*code/ (int)pow(10,3)))
    {
    case 1:
        row4[location::left_arm]=lArm::type1;
        break;
    case 2:
        row3[location::left_arm]=lArm::type2;// up arm so row 3 
        break;
    case 3:
        row4[location::left_arm]=lArm::type3;
        break;
    case 4:
        row4[location::left_arm]=lArm::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }

    *code%= (int)pow(10,3);
     switch ((*code/ (int)pow(10,2)))
    {
    case 1:
        row4[location::right_arm]=rArm::type1;
        break;
    case 2:
        row3[location::right_arm]=rArm::type2;// up arm so row 3 
        break;
    case 3:
        row4[location::right_arm]=rArm::type3;
        break;
    case 4:
        row4[location::right_arm]=rArm::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
        *code%= (int)pow(10,2);


}

void fill_torso(int* code, string row4){
    switch ((*code/ (int)pow(10,1)))
    {
    case 1:
        row4.string::replace(3,5,torso::type1);
        break;
    case 2:
        row4.string::replace(3,5,torso::type2);
        break;
    case 3:
        row4.string::replace(3,5,torso::type3);
        break;
    case 4:
        row4.string::replace(3,5,torso::type4);
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
    *code%= (int)pow(10,1);

}

string fill_base(int code,string row5){
    switch (code)
    {
    case 1:
        row5 =base::type1;
        break;
    case 2:
        row5 =base::type2;
        break;
    case 3:
        row5 =base::type3;
        break;
    case 4:
        row5 =base::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
    return row5 ;
}

    
string ariel::snowman(int code){
    string hat = fill_hat(&code);
    string row3_face= EMPTY_ROW;
    fill_face(&code, row3_face);
    string row4_torso = EMPTY_ROW;
    fill_arms(&code,row3_face,row4_torso);
    fill_torso(&code, row4_torso);
    string row5_base = EMPTY_ROW;
    fill_base(code,row5_base);
    return hat+row3_face+row4_torso+row5_base ;
}