#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double whichSide(double x0, double y0, double x1, double y1, double x2, double y2)
{
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

double distance(double x1, double y1, double x2, double y2)
{
  return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

class MyPoint
{
public:
  double x, y;
  MyPoint *rightMostLowestPoint;

  MyPoint(double x, double y) : x(x), y(y), rightMostLowestPoint(nullptr) {}

  void setRightMostLowestPoint(MyPoint *p)
  {
    rightMostLowestPoint = p;
  }

  bool operator<(const MyPoint &p) const
  {
    double status = whichSide(rightMostLowestPoint->x, rightMostLowestPoint->y, p.x, p.y, this->x, this->y);
    if (status > 0)
      return true;
    else if (status == 0)
      return distance(rightMostLowestPoint->x, rightMostLowestPoint->y, this->x, this->y) >
             distance(rightMostLowestPoint->x, rightMostLowestPoint->y, p.x, p.y);
    else
      return false;
  }
};


std::vector<MyPoint> discardTies(std::vector<MyPoint> &p)
{
  std::vector<MyPoint> list;
  list.push_back(p[0]);

  size_t i = 1;
  while (i < p.size())
  {
    double d = distance(p[0].x, p[0].y, p[i].x, p[i].y);
    size_t indexOfLargest = i;
    size_t k = i + 1;
    while (k < p.size() && p[i] < p[k])
    {
      if (d < distance(p[0].x, p[0].y, p[k].x, p[k].y))
      {
        d = distance(p[0].x, p[0].y, p[k].x, p[k].y);
        indexOfLargest = k;
      }
      k++;
    }

    list.push_back(p[indexOfLargest]);
    i = k;
  }

  return list;
}

void placeP0(std::vector<MyPoint> &p)
{
  size_t rightMostIndex = 0;
  double rightMostX = p[0].x;
  double rightMostY = p[0].y;

  for (size_t i = 1; i < p.size(); i++)
  {
    if (rightMostY > p[i].y || (rightMostY == p[i].y && rightMostX < p[i].x))
    {
      rightMostY = p[i].y;
      rightMostX = p[i].x;
      rightMostIndex = i;
    }
  }

  std::swap(p[0], p[rightMostIndex]);
}

std::vector<MyPoint> getConvexHull(std::vector<std::vector<double>> &points)
{
  std::vector<MyPoint> p;
  for (auto &point : points)
    p.emplace_back(point[0], point[1]);

  placeP0(p);

  for (auto &point : p)
    point.setRightMostLowestPoint(&p[0]);

  std::sort(p.begin(), p.end());

  p = discardTies(p);

  if (p.size() < 3)
    return {};

  std::vector<MyPoint> stack;
  stack.push_back(p[0]);
  stack.push_back(p[1]);
  stack.push_back(p[2]);

  size_t i = 3;
  while (i < p.size())
  {
    MyPoint t2 = stack.back();
    stack.pop_back();
    MyPoint t1 = stack.back();

    if (whichSide(t1.x, t1.y, t2.x, t2.y, p[i].x, p[i].y) <= 0)
    {
      stack.pop_back();
    }
    else
    {
      stack.push_back(t2);
      stack.push_back(p[i]);
      i++;
    }
  }

  return stack;
}

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

  std::vector<MyPoint> list = getConvexHull(p);

  std::cout << "The convex hull is ";
  for (auto &point : list)
  {
    std::cout << "(" << point.x << ", " << point.y << ") ";
  }
  std::cout << std::endl;

  return 0;
}
