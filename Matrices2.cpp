//This program is for matrix calculations
#include <iostream>
#include <vector>
#include <conio.h> // for _getch
#include <cctype>
#include <string>
std::vector < std::vector<double> > matrix_1;
std::vector < std::vector<double> > matrix_2;
int rows_1;
int columns_1;
int rows_2; //This is for the second matrix when multiplying
int columns_2; //This is for the second matrix when multiplying
std::vector < std::vector<double> > result; //This is for storing the result
int operation;//This one is for the user to choose the operation
double input;//This is for the user input for the values inside the Matrices
//---------------------------------------------------------------------------------------------------------------------
//The below function is for being to able to give input without inserting a new line
double get_input()
    {std::string word ="";
    char c = _getch();
    while (not(std::isspace(c)))
        {word.push_back(c);
        std::cout<<c;
        c=_getch();
        }
    std::cout<< c;
    input = std::stod(word);
    return input;}
//The below function is for creating a matrix
void create_matrix(std::vector < std::vector<double> > & matrix, int rows, int columns){
    matrix.clear();
    for (int i =0; i<rows; i++)
            {std::vector<double> row ={};
            for (int j = 0; j<columns; j++){
                if (rows==1 and columns==1){
                    std::cout<<"[ ";
                    input = get_input();
                    row.push_back(input);
                    std::cout<<"]"<<"\n";}
                else if ((columns==1 and i==0) or (columns==1 and (i==rows-1)))
                {std::cout<<"[ ";
                    input = get_input();
                    row.push_back(input);
                    std::cout<<"]"<<"\n";}
                else if (columns==1){
                    std::cout<<"| ";
                    input = get_input();
                    row.push_back(input);
                    std::cout<<"|"<<"\n";}
                else if ((j==0 and i==0) or (j==0 and i==(rows-1)))
                {std::cout<<"[ ";
                input = get_input();
                row.push_back(input);
                std::cout<<" ";}
                else if ((j==(columns-1) and i==0) or (j==(columns-1) and i==(rows-1)))
                {input = get_input();
                std::cout<<" ]"<<"\n";
                row.push_back(input);}
                else if (j==0){ std::cout<<"| ";
                                input= get_input();
                                row.push_back(input);
                                std::cout<<" ";}
                else if (j==(columns-1)){input = get_input();
                                    std::cout<<" |";
                                    row.push_back(input);
                                    std::cout<<"\n";}
                else {input = get_input();
                    row.push_back(input);
                    std::cout<<" ";}
                    }
            matrix.push_back(row);
            }
            }
//This function is for addition
void add(){
    std::cout<<"Insert the amount of rows (horizontal - ) there are: ";
    std::cin >> rows_1;
    std::cout<<"Insert the amount of columns (vertical | ) there are: ";
    std::cin >> columns_1;
    std::cout<<"\nENTER EACH NUMBER IN THE FIRST MATRIX SEPARATED BY A SPACE, NO BACKSPACE ALLOWED\n\n";
    create_matrix(matrix_1, rows_1, columns_1);
    std::cout<<"\nNow for the creation of the second matrix\n";
    create_matrix(matrix_2, rows_1, columns_1);
    //Creating the result matrix
    result={};
    for (int i=0; i<rows_1; i++)
    {std::vector<double> row = {};
    for (int j=0; j<columns_1; j++)
    {row.push_back((matrix_1[i][j]+matrix_2[i][j]));}
    result.push_back(row);}
    //Printing the result matrix
    std::cout<<"\nHere is the result: \n";
    for (int i=0; i<rows_1; i++)
    {for (int j=0; j<columns_1; j++)
    {if (rows_1==1 and columns_1==1){std::cout<<"[ "<<result[0][0]<<" ]\n";}
    else if ((columns_1==1 and i == 0 ) or ( columns_1==1 and (i==rows_1-1))){std::cout<<"[ "<<result[i][j]<<" ]\n";}
    else if (columns_1==1){std::cout<<"| "<<result[i][j]<<" |";}
    else if ((i==0 and j==0) or (i==(rows_1-1) and j==0)){std::cout<<"[ "<<result[i][j]<<" ";}
    else if ((i==0 and j==(columns_1-1)) or (i==(rows_1-1) and j==(columns_1-1))) {std::cout<<result[i][j]<<" ]\n";}
    else if (j==0){std::cout<<"| "<<result[i][j]<<" ";}
    else if (j==(columns_1-1)) {std::cout<< result[i][j] <<" |\n";}
    else {std::cout<<result[i][j]<<" ";}}
    }
    }

