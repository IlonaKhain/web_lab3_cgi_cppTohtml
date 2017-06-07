// OOP_lab1_triangle.cpp: определяет точку входа для консольного приложения.
//


#include <cstdlib>
#include "stdafx.h"
//#include <stdlib.h>
#include <vector>

#include <string>
#include "triangle.h"
#include <iostream>


using namespace std;

int main()
{
	char* str=getenv("QUERY_STRING");
	if (str == NULL)
	{
		cout << "error data";
		return 0;
		//str = "3,4,50,1,1,2";
	}
	else if (strcmp(str,"")==0)
	{
		cout << "Content-type:text/html\r\n\r\n";
		cout << "1-st parametr is edge1, 2-nd - edge2, 3-d - percent, 4-th - edge to change 5-th and farther - items of operations" << "<br>";
		cout << "_______________________________________________________" << "<br>";
		cout << "Choose number from the list, which mathes what you want to do with right triangle" << "<br>";
		cout << "1. increase size of edge" << "<br>";
		cout << "2. decrease size of edge" << "<br>";
		cout << "3. count the circumcircle radius" << "<br>";
		cout << "4. count the semiperimetr" << "<br>";
		cout << "5. value of angles" << "<br>";
		return 0;
	}
	else
	{
		string s = str;

		vector<int> param;
		int i = 0;
		string temp = "";
		while (i<s.length())
		{			
			if (str[i] == ',')
			{
				int paramtemp=stoi(temp);
				param.push_back(paramtemp);
				temp = "";	
				i++;
			}
			else if (i == s.length()-1)
			{
				temp += str[i];
				int paramtemp = stoi(temp);
				param.push_back(paramtemp);
				i++;
			}
			else
			{
				temp += str[i];
				i++;
			}	

		}		

		cout << "Content-type:text/html\r\n\r\n";
		cout << "<html>\n";
		cout << "<head>\n";

		cout << "</head>\n";
		cout << "<body>\n";

		cout << "</body>\n";
		cout << "</html>\n";
		int trianglenumber, item, changedtrianglenumber, edge;
		double percent;
		//	cout << "Input number of right triangles ";		
		//	cin >> trianglenumber;	
		trianglenumber = 1;
		// check correctness of inputud value 

		Triangle *triangle = new Triangle[trianglenumber];
		i = 0;
		while (i < trianglenumber)
		{
			/*cout << "Input edge 1 length of " << i + 1 << " triangle ";
			cin >> triangle[i].edge1;
			cout << "Input edge 2 length of " << i + 1 << " triangle ";
			cin >> triangle[i].edge2;*/

			triangle[i].edge1 = param[0];
			triangle[i].edge2 = param[1];
			i++;
			//check correctness of edge length
		}
		cout << "1-st parametr is edge1, 2-nd - edge2, 3-d - percent, 4-th - edge to change 5-th and farther - items of operations" << "<br>";
		cout << "_______________________________________________________" << "<br>";
		cout << "Choose number from the list, which mathes what you want to do with right triangle" <<"<br>";
		cout << "1. increase size of edge" << "<br>";
		cout << "2. decrease size of edge" << "<br>";
		cout << "3. count the circumcircle radius" <<"<br>";
		cout << "4. count the semiperimetr" << "<br>";
		cout << "5. value of angles" << "<br>";
		//cin >> item;
		//cout << "chose triange to be changed (1 - " << trianglenumber << ") ";
		//	cin >> changedtrianglenumber;
		changedtrianglenumber = 1;

		//check does such triange exsist or no
		int j = 4;
		while (j < param.size())
		{
			switch (param[j])
			{
			case 1:
			{
				//	cout << "Input percent which on edge should be increase ";
				//	cin >> percent;
				percent = param[2];
				//cout << "input edge which shoud be increase (1 or 2) ";			
				edge = param[3];
				//cin >> edge;
				cout << "New edge length: " << triangle[changedtrianglenumber - 1].EdgeSizeUp(percent, edge) << "<br>"; break;
			}
			case 2:
			{
				//cout << "Input percent which on edge should be decrease ";			
				//	cin >> percent;
				percent = param[2];
				//cout << "input edge which shoud be increase (1 or 2) ";

				//	cin >> edge;
				edge = param[3];
				cout << "New edge length: " << triangle[changedtrianglenumber - 1].EdgeSizeDown(percent, edge) << "<br>"; break;
			}
			case 3: cout << "Radius: " << triangle[changedtrianglenumber - 1].CircumcircleRadius() << "<br>"; break;
			case 4: cout << "semiperimetr: " << triangle[changedtrianglenumber - 1].HalfPerimetr() << "<br>"; break;
			case 5:
			{
				cout << "Angle 1: " << 90 << "<br>" << endl;
				cout << "Angle 2: " << triangle[changedtrianglenumber - 1].Angle2() << "<br>";
				cout << "Angle 3: " << triangle[changedtrianglenumber - 1].Angle3() << "<br>"; break;
			}
			default: cout << "Such item doesn't exist" << "<br>"; break;

			}
			j++;
		}
		delete[]triangle;
	}		
	//system("pause");
    return 0;
}

