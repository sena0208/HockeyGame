#ifndef _VECTOR2D_
#define _VECTOR2D_

//#include "include.hpp"
//#include "matrix_2d.hpp"

#define DEG2RAD (M_PI / 180.0)
#define RAD2DEG (180.0 / M_PI)

//class Line2D;
//class Matrix2D;

class Vector2D {
  public:
    double x;
    double y;
    //constructor
    Vector2D() : x(0.0), y(0.0) { }
    //constructor
    Vector2D(const double & xx, const double & yy) : x(xx), y(yy) { }
    //inline
    Vector2D & assign(const double & xx, const double & yy)
    {
      x = xx;
      y = yy;
      return *this;
    }

    double abs() const
    {
      return sqrt(this->x * this->x +this->y * this->y);
    }

    double abs_x() const
    {
      if(x >= 0.0) return x;
      else         return (-x);
    }

    double abs_y() const
    {
      if(y >= 0.0) return y;
      else         return (-y);
    }

    double r2() const
    {
      return x * x + y * y;
    }

    double r() const
    {
      return sqrt( r2() );
    }

    double r3() const
    {
      return ( r() * r() * r() );
    }

    double dist(Vector2D point)
    {
      Vector2D rel = point - *this;
      return rel.r();
    }

    bool isSmallerthan(double r_max)
    {
      if(r() > r_max) return false;
      else            return true;
    }

    Vector2D setPolar(const double radius, const double angle)
    {
      x = radius * std::cos(angle);
      y = radius * std::sin(angle);
      
      return *this;
    }

    void print()
    {
      std::cout << "(x, y) = " << x << ", " << y << std::endl;
    }

    void rotateVector(const double angle)
    {
      double xx = x * cos(angle) - y * sin(angle);
      double yy = x * sin(angle) + y * cos(angle);

      x = xx;
      y = yy;
    }

    Vector2D normalize() const
    {
      Vector2D vec;
      vec = *this;
      vec /= r();
      return vec;
    }

    Vector2D extend(double length)
    {
      Vector2D vec;
      vec = *this;
      vec /= r();
      vec *= length;
      return vec;
    }


    double innerProduct(Vector2D v) const
    {
      return ( (x * v.x) + (y * v.y) );
    }

    double outerProduct(Vector2D v) const
    {
      return ( (x * v.y) - (y * v.x) );
    }

    double radians() const
    {
      return atan(y / x);
    }

    double degrees() const
    {
      return ( atan(y/x) * RAD2DEG );
    }

    Vector2D rel_pos(const Vector2D origin)
    {
      Vector2D rel;

      rel.x = x - origin.x;
      rel.y = y - origin.y;

      return rel;
    }


    /*
       operator overload
    */

    Vector2D operator += (const Vector2D & v)
    {
      x += v.x;
      y += v.y;
      return *this;
    }

    Vector2D operator + (const Vector2D & v)
    {
      x += v.x;
      y += v.y;
      return *this;
    }

    Vector2D operator -= (const Vector2D & v)
    {
      x -= v.x;
      y -= v.y;
      return *this;
    }

    Vector2D operator - (const Vector2D & v)
    {
      x = x - v.x;
      y = y - v.y;
      return *this;
    }

    Vector2D operator *= (const double & a)
    {
      x *= a;
      y *= a;
      return *this;
    }

    Vector2D operator * (const double a)
    {
      x *= a;
      y *= a;
      return *this;
    }

    Vector2D operator /= (const double & a)
    {
      x /= a;
      y /= a;
      return *this;
    }

    Vector2D operator / (const double & a)
    {
      x /= a;
      y /= a;
      return *this;
    }
    
    Vector2D operator = (const Vector2D & v)
    {
      x = v.x;
      y = v.y;
      return *this;
    }

};

#endif //_VECTOR2D_
