#include <stdio.h>
#include <stdlib.h>

//1
double add(double firstNumber, double secondNumber){
    double sum;
    sum = firstNumber + secondNumber;
    return sum;
}

//2
double multiply(double firstNumber, double secondNumber){
    double result;
    result = firstNumber * secondNumber;
    return result;
}

//3
double divide(double firstNumber, double secondNumber){
    double result;
    result = firstNumber / secondNumber;
    return result;
}

//4
void minOfList(int list[],int size){
  int min,i,location;
  min=list[0];
  for(i=1;i<size;i++){
        if(min>list[i]){
            min=list[i];
            location=i+1;
        }
  }
  printf("The Minimum number in the list is :%d and Represented in location %d\n",min,location);
}

//5
float calculateSin(float angle){
    float toRadian=3.142 / 180.0;
    angle = angle * toRadian; //Converting the angle to radian
    float term = angle; //The radian angle is now our initial term
    float lastValue = term;
    int n = 1;
    int i=0;
    while(i<10){ //Calculate the sum of Taylor's Series Terms and add them to the initial term
            // Keep doing this until you get a desired precise output
        float denominator = 2 * n * (2 * n + 1);
        term = -term * angle * angle / denominator;
        lastValue = lastValue + term;
        n = n + 1;
        i++;
    }
    return lastValue;
}

//6
double calculateCosine(double x)
{
    double t0, t1, R, sum;
    x = x * 0.01745;//to convert the degree value to radian
    t0 = 1;
    sum = t0;
    for(int i = 1; i < 100; i++)
    {
        R =- (x*x)/(2*i-1)/(2*i);//Find the ratio of the second term to the first term using already known relation
        t1 = R * t0;//Calculate the second term
        sum = sum + t1; //find the new sum
        t0 = t1;
        //Keep on summing the terms to get a more precise number after the floating point
    }
    return sum;
}

//7
float calculateTan(float angle){
    float sin,cosine,result;
    sin = calculateSin(angle);
    cosine = calculateCosine(angle);
    result = sin / cosine;
    return result;
}

//8
int square_detection(float a, float b, float c, float d)
{
    return(a == b && a == c && a == d); //if the return value is true then it is a square, otherwise it is not
}

//9
int rectangle_detection(float a, float b, float c, float d)
{
    if(a == b && c == d)
        return 1;

    if(a == d && b == c)
        return 1;

    if(a == c && b == d)
        return 1;

    return 0;
}

//10
int triangle_detection(float a, float b, float c)
{
    return(a + b > c && b + c > a && a + c > b); //if the return value is true then it is a triangle, otherwise it is not
}


int main()
{
    int operationNumber,c;
    do{
    printf("\nScientific Calculator:\n0- Exit\n1- Add Operation\n2- Multiply Operation\n3- Division Operation\n4- Minimum of List\n5- Sin of angle\n6- Cos of angle\n7- Tan of angle\n8- Square Detection\n9- Rectangle Detection\n10- Triangle Detection\n\n");
    printf("Your choice: \n");
    scanf("%d",&operationNumber);
    switch(operationNumber){
        case 0:
            break;
        case 1:
            printf("Enter the first number: \n");
            double h,y,sum;
            scanf("%lf",&h);
            printf("Enter the second number: \n");
            scanf("%lf",&y);
            sum = add(h,y);
            printf("The result = %lf\n",sum);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 2:
            printf("Enter the first number: \n");
            double s,r,number;
            scanf("%lf",&s);
            printf("Enter the second number: \n");
            scanf("%lf",&r);
            number = multiply(s,r);
            printf("The result = %lf\n", number);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 3:
            printf("Enter the first number: \n");
            double e,n,end;
            scanf("%lf",&e);
            printf("Enter the second number: \n");
            scanf("%lf",&n);
            end = divide(e,n);
            printf("The result = %lf\n", end);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 4:
            printf("Enter the size of list ");
            int size,list[10000];
            scanf("%d",&size);
            printf("Enter the elements of list:");
            for(int i=0;i<size;i++){
                scanf("%d",&list[i]);
            }
            minOfList(list,size);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 5:
            printf("Enter the angle in degree: \n");
            float angle,result;
            scanf("%f",&angle);
            result = calculateSin(angle);
            printf("The sine = %f\n",result);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 6:
            printf("Enter the angle in degree: \n");
            double x,value;
            scanf("%lf",&x);
            value = calculateCosine(x);
            printf("The sine = %f\n",value);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 7:
            printf("Enter the angle in degree: \n");
            scanf("%f",&angle);
            result = calculateTan(angle);
            printf("The tan = %f\n",result);
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 8:
            printf("Enter the four sides of the square: \n");
            int answer;
            float a,b,c,d;
            scanf("%f",&a);
            scanf("%f",&b);
            scanf("%f",&c);
            scanf("%f",&d);
            answer = square_detection(a,b,c,d);
            if(answer){
                printf("It is a Square");
            }
            else
                printf("It is not a Square");
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 9:
            printf("Enter the four sides of the Rectangle: \n");
            int t;
            float o,p,z,m;
            scanf("%f",&o);
            scanf("%f",&p);
            scanf("%f",&z);
            scanf("%f",&m);
            t = rectangle_detection(o,p,z,m);
            if(t){
                printf("It is a Rectangle");
            }
            else
                printf("It is not a Rectangle");
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        case 10:
            printf("Enter the three sides of the Triangle: \n");
            int k;
            float first,second,third;
            scanf("%f",&first);
            scanf("%f",&second);
            scanf("%f",&third);
            k = triangle_detection(first,second,third);
            if(k){
                printf("It is a Triangle");
            }
            else
                printf("It is not a Triangle");
            printf("0- Exit\n1- Another Operation\n");
            scanf("%d",&operationNumber);
            break;
        default:
            printf("Please enter a valid choice");
            break;
    }}while(operationNumber != 0);
    return 0;
}
