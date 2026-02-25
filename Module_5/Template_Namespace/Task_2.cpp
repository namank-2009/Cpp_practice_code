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

// Namespace alias - simplifying namespace access
namespace G = Geometry;
int main(){
    // Calling the namespace for struct point
    G::Point p{3, 4};
    // calling the namespace for printPoint function
    G::printPoint(p);
    return 0;
}