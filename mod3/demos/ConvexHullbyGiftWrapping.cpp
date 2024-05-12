#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

class Point2D
{
public:
  double x, y;
  Point2D(double x, double y) : x(x), y(y) {}
};

std::vector<Point2D> getConvexHull(std::vector<std::vector<double>> &s);
Point2D getRightmostLowestPoint(std::vector<Point2D> &points);
double distance(double x1, double y1, double x2, double y2);
double whichSide(double x0, double y0, double x1, double y1, double x2, double y2);

int main()
{
  int numberOfPoints;
  std::cout << "How many points are in the set? ";
  std::cin >> numberOfPoints;

  std::vector<std::vector<double>> p(numberOfPoints, std::vector<double>(2));
  std::cout << "Enter " << numberOfPoints << " points: ";
  for (int i = 0; i < numberOfPoints; i++)
    for (int j = 0; j < 2; j++)
      std::cin >> p[i][j];

  std::vector<Point2D> list = getConvexHull(p);

  std::cout << "The convex hull is ";
  for (Point2D point : list)
  {
    std::cout << "(" << point.x << ", " << point.y << ") ";
  }
  std::cout << std::endl;

  return 0;
}

std::vector<Point2D> getConvexHull(std::vector<std::vector<double>> &s)
{
  std::vector<Point2D> myPoints;
  for (auto &point : s)
    myPoints.emplace_back(point[0], point[1]);

  Point2D h0 = getRightmostLowestPoint(myPoints);
  std::vector<Point2D> H;
  H.push_back(h0);

  Point2D t0 = h0;

  while (true)
  {
    Point2D t1 = myPoints[0];
    for (int i = 1; i < myPoints.size(); i++)
    {
      double status = whichSide(t0.x, t0.y, t1.x, t1.y, myPoints[i].x, myPoints[i].y);

      if (status < 0)
        t1 = myPoints[i];
      else if (status == 0)
      {
        if (distance(s[i][0], s[i][1], t0.x, t0.y) > distance(t1.x, t1.y, t0.x, t0.y))
          t1 = myPoints[i];
      }
    }

    if (t1.x == h0.x && t1.y == h0.y)
      break;
    else
    {
      H.push_back(t1);
      t0 = t1;
    }
  }

  return H;
}

Point2D getRightmostLowestPoint(std::vector<Point2D> &points)
{
  int rightMostIndex = 0;
  double rightMostX = points[0].x;
  double rightMostY = points[0].y;

  for (int i = 1; i < points.size(); i++)
  {
    if (rightMostY > points[i].y)
    {
      rightMostY = points[i].y;
      rightMostX = points[i].x;
      rightMostIndex = i;
    }
    else if (rightMostY == points[i].y && rightMostX < points[i].x)
    {
      rightMostX = points[i].x;
      rightMostIndex = i;
    }
  }

  return points[rightMostIndex];
}

double distance(double x1, double y1, double x2, double y2)
{
  return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double whichSide(double x0, double y0, double x1, double y1, double x2, double y2)
{
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
