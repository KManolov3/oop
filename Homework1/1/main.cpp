#include <iostream>
#include "Stack.cpp"
#include "NotSTL.cpp"

double pow(double number, int times){
    double result = number;
    for(int i=1; i<times; i++)
        result *= number;
    return result;
}

double getElement(LStack<double>& st){
    if(st.isEmpty()){
        std::cerr<<"Invalid input format!\n";
        return 0;
    }
    return st.pop();
}

double calculate(char* expression){
    LStack<double> st;
    double sum = 0;

    int n = getLength(expression);

    for(int i=0; i<n; i++){
        if(expression[i] >= '0' && expression[i] <= '9'){
            double toPush = expression[i] - '0';
            while(expression[i+1] >= '0' && expression[i+1]<= '9')
            {
                toPush*=10;
                toPush += expression[i+1] - '0';
                i++;
            }
            if(expression[i+1] == '.'){
                i++;
                int placeAfterDecimal=1;
                while(expression[i+1] >='0' && expression[i+1] <= '9'){
                    toPush += (expression[i+1] - '0') * pow(0.1, placeAfterDecimal);
                    i++;
                }
            }
            st.push(toPush);
        } else {
            if(expression[i]!=' '){

                double second = getElement(st);
                double first = getElement(st);
                if(expression[i] == '+')
                    st.push(first + second);
                else if(expression[i] == '-')
                        st.push(first - second);
                    else if(expression[i] == '*')
                            st.push(first * second);
                        else if(expression[i] == '/')
                                st.push(first/second);
                            else if(expression[i] == '%'){
                                    if(second!=(int)second || first!=(int)first){
                                        std::cerr<<"Trying to use % operation on double arguments!\n";
                                        return 0;
                                    }
                                    st.push((int)first%(int)second);
                            }
            }
        }
    }
    double result = st.pop();
    if(!st.isEmpty()){
        std::cerr<<"Invalid input format!\n";
        return 0;
    }
    return result;
}

int main(){
    char *expression = new char[100];
    std::cin.getline(expression, 100);

    std::cout<<calculate(expression)<<std::endl;

    return 0;
}
