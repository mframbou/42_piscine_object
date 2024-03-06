#include <iostream>
#include <vector>
#include <algorithm>

// No getters / setters for simplicity, so we can easily access / modify the values
struct Vector2 {
    float x;
    float y;

    Vector2(float x, float y) : x(x), y(y) {}
};

class Graph {
    private:
        std::vector<Vector2> points;

        bool hasPoint(int x, int y) {
            for (auto &point : points) {
                if (static_cast<int>(point.x) == x && static_cast<int>(point.y) == y) {
                    return true;
                }
            }
            return false;
        }

    public:
        void addPoint(Vector2 point) {
            points.push_back(point);
        }

        // prints graph approximately (rounds the float values to int)
        void printGraph() {
            // first determine the size of the graph rectangle to print
            if (points.empty()) {
                std::cout << "Graph is empty" << std::endl;
                return;
            }
            
            int minX = points[0].x;
            int minY = points[0].y;
            int maxX = points[0].x;
            int maxY = points[0].y;
            for (auto &point : points) {
                if (point.x < minX) minX = point.x;
                if (point.y < minY) minY = point.y;
                if (point.x > maxX) maxX = point.x;
                if (point.y > maxY) maxY = point.y;
            }

            // add 1 to each side like in subject, and print grid         
            for (int y = maxY + 1; y >= minY; y--) {
                std::cout << y << " ";
                for (int x = minX; x <= maxX + 1; x++) {
                    if (hasPoint(x, y)) {
                        std::cout << "x";
                    } else {
                        std::cout << ".";
                    }
                    std::cout << " ";
                }
                std::cout << std::endl;
            }

            std::cout << " ";
            for (int x = minX; x <= maxX + 1; x++) {
                std::cout << " " << x;
            }
            std::cout << std::endl;
        }
};

int main() {
    Graph graph;
    graph.addPoint(Vector2(0, 0));
    graph.addPoint(Vector2(2, 2));
    graph.addPoint(Vector2(4, 2));
    graph.addPoint(Vector2(2, 4));
    graph.printGraph();
    return 0;
}