//Create another function that will do the subtraction. It is the same as the addition one, only that corresponding values are subtracted
void subtract(){
    std::cout<<"Insert the amount of rows (horizontal - ) there are: ";
    std::cin >> rows_1;
    std::cout<<"Insert the amount of columns (vertical | ) there are: ";
    std::cin >> columns_1;
    std::cout<<"\nENTER EACH NUMBER IN THE FIRST MATRIX SEPARATED BY A SPACE, NO BACKSPACE ALLOWED\n\n";
    create_matrix(matrix_1, rows_1, columns_1);
    std::cout<<"\nNow for the creation of the second matrix\n";
    create_matrix(matrix_2, rows_1, columns_1);
    //Creating the result matrix
    result={};
    for (int i=0; i<rows_1; i++)
    {std::vector<double> row = {};
    for (int j=0; j<columns_1; j++)
    {row.push_back((matrix_1[i][j]-matrix_2[i][j]));}
    result.push_back(row);}
    //Printing the result matrix
    std::cout<<"\nHere is the result: \n";
    for (int i=0; i<rows_1; i++)
    {for (int j=0; j<columns_1; j++)
    {if (rows_1==1 and columns_1==1){std::cout<<"[ "<<result[0][0]<<" ]\n";}
    else if ((columns_1==1 and i == 0 ) or ( columns_1==1 and (i==rows_1-1))){std::cout<<"[ "<<result[i][j]<<" ]\n";}
    else if (columns_1==1){std::cout<<"| "<<result[i][j]<<" |";}
    else if ((i==0 and j==0) or (i==(rows_1-1) and j==0)){std::cout<<"[ "<<result[i][j]<<" ";}
    else if ((i==0 and j==(columns_1-1)) or (i==(rows_1-1) and j==(columns_1-1))) {std::cout<<result[i][j]<<" ]\n";}
    else if (j==0){std::cout<<"| "<<result[i][j]<<" ";}
    else if (j==(columns_1-1)) {std::cout<< result[i][j] <<" |\n";}
    else {std::cout<<result[i][j]<<" ";}}
    }
    }
//Create another function that will do the multiplication
int multiply(){
    std::cout<<"Insert the amount of rows (horizontal - ) there are in the first matrix: ";
    std::cin >> rows_1;
    std::cout<<"Insert the amount of columns (vertical | ) there are in the first matrix: ";
    std::cin >> columns_1;
    std::cout<<"\nInsert the amount of rows (horizontal - ) there are IN THE SECOND MATRIX: ";
    std::cin >> rows_2;
    std::cout<<"Insert the amount of columns (vertical | ) there are IN THE SECOND MATRIX: ";
    std::cin >> columns_2;
    //This is just to prevent multiplying matrices which cannot be multiplied
    if (not(columns_1==rows_2)) {std::cout<<"\nYOU CAN'T MULTIPLY THESE 2 MATRICES !!!\n"; return 0;}
    std::cout<<"\nENTER EACH NUMBER IN THE FIRST MATRIX SEPARATED BY A SPACE, NO BACKSPACE ALLOWED\n\n";
    create_matrix(matrix_1, rows_1, columns_1);
    std::cout<<"\nNow for the creation of the second matrix\n";
    create_matrix(matrix_2, rows_2, columns_2);
    //Creating the result matrix
    result={};
    std::vector<double> row (columns_2); //This is a temporary variable to store the rows that will be added to the result matrix
    for (int i = 0; i<rows_1; i++){result.push_back(row);}
    //Now to add values to the result matrix
    for (int a = 0; a<rows_1; a++){
        for (int b = 0; b<columns_2; b++){
                for (int j = 0; j<rows_2; j++){
                    result[a][b]+=(matrix_1[a][j]*matrix_2[j][b]);}
        }}
    //Printing the result
    std::cout<<"\nHere is the result: \n";
    for (int i=0; i<rows_1; i++)
    {for (int j=0; j<columns_2; j++)
    {if (rows_1==1 and columns_2==1){std::cout<<"[ "<<result[0][0]<<" ]\n";}
    else if ((columns_2==1 and i == 0 ) or ( columns_2==1 and (i==rows_1-1))){std::cout<<"[ "<<result[i][j]<<" ]\n";}
    else if (columns_2==1){std::cout<<"| "<<result[i][j]<<" |";}
    else if ((i==0 and j==0) or (i==(rows_1-1) and j==0)){std::cout<<"[ "<<result[i][j]<<" ";}
    else if ((i==0 and j==(columns_2-1)) or (i==(rows_1-1) and j==(columns_2-1))) {std::cout<<result[i][j]<<" ]\n";}
    else if (j==0){std::cout<<"| "<<result[i][j]<<" ";}
    else if (j==(columns_2-1)) {std::cout<< result[i][j] <<" |\n";}
    else {std::cout<<result[i][j]<<" ";}}
    }
    return 0;
}

//This function is for choosing the operation
void decide(){
    std::cout<<"\nSelect an operation: \n";
    std::cout<<"1. Addition\n";
    std::cout<<"2. Subtraction\n";
    std::cout<<"3. Multiplication\n";
    std::cin >> operation;
    while ((operation!=1) and (operation!=2) and (operation!=3)){
        std::cout<<"Please enter the number of an existing operation: ";
        std::cin >> operation;}
    if (operation==1){ add(); }
    else if (operation==2){ subtract(); }
    else { multiply(); }}
//---------------------------------------------------------------------------------------------------------------------
int main() {
    std::cout<<"This program was coded by Saifeldin Mohamed Farid from 11XE in 2020\n";
    std::cout<<"-------------------------------------------------------------------\n";
    std::cout<<"MATRIX CALCULATOR\n";
    std::cout<<"-------------------------------------------------------------------\n";
    while(true){decide();}
}