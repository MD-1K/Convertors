
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>


using namespace std;

//Function which converts hexa to binary
string convert_binary(string hexa_num){
    int string_size = 0;
    string binary = "";
while(string_size!=8){ //Loop which has all possibilities
        if(hexa_num[string_size] == '0'){
            binary = binary + "0000";
        }
        else if(hexa_num[string_size] == '1'){
            binary = binary + "0001";
        }
        else if(hexa_num[string_size] == '2'){
            binary = binary + "0010";
        }
        else if(hexa_num[string_size] == '3'){
            binary = binary + "0011";
        }
        else if(hexa_num[string_size] == '4'){
            binary = binary + "0100";
        }
        else if(hexa_num[string_size] == '5'){
            binary = binary + "0101";
        }
        else if(hexa_num[string_size] == '6'){
            binary = binary + "0110";
        }
        else if(hexa_num[string_size] == '7'){
            binary = binary + "0111";
        }
        else if(hexa_num[string_size] == '8'){
            binary = binary + "1000";
        }
        else if(hexa_num[string_size] == '9'){
            binary = binary + "1001";
        }
        else if(hexa_num[string_size] == 'A'){
            binary = binary + "1010";
        }
        else if(hexa_num[string_size] == 'B'){
            binary = binary + "1011";
        }
        else if(hexa_num[string_size] == 'C'){
            binary = binary + "1100";
        }
        else if(hexa_num[string_size] == 'D'){
            binary = binary + "1101";
        }
        else if(hexa_num[string_size] == 'E'){
            binary = binary + "1110";
        }
        else if(hexa_num[string_size] == 'F'){
            binary = binary + "1111";
        }
        string_size++;
        
    }
    return binary; //return the binary answer
    
}

//Function which gives the unsigned number
long long nonsigned_num(string binary){ 
   long long binary_size = binary.size()-1; //Variable
   long long unsigned_num = 0; //Variable
   long long temp = 0; //Variable
     
   //Loop which adds all the one's in base 2 and it's power.
   // It excludes the 0's which are in the binary
while(binary_size >= 0){
       
            if(binary[binary_size] == '1'){
               unsigned_num = unsigned_num + pow(2,temp);
            }
            binary_size--;
            temp++;
        }
   return unsigned_num;
}

//Function which flips the binary to apply 2's compliment
string flip_binary(string binary){
    int binary_size = 0;
    string flip_binary = "";
    int i = 31;
    
    //Loop where it checks if the position has 1 change it to 0
    //if the position has a 0 change it to a 1
while(binary_size < 32){
        if(binary[binary_size] == '0'){
            flip_binary = flip_binary + '1';
        }
        else if(binary[binary_size] == '1'){
            flip_binary = flip_binary + '0';
        }
        binary_size++;
    }
    
    //If / else statements to make sure to apply the flip is applied to the negative numbers and not the positive one's
    if(binary[0] == '1'){
    while(i > 0){
        
        if(flip_binary[i] == '0'){
            flip_binary[i] = '1';
            i = 0;
        }
        else if(flip_binary[i] == '1'){
            flip_binary[i] = '0';
        }
        i--;
    }
  }
    return flip_binary; //Returns the flipped binary
}

//Function which gives the signed number
long long sign_num(string binary, string flip_binary){
   long long binary_size = binary.size()-1;
   long long temp = 0;
   long long signed_num = 0;
   
   //Loop which adds the one's in binary if the binary is positive
   //if the binary is negative it adds the ones in the flipped binary
   while(binary_size > 0){
   if(binary[0] == '0'){
       if(binary[binary_size] == '1'){
       signed_num = signed_num + pow(2,temp);
       }
   }
   else{
       if(flip_binary[binary_size] == '1'){
           signed_num = signed_num + pow(2,temp);
       }
   }
   binary_size--;
   temp++;
   }
   
   //Makes sure if it's a positive number comes out positive
   //if it's a negative one makes sure it gives a negative number
   if(binary[0] == '1'){
   return signed_num * -1; //returns the sign number
   }
   else{
       return signed_num; //returns the sign number
   }
}

//Function which changes the binary into a float
double Float(string binary){
    int exponent = 0;
    string exponent_str = binary.substr(1,8);
    int str_size = exponent_str.size()-1;
    int temp = 0;
    double float_num = 0;
    
    //Loop which solves for the exponent
    while(str_size >= 0){
        if(exponent_str[str_size] == '1'){
            exponent = exponent + pow(2,temp);
        }
        temp++;
        str_size--;
    }
    exponent = exponent - 127;
    string fraction_str = binary.substr(9);
    int i = 0;
    double power = -1;
    
    //Loop which solves for the fraction part.
    while(i <= fraction_str.size()-1){
        if(fraction_str[i] == '1' ){
            float_num = float_num + pow(2,power);
        }
        i++;
        power = power - 1;
    }
    float_num = (1.0 + float_num)*pow(2,exponent); //The line that combines the float and the exponent to give us the answer
    
    //Check to see if it's a negative binary or not.
    //If it is a negative binary then returns a negative float else not.
    if(binary[0] == '1'){
        float_num = float_num * (-1);
    }
    return float_num; //returns the float number
   
}


int main() {
    string hexa_num;
    string binary1 = "";
    string flipped = "";
    char start = 'Y';
    
    //Loop which keeps asking user if he wants to keep going
    while(start== 'Y'){
        
    cout << "Enter a 8 digit Hexadecimal Number: "<< endl; //Asks user to enter a hexadecimal value
    cin >> hexa_num;
    
    if(hexa_num.size() > 8 || hexa_num.size() < 8){ //Makes sure the hexadecimal meets requirements
        cout << "Please re-enter the 8 digit Hexadecimal Number: " << endl;
        cin >> hexa_num;
    }
  
    
    binary1 = convert_binary(hexa_num); //Applied binary to hexa conversion
    flipped = flip_binary(binary1); //Stores the flipped binary in "flipped"
      
    cout<< "Binary: " << binary1 << endl; //Outputs the Binary
    cout<< "Flipped: " <<flipped <<endl; //Outputs the flipped binary
    cout <<"Non Signed: " << nonsigned_num(binary1) <<endl; //Outputs the non signed number
    cout<<"Signed: " << sign_num(binary1, flipped) << endl; //Outputs the signed number
    cout<< "Float Number: " <<Float(binary1) << endl; // Outputs the float number
    cout<<"Would you like to do another hexadecimal number? (Y/N)" <<endl;
    cin >> start;
    }
    return 0;
}

