#include <iostream>
#include <cmath>

using namespace std;

void printResult(string explanaion ,  float res){
    cout << explanaion << " : " << res << endl;
}

int main()
{

    std::string st (80, '=');
    std::cout<< st<<endl;
    cout << " COVARIANCE == CORRELATION , 단 correlation is bounded btw -1 ~ 1 " << endl;
    std::cout<< st<<endl;


    int x[] = {4,5,8,10};
    int y[] = {12,12,4,3};

    // print X 내용
    int length = 0.0;
    //int sum = 0;
    cout << "x : ";
    for (auto i: x){
        cout << i << " ";
       // sum += i;

        length++;
    }
    cout << "  y : ";
    // print Y 내용
    for (auto i: y){
        cout << i << " ";
    }
    cout << endl;



    int sigmaOfXsquare = 0;
    int sigmaOfYsquare = 0;
    float meanX = 0;
    float meanY = 0;
    float sigmaOfXY = 0;

    for (int i = 0; i< length; i++){

        meanX += x[i];
        meanY += y[i];


        sigmaOfXsquare += pow(x[i], 2);
        sigmaOfYsquare += (y[i]*y[i]);

        sigmaOfXY += (x[i]*y[i]);
    }

    meanX /= length;
    meanY /= length;

    // 1. Variance of X and Y

    float varianceX;
    float varianceY;

    varianceX = sigmaOfXsquare / length - pow(meanX, 2);
    varianceY = sigmaOfYsquare / length - pow(meanY,2);

    // 2. covariance of X, Y

    float covarianceXY;
    covarianceXY = sigmaOfXY / length - (meanX * meanY);

    // 3. correlation coefficient
    float corrCoeff;
    corrCoeff = covarianceXY / (sqrt(varianceX) * sqrt(varianceY));


    printResult("                  X mean", meanX);
    printResult("                  Y mean", meanY);
    printResult("             variance(X)",varianceX );
    printResult("             variance(Y)",varianceY );
    printResult("         COVARIANCE (XY)",covarianceXY );
    printResult("correlation  coefficient", corrCoeff);

    cout << endl ;
    std::cout<< st<<endl;
    cout << "correlation coefficient is -0.99 ==> 반대 상관관계 ==> if X gets big, Y gets smaller  OR 반대로" << endl;
    std::cout<< st<<endl;



    return 0;
}
