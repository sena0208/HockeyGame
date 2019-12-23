#ifndef _VECTOR2D_
#define _VECTOR2D_

#include <iostream>
#include <cmath>

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
      if(x < 0) return (-x);
      else      return x;
    }

    double abs_y() const
    {
      if(y < 0) return (-y);
      else      return y;
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

};

#endif //_VECTOR2D_
