#include "snowman.hpp"
#include <string>
#include <math.h>
#include <iostream>


using namespace std;
const string empty_row= " (   ) \n";

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
namespace digit{
    int const hat_digit=(int)pow(10,7);
    int const nose_digit=(int)pow(10,6);
    int const left_eye_digit=(int)pow(10,5);
    int const right_eye_digit=(int)pow(10,4);
    int const left_arm_digit=(int)pow(10,3);
    int const right_arm_digit=(int)pow(10,2);
    int const torso_digit=(int)pow(10,1);
    int const option1 = 1;
    int const option2 = 2;
    int const option3 = 3;
    int const option4 = 4;
    int const max_unit_digit = 9;
    int const min_unit_digit = 0;

}
    


string fill_hat(int* const code)
{
    string row1and2;
    int hat_type= *code/digit::hat_digit;
    if(hat_type>digit::max_unit_digit){
        throw("the code length is to long");
    }
    if(hat_type>digit::option4){
        throw(__throw_out_of_range);
    }
    if(hat_type==digit::min_unit_digit){
        throw( "the code length is to short");
    }
    if(hat_type<digit::min_unit_digit){
        throw( "not possible to insert negative code");
    }
    if(hat_type== digit::option1){ row1and2 =hat::type1;}
    if(hat_type== digit::option2){ row1and2 =hat::type2;}
    if(hat_type== digit::option3){ row1and2 =hat::type3;}
    if(hat_type== digit::option4){ row1and2 =hat::type4;}
    
    *code%= digit::hat_digit;
    return row1and2 ;
}

void fill_nose(int *code, string &row3){
    switch ((*code/digit::nose_digit))
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
    *code%= digit::nose_digit;
}

void fill_left_eye(int *code,string &row3){
    switch ((*code/digit::left_eye_digit))
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
    *code%= digit::left_eye_digit;
}

void fill_right_eye(int *code, string &row3){
    switch ((*code/digit::right_eye_digit))
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
    *code%= digit::right_eye_digit;
}

void fill_face(int *code,string &row3){
    fill_nose(code,row3);
   
    fill_left_eye(code,row3);
    fill_right_eye(code, row3);

}

void fill_arms(int* code, string &row3, string &row4){
    switch ((*code/ digit::left_arm_digit))
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

    *code%= digit::left_arm_digit;
     switch (*code/ digit::right_arm_digit)
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
    *code%= digit::right_arm_digit;


}

void fill_torso(int* code, string &row4){
    switch (*code/ digit::torso_digit)
    {
    case 1:
        row4.string::replace(2,3,torso::type1);
        break;
    case 2:
        row4.string::replace(2,3,torso::type2);
        break;
    case 3:
        row4.string::replace(2,3,torso::type3);
        break;
    case 4:
        row4.string::replace(2,3,torso::type4);
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }

    *code%= digit::torso_digit;
    
}

string fill_base(int code){
    switch (code)
    {
    case 1:
        return base::type1;
        break;
    case 2:
        return base::type2;
        break;
    case 3:
        return base::type3;
        break;
    case 4:
        return base::type4;
        break;
    
    default:
        throw(__throw_out_of_range);
        break;
    }
}

    
string ariel::snowman(int code){
    string hat = fill_hat(&code);
    string row3_face= empty_row;
    fill_face(&code, row3_face);
    string row4_torso = empty_row;
    fill_arms(&code,row3_face,row4_torso);
    fill_torso(&code, row4_torso);
    string row5_base = fill_base(code);
    return hat+row3_face+row4_torso+row5_base ;
}
