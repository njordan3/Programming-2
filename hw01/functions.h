
// put your function bodies here


// create a function  that returns the middle value of 3 integer parameters

int	Function1(int a,int b,int c)
{
	LogStart(a,b,c);
	int result =c;
	if ((a - b) * (c - a) >= 0)
		result=a;
	if ((b - a) * (c - b) >= 0)
		result=b;
	LogEndReturning(result);
	return result;
}

// create a function  that returns the middle value of 3 char parameters

char MiddleChar_PBV(char a,char b,char c)
{
    LogStart(a,b,c);
    char result;
    if(a > b && b > c)
    {
        result = b;          
    }
    else if(b > a && a > c)
    {
        result = a;
    }
    else if(c > b && b > a)
    {
        result = b;
    }
    else if(b > c && c > a)
    {
        result = c;
    }
    else if(c > a && a > b)
    {
        result = a;   
    }
    else if(a > c && c > b)
    {
        result = c;
    }
    LogEndReturning(result);
    return result; 
}

// create a function  that determines the middle value of ( int )parameters 2,3 & 4 and stores that value into the 1st parameter

void MiddleValue_PBR(int &result, int a,int b,int c)
{
    LogStart(result,a,b,c);
    
    result = c;
    if((a - b) * (c - a) >= 0)
        result = a;
    if((b - a) * (c - b) >= 0)
        result = b;

    LogEnd(result,a,b,c);
}


// create a functions that determines the middle value of ( char ) parameters 2,3 & 4 and stores that value into the 1st parameter 

void MiddleChar_PBR(char& result, char a,char b,char c)
{
    LogStart(result,a,b,c);
    if(a > b && b > c)
    {
        result = b;          
    }
    else if(b > a && a > c)
    {
        result = a;
    }
    else if(c > b && b > a)
    {
        result = b;
    }
    else if(b > c && c > a)
    {
        result = c;
    }
    else if(c > a && a > b)
    {
        result = a;   
    }
    else if(a > c && c > b)
    {
        result = c;
    }
    LogEnd(result,a,b,c);

}

// create a function that returns the sum of parameters 1,2,3,4 & 5 

double GetSum_PBV(double a,double b,double c,double d,double e)
{
    LogStart(a,b,c,d,e);
    double result = a + b + c + d + e; 
    LogEndReturning(result);
    return result;
}

// create a function that determines the sum of parameters 2,3,4,5 & 6 and stores that result in parameter 1 

void GetSum_PBR(double& result ,double a,double b,double c,double d,double e)
{
    LogStart(result,a,b,c,d,e);
    result = a + b + c + d + e;
    LogEnd(result,a,b,c,d,e);
}

// create a functions that can sort parameters 1 ,2 ,3  in ascending order

void SortInAscending(double& one , double& two, double& three)
{
    LogStart(one,two,three);
    int a = one, b = two, c = three;
    if(one > two && two > three)
    {
        one = c;
        two = b;
        three = a;       
    }
    else if(two > one && one > three)
    {
        one = c;
        two = a;
        three = b;
    }
    else if(three > two && two > one)
    {
        one = a;
        two = b;
        three = c;
    }
    else if(two > three && three > one)
    {
        one = a;
        two = c;
        three = b;
    }
    else if(three > one && one > two)
    {
        one = b;
        two = a;
        three = c;
    }
    else if(one > three && three > two)
    {
        one = b;
        two = c;
        three = a;
    }
    LogEnd(one,two,three);
}


// create a functions that can sort parameters 1 ,2 ,3  in descending order

void SortInDescending(double& one, double& two, double& three)
{
    LogStart(one,two,three);
    int a = one, b = two, c = three;
    if(one > two && two > three)
    {
        one = a;
        two = b;
        three = c;       
    }
    else if(two > one && one > three)
    {
        one = b;
        two = a;
        three = c;
    }
    else if(three > two && two > one)
    {
        one = c;
        two = b;
        three = a;
    }
    else if(two > three && three > one)
    {
        one = b;
        two = c;
        three = a;
    }
    else if(three > one && one > two)
    {
        one = c;
        two = a;
        three = b;
    }
    else if(one > three && three > two)
    {
        one = a;
        two = c;
        three = b;
    }
    LogEnd(one,two,three);
}





