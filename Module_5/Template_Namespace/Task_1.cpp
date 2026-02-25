#include<iostream>
using namespace std;

//Namespace defined with struct point and printPoint
namespace Geometry{
    struct Point{
        int x;
        int y;
    };
    void printPoint(const Point& pt){
        std::cout <<"Point coordinates: (" << pt.x << ", " << pt.y << ")" << std::endl;
    }
}

int main(){
    // Calling the namespace for struct point
    Geometry::Point p{3, 4};
    // calling the namespace for printPoint function
    Geometry::printPoint(p);
    return 0;
}